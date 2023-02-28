#include "Person.h"
#include <iostream>
using namespace std;

Person::Person() { // gan gia tri mac dinh cho person.h
	this->age = 0;
	this->pId = 0;
	this->firstName = "";
	this->midName = "";
	this->lastName = "";
	this->address = "";
	this->phoneNumber = "";
	this->gender = "";
}

Person::Person(int id, int age, string firstName, string lastName,
	string midName, string address, string phoneNumber, string gender) {
	setID(id);
	setAge(age);
	setFirstName(firstName);
	setMidName(midName);
	setLastName(lastName);
	setAddress(address);
	setPhone(phoneNumber);
	setGender(gender);
}

int Person::id = 100;

void Person::setID(int id) {
	this->pId = (id >= 100) ? id : Person::id++;
}
void Person::setAge(int age) {
	this->age = (age >= 0) ? age : 0; 
}
void Person::setFirstName(string firstName) {
	this->firstName = firstName;
}
void Person::setMidName(string midName) {
	this->midName = midName;
}
void Person::setLastName(string lastName) {
	this->lastName = lastName;
}
void Person::setAddress(string address) {
	this->address = address;
}
void Person::setPhone(string phoneNumber) {
	this->phoneNumber = phoneNumber;
}
void Person::setGender(string gender) {
	this->gender = gender;
}

int Person::getAge() {
	return this->age;
}
int Person::getID() {
	return this->pId;
}
string Person::getFirstName() {
	return this->firstName;
}
string Person::getMidName() {
	return this->midName;
}
string Person::getLastName() {
	return this->lastName;
}
string Person::getAddress() {
	return this->address;
}
string Person::getPhone() {
	return this->phoneNumber;
}
string Person::getGender() {
	return this->gender;
}

void Person::showInfo() {
	cout << "\nID: " << pId /*getID()*/ << "\n"
		<< "First Name: " << firstName /*getFirstName()*/ << endl
		<< "Middle Name: " << midName << endl
		<< "Last Name: " << lastName << endl
		<< "Full name is: " << fullName() << endl
		<< "Gender: " << gender << endl
		<< "Age: " << age << " years old" << endl
		<< "Address: " << address << endl
		<< "Phone number: " << phoneNumber << endl;
	cout << "\n======================================\n";

}

string Person::fullName() {
	return getLastName() + " " + getMidName() + " " + getFirstName();
}
