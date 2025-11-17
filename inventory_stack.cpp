#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Inventory class
class Inventory {
private:
    int serialNum;
    string manufactDate;
    int lotNum;

public:
    // Constructors
    Inventory() : serialNum(0), manufactDate(""), lotNum(0) {}
    Inventory(int s, const string& d, int l) : serialNum(s), manufactDate(d), lotNum(l) {}

    // Setters
    void setSerialNum(int s) { serialNum = s; }
    void setManufactDate(const string& d) { manufactDate = d; }
    void setLotNum(int l) { lotNum = l; }

    // Getters
    int getSerialNum() const { return serialNum; }
    string getManufactDate() const { return manufactDate; }
    int getLotNum() const { return lotNum; }

    // Display function
    void display() const {
        cout << "Serial Number: " << serialNum << endl;
        cout << "Manufacture Date: " << manufactDate << endl;
        cout << "Lot Number: " << lotNum << endl;
    }
};

class InventoryStack {
private:
    vector<Inventory> stack;

public:
    void push(const Inventory& item) {
        stack.push_back(item);
    }

    bool pop(Inventory& item) {
        if (stack.empty()) {
            return false;  
        }
        item = stack.back();
        stack.pop_back();
        return true;
    }

    bool isEmpty() const {
        return stack.empty();
    }

    void displayAll() const {
        cout << "\nRemaining items in inventory stack:\n";
        for (int i = (int)stack.size() - 1; i >= 0; --i) {
            cout << "Item " << i + 1 << ":\n";
            stack[i].display();
            cout << "-------------------\n";
        }
    }
};

int main() {
    InventoryStack inventoryStack;
    char choice;

    do {
        cout << "\nWould you like to add a part (A), take a part (T), or finish (F)? ";
        cin >> choice;
        choice = toupper(choice);

        if (choice == 'A') {
            int serialNum, lotNum;
            string manufactDate;

            cout << "Enter serial number: ";
            cin >> serialNum;
            cout << "Enter manufacture date (e.g., 2025-07-02): ";
            cin.ignore(); // clear input buffer
            getline(cin, manufactDate);
            cout << "Enter lot number: ";
            cin >> lotNum;

            Inventory newPart(serialNum, manufactDate, lotNum);
            inventoryStack.push(newPart);
            cout << "Part added to inventory.\n";

        } else if (choice == 'T') {
            Inventory part;
            if (inventoryStack.pop(part)) {
                cout << "Removed part from inventory:\n";
                part.display();
            } else {
                cout << "Inventory is empty, no part to remove.\n";
            }

        } else if (choice == 'F') {
            cout << "Finishing program.\n";
            break;

        } else {
            cout << "Invalid option, please enter A, T, or F.\n";
        }
    } while (true);

    if (!inventoryStack.isEmpty()) {
        inventoryStack.displayAll();
    } else {
        cout << "No remaining parts in inventory.\n";
    }

    return 0;
}
