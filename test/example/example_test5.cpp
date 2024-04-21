#include <gtest/gtest.h>
#include "SearchEngine.h"
#include "Apartment.h"

TEST(SuiteName, OperatorOverloading) {
    Apartment Ap1("sajgsd", "Lefkada, Greece", "Villa", "On the west coast of Lefkada, there are unlimited spectacles offered by all indoor and outdoor spaces, showcasing the sea and sunset on the horizon.", 2, 3, 145);
    Apartment Ap2("asfDSDG", "Ko Samui, Thailand", "Entire Condo", "Enjoy the panoramic sea and mountain views from the pool, terrace and lush garden. The villa is located on a small hilltop in Maenam village, a locals-only spot with a bustling night market and long sandy beach.", 5, 8, 120);
    Apartment Ap3("fsafAS", "Kas, Turkey", "Villa", "This rental holiday villa is located in Kördere area of Kalkan. It is a holiday villa with sea view and with unseen pool area. The city center is 3 km away.", 5, 12, 260);

    std::vector<Apartment> vec_apts = {Ap1, Ap2, Ap3};

    SearchEngine query;
    query += Ap1; query += Ap2; query += Ap3;
    EXPECT_EQ(query.getApts(), vec_apts);
}