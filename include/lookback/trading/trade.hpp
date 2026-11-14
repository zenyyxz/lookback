#pragma once

#include "lookback/core/tradeData.hpp"
#include <vector>

namespace lookback::trade {

    class TradeFutures {
        public:
            explicit TradeFutures() = default;
            virtual ~TradeFutures() = default;

            virtual double checkBalance() const = 0;
            virtual void placeTrade(const trade::TradeData &trade) = 0;
    };

    class PaperTrade : public TradeFutures {
        public:
            double checkBalance() const override;
            void placeTrade(const trade::TradeData &trade) override;
            void setInitialWalletCapital(int amount);

        private:
            inline static double walletCapital = 10000.000; // shared var
            std::vector<trade::TradeData> currentTrades;
    };

} // namespace lookback::papertrading
