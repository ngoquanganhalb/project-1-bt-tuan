#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    set<string> database;
    
    string key;
    
    // Read the first block of information
    while (true) {
        cin >> key;
        if (key == "*") {
            break;
        }
        database.insert(key);
    }

    string cmd, k;
    
    // Read the second block of actions
    while (true) {
        cin >> cmd;
        if (cmd == "***") {
            break;
        }
        cin >> k;

        if (cmd == "find") {
            // Check if the key exists in the database
            if (database.count(k) > 0) {
                cout << "1" << endl;
            } else {
                cout << "0" << endl;
            }
        } else if (cmd == "insert") {
            // Try to insert the key into the database
            if (database.count(k) > 0) {
                // Key already exists
                cout << "0" << endl;
            } else {
                // Key does not exist, insert it
                database.insert(k);
                cout << "1" << endl;
            }
        }
    }

    return 0;
}
