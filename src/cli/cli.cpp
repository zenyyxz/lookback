#include "lookback/cli/cli.hpp"

#include <iostream>

namespace lookback::cli {

    CLIParser::CLIParser(int argc, char* argv[]) {
        for (int i = 1; i < argc; i++) {
            _args.push_back(argv[i]);
        }
    }

    void CLIParser::printHelp() const {
        std::cout << "Usage: lookback [options...]\n\n"
        << " -h, --help                          Print this message\n"
        << " -s, --strategy                      Choose trading strategy.\n"
        << " -f, --filepath                      Use local CSV file to get candle data.\n"
        << " This is all for now. \n\n";
    }

    bool CLIParser::hasCommand(const std::string &command) const {
        for (const auto &cmd : _args) {
            if (cmd == command) return true;
        }
        return false;
    }

    /*
    std::string CLIParser::getFlag(const std::string& flag) const {
        if ()
    }
    */
} // namespace lookback::cli
