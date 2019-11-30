#include<iostream>
using namespace std;
#pragma once
#ifndef ROOM_H
#define ROOM_H
class Room
{
protected:
	string roomNumber;
	string roomStatus;
	double roomPrice;
public:
	Room();
	Room(string, string, double);
	string getRoomNumber();
	string getRoomStatus();
	double getRoomPrice();
	void setRoomNumber(string roomNumber);
	void setRoomStatus(string roomStatus);
	void setRoomPrice(double roomPrice);
	virtual void input();
	virtual void output();
	virtual void doc_fileRoom(ifstream& docfile);
	virtual void ghi_fileRoom(string ghifile);
	friend istream& operator>>(istream& is, Room& room);
	friend ostream& operator<<(ostream& os, Room& room);
};
#endif
