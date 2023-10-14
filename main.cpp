/**
 * @file main.cpp
 * @author Jace Riley
 * @date 2023-10-12
 * @brief 
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "phonebook.h"

using namespace std;

int main() {
    Phonebook phonebook;
    string filename;
    string searchName;
    string phoneNumber;
    string searchPhone;
    string reverseName;
    string firstName;
    string lastName;
    string newPhoneNumber;
    string lastNameToDelete;

    while (true) {
        cout << "Welcome to the UTM Phonebook!" << endl;
        cout << "You may select one of the following options:" << endl;
        cout << "1. Read a phonebook from a file" << endl;
        cout << "2. Write the phonebook to a file" << endl;
        cout << "3. Print the phonebook" << endl;
        cout << "4. Search for a user's phone number" << endl;
        cout << "5. Reverse lookup by phone number" << endl;
        cout << "6. Add a user" << endl;
        cout << "7. Delete a user" << endl;
        cout << "8. Exit this program" << endl;
        cout << "Please enter your choice now: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the filename to read from: ";
                cin >> filename;
                phonebook.read_from_file(filename);
                cout << "Phonebook read from file." << endl;
                break;

            case 2:
                cout << "Enter the filename to write to: ";
                cin >> filename;
                phonebook.write_to_file(filename);
                cout << "Phonebook written to file." << endl;
                break;

            case 3:
                cout << "Enter the filename you wish to print: ";
                cin >> filename;
                phonebook.print(filename);
                break;

            case 4:
                cout << "Enter the user's name to search: ";
                cin.ignore();
                getline(cin, searchName);
                phoneNumber = phonebook.lookup(searchName);
                if (phoneNumber != "Not found") {
                    cout << "Phone number: " << phoneNumber << endl;
                } else {
                    cout << "User not found." << endl;
                }
                break;

            case 5:
                cout << "Enter the phone number to reverse lookup: ";
                cin.ignore();
                getline(cin, searchPhone);
                reverseName = phonebook.reverse_lookup(searchPhone);
                if (reverseName != "Not found") {
                    cout << "User's name: " << reverseName << endl;
                } else {
                    cout << "Phone number not found." << endl;
                }
                break;

            case 6:
                cout << "Enter first name: ";
                cin.ignore();
                getline(cin, firstName);
                cout << "Enter last name: ";
                getline(cin, lastName);
                cout << "Enter phone number: ";
                getline(cin, newPhoneNumber);
                phonebook.push_back(firstName, lastName, newPhoneNumber);
                cout << "User added to the phonebook." << endl;
                break;

            case 7:
                cout << "Enter the last name of the user to delete: ";
                cin.ignore();
                getline(cin, lastNameToDelete);
                phonebook.delete_user(lastNameToDelete);
                break;

            case 8:
                return 0; // Exit the program
        }
    }

    return 0;
}
