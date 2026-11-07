#pragma once

#include <string>
#include <cstdint>

namespace lookback::trade {
    struct TradeData {
        TradeData() = default;
        TradeData(std::string _pair, int64_t _margin, bool _futures, int _leverage, int64_t _sl, int64_t _tp) : coinPair(_pair), margin(_margin), futures(_futures), leverage(_leverage), stopLoss(_sl), takeProfit(_tp) {};

        std::string coinPair;
        int64_t margin;
        bool futures;
        int leverage;
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
