#ifndef OOP_APARTMENT_H // if not defined
#define OOP_APARTMENT_H

#include <string>
#include <vector>

class Apartment{
private:
    std::string apartment_id;
    std::string location;
    std::string type;
    std::string short_description;
    int no_rooms;
    int no_guests;
    int price_per_individual;
    std::vector<int> reservation_status; // a vector of tuples to track the days on which a certain apartment is already booked
public:
    // overloaded constructors
    Apartment();
    Apartment(std::string apartment_id, std::string location, std::string type, std::string description, int no_rooms, int no_guests, int price_per_individual);// constructor definit explicit
    ~Apartment(); // destructor

    // operators
    friend std::ostream& operator<<(std::ostream& out, const Apartment &obj);
    friend std::istream& operator>>(std::istream& in, Apartment &obj);
    bool operator==(const Apartment& other_apt) const;

    // getters
    [[nodiscard]] std::string getApartmentID() const;
    [[nodiscard]] int getPrice_perIndividual() const;
    [[nodiscard]] int getNoRooms() const;

    // other methods

    // 1) these two functions are working together (can be considered as one functionality)
    static std::string CaesarCipherEncryption(const std::string &host_user, int offset);
    static void generateApartmentID(Apartment &obj); // one day i might to have to rewrite this, so that the list of parameters contains User &host_user as well

    // 2) these three functions also work together (another functionality)
    [[nodiscard]] bool searchCriteriaLocation(const Apartment &obj, const std::string& city, const std::string& country) const;
    static bool searchCriteriaRooms(const Apartment &obj, int rooms, int guests, const int &choice) ;
    [[nodiscard]] static bool searchCriteriaPrice(const Apartment &obj, int p) ;

    // 3) these two work together
    void bookApartment(int day_in_the_year);
    bool isBooked(int start_date, int end_date);
};

#endif //OOP_APARTMENT_H end if not defined