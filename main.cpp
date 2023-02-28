#include <iostream>
#include "Person.h"
#include <string>
using namespace std;

void getPersonInfo(Person* ps, size_t n) {
	int age;
	string first, last, mid, addr, phone, gender;
	for (size_t i = 0; i < n; i++) {
		cout << "First Name: ";
		cin >> first;
		cout << "Last name: ";
		cin >> last;
		cout << "Middle name: ";
		cin.ignore();
		getline(cin, mid);
		cout << "Address: ";
		getline(cin, addr); // chuoi co nhieu khoang trang
		cout << "Gender: ";
		cin >> gender;
		cout << "Phone number: ";
		cin >> phone; //chuoi lien hoac 1 chu
		cout << "Age: ";
		cin >> age;

		Person p(0, age, first, last, mid, addr, phone, gender);
		ps[i] = p;
	}
}

void showInfo(Person* ps, size_t n) {
	for (size_t i = 0; i < n; i++) {
		ps[i].showInfo();
	}
}

int main()
{
	Person* people;
	size_t N;
	cout << "Enter the number of people: ";
	cin >> N;

	people = new Person[N];	// cap nhat
	getPersonInfo(people, N); // nhap du lieu
	showInfo(people, N); //hien thi danh sach cac du lieu vua nhap

	return 0;
}