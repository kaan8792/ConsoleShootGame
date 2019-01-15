#pragma once

#include "Bullet.h"

class MainShip
{
public:
	int x; //Geminin x konumu.
	int y; //Geminin y konumu.
	int r; //Geminin yar��ap�.
	const char SHIPCARACTER = 219; //Geminin Karakteri.
	static const int MAXBULLET = 10; //Sahnedeki maximum mermi say�s�.
	Bullet bullets[MAXBULLET];

	MainShip();
	void setValues(int, int, int); 
	void Shoot(); //Ate�!
	void ResetBullets();//Mermilerin ilk de�erlerini false yap.
	void DrawShip();
	void EraseShip();
	virtual ~MainShip();
};

