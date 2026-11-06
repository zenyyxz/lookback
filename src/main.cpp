#include "cli.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        std::cerr << "\npass some shit dude.\n\n";
    }

    lookback::cli::CLIParser parser(argc, argv);

    if (parser.hasCommand("-h") || parser.hasCommand("--help")) {
        parser.printHelp();
    }

    return 0;
}
