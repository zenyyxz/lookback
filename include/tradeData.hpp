#pragma once

#include <string>
#include <cstdint>

namespace lookback::trade {
    struct TradeData {
        TradeData() = default;
        ~TradeData() = default;
        TradeData(std::string _pair, int64_t _margin, bool _futures, int _leverage, int64_t _sl, int64_t _tp) : coinPair(_pair), margin(_margin), futures(_futures), leverage(_leverage), stopLoss(_sl), takeProfit(_tp) {};

        std::string coinPair;
        int64_t margin;
        bool futures;
        int leverage;
        int64_t stopLoss;
        int64_t takeProfit;
    };

    struct Candle {
        Candle() = default;

        int64_t open_time;
        double open;
        double close;
        double high;
        double low;
        double volume;
        int64_t close_time;
        // int64_t quote_volume;
    };
} // namespace lookback::trade

//open_time,open,high,low,close,volume,close_time,quote_volume,count,taker_buy_volume,taker_buy_quote_volume,ignore
