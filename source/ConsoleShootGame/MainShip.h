#pragma once

#include "Bullet.h"

class MainShip
{
public:
	int x; //Geminin x konumu.
	int y; //Geminin y konumu.
	int r; //Geminin yarýçapý.
	const char SHIPCARACTER = 219; //Geminin Karakteri.
	static const int MAXBULLET = 10; //Sahnedeki maximum mermi sayýsý.
	Bullet bullets[MAXBULLET];

	MainShip();
	void setValues(int, int, int); 
	void Shoot(); //Ateþ!
	void ResetBullets();//Mermilerin ilk deðerlerini false yap.
	void DrawShip();
	void EraseShip();
	virtual ~MainShip();
};

