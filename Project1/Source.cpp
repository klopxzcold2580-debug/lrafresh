#include "Refrigerator.h"

Database::Database() {
    arr = nullptr;
    count = 0;
    size = 0;
}

Database::~Database() {
    delete[] arr;
}

void Database::resize() {
    int newSize = (size == 0) ? 1 : size * 2;
    Refrigerator* newArr = new Refrigerator[newSize];

    for (int i = 0; i < count; i++) {
        newArr[i] = arr[i];
    }

    delete[] arr;
    arr = newArr;
    size = newSize;
}

void Database::add(Refrigerator r) {
    if (count == size) {
        resize();
    }
    arr[count] = r;
    count++;
    cout << "dobavleno\n";
}

void Database::remove(int index) {
    if (index < 0 || index >= count) {
        cout << "neverno\n";
        return;
    }

    for (int i = index; i < count - 1; i++) {
        arr[i] = arr[i + 1];
    }
    count--;
    cout << "delete\n";
}

void Database::edit(int index, Refrigerator r) {
    if (index < 0 || index >= count) {
        cout << "neverno\n";
        return;
    }
    arr[index] = r;
}

void Database::printAll() {
    if (count == 0) {
        cout << "pysto\n";
        return;
    }

    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". " << arr[i] << endl;
    }
}

void Database::searchByBrand(string brand) {
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (arr[i].getBrand() == brand) {
            cout << i + 1 << ". " << arr[i] << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "nety3\n";
    }
}

void Database::searchByCapacity(int minC, int maxC) {
    bool found = false;
    for (int i = 0; i < count; i++) {
        int cap = arr[i].getCapacity();
        if (cap >= minC && cap <= maxC) {
            cout << i + 1 << ". " << arr[i] << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "nety2\n";
    }
}

void Database::loadFromFile(string filename) {
    ifstream in(filename, ios::binary);
    if (!in) {
        cout << "nety1\n";
        return ;
    }

    
    int n;
    in.read((char*)&n, sizeof(n));

   
    delete[] arr;
    arr = nullptr;
    count = 0;
    size = 0;

   
    for (int i = 0; i < n; i++) {
        Refrigerator r;
        r.readFromFile(in);
        add(r);
    }

    in.close();
    cout << "c " << n << " c\n";
}

void Database::saveToFile(string filename) {
    ofstream out(filename, ios::binary);
    if (!out) {
        cout << "mistake\n";
        return;
    }

    out.write((char*)&count, sizeof(count));


    for (int i = 0; i < count; i++) {
        arr[i].writeToFile(out);
    }

    out.close();
    cout << "g " << count << " g\n";
}