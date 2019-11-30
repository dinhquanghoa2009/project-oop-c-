#include"Person.h"
#include "Customer.h"
#include<string>
#include<fstream>
#include<iostream>
using namespace std;
Customer::Customer() :Person() {
	this->idCustomer = "";
	this->numberToHotel = 0;
}
Customer::Customer(string idCustomer, string idNumber, string name, string phoneNumber, string sex, Date dob, Address address, int numberToHotel) : Person(idNumber, name, phoneNumber, sex, dob, address) {
	setIdCustomer(idCustomer);
	setNumberToHotel(numberToHotel);
}
	
string Customer::getIdCustomer() {
	return this->idCustomer;
}
int Customer::getNumberToHotel() {
	return this->numberToHotel;
}
void Customer::setIdCustomer(string idCustomer) {
	this->idCustomer = idCustomer;
}
void Customer::setNumberToHotel(int numberToHotel) {
	if (this->numberToHotel < 0)
		this->numberToHotel = 1;
	else this->numberToHotel = numberToHotel;
}
void Customer::input() {
	cout << "\tEnter IDCustomer:";
	getline(cin, idCustomer);
	Person::input();
	cout << ("\tEnter Number Of Times To The Hotel:");
	cin >> numberToHotel;
}
istream& operator>>(istream& is, Customer& customer) {
	customer.input();
	return is;
}
void Customer::output() {
	cout << "\tIDCustomer:" << idCustomer;
	Person::output();
	cout << "\tNumber Of Times To The Hotel:" << numberToHotel;
}

ostream& operator<<(ostream& os, Customer& customer) {
	customer.output();
	return os;
} 
void Customer::doc_fileCustomer(ifstream& filein) {
		getline(filein, idCustomer, ',');
		filein.seekg(1, 1);
		Person::doc_filePerson(filein);
		filein.seekg(1, 1);
		filein >> numberToHotel;
}
void Customer::ghi_fileCustomer(string fileout) {
	ofstream ghifile(fileout, ios::app);
	ghifile << endl;
	ghifile << idCustomer << ", ";
	ghifile << Person::getIdNumber() << ", ";
	ghifile << Person::getName() << ", ";
	ghifile << Person::getPhoneNumber() << ", ";
	ghifile << Person::getSex() << ", ";
	ghifile << Person::getDob().getDay() << "/" << Person::getDob().getMonth() << "/" << Person::getDob().getYear() << ",";
	ghifile << Person::getAddress().getNumberAddress() << "- " << Person::getAddress().getStreet() << "- " << Person::getAddress().getDistrict() << "- " << Person::getAddress().getCity() << "- " << Person::getAddress().getCountry() << ", ";
	ghifile << numberToHotel; 
}
