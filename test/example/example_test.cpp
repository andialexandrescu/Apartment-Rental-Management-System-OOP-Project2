#include <gtest/gtest.h>
#include "User.h"

TEST(SuiteName, Constructor_andGetters) {
    const char *name = "louisarletta9";
    std::string pswd = "blu3skies";
    User user(name, pswd, "louis.arletta@gmail.com", "Louis", "Arletta", 234513427, "Puerta 728 Salida Andres Sisneros, 65, Malaga, Bal 26010", "+340223419028");
    // https://testingbot.com/free-online-tools/random-address-generator
    std::string name_string(name); // converting to string
    EXPECT_EQ(user.getUsername(), name_string);
    EXPECT_EQ(user.getPassword(), pswd);
    // Other assertions: https://google.github.io/googletest/reference/assertions.html#boolean
}