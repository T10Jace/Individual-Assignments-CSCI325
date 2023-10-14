/**
 * @file phonebook.h
 * @author Jace Riley
 * @date 2023-10-12
 * @brief 
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

class Phonebook {

    struct Node {
    std::string first_name;
    std::string last_name;
    std::string phone_number;

    Node *next;

    Node() : first_name(""), last_name(""), phone_number("") {}  // Default constructor

    Node(const std::string& fname, const std::string& lname, const std::string& number)
        : first_name(fname), last_name(lname), phone_number(number) {}
};



public:
    // Constructor and destructor
    Phonebook();
    ~Phonebook();

    // Methods
    void push_front(const std::string& first_name, const std::string& last_name, const std::string& phone_number);
    void push_back(const std::string& first_name, const std::string& last_name, const std::string& phone_number);
    void read_from_file(const std::string& filename);
    void write_to_file(const std::string& filename);
    void insert_sorted(const std::string& first_name, const std::string& last_name, const std::string& phone_number);
    std::string lookup(const std::string& name);
    std::string reverse_lookup(const std::string& phone_number);
    void print(const std::string& filename);
    void delete_user(const std::string& name);

private:

    std::string first_name;
    std::string last_name;
    std::string phone_number;

    Node* next;
    Node* head;

    // Helper function to use as deallocator
    void destroy();
};

#endif // #phonebook_H
