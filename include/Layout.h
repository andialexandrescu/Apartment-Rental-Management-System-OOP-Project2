#ifndef OOP_LAYOUT_H
#define OOP_LAYOUT_H

#include <iostream>

class Layout{ // abstract class which uses multiple virtual pure functions
private:
    float length;
    float width;
public:
    // constructors
    Layout(); // invalid measurements for a layout instance
    Layout(float length, float width);
    Layout(const Layout &other_obj) = default; // copy constructor
    Layout& operator=(const Layout &other_obj); // assignment constructor
    // destructor
    virtual ~Layout() = default; // ensures that the correct destructor is called when deleting a derived class object through a base class pointer
    bool operator==(const Layout& other_obj) const; // google test

    // const functions: getters won't modify the data members regardless of any use case
    [[nodiscard]] const float &getLength() const; // there's no reason for overriding these getter function, therefore using the virtual keyword doesn't make sense (neither RoomLayout, nor ApartmentLayout will override these getters)
    [[nodiscard]] const float &getWidth() const;
    [[maybe_unused]] virtual void setLength(float l); // since Layout is more on the abstract side with no real functionality, these will be overridden in RoomLayout and ApartmentLayout
    [[maybe_unused]] virtual void setWidth(float w);

    // pure virtual function (any derived classes will provide their own implementation of these functions)
    // read and display pure virtual functions
    virtual void read(std::istream& in) = 0; // !!! non-const for obvious reasons
    friend std::istream &operator>>(std::istream &in, Layout &obj); // overloading the operator<< only in the base class, since any derived class will be able to access the standard input operator
    virtual void display(std::ostream &out) const = 0;
    friend std::ostream &operator<<(std::ostream &out, const Layout &obj);
    void description(std::ostream &out) const;
    [[nodiscard]] virtual float computeArea() const;
};

#endif //OOP_LAYOUT_H