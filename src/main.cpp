#include "cli.hpp"
#include "paperTrading.hpp"
#include "tradeData.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        std::cerr << "\npass some shit dude.\n\n";
    }

    lookback::cli::CLIParser parser(argc, argv);
    lookback::papertrading::PaperTrading mockTrade;

    if (parser.hasCommand("-h") || parser.hasCommand("--help")) {
        parser.printHelp();
    }

    std::cout << "Capital before updating.\n";
    std::cout << mockTrade.checkBalance() << "\n\n";
    std::cout << "Capital after updating.\n";
    mockTrade.setInitialWalletCapital(15000);
    std::cout << mockTrade.checkBalance() << "\n\n";

    std::cout << "Balance after placing a trade.\n";
    lookback::trade::TradeData trade("BTCUSDT", 500, true, 3, 76008, 78000);

    mockTrade.placeTrade(trade);
    std::cout << mockTrade.checkBalance() << "\n\n";

    return 0;
}
