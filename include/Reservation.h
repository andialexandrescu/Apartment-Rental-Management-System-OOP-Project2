#ifndef OOP_RESERVATION_H
#define OOP_RESERVATION_H

#include <iostream>

class Reservation {
private:
    int card_number;
    std::string card_holder_name;
    int cvv;
public:
    // overloaded constructors
    Reservation();
    [[maybe_unused]] Reservation(int card_number, const std::string &card_holder_name, int cvv);

    // operators
    friend std::istream& operator>>(std::istream& in, Reservation &r);

    // getters
    [[nodiscard]] std::string getCardHolderName() const;
    [[nodiscard]] int getCardNumber() const;
    [[nodiscard]] int getCardCVV() const;
};

#endif //OOP_RESERVATION_H