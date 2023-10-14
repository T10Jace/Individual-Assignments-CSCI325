/**
 * @file phonebook.cpp
 * @author Jace Riley
 * @date 2023-10-12
 * @brief 
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

const int MAX = 100;

#include "phonebook.h"

// Constructor
Phonebook::Phonebook() {
    head = NULL;
}

// Destructor
Phonebook::~Phonebook() {

    //std::cout << "Destroying list: " << std::endl;

    Node* current = head;

    while (current != NULL) {

        //std::cout << "Removing list member: " << std::endl;
        Node* next = current->next;

        delete current;

        current = next;
    }

    head = NULL;
}

void Phonebook::push_front(const std::string& first_name, const std::string& last_name, const std::string& phone_number) {
    Node* new_node = new Node(first_name, last_name, phone_number);
    
    new_node->next = head;
    
    head = new_node;
}

void Phonebook::push_back(const std::string& first_name, const std::string& last_name, const std::string& phone_number) {
    Node* new_node = new Node(first_name, last_name, phone_number);

    if (!head) {
        // If the list is empty, the new node becomes the head
        head = new_node;
    } 
    
    else {
        Node* current = head;

        while (current->next) {
            current = current->next;
        }

        current->next = new_node;
    }
}

// Read Phonebook data from a file
void Phonebook::read_from_file(const std::string& filename) {
    // Open the file for reading
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cout << "Failed to open the file for reading: " << filename << std::endl;
        return;
    }

    // Temporary variables
    std::string line;

    // Read data from the file and insert it into the phonebook
    while (std::getline(file, line)) {
        // Create a new Node for each entry
        Node* temp = new Node;

        temp->first_name = line;

        if (std::getline(file, line)) {
            temp->last_name = line;
        } else {
            std::cout << "Error: Incomplete data in the file." << std::endl;
            delete temp; // Don't forget to clean up allocated memory
            break;
        }

        if (std::getline(file, line)) {
            temp->phone_number = line;
        } else {
            std::cout << "Error: Incomplete data in the file." << std::endl;
            delete temp; // Don't forget to clean up allocated memory
            break;
        }

        // Insert the new Node into your phonebook (you may need to implement this)
        // insert_sorted(temp);
    }

    // Close the file
    file.close();
}


void Phonebook::write_to_file(const std::string& filename) {
    std::ofstream file(filename);

    if (!file) {
        std::cout << "Failed to open the file for writing: " << filename << std::endl;
        return;
    }

    Node* current = head;

    while (current) {
        file << current->first_name << " " << current->last_name << "\n";
        file << current->phone_number << "\n";

        current = current->next;
    }

    file.close();
}


void Phonebook::insert_sorted(const std::string& first_name, const std::string& last_name, const std::string& phone_number) {
    Node* new_node = new Node(first_name, last_name, phone_number);
    
    if (!head || last_name < head->last_name) {
        new_node->next = head;
        head = new_node;
        return;
    }

    Node* current = head;
    Node* previous = NULL;

    while (current && last_name > current->last_name) {
        previous = current;
        current = current->next;
    }

    new_node->next = current;
    if (previous) {
        previous->next = new_node;
    }

    else {
        head = new_node;
    }
}


std::string Phonebook::lookup(const std::string& name) {
 Node* current = head;

    while (current) {
        // Combine the first name and last name to form a full name for comparison
        std::string full_name = current->first_name + " " + current->last_name;
        
        if (full_name == name) {
            // If the name is found, return the associated phone number
            return current->phone_number;
        }

        current = current->next;
    }

    return "Not found";
}

std::string Phonebook::reverse_lookup(const std::string& phone_number) {
Node* current = head;

    while (current) {
        if (current->phone_number == phone_number) {
            // If the phone number is found, return the associated name
            return current->first_name + " " + current->last_name;
        }

        current = current->next;
    }

    return "Not found";
}

void Phonebook::print(const std::string& filename) {
    std::string name;
    std::string phone_number;
    std::string Name[MAX];
    std::string number[MAX];
    int count = 0;

    std::ifstream file(filename);
    file.open(filename);

    std::getline(file, name);
    std::getline(file, phone_number);


    

   // std::getline(file, first_name);
   // std::getline(file, last_name);
   // std::getline(file, phone_number);

    while(file){
        Name[count] = name;
        number[count] = phone_number;

        count++;

        std::getline(file, name);
        std::getline(file, phone_number);
    }

    for(int i = 0; i > MAX; i++){
        std::cout << "Name: " << Name[i] << std::endl;
        //std::cout << "Last Name: " << lname[i] << std::endl;
        std::cout << "Phone Number: " << number[i] << std::endl;
        std::cout << "----------------------------------" << std::endl;
    } 
}

void Phonebook::delete_user(const std::string& name) {
    Node* current = head;
    Node* previous = NULL;

    while (current) {
        // Check if the current node's last name matches the name to be deleted
        if (current->last_name == name) {
            // If found, update the next pointer of the previous node
            if (previous) {
                previous->next = current->next;
            }
            else {
                // If there's no previous node, the node to be deleted is the head
                head = current->next;
            }
            
            delete current; // Deallocate the memory of the deleted node
            return; // Exit the function after deleting the user
        }

        previous = current;
        current = current->next;
    }

    // If the function reaches this point, the user was not found
    std::cout << "User not found: " << name << std::endl;
}


void Phonebook::destroy() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = NULL; // Set the head pointer to NULL to indicate an empty list
}
