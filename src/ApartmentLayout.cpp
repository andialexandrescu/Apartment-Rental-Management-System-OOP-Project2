#include "ApartmentLayout.h"
#include <iomanip>

int ApartmentLayout::no_living_rooms = 0, ApartmentLayout::no_bedrooms = 0, ApartmentLayout::no_bathrooms = 0, ApartmentLayout::no_kitchens = 0;

ApartmentLayout::ApartmentLayout(): Layout(), max_rows(0), max_columns(0) {
    if(!l_rooms.empty())
    {
        l_rooms.clear();
    }
    if(!m_layout.empty())
    {
        m_layout.clear();
    }
}

[[maybe_unused]] ApartmentLayout::ApartmentLayout(int max_rows, int max_columns): Layout(), max_rows(max_rows), max_columns(max_columns) { // built-up area for an apartment layout is represented in square meters, there's no need to specify two dimensions, besides the ones for the matrix
    m_layout.resize(max_rows, std::vector<std::string>(max_columns, ""));
}

[[maybe_unused]] ApartmentLayout::ApartmentLayout(const ApartmentLayout &other_obj): Layout(other_obj), max_rows(other_obj.max_rows), max_columns(other_obj.max_columns) {
    for(const auto& room : other_obj.l_rooms)
    {
        l_rooms.push_back(room);
    }
    m_layout.resize(max_rows, std::vector<std::string>(max_columns, ""));
    for(const auto& row: other_obj.m_layout)
    {
        m_layout.push_back(row);
    }
}

ApartmentLayout &ApartmentLayout::operator=(const ApartmentLayout &other_obj) {
    if(this != &other_obj)
    {
        Layout::operator=(other_obj);
        this->max_columns = other_obj.max_columns;
        this->max_rows = other_obj.max_rows;
        this->l_rooms.clear();
        for(const auto& room : other_obj.l_rooms)
        {
            this->l_rooms.push_back(room);
        }
        this->m_layout.clear();
        m_layout.resize(max_rows, std::vector<std::string>(max_columns, ""));
        for(const auto& row : other_obj.m_layout)
        {
            this->m_layout.push_back(row);
        }
    }
    return *this;
}

ApartmentLayout::~ApartmentLayout() {
    if(!this->l_rooms.empty())
    {
        this->l_rooms.clear();
    }
    if(!this->m_layout.empty())
    {
        this->m_layout.clear();
    }
}

std::vector<std::shared_ptr<const Layout>> ApartmentLayout::getRooms() const{
    return l_rooms;
}

void ApartmentLayout::addRoom(const std::shared_ptr<const Layout> &obj) {
    l_rooms.push_back(obj);
}

void ApartmentLayout::display(std::ostream &out) const {
    out<<std::endl<<"The apartment consists of these rooms:"<<std::endl;
    for(const auto& item : this->getRooms())
    {
        auto ptr_room = std::dynamic_pointer_cast<RoomLayout>(std::const_pointer_cast<Layout>(item));
        if(ptr_room)
        {
            out<<*ptr_room<<std::endl;
        }
    }
    //out<<std::endl<<"The apartment's layout has a total of "<<this->computeArea()<<" square meters of usable surface area"<<std::endl;
    /// shouldn't forget about l_in_unit_amenities once i implement some logic
}

void ApartmentLayout::read(std::istream &in) {
    std::cout<<"In order to create the apartment layout plan, you will be prompted to enter the number of rooms that fit in the specified apartment layout."<<std::endl;
    std::cout<<"The apartment canvas is structured as a grid of pairs (i, j), representing a cell and the exact coordinates of a room's position."<<std::endl;
    std::cout<<"Enter the maximum number of rooms part of the apartment's width: ";
    in>>this->max_columns;
    std::cout<<"Enter the maximum number of rooms part of the apartment's length: ";
    in>>this->max_rows;
    m_layout.resize(max_rows, std::vector<std::string>(max_columns, ""));
    std::cout<<"This is the apartment layout before entering the room's positions based on (i, j) pairs of coordinates: "<<std::endl;
    for(int i = 0; i < max_rows; i++)
    {
        for(int j = 0; j < max_columns; j++)
        {
            std::cout<<"+-----";
        }
        std::cout<<"+"<<std::endl;
        for (int j = 0; j < max_columns; j++)
        {
            std::cout<<"|("<<i<<","<<j<<")";
        }
        std::cout<<"|"<<std::endl;
    }
    for (int j = 0; j < max_columns; j++)
    {
        std::cout<<"+-----";
    }
    std::cout<<"+"<<std::endl;
}

