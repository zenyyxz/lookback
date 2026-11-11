#pragma once

#include "tradeData.hpp"
#include "utils.hpp"
#include <cstdint>
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>

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
                     *      open_time,open,high,low,close,volume,close_time,quote_volume
                     */
                    Candle candle;
                    candle.open_time = static_cast<int64_t>(std::stoll(values[0]));
                    // TODO: declare a new utility function to convert doubles into int64_t after rounding them and multiplying them correctly without dropping the decimal parts.
                }
            }
    };
} // namespace lookback::trade

// open_time,open,high,low,close,volume,close_time,quote_volume,count,taker_buy_volume,taker_buy_quote_volume,ignore
/**
 * 1740787200000,316.48,316.51,315.79,316.27,229,1740788099999,7.24363564,229,0,0,0
 1740788100000,316.51,316.93,315.55,316.24,169,1740788999999,5.34408557,169,0,0,0
 1740789000000,316.39,316.75,315.28,315.58,164,1740789899999,5.18864521,164,2,0.06338744,0
 1740789900000,315.70,316.09,315.22,315.34,104,1740790799999,3.29437411,104,0,0,0
 1740790800000,315.34,315.34,315.34,315.34,0,1740791699999,0,0,0,0,0
 1740791700000,315.34,315.34,315.34,315.34,0,1740792599999,0,0,0,0,0
 1740792600000,315.34,315.34,315.34,315.34,0,1740793499999,0,0,0,0,0
 1740793500000,321.07,321.35,320.46,320.95,128,1740794399999,3.98884074,128,0,0,0
 1740794400000,320.92,320.95,318.22,319.71,1669,1740795299999,52.25906087,1668,1553,48.63186238,0
 1740795300000,319.42,321.69,318.60,321.52,2694,1740796199999,84.20410611,2502,2694,84.20410611,0
 */
