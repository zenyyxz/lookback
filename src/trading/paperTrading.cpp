#include "lookback/trading/paperTrading.hpp"

namespace lookback::papertrading {

    int PaperTrading::checkBalance() const {
        return walletCapital;
    }

    void PaperTrading::placeTrade(const trade::TradeData &trade) {
        walletCapital -= trade.margin;
        currentTrades.push_back(trade);
    }

    void PaperTrading::setInitialWalletCapital(int amount) {
        walletCapital = amount;
    }

} // namespace lookback::papertrading
