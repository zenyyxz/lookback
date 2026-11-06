#pragma once

#include <vector>
#include <string>

namespace lookback::cli {
    class CLIParser {
        public:
            CLIParser() = default;
            CLIParser(int argc, char* argv[]);

            void printHelp() const;
            // std::string getFlag(const std::string& flag) const;
            bool hasCommand(const std::string& command) const;

        private:
            std::vector<std::string> _args;
    };
} // namespace lookback::cli