void ApartmentLayout::drawFloorPlan() { // acts as an engine as well, since the user is being prompted to enter floor plan details
    for(const auto &item : l_rooms)
    {
        try
        {
            /*RoomLayout *ptr_room;
            ptr_room = dynamic_cast<RoomLayout *>(item);*/
            auto ptr_room = std::dynamic_pointer_cast<RoomLayout>(std::const_pointer_cast<Layout>(item));
            if(ptr_room)
            {
                int i, j;
                std::cout<<std::endl<<"Enter the coordinates for "<<ptr_room->getName()<<":"<<std::endl;
                std::cout<<"\ti: ";
                std::cin>>i;
                std::cout<<std::endl<<"\tj: ";
                std::cin>>j;
                m_layout[i][j] = ptr_room->getName();
            } else
            {
                std::cout<<"Item "<<*item<<" is pointing at an instance of abstract class Item"<<std::endl;
                throw std::runtime_error("Failed to cast item to RoomLayout*");
            }
            /* OR
            if(dynamic_cast<RoomLayout *>(item))
            {
                m_layout[i][j] = dynamic_cast<RoomLayout *>(item)->getName();
            } */
        } catch(const std::runtime_error &)
        {
            std::cout<<"The apartment layout did not add the abstract class instance to the floor plan"<<std::endl;
        }
    }
    std::cout<<"Here is the final apartment layout created:"<<std::endl;
    for (int i = 0; i < max_rows; i++)
    {
        for (int j = 0; j < max_columns; j++)
        {
            std::cout << "+-------------";
        }
        std::cout << "+" << std::endl;
        for (int j = 0; j < max_columns; j++)
        {
            if(!m_layout[i][j].empty())
            {
                std::cout<<"|"<<std::setw(13)<<std::left<<m_layout[i][j];
            } else
            {
                std::cout<<"|             ";
            }
        }
        std::cout<<"|"<<std::endl;
    }
    for (int j = 0; j < max_columns; j++)
    {
        std::cout<<"+-------------";
    }
    std::cout<<"+"<<std::endl;
}

void ApartmentLayout::incrementStaticVariable(RoomLayout *ptr_room) {
    if(ptr_room->getRoomType() == "bedroom")
    {
        no_bedrooms++;
    } else if(ptr_room->getRoomType() == "living room")
    {
        no_living_rooms++;
    } else if(ptr_room->getRoomType() == "bathroom")
    {
        no_bathrooms++;
    } else if(ptr_room->getRoomType() == "kitchen")
    {
        no_kitchens++;
    }
}

int ApartmentLayout::getNoLivingRooms() {
    return no_living_rooms;
}

int ApartmentLayout::getNoBedrooms() {
    return no_bedrooms;
}

int ApartmentLayout::getNoKitchens() {
    return no_kitchens;
}

int ApartmentLayout::getNoBathrooms() {
    return no_bathrooms;
}

float ApartmentLayout::computeArea() const {
    float total_size = 0;
    for(const auto &item : l_rooms)
    {
        /*RoomLayout *ptr_room;
        ptr_room = dynamic_cast<RoomLayout*>(item);*/
        auto ptr_room = std::dynamic_pointer_cast<RoomLayout>(std::const_pointer_cast<Layout>(item));
        if(ptr_room)
        {
            total_size += ptr_room->computeArea();
        }
    }
    return total_size;
}

void ApartmentLayout::resetStaticVariables() {
    ApartmentLayout::no_living_rooms = 0;
    ApartmentLayout::no_bedrooms = 0;
    ApartmentLayout::no_bathrooms = 0;
    ApartmentLayout::no_kitchens = 0;
}