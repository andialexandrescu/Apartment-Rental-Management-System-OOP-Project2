#include <gtest/gtest.h>
#include "SearchEngine.h"
#include "Apartment.h"

TEST(SuiteName, Search_Criteria) {
    Apartment Ap1("gsdAAS", "Jezierze, Poland", "Houseboat", "The Moors, or a cottage on the water, is a unique place where you can relax and connect with nature in a special way.", 1, 3, 75);
    Apartment Ap2("adsFAD", "Warsaw, Poland", "Rental Unit", "This apartment can be found in the modern city center, near Grzybowski Square and Saski Garden. A supermarket is located in the same building, and the Hala Mirowska food market is nearby, along with restaurants, cafes, and 2 modern art galleries.", 4, 5, 210);
    Apartment Ap3("fdjhg9", "Rabka-Zdroj, Poland", "Cottage", "Comfortable year-round cottages, located on a hill with a beautiful view of the forest. The perfect place to relax away from the hustle and bustle.", 3, 4, 125);
    SearchEngine query;
    std::string city = "-", country = "Poland";
    int rooms = 4, guests = 4, choice = 2, p = 230;
    int counter = 0;
    query += Ap1; query += Ap2; query += Ap3;
    for(const Apartment& apt : query.getApts())
    {
        if(apt.searchCriteriaLocation(apt, city, country) && Apartment::searchCriteriaRooms(apt, rooms, guests, choice) && Apartment::searchCriteriaPrice(apt, p))
        {
            counter++;
        }
    }
    int result = 2;
    EXPECT_EQ(counter, result);
}