#include"Room.h"
#include "PrivateRoom.h"
#include<fstream>
#include<string>
#include<iostream>
using namespace std;
PrivateRoom::PrivateRoom() :Room() {
	this->numberPerson = this->roomType = 0;
}
PrivateRoom::PrivateRoom(string roomNumber, string roomStatus, double roomPrice, int numberPerson, int roomType):Room(roomNumber,roomStatus,roomPrice) {
	setNumberPerson(numberPerson);
	setRoomType(roomType);
}
int PrivateRoom::getNumberPerson() {
	return this->numberPerson;
}
int PrivateRoom::getRoomType() {
	return this->roomType;
}
void PrivateRoom::setNumberPerson(int numberPerson) {
	if (this->numberPerson < 0)
		this->numberPerson = 1;
	else
		this->numberPerson = numberPerson;
}
void PrivateRoom::setRoomType(int roomType) {
	if (this->roomType < 0)
		this->roomType = 1;
	else
		this->roomType = roomType;
}
void PrivateRoom::input() {
	Room::input();
	cout << "\tEnter NumberPerson:";
	cin >> numberPerson;
	setNumberPerson(numberPerson);
	cout << "\tEnter RoomType:";
	cin >> roomType;
	setRoomType(roomType);			
}
istream& operator>>(istream& is, PrivateRoom& privateRoom) {
	privateRoom.input();
	return is;
}
void PrivateRoom::output() {
	Room::output();
	cout << "\n\tNumberPerson:" << numberPerson << "\tRoomType:" << roomType;
}
ostream& operator<<(ostream& os, PrivateRoom& privateRoom) {
	privateRoom.output();
	return os;
}
void PrivateRoom::doc_fileRoom(ifstream& docfile) {
	Room::doc_fileRoom(docfile);
	docfile >> numberPerson;
	docfile.seekg(1, 1);
	docfile >> roomType;
}
void PrivateRoom::ghi_fileRoom(string ghifile) {
	ofstream fileout(ghifile, ios::app);
	Room::ghi_fileRoom(ghifile);
	fileout << numberPerson << ", " << roomType;
	fileout << endl;
}