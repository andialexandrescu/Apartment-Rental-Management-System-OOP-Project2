#include "Apartment.h"
#include <iostream>
#include <utility>
//#include <limits>

Apartment::Apartment(): apartment_id("Undefined"), location("Undefined"), type("Undefined"), short_description("None"), no_rooms(0), no_guests(0), price_per_individual(0) {
    reservation_status.clear();
}

//variant_1: initialization list - better performance, less code
//Apartment::Apartment(std::string apt_id, std::string l, std::string t, std::string desc, int k_rooms, int p): apartment_id(apt_id), location(l), type(t), short_description(desc), no_rooms(k_rooms), price_per_night(p) {}
//variant_2: using pointers
Apartment::Apartment(std::string apartment_id, std::string location, std::string type, std::string short_description, int no_rooms, int no_guests, int price_per_individual)
{
    this->apartment_id = std::move(apartment_id);
    this->location = std::move(location);
    this->type = std::move(type);
    this->short_description = std::move(short_description);
    this->no_rooms = no_rooms;
    this->no_guests = no_guests;
    this->price_per_individual = price_per_individual;
}

Apartment::~Apartment() {
    if(!this->reservation_status.empty())
    {
        this->reservation_status.clear();
    }
}

std::ostream &operator<<(std::ostream &out, const Apartment &obj) {
    out<<std::endl<<"Apartment ID: #"<<obj.apartment_id<<std::endl;
    out<<"Location: "<<obj.location<<std::endl;
    out<<"Type of apartment: "<<obj.type<<std::endl;
    out<<"Short Description: "<<obj.short_description<<std::endl;
    out<<"Number of rooms: "<<obj.no_rooms<<std::endl;
    out<<"Number of guests: "<<obj.no_guests<<std::endl;
    out<<"Price/ individual: "<<obj.price_per_individual;
    return out;
}

std::istream &operator>>(std::istream &in, Apartment &obj) { // only the host/ admin can add apartments
    Apartment::generateApartmentID(obj);
    std::cout<<"Apartment ID: "<<obj.apartment_id<<std::endl;
    std::cout<<"Location: ";
    /// std::ws discards leading whitespace from an input stream
    std::getline(in >> std::ws, obj.location); // in>>obj.location; in.clear(); in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout<<"Type of apartment: ";
    std::getline(in >> std::ws, obj.type); // in>>obj.type; in.clear(); in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout<<"Short Description: ";
    std::getline(in >> std::ws, obj.short_description);// in>>obj.short_description; in.clear(); in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout<<"Number of rooms: ";
    in>>obj.no_rooms;
    std::cout<<"Number of guests: ";
    in>>obj.no_guests;
    std::cout<<"Price/ individual: ";
    in>>obj.price_per_individual;
    return in;
}

bool Apartment::operator==(const Apartment &other_apt) const {
    return (this->apartment_id == other_apt.apartment_id &&
            this->location == other_apt.location &&
            this->type == other_apt.type &&
            this->short_description == other_apt.short_description &&
            this->no_rooms == other_apt.no_rooms &&
            this->no_guests == other_apt.no_guests &&
            this->price_per_individual == other_apt.price_per_individual);
}

std::string Apartment::getApartmentID() const {
    return apartment_id;
}

int Apartment::getPrice_perIndividual() const {
    return price_per_individual;
}

int Apartment::getNoRooms() const {
    return no_rooms;
}

std::string Apartment::CaesarCipherEncryption(const std::string &host_user, int offset) { // more of a helper function, in usual circumstances it should've been part of generateApartmentID()
    std::string encrypted_username;
    for(unsigned long long i = 0; i < host_user.length(); i++)
    {
        if(isupper(host_user[i]))
        {
            encrypted_username += char(int(host_user[i]+offset-65)%26+65);
        } else encrypted_username += char(int(host_user[i]+offset-97)%26+97);
    }
    return encrypted_username;
}

void Apartment::generateApartmentID(Apartment &obj) {
    std::string host_user;
    int offset;
    std::cout<<std::endl<<std::endl<<"Apartment ID will be generated based on your username, the encryption is using an offset you have to choose. In case you have multiple apartments to list, make sure to use a different offset each time, otherwise data might be lost. "<<std::endl;
    std::cout<<"Re-enter username: ";
    std::cin>>host_user;
    std::cout<<"Choose offset (short integer): ";
    std::cin>>offset;
    obj.apartment_id = CaesarCipherEncryption(host_user, offset);
}

bool Apartment::searchCriteriaLocation(const Apartment &obj, const std::string& city, const std::string& country) const {
    std::string aux_city, aux_country;
    unsigned long long comma_pos = obj.location.find(','); // <City, Country>
    aux_city = obj.location.substr(0, comma_pos);
    aux_country = obj.location.substr(comma_pos+2, location.length()-1);
    return (aux_city == city || aux_country == country);
}

bool Apartment::searchCriteriaRooms(const Apartment &obj, int rooms, int guests, const int &choice) {
    switch(choice)
    {
        case 1:
            return (obj.no_rooms == rooms);
        case 2:
            return (obj.no_rooms == rooms || obj.no_guests >= guests);
        default:
            return false;
    }
}

bool Apartment::searchCriteriaPrice(const Apartment &obj, int p) {
    return obj.price_per_individual <= p;
}

void Apartment::bookApartment(int day_in_the_year) {
    reservation_status.push_back(day_in_the_year);
}

bool Apartment::isBooked(int start_date, int end_date) {
    for(const auto r: reservation_status)  // NOLINT(*-use-anyofallof)
    {
        if (r >= start_date && r <= end_date)
        {
            return true;
        }
    }
    return false;
}