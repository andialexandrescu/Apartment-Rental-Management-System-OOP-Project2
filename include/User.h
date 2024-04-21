#ifndef OOP_USER_H
#define OOP_USER_H

#include <string>
#include <cstring>
#include <vector>

class User{
private:
    char *username; // academic example since otherwise the destructor would've been useless
    // usage: regardless of how many characters are from input, the username will only contain the first 10
    std::string password;
    std::string email;
    std::string first_name;
    std::string last_name;
    long long id_number;
    std::string id_residence;
    std::string phone_number;
public:
    // overloaded constructors
    User(); // no parameters init constructor
    User(const char *client, std::string pswd, std::string contact_email, std::string fname, std::string lname, long long id, std::string residence, std::string phone);
    User(const User &other_obj); // copy constructor
    ~User();// destructor

    // operators
    User& operator=(const User &obj); // operator=
    bool operator!=(const User &other) const; // operator overloading as member functions
    friend std::ostream& operator<<(std::ostream& out, const User &obj); // operator<<
    friend std::istream& operator>>(std::istream& in, User &obj); // operator>>
    bool operator<(const User& obj);// operator overloading as non-member function

    // getters
    [[nodiscard]] char *getUsername() const;
    [[nodiscard]] std::string getPassword() const;
    [[nodiscard]] std::string getEmail() const;
    [[nodiscard]] std::string getFirstName() const;
    [[nodiscard]] std::string getLastName() const;
    [[nodiscard]] long long getIDNumber() const;
    [[nodiscard]] std::string getIDResidence() const;
    [[nodiscard]] std::string getPhoneNumber() const;

    // setters
    void setUsername(const char *client);

    // other methods
    static void loginMenu(const User &user, bool &credentials);
    static void generateStrongPassword(User &user);
    static bool validatingChosenPassword(const std::string &pswd);
    static bool validatingIDNumber(std::string &id_no);
};

#endif //OOP_USER_H