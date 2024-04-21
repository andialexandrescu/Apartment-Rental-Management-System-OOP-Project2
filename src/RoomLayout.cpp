#include "RoomLayout.h"
#include <algorithm>

RoomLayout::RoomLayout(): Layout(), bed_capacity(0){
    if(!l_amenities.empty())
    {
        l_amenities.clear();
    }
}

RoomLayout::RoomLayout(float length, float width, std::string room_type, std::string name, int bed_capacity) : Layout(length, width), room_type(std::move(room_type)), name(std::move(name)), bed_capacity(bed_capacity) {}

[[maybe_unused]] RoomLayout::RoomLayout(const RoomLayout &other_obj): Layout(other_obj), room_type(other_obj.room_type), name(other_obj.name), bed_capacity(other_obj.bed_capacity) {
    // !!! deep copy instead of a shallow one
    for(const auto& t : other_obj.l_amenities)
    {
        l_amenities.push_back(t);
    }
}

RoomLayout &RoomLayout::operator=(const RoomLayout &other_obj) {
    if(this != &other_obj)
    {
        Layout::operator=(other_obj);
        this->room_type = other_obj.room_type;
        this->name = other_obj.name;
        this->bed_capacity = other_obj.bed_capacity;
        this->l_amenities.clear(); // clearing existing list of amenities
        for(const auto& t : other_obj.l_amenities)
        {
            this->l_amenities.push_back(t);
        }
    }
    return *this;
}

RoomLayout::~RoomLayout() {
    if(!this->l_amenities.empty())
    {
        this->l_amenities.clear();
    }
}

void RoomLayout::setDimensions(float dim1, float dim2) {
    if(dim1 < dim2)
    {
        this->setLength(dim2);
        this->setWidth(dim1);
    } else
    {
        this->setLength(dim1);
        this->setWidth(dim2);
    }
}

void RoomLayout::setAmenity(const std::string &amenity) {
    l_amenities.push_back(amenity); // the list will only contain those amenities which are included in different rooms categorized by room_type
}

const std::string &RoomLayout::getName() const {
    return name;
}

const std::string &RoomLayout::getRoomType() const {
    return room_type;
}

void RoomLayout::read(std::istream &in) {
    float dim1, dim2;
    std::cout<<"You will be prompted to enter the room's exact dimensions"<<std::endl;
    std::cout<<"Enter both dimensions: "<<std::endl;
    std::cout<<"\tDimension 1:";
    in>>dim1;
    std::cout<<std::endl<<"\tDimension 2:";
    in>>dim2;
    setDimensions(dim1, dim2);
    if(this->room_type == "living room" || this->room_type == "bedroom")
    {
        std::cout<<"Enter the sleeping capacity: ";
        int capacity;
        in>>capacity;
        this->bed_capacity = capacity; // no need to declare a setter function for bed_capacity since this is the only place in which it is needed
    }
}

void RoomLayout::display(std::ostream &out) const {
    out<<std::endl<<this->name<<"'s details are:"<<std::endl;
    out<<"\tRoom type: "<<this->room_type<<std::endl;
    out<<"\tBed capacity: "<<this->bed_capacity<<std::endl;
    out<<"\tList of amenities: ";
    for (const auto& t : this->l_amenities)
    {
        out<<t<<" ";
    }
    out<<std::endl;
    this->description(out); // no need to specify scope resolution since the subclass will also have the superclass' methods (not overridden in this case)
}

void RoomLayout::createRoom(ApartmentLayout *apt_layout) { // must have as the parameter a pointer to an ApartmentLayout instance since it must be added to l_rooms of a specific apartment NOLINT(*-no-recursion)
    std::string user_input;
    std::vector<std::string> l_types = {"bedroom", "living room", "kitchen", "bathroom"};
    try{
        std::cout<<"Enter room type: ";
        std::getline(std::cin>>std::ws, user_input);
        auto position = std::find(l_types.begin(), l_types.end(), user_input);
        if(position == l_types.end()) // the input hasn't been found in l_types, meaning it's invalid
        {
            throw std::runtime_error("Invalid room type entered");
        }
        // this will be executed only if the exception hasn't been thrown yet
        this->room_type = user_input; // set the room_type if it's valid
    } catch(const std::runtime_error &)
    {
        std::cout<<"You will be prompted to enter the room details again"<<std::endl;
        return createRoom(apt_layout);
    }
    std::cin>>*this;
    processRoom(this, apt_layout); // deals with attributing the room_type string to the actual name since it's only one room of that type in the apartment
    addAmenities();
}

