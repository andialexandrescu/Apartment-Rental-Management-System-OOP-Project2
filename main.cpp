#include <iostream>
#include <thread>
#include <limits>
#include "Apartment.h"
#include "User.h"
#include "Reservation.h"
#include "SearchEngine.h"
#include "RoomLayout.h"
#include "ApartmentLayout.h"

int main() {
    // using setters to get rid of [unusedFunction] cppcheck error
    User test;
    test.setUsername("testing");

    Apartment Ap1("12rg3g0", "Benidorm, Spain", "Rental Unit", "Apartment Ideal to enjoy Playa de Benidorm, in the heart of Playa de Poniente. Views from the living room to the ocean and the Isle of Benidorm.", 4, 5, 136);
    Apartment Ap2("1wd27", "Santona, Spain", "Duplex", "Unique oceanfront location within a few meters from the beach. Very large terrace to enjoy.", 4, 6, 155);
    Apartment Ap3("323w", "Altea, Spain", "Villa", "Beautiful villa with a private pool and a hot tub in Altea’s prime location, on Don Cayo golf course and nestled away from highway noise. Ideal for big families or groups.", 4, 4, 120);
    Apartment Ap4("56sf7", "Florence, Italy", "Rental Unit", "Chez Geraldine is an apartment just outside the historical center. It’s predominantly a residential district, but the cathedral, Galleria dell'Accademia, and Piazza San Marco are a 15-minute walk away. Food stores, restaurants, and bars are close by.", 3, 5, 90);
    Apartment Ap5("9g65", "Dubrovnik, Croatia", "Rental Unit", "The apartment is perched on a small hill in Montovjerna, offering stunning views of the Adriatic Sea. Dubrovnik's Old Town is around a five-minute drive away, while the nearest beach, Bellevue, is around 300 metres away.", 4, 7, 180);
    Apartment Ap6("hdhsa", "Malaga, Spain", "Rental Unit", "Our vacation apartment with terrace and sea view is located on the beachfront, in the Huelin area. The seafront promenade and Plaza de Huelin are just 20 meters away.", 4, 7, 210);
    Apartment Ap7("dsaa53", "A Coruna, Spain", "Mansion", "La Casa de la Pradera is located in A Bana, A Coruna, Galicia. It is located 50 km from O Grove.", 4, 4, 115);
    Apartment Ap8("edas2sa", "Florence, Italy", "Entire Condo", "The apartment is located in a pedestrian area in the historic center of Florence, a stone's throw from the Duomo and Piazza della Signoria, and not far from the Ponte Vecchio and the Mercato di San Lorenzo.", 3, 4, 220);
    Apartment Ap9("adsw3aa", "Lecce, Italy", "Entire Suite", "Wooden Cabin situated just under 1 km away from Torre Rinalda and 9 km from Oaks.", 3, 4, 80);
    Apartment Ap10("sdgfas4", "Furore, Italy", "Duplex", "Romantic, quiet and sea view, this accommodation opens to the cozy area, consisting of a small living room with kitchenette from which you can access the panoramic terrace", 3, 4, 110);
    Apartment Ap11("sajgsd", "Lefkada, Greece", "Villa", "On the west coast of Lefkada, there are unlimited spectacles offered by all indoor and outdoor spaces, showcasing the sea and sunset on the horizon.", 2, 3, 145);
    Apartment Ap12("asfDSDG", "Ko Samui, Thailand", "Entire Condo", "Enjoy the panoramic sea and mountain views from the pool, terrace and lush garden. The villa is located on a small hilltop in Maenam village, a locals-only spot with a bustling night market and long sandy beach.", 5, 8, 120);
    Apartment Ap13("fsafAS", "Kas, Turkey", "Villa", "This rental holiday villa is located in Kördere area of Kalkan. It is a holiday villa with sea view and with unseen pool area. The city center is 3 km away.", 5, 12, 260);
    Apartment Ap14("sajgsd", "Lefkada, Greece", "Villa", "On the west coast of Lefkada, there are unlimited spectacles offered by all indoor and outdoor spaces, showcasing the sea and sunset on the horizon.", 2, 3, 145);
    Apartment Ap15("gsdAAS", "Jezierze, Poland", "Houseboat", "The Moors, or a cottage on the water, is a unique place where you can relax and connect with nature in a special way.", 1, 3, 75);
    Apartment Ap16("adsFAD", "Warsaw, Poland", "Rental Unit", "This apartment can be found in the modern city center, near Grzybowski Square and Saski Garden. A supermarket is located in the same building, and the Hala Mirowska food market is nearby, along with restaurants, cafes, and 2 modern art galleries.", 4, 5, 210);
    Apartment Ap17("fdjhg9", "Rabka-Zdroj, Poland", "Cottage", "Comfortable year-round cottages, located on a hill with a beautiful view of the forest. The perfect place to relax away from the hustle and bustle.", 3, 4, 125);

    SearchEngine query;
    query += Ap1; query += Ap2; query += Ap3; query += Ap4; query += Ap5; query += Ap6; query += Ap7; query += Ap8; query += Ap9; query += Ap10; query += Ap11; query += Ap12; query += Ap13; query += Ap14; query += Ap15; query += Ap16; query += Ap17;

    std::this_thread::sleep_for(std::chrono::milliseconds(250));
    std::cout<<"Welcome to our apartment rental management system! Are you looking to rent an apartment while travelling OR would you like to put your apartment up for rent? Then, you're in the right place."<<std::endl;
    /*std::cout<<"Press Enter twice to continue browsing.";
    std::cin.get(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');*/
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout<<std::endl<<"An interactive menu will be displayed to improve your user experience."<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout<<"------- These are all of the apartments listed on our platform so far: -------"<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

    // using getters to get rid of [unusedFunction] cppcheck error
    std::vector<Apartment> vec_apts = query.getApts();
    for(const auto &apt: vec_apts)
    {
        std::cout<<apt<<std::endl;
    }

    User current_user;
    Reservation r;
    int choice_differentiate_users;
    bool credentials = false, booked = false;
    std::cout<<std::endl<<std::endl<<"Please select your choice of browsing: "<<std::endl;
    std::cout<<"1. Search for an apartment to rent\n2. Update/ upload details about an apartment I own"<<std::endl;
    std::cin>>choice_differentiate_users; std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout<<std::endl<<"Loading..."<<std::endl;
    switch(choice_differentiate_users)
    {
        case 1:
            std::cout<<"------- Tenant's view -------"<<std::endl;
            do{
                query.proceedTransaction(query, booked);
            } while(!booked);
            std::cout<<"Last step of your booking is to create an account and to specify your card details."<<std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin>>current_user;
            User::loginMenu(current_user, credentials);
            std::cout<<std::endl<<"Account was created successfully. Your account details:"<<std::endl;
            std::cout<<current_user<<std::endl;
            std::cin>>r;
            // using getters to get rid of [unusedFunction] cppcheck error
            std::cout<<std::endl<<"These are your card details: "<<std::endl;
            std::cout<<"Card Number: "<<r.getCardNumber()<<std::endl;
            std::cout<<"Card Holder Name: "<<r.getCardHolderName()<<std::endl;
            std::cout<<"Card CVV: "<<r.getCardCVV()<<std::endl;
            std::cout<<std::endl<<"Payment received. Thank you for choosing our platform!"<<std::endl;
            break;
        case 2:
            std::cout<<"------- Host's View -------"<<std::endl;
            std::cout<<"You must create an account before proceeding to upload details about an apartment."<<std::endl;
            std::cin>>current_user;
            User::loginMenu(current_user, credentials);
            if(credentials)
            {
                std::cout<<" Account was created successfully. Your account details:"<<std::endl;
                //std::cout<<current_user<<std::endl;

                // using getters to get rid of [unusedFunction] cppcheck error
                std::cout<<"Username: "<<current_user.getUsername()<<std::endl;
                std::cout<<"Password: "<<current_user.getPassword()<<std::endl;
                std::cout<<"First Name: "<<current_user.getFirstName()<<std::endl;
                std::cout<<"Last Name: "<<current_user.getLastName()<<std::endl;
                std::cout<<"Email: "<<current_user.getEmail()<<std::endl;
                std::cout<<"ID Number: "<<current_user.getIDNumber()<<std::endl;
                std::cout<<"ID Residence: "<<current_user.getIDResidence()<<std::endl;
                std::cout<<"Phone Number: "<<current_user.getPhoneNumber()<<std::endl;
                std::cout<<std::endl<<"How many apartments will your portfolio contain? Enter the number of apartments you would like to list on the market."<<std::endl;
                std::cout<<"Number of apartments to list: ";
                int no_apts;
                std::cin>>no_apts;
                std::vector<Apartment> vec_host_apts;

                // reading n objects
                for(int i = 0; i < no_apts; i++)
                {
                    Apartment Ap;
                    std::cin>>Ap;
                    query += Ap;
                    vec_host_apts.push_back(Ap);
                    std::this_thread::sleep_for(std::chrono::milliseconds(250));
                    std::cout<<"The apartment added to your portfolio contains a total of "<<Ap.getNoRooms()<<" rooms."<<std::endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                    std::cout<<"An apartment layout will be created in order to display a user-friendly floor plan of your listed apartment."<<std::endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
                    ApartmentLayout *ptr_l1;
                    ptr_l1 = new ApartmentLayout();
                    std::cout<<"You will be prompted to enter some details about the rooms' layouts in order to display the exact details and amenities included."<<std::endl;
                    int k = 0;
                    while(k < Ap.getNoRooms())
                    {
                        std::cout<<std::endl<<"Enter details for a new room: "<<std::endl;
                        RoomLayout *room;
                        room = new RoomLayout();
                        room->createRoom(ptr_l1);
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                        std::cout<<std::endl<<"These are all of the rooms that match the specific room type:";
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                        for(const auto &item: ptr_l1->getRooms())
                        {
                            /*RoomLayout *ptr_room;
                            ptr_room = dynamic_cast<RoomLayout *>(item);*/
                            auto ptr_room = std::dynamic_pointer_cast<RoomLayout>(std::const_pointer_cast<Layout>(item));
                            if(ptr_room)
                            {
                                if(ptr_room->getRoomType() == room->getRoomType())
                                {
                                    if(ptr_room->getName() == room->getName())
                                    {
                                        std::cout<<std::endl<<std::endl<<"The room '"<<room->getName()<<"' has been added to the apartment layout. These are the room's details: "<<std::endl;
                                    }
                                    std::cout<<*ptr_room;
                                }
                            }
                        }
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                        std::cout<<std::endl<<"You have currently entered a total of: "<<ApartmentLayout::getNoBedrooms()<<" bedrooms, "<<ApartmentLayout::getNoLivingRooms()<<" living rooms, "<<ApartmentLayout::getNoKitchens()<<" kitchens and "<<ApartmentLayout::getNoBathrooms()<<" bathrooms."<<std::endl;
                        k++;
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                        std::cout<<"You have a remaining of "<<Ap.getNoRooms() - k<<" rooms to add."<<std::endl;
                    }
                    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                    std::cout<<std::endl<<"These are all of the items included in the apartment layout for apartment ID "<<Ap.getApartmentID()<<":"<<std::endl<<std::endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    for(const auto &item: ptr_l1->getRooms())
                    {
                        std::cout<<*item;
                    }
                    std::cout<<std::endl;
                    std::cin>>*ptr_l1;
                    ptr_l1->drawFloorPlan();
                    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
                    std::cout<<std::endl<<*ptr_l1;
                    // downcasting
                    Layout *ptr_layout = ptr_l1;
                    std::cout<<std::endl<<"The apartment's layout has a total of "<<ptr_layout->computeArea()<<" square meters of usable surface area"<<std::endl;

                    ApartmentLayout::resetStaticVariables();
                    delete ptr_l1;
                }
                std::cout<<"Added successfully to the catalog."<<std::endl;

                // displaying n objects (n is being represented by the size of vector l_apt_layouts)
                std::cout<<std::endl<<"Your apartment/s details are:"<<std::endl;
                for(int i = 0; i < no_apts; i++)
                {
                    std::this_thread::sleep_for(std::chrono::milliseconds(800));
                    std::cout<<vec_host_apts[i]<<std::endl;
                }

                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                std::cout<<"Would you like to see the updated version of the latest listed apartments?"<<std::endl;
                std::cout<<"1. Yes\n2. No"<<std::endl;
                int choice_display;
                std::cin>>choice_display;
                if(choice_display == 1)
                {
                    std::cout<<query;
                }
                std::cout<<std::endl<<"Thank you for choosing our platform!"<<std::endl;
            } else
            {
                std::cout<<" Account was not created. Stop and run this script again."<<std::endl;
            }
            break;
        default:
            return 0;
    }
    /*
    Apartment Ap1("12rg3g0", "Benidorm, Spain", "Rental Unit", "Apartment Ideal to enjoy Playa de Benidorm, in the heart of Playa de Poniente. Views from the living room to the ocean and the Isle of Benidorm.", 4, 5, 136);
    std::this_thread::sleep_for(std::chrono::milliseconds(250));
    std::cout<<"The apartment added to your portfolio contains a total of "<<Ap1.getNoRooms()<<" rooms."<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout<<"An apartment layout will be created in order to display a user-friendly floor plan of your listed apartment."<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    ApartmentLayout *ptr_l1;
    ptr_l1 = new ApartmentLayout();
    std::cout<<"You will be prompted to enter some details about the rooms' layouts in order to display the exact details and amenities included."<<std::endl;
    int k = 0;
    while(k < Ap1.getNoRooms())
    {
        std::cout<<std::endl<<"Enter details for a new room: "<<std::endl;
        RoomLayout *room;
        room = new RoomLayout();
        room->createRoom(ptr_l1);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout<<std::endl<<"These are all of the rooms that match the specific room type:";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        for(const auto &item: ptr_l1->getRooms())
        {
            if(dynamic_cast<RoomLayout *>(item)->getRoomType() == room->getRoomType())
            {
                if(dynamic_cast<RoomLayout *>(item)->getName() == room->getName())
                {
                    std::cout<<std::endl<<std::endl<<"The room '"<<room->getName()<<"' has been added to the apartment layout. These are the room's details: "<<std::endl;
                }
                std::cout<<*item;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout<<std::endl<<"You have currently entered a total of: "<<ApartmentLayout::getNoBedrooms()<<" bedrooms, "<<ApartmentLayout::getNoLivingRooms()<<" living rooms, "<<ApartmentLayout::getNoKitchens()<<" kitchens and "<<ApartmentLayout::getNoBathrooms()<<" bathrooms."<<std::endl;
        k++;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout<<"You have a remaining of "<<Ap1.getNoRooms() - k<<" rooms to add."<<std::endl;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout<<std::endl<<"These are all of the items included in the apartment layout for apartment ID "<<Ap1.getApartmentID()<<":"<<std::endl<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    for(const auto &item: ptr_l1->getRooms())
    {
        std::cout<<*item;
    }
    std::cout<<std::endl;
    std::cin>>*ptr_l1;
    ptr_l1->drawFloorPlan();
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    std::cout<<std::endl<<*ptr_l1;
    // downcasting
    Layout *ptr_layout = ptr_l1;
    std::cout<<std::endl<<"The apartment's layout has a total of "<<ptr_layout->computeArea()<<" square meters of usable surface area"<<std::endl;

    delete ptr_l1;
    return 0;
     */
    return 0;
}