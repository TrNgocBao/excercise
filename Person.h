#pragma once
#include <string>
using namespace std;

class Person
{
private:
	int age;
	int pId; // rieng
	string firstName;
	string lastName;
	string midName;
	string address;
	string phoneNumber;
	string gender;
public:
	Person(); // ham tao mac dinh
	Person(int, int, string, string, string, string, string, string);
	
	static int id; // dung chung
	
	int getID();
	void setID(int);
	int getAge();
	void setAge(int);
	string getFirstName();
	void setFirstName(string);
	string getMidName();
	void setMidName(string);
	string getLastName();
	void setLastName(string);
	string getAddress();
	void setAddress(string);
	string getPhone();
	void setPhone(string);
	string getGender();
	void setGender(string);

	void showInfo();
	string fullName();
};
