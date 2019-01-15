#include "pch.h"
#include "EnemyShip.h"


EnemyShip::EnemyShip()
{
}


void EnemyShip::SetData(int gx, int gy, int gr, int glives, char genemyCharacter) {
	x = gx;
	y = gy;
	r = gr;
	lives = glives;
	enemyCharacter = genemyCharacter;
}

void EnemyShip::DrawShip() {
	for (int i = -r; i < (r + 1); i++)
	{
		for (int ii = -r; ii < (r + 1); ii++) {
			
			rlutil::setColor(lives+8);
			rlutil::locate(x + i, y + ii);
			cout << enemyCharacter;
		}
	}
	rlutil::locate(x , y );
	cout << lives;
	rlutil::setColor(7);
}
void EnemyShip::EraseShip() {
	for (int i = -r; i < (r + 1); i++)
	{
		for (int ii = -r; ii < (r + 1); ii++) {

			rlutil::locate(x + i, y + ii);
			cout << ' ';
		}
	}
}
 
EnemyShip::~EnemyShip()
{
}
