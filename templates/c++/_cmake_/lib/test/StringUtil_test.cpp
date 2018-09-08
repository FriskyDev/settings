#include <gtest/gtest.h> // googletest header file

#include <string>

#include <cex/StringUtil.hpp>

TEST(StringUtil_test, left_trim)
{
    using namespace cex;
    using std::string;

    string value = "   <-left_trim";
    char const* expectVal = "<-left_trim";

    StringUtil::left_trim(value);
    EXPECT_STREQ(expectVal, value.c_str());
}

TEST(StringUtil_test, right_trim)
{
    using namespace cex;
    using std::string;

    string value = "right_trim->   ";
    char const* expectVal = "right_trim->";

    StringUtil::right_trim(value);
    EXPECT_STREQ(expectVal, value.c_str());
}
