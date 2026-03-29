#include "Refrigerator.h"


Refrigerator::Refrigerator() {
    brand = "";
    model = "";
    capacity = 0;
    price = 0;
}

Refrigerator::Refrigerator(string b, string m, int c, double p) {
    brand = b;
    model = m;
    capacity = c;
    price = p;
}


string Refrigerator::getBrand() const { return brand; }
string Refrigerator::getModel() const { return model; }
int Refrigerator::getCapacity() const { return capacity; }
double Refrigerator::getPrice() const { return price; }


void Refrigerator::setBrand(string b) { brand = b; }
void Refrigerator::setModel(string m) { model = m; }
void Refrigerator::setCapacity(int c) { capacity = c; }
void Refrigerator::setPrice(double p) { price = p; }


ostream& operator<<(ostream& os, const Refrigerator& ref) {
    os << ref.brand << " | " << ref.model << " | "
        << ref.capacity << " л | " << ref.price << " руб";
    return os;
}


istream& operator>>(istream& is, Refrigerator& ref) {
    cout << "brend: ";
    is >> ref.brand;
    cout << "model: ";
    is >> ref.model;
    cout << "obem: ";
    is >> ref.capacity;
    cout << "cena: ";
    is >> ref.price;
    is.ignore(10000, '\n');
    return is;
}


string Refrigerator::operator()(int index) const {
    if (index == 0) return brand;
    if (index == 1) return model;
    if (index == 2) return to_string(capacity);
    if (index == 3) return to_string(price);
    return "";
}

void Refrigerator::writeToFile(ofstream& out) const {
    size_t len = brand.length();
    out.write((char*)&len, sizeof(len));
    out.write(brand.c_str(), len);

    len = model.length();
    out.write((char*)&len, sizeof(len));
    out.write(model.c_str(), len);

    out.write((char*)&capacity, sizeof(capacity));
    out.write((char*)&price, sizeof(price));
}


void Refrigerator::readFromFile(ifstream& in) {
    size_t len;
    char* buffer;

    in.read((char*)&len, sizeof(len));
    buffer = new char[len + 1];
    in.read(buffer, len);
    buffer[len] = '\0';
    brand = buffer;
    delete[] buffer;

    in.read((char*)&len, sizeof(len));
    buffer = new char[len + 1];
    in.read(buffer, len);
    buffer[len] = '\0';
    model = buffer;
    delete[] buffer;

    in.read((char*)&capacity, sizeof(capacity));
    in.read((char*)&price, sizeof(price));
}