#include "Refrigerator.h"
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    Database db;
    string filename;
    cout << "name file: ";
    cin >> filename;
    ifstream testFile(filename, ios::binary);
    if (testFile.good()) {
        testFile.close();
        db.loadFromFile(filename);
    }
    else {
        cout << "file \"" << filename << "\"no find\n";
        testFile.close();
        return 0;
    }


    int choice;

    do {
        cout << "\n========== menu ==========\n";
        cout << "1.pokazat vce\n";
        cout << "2. dobavit\n";
        cout << "3. ydalit\n";
        cout << "4. redaktirovat\n";
        cout << "5. poisk po brendy\n";
        cout << "6. poisk po obemy\n";
        cout << "7. exist\n";
        cout << "choise ";
        if (!(cin >> choice)) {
            clearInput();
            cout << "vvedite chislo\n";
            continue;
        }
        clearInput();

        switch (choice) {
        case 1:
            db.printAll();
            break;

        case 2: {
            Refrigerator r;
            cin >> r;
            db.add(r);
            break;
        }

        case 3: {
            if (db.getCount() == 0) {
                cout << "net elementov \n";
                break;
            }
            int num;
            cout << "vvedite nomer: ";
            cin >> num;
            db.remove(num - 1);
            break;
        }

        case 4: {
            if (db.getCount() == 0) {
                cout << "Нnet elementov\n";
                break;
            }
            int num;
            cout << "vvedite nomer: ";
            cin >> num;
            Refrigerator r;
            cin >> r;
            db.edit(num - 1, r);
            break;
        }

        case 5: {
            string brand;
            cout << "vvedite brend: ";
            cin >> brand;
            db.searchByBrand(brand);
            break;
        }

        case 6: {
            int minC, maxC;
            cout << "min obem: ";
            cin >> minC;
            cout << "max obem: ";
            cin >> maxC;
            db.searchByCapacity(minC, maxC);
            break;
        }
        default:
            db.saveToFile(filename);
            cout << "file save in: " << filename << endl;
            break;

        }
    } while (choice != 7);

    return 0;
}