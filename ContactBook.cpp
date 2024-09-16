#include "ContactBook.h"
#include <algorithm>

Contact::Contact(std::string name, std::string number) {
    this->name = name;
    this->number = number;
}

string Contact::getName(){
    return name;
}

string Contact::getNumber(){
    return number;
}

void Contact::Display(){
    cout << name << ", " << number << endl;
}

ContactBook::ContactBook() {
    for (int i = 0; i < 100; i++){
        contacts[i] = nullptr;
    }
}

Contact* ContactBook::Find(string info){
    for (int i =0; i < curr_size; i++){
        if (info == contacts[i]->getName() || info == contacts[i]->getNumber()){
            return contacts[i];
        }
    }
    return nullptr;
}

void ContactBook::Add(Contact &c){
    contacts[curr_size] = &c;
    curr_size++;
}

void ContactBook::AddContacts(vector<Contact*> vec) {
    int j = 0;
    for (int i = curr_size; i < (curr_size + vec.size()); i++){
        contacts[i] = vec[j];
        j++;
    }
    curr_size += vec.size();
}

void ContactBook::Remove(Contact &c){
    Contact* ptr = Find(c.getName());
    if (ptr != nullptr){ //contact exists
        for (int i = 0; i < curr_size; i++){
            if (contacts[i] == ptr){ //find location of removed ptr in array
                while(contacts[i] != nullptr){
                    if (i == 99){ //reached final contact
                        contacts[99] = nullptr;
                        break;
                    }
                    contacts[i] = contacts[i + 1]; //shift each contact ptr one
                }
            }
        }
        curr_size--;
    }
}

void ContactBook::Display(){
    for (int i = 0; i < curr_size; i++){
        contacts[i]->Display(); //call contact specific display function on each contact ptr
    }
}

void ContactBook::Alphabetize(){
    string temp_array[curr_size];
    for (int i = 0; i < curr_size; i++){
        temp_array[i] = contacts[i]->getName();
    }
    sort(temp_array, temp_array + curr_size);
    for (int i = 0; i < curr_size; i++){
        contacts[i] = Find(temp_array[i]);
    }
}

void ContactBook::operator+=(Contact& c){
    this->Add(c);
}

void ContactBook::operator+=(ContactBook& cb){
    vector<Contact*> vec;
    for (int i = 0; i < cb.curr_size; i++){
        vec.push_back(cb.contacts[i]);
    }
    this->AddContacts(vec);
}

ContactBook ContactBook::operator+(ContactBook& cb){
    *this += cb;
    return *this;
};

void ContactBook::operator-(Contact& c){
    this->Remove(c);
}

void ContactBook::operator-=(ContactBook& cb){
    for (int i = 0; i < curr_size; i++){
        this->Remove(*(cb.contacts[i]));
    }
}

ContactBook ContactBook::operator-(ContactBook& cb){
    ContactBook temp;
    temp = *this;
    temp -= cb;
    return temp;
}

bool ContactBook::operator==(ContactBook& cb){
    if (this->curr_size == cb.curr_size){
        this->Alphabetize();
        cb.Alphabetize();
        for (int i = 0; i < curr_size; i++){
            if (this->contacts[i]->getName() != cb.contacts[i]->getName()){
                return false;
            }
        }
    }
    return true;
}

bool ContactBook::operator!=(ContactBook& cb){
    if (this->curr_size != cb.curr_size) {
        return true;
    }
    this->Alphabetize();
    cb.Alphabetize();
    for (int i = 0; i < curr_size; i++){
        if (this->contacts[i]->getName() != cb.contacts[i]->getName()){
            return true;
        }
    }
    return false;
}
