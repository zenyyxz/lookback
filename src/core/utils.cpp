#include "lookback/core/utils.hpp"

#include <sstream>

namespace lookback::utils {
    std::vector<std::string> split(const std::string &str, const char deliminator) {
        std::vector<std::string> tokens;
        std::istringstream ss(str);
        std::string token;

        while (std::getline(ss, token, deliminator)) {
            tokens.push_back(token);
        }
        return tokens;
    }
}
