#include "Room.h"
#include<string>
#include<fstream>
#include<iostream>
using namespace std;
Room::Room() {
	this->roomNumber = "";
	this->roomStatus = "";
	this->roomPrice = 0;
}
Room::Room(string roomNumber, string roomStatus, double roomPrice) {
	setRoomNumber(roomNumber);
	setRoomStatus(roomStatus);
	setRoomPrice(roomPrice);
}
string Room::getRoomNumber() {
	return this->roomNumber;
}
string Room::getRoomStatus() {
	return this->roomStatus;
}
double Room::getRoomPrice() {
	return this->roomPrice;
}
void Room::setRoomNumber(string roomNumber) {
	this->roomNumber = roomNumber;
}
void Room::setRoomStatus(string roomStatus) {
	this->roomStatus = roomStatus;
}
void Room::setRoomPrice(double roomPrice) {
	if (this->roomPrice < 0)
		this->roomPrice = 1;
	else this->roomPrice = roomPrice;
}
void Room::input() {
	cout << "\tEnter RoomNumber:";
	getline(cin, roomNumber);
	cout << "\tEnter RoomStatus:";
	getline(cin, roomStatus);
	cout << "\tEnter RoomPrice:";
	cin >> roomPrice;
}
void Room::output() {
	cout << "\n\tRoomNumber:" << roomNumber << "	RoomStatus:" << roomStatus << "\n\tRoomPrice:" << roomPrice;
}
istream& operator>>(istream& is, Room& room) {
	room.input();
	return is;
}
ostream& operator<<(ostream& os, Room& room) {
	room.output();
	return os;
}
void Room::doc_fileRoom(ifstream& docfile) {
	getline(docfile, roomNumber, ',');
	docfile.seekg(1, 1);
	getline(docfile, roomStatus, ',');
	docfile >> roomPrice;
	docfile.seekg(1, 1);
}
void Room::ghi_fileRoom(string ghifile) {
	ofstream fileout(ghifile, ios::app);
	fileout << roomNumber << ", ";
	fileout << roomStatus << ", ";
	fileout << roomPrice << ", ";
}