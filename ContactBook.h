//
// Created by tenni on 2/23/2024.
//

#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Contact{
    string name;
    string number;
public:
    Contact(string name, string number);
    string getName();
    string getNumber();
    void Display();
};

class ContactBook{
    static const int MAX_SIZE = 100;
    Contact* contacts[MAX_SIZE]; //create an array called contacts
    unsigned int curr_size = 0;

public:
    ContactBook();
    Contact* Find(string info);
    void Add(Contact &c);
    void AddContacts(vector <Contact*> vec);
    void Remove(Contact &c);
    void Display();
    void Alphabetize();

    void operator+=(Contact& c);
    void operator+=(ContactBook& cb);
    ContactBook operator+(ContactBook& cb);
    void operator-=(Contact& c);
    void operator-=(ContactBook& cb);
    void operator-(Contact& c);
    ContactBook operator-(ContactBook& cb);
    bool operator==(ContactBook& cb);
    bool operator!=(ContactBook& cb);


};