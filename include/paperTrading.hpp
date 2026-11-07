#pragma once

#include "tradeData.hpp"
#include <vector>

namespace lookback::papertrading {

    class PaperTrading {
        public:
            explicit PaperTrading() = default;
            int checkBalance() const;
            void placeTrade(const trade::TradeData &trade);

            static void setInitialWalletCapital(int amount);

        private:
            inline static int walletCapital = 10000; // shared var
            std::vector<trade::TradeData> currentTrades;

    };

} // namespace lookback::papertrading
