#ifndef REFRIGERATOR_H
#define REFRIGERATOR_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Refrigerator {
private:
    string brand;
    string model;
    int capacity;
    double price;

public:
   
    Refrigerator();
    Refrigerator(string b, string m, int c, double p);

    
    string getBrand() const;
    string getModel() const;
    int getCapacity() const;
    double getPrice() const;

    
    void setBrand(string b);
    void setModel(string m);
    void setCapacity(int c);
    void setPrice(double p);

    
    friend ostream& operator<<(ostream& os, const Refrigerator& ref);
    friend istream& operator>>(istream& is, Refrigerator& ref);

    
    string operator()(int index) const;

    
    void writeToFile(ofstream& out) const;
    void readFromFile(ifstream& in);
};


class Database {
private:
    Refrigerator* arr;  
    int count;          
    int size;           

    void resize();      

public:
    Database();
    ~Database();

    void add(Refrigerator r);           
    void remove(int index);             
    void edit(int index, Refrigerator r); 
    void printAll();                    
    void searchByBrand(string brand);   
    void searchByCapacity(int minC, int maxC); 

    void loadFromFile(string filename); 
    void saveToFile(string filename);   

    int getCount() { return count; }
};

#endif