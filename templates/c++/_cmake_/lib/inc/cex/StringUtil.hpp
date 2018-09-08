#pragma once

#include <string>
#include <vector>

namespace cex
{
    namespace StringUtil
    {
        std::vector<std::string> splitString(const std::string& s, char delimiter);

        // trim from start (in place)
        void left_trim(std::string& s);

        // trim from end (in place)
        void right_trim(std::string& s);

        // trim from both ends (in place)
        void trim(std::string& s);

        // trim from start (copying)
        std::string left_trim_copy(std::string s);

        // trim from end (copying)
        std::string right_trim_copy(std::string s);

        // trim from both ends (copying)
        std::string trim_copy(std::string s);
    }
}
