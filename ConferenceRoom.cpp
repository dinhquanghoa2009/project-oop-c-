#include"Room.h"
#include "ConferenceRoom.h"
#include<string>
#include<fstream>
#include<iostream>
using namespace std;
ConferenceRoom::ConferenceRoom() :Room() {
	this->nameConference = "";
	this->capacity = 0;
}
ConferenceRoom::ConferenceRoom(string roomNumber, string roomStatus, double roomPrice, string nameConference, int capacity) : Room(roomNumber,roomStatus,roomPrice) {
	setNameConference(nameConference);
	setCapacity(capacity);
}
int ConferenceRoom::getCapacity() {
	return this->capacity;
}
string ConferenceRoom::getNameConference() {
	return this->nameConference;
}
void ConferenceRoom::setCapacity(int capacity) {
	if (this->capacity < 0)
		this->capacity = 1;
	else
		this->capacity = capacity;
}
void ConferenceRoom::setNameConference(string nameConference) {
	this->nameConference = nameConference;
}
void ConferenceRoom::input() {
	Room::input();
	cin.ignore();
	cout << "\tEnter NameConferenceRoom:";
	getline(cin, nameConference);
	cout << "\tEnter Capacity:";
	cin >> capacity;
	setCapacity(capacity);
}
istream& operator>>(istream& is, ConferenceRoom& conferenceRoom) {
	conferenceRoom.input();
	return is;
}
void ConferenceRoom::output() {
	Room::output();
	cout << "\n\tNameConferenceRoom:" << nameConference << "    Capacity:" << capacity;
}
ostream& operator<<(ostream& os, ConferenceRoom& conferenceRoom) {
	conferenceRoom.output();
	return os;
}
void ConferenceRoom::doc_fileRoom(ifstream& docfile) {
	Room::doc_fileRoom(docfile);
	getline(docfile, nameConference, ',');
	docfile>>capacity;
}
void ConferenceRoom::ghi_fileRoom(string ghifile) {
	ofstream fileout(ghifile, ios::app);
	Room::ghi_fileRoom(ghifile);
	fileout << nameConference << ", " << capacity;
	fileout << endl;
}