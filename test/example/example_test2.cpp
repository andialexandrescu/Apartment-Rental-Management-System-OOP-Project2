#include <gtest/gtest.h>
#include "User.h"

TEST(SuiteName, CopyConstructor) {
    User user1;
    const char *name = "yours_celestina";
    User user2(name, "swimmingenthusiast", "celestina_genevra2005@yahoo.com", "Celestina", "Genevra", 28523452, "Puerta 189 Ramal Anita Deleon 3, Sanlucar de Barrameda, Bal 74244", "+3465234563782");
    user1 = user2;
    User user3("yours_andreea", "newt'hang","andreea@gmail.com", "Andreea", "Joost", 1312323, "Amsterdam, Netherlands", "+521635");
    std::string name_string(name);
    EXPECT_EQ(user1.getUsername(), name_string);
    EXPECT_EQ(user2.getUsername(), name_string);
    EXPECT_EQ(user1.getPassword(), user2.getPassword());
    EXPECT_EQ(user1.getEmail(), user2.getEmail());
    EXPECT_EQ(user1.getFirstName(), user2.getFirstName());
    EXPECT_EQ(user1.getLastName(), user2.getLastName());
    EXPECT_EQ(user1.getIDNumber(), user2.getIDNumber());
    EXPECT_EQ(user1.getIDResidence(), user2.getIDResidence());
    EXPECT_EQ(user1.getPhoneNumber(), user2.getPhoneNumber());
    EXPECT_EQ(user1 != user2, false);
    EXPECT_EQ(user3 < user1, true); // lexicographically
}