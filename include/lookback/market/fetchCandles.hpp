#pragma once

#include "lookback/core/tradeData.hpp"
#include "lookback/core/utils.hpp"
#include <cstdint>
#include <fstream>
#include <vector>
#include <iostream>

/**
 * We'll be reading local flat file database of candles, probably in CSV format.
 *
 * NOTE: Implement WS client to connect to binance public WS server for future candle updates
 *       instead of using this dumb flat file method.
 */

namespace lookback::trade {
    class FetchCandles {
        public:
            FetchCandles() = default;
            virtual ~FetchCandles() = default;
            virtual std::vector<Candle> fetch(const std::string &source) = 0;
    };

    class FetchCandlesCSV : public FetchCandles {
        public:
            std::vector<Candle> fetch(const std::string &filePath) override {
                // read lines from CSV file, assign values to candle, then push to candles vector.
                std::vector<Candle> candles;

                std::fstream file(filePath, std::ios::in);
                if (!file.is_open()) {
                    std::cerr << "Error opening " << filePath << ".\n";
                    return {};
                }

                std::string line;
                while (std::getline(file, line)) {
                    if (line.starts_with("open_time")) continue;
                    std::vector<std::string> values = lookback::utils::split(line, ',');
                    /**
                     * values format:
                     *      open_time,open,high,low,close,volume,close_time
                     */
                    Candle candle;
                    candle.open_time = static_cast<int64_t>(std::stoll(values[0]));
                    candle.open = std::stod(values[1]);
                    candle.high = std::stod(values[2]);
                    candle.low = std::stod(values[3]);
                    candle.close = std::stod(values[4]);
                    candle.volume = std::stod(values[5]);
                    candle.close_time = std::stod(values[6]);

                    candles.push_back(candle);
                }

                return candles;
            }
    };

} // namespace lookback::trade
