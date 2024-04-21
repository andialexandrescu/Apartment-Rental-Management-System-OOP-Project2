#ifndef OOP_SEARCHENGINE_H
#define OOP_SEARCHENGINE_H

#include "Apartment.h"

class SearchEngine { // reservation also acts as a submenu for choosing an apartment
private:
    std::vector<Apartment> l_apts;
public:
    // overloaded constructors
    SearchEngine();
    ~SearchEngine();

    // operators
    SearchEngine& operator+=(const Apartment &apt); // operator overloading as member functions
    friend std::ostream& operator<<(std::ostream& out, const SearchEngine &r);// operator overloading as friend/ non-member functions

    // getters
    [[nodiscard]] std::vector<Apartment> getApts() const;

    // other methods
    static void searchResults(const SearchEngine &menu);
    static void convertDate(int year, int month, int day, int &date);
    void proceedTransaction(const SearchEngine &menu, bool &booked);
    static void computeTransaction(const Apartment &apt, int start_date, int end_date);
};

#endif //OOP_SEARCHENGINE_H