#include"Room.h"
#include<iostream>
using namespace std;
#pragma once
#ifndef CONFERENCE_H
#define CONFERENCE_H
class ConferenceRoom:public Room
{
private:
	string nameConference;
	int capacity;
public:
	ConferenceRoom();
	ConferenceRoom(string, string, double, string, int);
	int getCapacity();
	string getNameConference();
	void setCapacity(int capacity);
	void setNameConference(string nameConference);
	void input();
	void output();
	friend istream& operator>>(istream& is, ConferenceRoom& conferenceRoom);
	friend ostream& operator<<(ostream& os, ConferenceRoom& conferenceRoom);
	void doc_fileRoom(ifstream& docfile);
	void ghi_fileRoom(string ghifile);
};
#endif
