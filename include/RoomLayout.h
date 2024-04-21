#ifndef OOP_ROOMLAYOUT_H
#define OOP_ROOMLAYOUT_H

#include "Layout.h"
#include "ApartmentLayout.h"
#include <iostream>
#include <string>
#include <vector>

class ApartmentLayout;
class RoomLayout : public Layout{
private:
    std::string room_type;
    std::string name;
    int bed_capacity; // the so-called living-space rooms have sleeping places (kitchens, bathrooms won't be taken into consideration)
    std::vector<std::string> l_amenities; // a list available amenities, amenities are specific for a room_type
public:
    // constructors
    RoomLayout();
    // rule i've decided upon: a RoomLayout instance will be explicitly constructed without its amenities vector, meaning that these amenities will be added only by using the addAmenities() method; decided that the copy constructor will copy the list of amenities from the other_obj instance
    RoomLayout(float length, float width, std::string room_type, std::string name, int bed_capacity);

    [[maybe_unused]] RoomLayout(const RoomLayout &other_obj);
    RoomLayout& operator=(const RoomLayout &other_obj);
    ~RoomLayout() override;

    // getters and setters
    void setDimensions(float dim1, float dim2);
    void setAmenity(const std::string &amenity);
    [[nodiscard]] const std::string &getName() const;
    [[nodiscard]] const std::string &getRoomType() const;

    // there's no need to declare virtual functions for getRooms() and addRoom(), which are methods specific to ApartmentLayout, because when reading a room and assigning an unique name, in order to ensure it won't be overwritten, we must use the addRoom() method from ApartmentLayout by downcasting (virtual is for upcasting)
    void read(std::istream& in) override; // !!! the overridden function's header must match
    void display(std::ostream& out) const override;

    void addAmenities();
    void createRoom(ApartmentLayout *apt_layout);
    static void processRoom(RoomLayout *obj, ApartmentLayout *apt_layout); // static function
    static void generateRoomName(RoomLayout *obj);
    //static void processMultipleRooms(RoomLayout *obj, ApartmentLayout *apt_layout);
};

#endif //OOP_ROOMLAYOUT_H