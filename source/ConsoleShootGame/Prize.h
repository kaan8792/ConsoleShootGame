#pragma once
class Prize
{
public:
	int x;
	int y;
	bool live;
	int prizeValue = 50;
	const char PRIZECHARACTER = '$';
	

	void setData(int,int,bool);
	void DrawPrize();
	void ErasePrize();
	Prize();
	virtual ~Prize();
};

