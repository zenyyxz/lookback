#include "cli.hpp"

#include <iostream>

namespace lookback::cli {

    CLIParser::CLIParser(int argc, char* argv[]) {
        for (int i = 1; i < argc; i++) {
            _args.push_back(argv[i]);
        }
    }

    void CLIParser::printHelp() const {
        std::cout << "Hi, ask me how i am doing.\n\n"
        << "I'm a dumb bot.\n"
        << "how are you doing bud?\n"
        << "how's life?\n\n";
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
}
