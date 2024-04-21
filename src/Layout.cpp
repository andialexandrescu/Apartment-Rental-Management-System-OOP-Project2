#include "Layout.h"

Layout::Layout(): length(0), width(0) {}

Layout::Layout(float length, float width): length(length), width(width) {}

//Layout::Layout(const Layout &other_obj): length(other_obj.length), width(other_obj.width) {}

Layout &Layout::operator=(const Layout &other_obj) {
    if(this != &other_obj) // prevents object self-assignment
    {
        this->length = other_obj.length;
        this->width = other_obj.width;
    }
    return *this;
}

const float &Layout::getLength() const {
    return length;
}

const float &Layout::getWidth() const {
    return width;
}

[[maybe_unused]] void Layout::setLength(float l) {
    this->length = l;
}

[[maybe_unused]] void Layout::setWidth(float w) {
    this->width = w;
}

std::istream &operator>>(std::istream &in, Layout &obj) {
    obj.read(in);
    return in;
}

std::ostream &operator<<(std::ostream &out, const Layout &obj) {
    obj.display(out);
    return out;
}

void Layout::description(std::ostream &out) const {
    out<<"Surface dimensions: "<<std::endl;
    out<<"\tLength: "<<this->getLength()<<" meters"<<std::endl;
    out<<"\tWidth: "<<this->getWidth()<<" meters"<<std::endl;
    out<<"\tTotal Area: "<<computeArea()<<" square meters"<<std::endl;
}

float Layout::computeArea() const {
    return this->length * this->width;
}

bool Layout::operator==(const Layout &other_obj) const {
    return this->length == other_obj.length && this->width == other_obj.width;
}