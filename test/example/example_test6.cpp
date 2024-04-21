#include <gtest/gtest.h>
#include "Reservation.h"
#include "SearchEngine.h"
#include "Apartment.h"

TEST(SuiteName, User_Reservation_Connection) { // one of the few times reservation is actually used for it's purpose instead of serving as a searching menu
    Apartment Ap1("sajgsd", "Lefkada, Greece", "Villa", "On the west coast of Lefkada, there are unlimited spectacles offered by all indoor and outdoor spaces, showcasing the sea and sunset on the horizon.", 2, 3, 145);
    int number = 123567123, cvv = 552; std::string name = "Joseph Gordon-Levitt";
    Reservation r(number, name, cvv);
    SearchEngine query;
    query += Ap1;
    std::vector<Apartment> vec_apts;
    vec_apts.push_back(Ap1);
    EXPECT_EQ(query.getApts(), vec_apts);
    EXPECT_EQ(r.getCardNumber(), number);
    EXPECT_EQ(r.getCardHolderName(), name);
    EXPECT_EQ(r.getCardCVV(), cvv);
}