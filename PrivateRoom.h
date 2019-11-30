#include"Room.h"
#include<iostream>
using namespace std;
#pragma once
#ifndef PRIVATEROOM_H
#define PRIVATEROOM_H
class PrivateRoom:public Room
{
private:
	int numberPerson;
	int roomType;
public:
	PrivateRoom();
	PrivateRoom(string, string, double, int, int);
	int getNumberPerson();
	int getRoomType();
	void setNumberPerson(int numberPerson);
	void setRoomType(int roomType);
	void input();
	void output();
	friend istream& operator>>(istream& is, PrivateRoom& privateroom);
	friend ostream& operator<<(ostream& os, PrivateRoom& privateroom);
	void doc_fileRoom(ifstream& docfile);
	void ghi_fileRoom(string ghifile);
};
#endif
