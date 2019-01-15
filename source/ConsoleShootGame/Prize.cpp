#include "pch.h"
#include "Prize.h"


Prize::Prize()
{
}

void Prize::setData(int gx, int gy, bool glive) {
	x = gx;
	y = gy;
	live = glive;
}
void Prize::DrawPrize() {
	rlutil::locate(x, y);
	rlutil::setColor(14);
	cout << PRIZECHARACTER;
	rlutil::setColor(7);
}
void Prize::ErasePrize() {
	rlutil::locate(x, y);
	cout << ' ';
}

Prize::~Prize()
{
}
