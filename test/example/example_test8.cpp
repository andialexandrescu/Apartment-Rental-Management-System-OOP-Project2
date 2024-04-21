#include <gtest/gtest.h>
#include <vector>
#include "RoomLayout.h"
#include "ApartmentLayout.h"

TEST(SuiteName, Rooms) {
    ApartmentLayout ptr_layout;

    auto room1 = std::make_shared<RoomLayout>(3.4, 6.1, "living room", "living room 1", 3);
    auto room2 = std::make_shared<RoomLayout>(4.2, 5, "bedroom", "bedroom 1", 4);
    auto room3 = std::make_shared<RoomLayout>(3, 4.6, "bedroom", "bedroom 2", 3);
    auto room4 = std::make_shared<RoomLayout>(2.3, 3.5, "bathroom", "bathroom 1", 0);
    auto room5 = std::make_shared<RoomLayout>(3.6, 5, "kitchen", "kitchen 1", 0);

    ptr_layout.addRoom(room1);
    ptr_layout.addRoom(room2);
    ptr_layout.addRoom(room3);
    ptr_layout.addRoom(room4);
    ptr_layout.addRoom(room5);

    // downcasting
    std::shared_ptr<Layout> l_room1 = room1;
    std::shared_ptr<Layout> l_room2 = room2;
    std::shared_ptr<Layout> l_room3 = room3;
    std::shared_ptr<Layout> l_room4 = room4;
    std::shared_ptr<Layout> l_room5 = room5;
    std::vector<std::shared_ptr<Layout>> vec_rooms = {l_room1, l_room2, l_room3, l_room4, l_room5};

    EXPECT_EQ(ptr_layout.getRooms().size(), vec_rooms.size());
    for (unsigned long long i = 0; i < vec_rooms.size(); ++i)
    {
        EXPECT_EQ(*ptr_layout.getRooms()[i], *vec_rooms[i]);
    }
    float expected_area = 81.59;
    EXPECT_EQ(ptr_layout.computeArea(), expected_area);
}