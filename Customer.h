#include"Person.h"
#include<iostream>
using namespace std;
#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H
class Customer:public Person
{
private:
	string idCustomer;
	int numberToHotel;
public:
	Customer();
	Customer(string, string, string, string, string, Date dob, Address address, int);
	string getIdCustomer();
	int getNumberToHotel();
	void setIdCustomer(string idCustomer);
	void setNumberToHotel(int numberToHotel);
	void input();
	void output();
	friend istream& operator>>(istream& is, Customer& customer);
	friend ostream& operator<<(ostream& os, Customer& customer);
	void doc_fileCustomer(ifstream& filein);
	void ghi_fileCustomer(string fileout);
};
#endif
