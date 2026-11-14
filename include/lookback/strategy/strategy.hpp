#pragma once

#include "lookback/core/tradeData.hpp"
#include <vector>

namespace lookback::strategy {

    class StrategyInterface {
        public:
            virtual ~StrategyInterface() = default;
            virtual lookback::trade::Signal onCandle(std::vector<lookback::trade::Candle> &history) = 0;
    };

} // namespace lookback::strategy
