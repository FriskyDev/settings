#include <cex/StringUtil.hpp>

#include <algorithm>
#include <sstream>
#include <string>

namespace cex
{
    namespace StringUtil
    {
        std::vector<std::string> splitString(const std::string& s, char delimiter)
        {
            std::stringstream str(s);
            std::string part;
            std::vector<std::string> elems;
            while (std::getline(str, part, delimiter)) {
                elems.push_back(part);
                part = "";
            }

            return std::move(elems);
        }

        // trim from start (in place)
        void left_trim(std::string& s)
        {
            s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) { return !std::isspace(ch); }));
        }

        // trim from end (in place)
        void right_trim(std::string& s)
        {
            s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) { return !std::isspace(ch); }).base(), s.end());
        }

        // trim from both ends (in place)
        void trim(std::string& s)
        {
            left_trim(s);
            right_trim(s);
        }

        // trim from start (copying)
        std::string left_trim_copy(std::string s)
        {
            left_trim(s);
            return std::move(s);
        }

        // trim from end (copying)
        std::string right_trim_copy(std::string s)
        {
            right_trim(s);
            return std::move(s);
        }

        // trim from both ends (copying)
        std::string trim_copy(std::string s)
        {
            trim(s);
            return std::move(s);
        }
    }
}
