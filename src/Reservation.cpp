#include "Reservation.h"
#include <iostream>
#include <limits>
#include <string>

Reservation::Reservation(): card_number(0), card_holder_name("None"), cvv(0) {}

[[maybe_unused]] Reservation::Reservation(int card_number, const std::string &card_holder_name, int cvv) {
    this->card_number = card_number;
    this->card_holder_name = card_holder_name;
    this->cvv = cvv;
}

std::istream &operator>>(std::istream &in, Reservation &r) {
    std::cout<<"Card Number: ";
    in>>r.card_number; in.clear(); in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout<<"Card Holder Name: ";
    std::getline(in >> std::ws, r.card_holder_name);
    std::cout<<"Card CVV: "; in.clear();
    in>>r.cvv;
    return in;
}

std::string Reservation::getCardHolderName() const {
    return card_holder_name;
}

int Reservation::getCardNumber() const {
    return card_number;
}

int Reservation::getCardCVV() const {
    return cvv;
}