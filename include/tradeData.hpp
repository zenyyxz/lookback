#pragma once

#include <string>
#include <cstdint>

namespace lookback::trade {
    struct TradeData {
        std::string coinPair = "BTCUSDT";
        int64_t margin;
        bool futures = true;
        int leverage = 1;
        int64_t stopLoss;
        int64_t takeProfit;
    };

    struct Candle {
        int64_t open;
        int64_t close;
        int64_t high;
        int64_t low;
    };
}
