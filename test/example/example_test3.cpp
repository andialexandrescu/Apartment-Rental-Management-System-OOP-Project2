#include <gtest/gtest.h>
#include "User.h"
#include "Apartment.h"

TEST(SuiteName, CaesarCipher_Encryption) {
    const char *user = "sweetmadeleine";
    User no1;
    no1.setUsername(user);
    // the username won't be trunciated since it's not from input; the offset is 9
    std::string result = "bfnncvjmnunrwn";
    std::string name_string(user);
    EXPECT_EQ(no1.getUsername(), name_string);
    EXPECT_EQ(Apartment::CaesarCipherEncryption(no1.getUsername(), 9), result);
}