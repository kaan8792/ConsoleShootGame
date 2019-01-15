#include "pch.h"
#include "MainShip.h"

MainShip::MainShip() {}

void MainShip::setValues(int gx, int gy , int gr)
{
	x = gx;
	y = gy;
	r = gr;
	ResetBullets();

}

void MainShip::Shoot() {
	for (int i = 0; i < MAXBULLET; i++)
	{
		if (!bullets[i].live)
		{
			bullets[i].setData(x + r + 2, y, true);
			break;
		}
	}
}

void MainShip::ResetBullets() {
	for (int i = 0; i < MAXBULLET; i++)
	{
		bullets[i].live = false;
	}
}

void MainShip::DrawShip() {
	for (int i = 0; i <= r; i++)
	{
		rlutil::setColor(15);
		rlutil::locate(x + i + 1, y - (r - i));
		cout << SHIPCARACTER;
		rlutil::locate(x + i + 1, y + (r - i));
		cout << this->SHIPCARACTER;
	}
	rlutil::setColor(7);
}

void MainShip::EraseShip() {
	for (int i = 0; i <= r; i++)
	{
		rlutil::locate(x + i + 1, y - (r - i));
		cout << ' ';
		rlutil::locate(x + i + 1, y + (r - i));
		cout << ' ';
	}
}


MainShip::~MainShip()
{
}
