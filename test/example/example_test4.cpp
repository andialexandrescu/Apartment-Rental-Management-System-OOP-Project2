#include <gtest/gtest.h>
#include "SearchEngine.h"
#include "Apartment.h"

TEST(SuiteName, ConvertDate_VerifyBooking) {
    Apartment Ap;
    int year = 2024, start_date, end_date;
    int start_date_result = 262, end_date_result = 269;
    int start_month = 9, start_day = 18, end_month = 9, end_day = 25;
    SearchEngine::convertDate(year, start_month, start_day, start_date);
    SearchEngine::convertDate(year, end_month, end_day, end_date);
    if(!Ap.isBooked(start_date, end_date))
    {
        for(int i = start_date; i < end_date; i++)
        {
            Ap.bookApartment(i);
        }
    }
    EXPECT_EQ(start_date, start_date_result);
    EXPECT_EQ(end_date, end_date_result);
    bool result = true;
    EXPECT_EQ(Ap.isBooked(263, 265), result);
}