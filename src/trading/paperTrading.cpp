#include "lookback/trading/trade.hpp"

namespace lookback::trade {

    double PaperTrade::checkBalance() const {
        return walletCapital;
    }

    void PaperTrade::placeTrade(const trade::TradeData &trade) {
        walletCapital -= trade.margin;
        currentTrades.push_back(trade);
    }

    void PaperTrade::setInitialWalletCapital(int amount) {
        walletCapital = amount;
    }

} // namespace lookback::trade
