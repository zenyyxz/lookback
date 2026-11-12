#include "cli.hpp"
#include "paperTrading.hpp"
#include "tradeData.hpp"
#include "fetchCandles.hpp"
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

    lookback::trade::FetchCandles* fetchObj = new lookback::trade::FetchCandlesCSV();
    std::vector<lookback::trade::Candle> candleVec = fetchObj->fetch("BCHUSD_250328-15m-2025-03.csv");
    if (candleVec.empty()) return 1;

    for (int i{0}; i < 10; i++) {
        std::cout << "\n\nChecking candle " << i <<   "'s data\n"
            << "open_time: " << candleVec[i].open_time << "\n"
            << "open: " << candleVec[i].open << "\n"
            << "high: " << candleVec[i].high << "\n"
            << "low: " << candleVec[i].low << "\n"
            << "close: " << candleVec[i].close << "\n"
            << "volume: " << candleVec[i].volume << "\n"
            << "close_time: " << candleVec[i].close_time << "\n";
    }

    return 0;
}
