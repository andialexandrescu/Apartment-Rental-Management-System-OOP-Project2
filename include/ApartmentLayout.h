#ifndef OOP_APARTMENTLAYOUT_H
#define OOP_APARTMENTLAYOUT_H

#include "Apartment.h"
#include "Layout.h"
#include "RoomLayout.h"
#include <iostream>
#include <vector>
#include <memory>

class RoomLayout;
class ApartmentLayout : public Layout{
private:
    static int no_living_rooms, no_bedrooms, no_bathrooms, no_kitchens;
    std::vector<std::shared_ptr<const Layout>> l_rooms;
    int max_rows; // the host will be prompted to enter the number of rows that fit in the apartment layout
    int max_columns; // the same goes for columns
    std::vector<std::vector<std::string> > m_layout; // a 2d vector of elements (a list of lists) which are strings that will represent the room's names
public:
    // constructors
    ApartmentLayout();
    //ApartmentLayout(float length, float width, int max_rows, int max_columns); //std::string room_type, std::string name, int bed_capacity, int max_rows, int max_columns);
    [[maybe_unused]] ApartmentLayout(int max_rows, int max_columns);

    [[maybe_unused]] [[maybe_unused]] ApartmentLayout(const ApartmentLayout &other_obj);
    ApartmentLayout& operator=(const ApartmentLayout &other_obj);
    // when destructing an ApartmentLayout instance, it will use the Layout destructor
    ~ApartmentLayout() override;

    [[nodiscard]] std::vector<std::shared_ptr<const Layout>> getRooms() const;
    void addRoom(const std::shared_ptr<const Layout>& obj);

    // static functions
    static void incrementStaticVariable(RoomLayout *ptr_room);
    static void resetStaticVariables();
    static int getNoLivingRooms();
    static int getNoBedrooms();
    static int getNoBathrooms();
    static int getNoKitchens();

    void read(std::istream& in) override;
    void display(std::ostream &out) const override;

    [[nodiscard]] float computeArea() const override;
    void drawFloorPlan();
};

#endif //OOP_APARTMENTLAYOUT_H