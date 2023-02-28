// .h chi khai bao khong dinh nghia
// .cpp dung de dinh nghia
// 1. thiet lap thong tin cho 1 tp cu the, thong qua phuong thuc set()
// ham set k can tra ve -> void
// 2. lay thong tin ra, phuong thuc get()
// 1&2 qui uoc tinh dong goi, chi ghi (set), chi doc (get)
// moi thuoc tinh co 1 cap get set rieng
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
	Person(int, int, string, string, string, string, string, string); // k can ten tham so
	
	static int id; // dung chung
	
	int getID();
	void setID(int);
	int getAge();
	void setAge(int);
	string getFirstName(); //giu crtl cong ten phuong thuc se dan den dinh nghia
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