void RoomLayout::processRoom(RoomLayout *obj, ApartmentLayout *apt_layout) {
    bool room_exists = false;
    // iterating through every l_rooms item and checking whether a room with its unique name initialized to a room_type exists already or not
    for(const auto &item: apt_layout->getRooms()) // dereferencing apt_layout in order to be able to access the l_rooms vector
    {
        try{
            /*RoomLayout *ptr_room;
            ptr_room = dynamic_cast<RoomLayout *>(item); // if the type casting doesn't fail, it is indeed a reference to a RoomLayout instance*/
            auto ptr_room = std::dynamic_pointer_cast<RoomLayout>(std::const_pointer_cast<Layout>(item));
            if(ptr_room && ptr_room->name == obj->room_type)
            {
                room_exists = true;
                break;
            }
            /* OR
            if(dynamic_cast<RoomLayout *>(item) && dynamic_cast<RoomLayout *>(item)->name != obj->room_type) {} */
        } catch(const std::bad_cast &)
        {
            std::cout<<"Dynamic cast failed";
        }
    }
    if(!room_exists)
    {
        ApartmentLayout::incrementStaticVariable(obj);
        generateRoomName(obj);
        // apt_layout->addRoom(obj);
        // resetting shared pointer with raw pointer
        std::shared_ptr<const Layout> shared_obj(obj);
        apt_layout->addRoom(shared_obj);
    }
}

void RoomLayout::generateRoomName(RoomLayout *obj) {
    if(obj->room_type == "bedroom")
    {
        obj->name = obj->room_type + " " + std::to_string(ApartmentLayout::getNoBedrooms());
    } else if(obj->room_type == "living room")
    {
        obj->name = obj->room_type + " " + std::to_string(ApartmentLayout::getNoLivingRooms());
    } else if(obj->room_type == "bathroom")
    {
        obj->name = obj->room_type + " " + std::to_string(ApartmentLayout::getNoBathrooms());
    } else if(obj->room_type == "kitchen")
    {
        obj->name = obj->room_type + " " + std::to_string(ApartmentLayout::getNoKitchens());
    }
}

void RoomLayout::addAmenities() {
    std::vector<std::string> living_space_amenities = {"air_conditioning", "heating", "tv", "bed_sheets"};
    std::vector<std::string> kitchen_amenities = {"refrigerator", "stove", "oven", "dishwasher", "microwave", "coffee_maker", "carbon_monoxide_alarm"};
    std::vector<std::string> bathroom_amenities = {"washer", "towels", "hygiene_products", "hair_dryer", "ventilation", "bathtub", "shower"};
    std::cout<<std::endl;
    if(this->room_type == "bedroom" || this->room_type == "living room")
    {
        for(const auto &amenity : living_space_amenities)
        {
            if(amenity[amenity.size()-1] != 's')
            {
                std::cout<<"Is "<<amenity<<" available? Enter y/n: ";
            } else // the plural of variable amenity should follow grammar norms
            {
                std::cout<<"Are "<<amenity<<" available? Enter y/n: ";
            }
            std::string choice;
            std::cin>>choice;
            if(choice == "y")
            {
                this->setAmenity(amenity);
            }
        }
    } else if(this->room_type == "kitchen")
    {
        for(const auto &amenity : kitchen_amenities)
        {
            std::cout<<"Is "<<amenity<<" available? Enter y/n: ";
            std::string choice;
            std::cin>>choice;
            if(choice == "y")
            {
                this->setAmenity(amenity);
            }
        }
    } else if(this->room_type == "bathroom")
    {
        for(const auto &amenity : bathroom_amenities)
        {
            if(amenity[amenity.size()-1] != 's')
            {
                std::cout<<"Is "<<amenity<<" available? Enter y/n: ";
            } else
            {
                std::cout<<"Are "<<amenity<<" available? Enter y/n: ";
            }
            std::string choice;
            std::cin>>choice;
            if(choice == "y")
            {
                this->setAmenity(amenity);
            }
        }
    }
}