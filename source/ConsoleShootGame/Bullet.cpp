#include "pch.h"
#include "Bullet.h"


Bullet::Bullet()
{
}

void Bullet::setData(int gx, int gy, bool glive) {
	x = gx;
	y = gy;
	live = glive;
}

void Bullet::DrawBullet() {
	rlutil::locate(x, y);
	rlutil::setColor(12);
	cout << BULLETCHARACTER;
	rlutil::setColor(7);
}
void Bullet::EraseBullet() {
	rlutil::locate(x, y);
	cout << ' ';
}

Bullet::~Bullet()
{
}
