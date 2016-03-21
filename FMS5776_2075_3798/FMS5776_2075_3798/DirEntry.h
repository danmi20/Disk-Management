#pragma once
#include "Today.h"
#include <string>
using namespace std;

class DirEntry
{
public:
	DirEntry() {};
	DirEntry(char[12], char[12] ,unsigned int, unsigned int,
		unsigned int, unsigned int, unsigned int, char, unsigned int, unsigned int, 
		char[2], unsigned char);
	~DirEntry() {};

private:
	char fileName[12];
	char fileOwner[12];
	unsigned int fileAddr; 
	char crDate[10];
	unsigned int fileSize; // number of sectors
	unsigned int eofRecNr;  //end of file record number
	unsigned int maxRecSize; // ������ �������
	unsigned int actualRecSize; //������ �����
	char recFormat[2]; //fixed size
	unsigned int keyOffset;
	unsigned int keySize; //number of bytes
	char keyType[2]; // I - 00 / F - 01 / D - 10 / C - 10
	unsigned char entryStatus; // 0 - empty / 1- active / 2 - deleted

};