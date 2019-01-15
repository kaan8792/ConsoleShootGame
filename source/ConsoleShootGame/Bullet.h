#pragma once
class Bullet
{
public:

	int x;
	int y;
	bool live;
	const char BULLETCHARACTER = 254;

	Bullet();
	void setData(int, int, bool);
	void DrawBullet();
	void EraseBullet();
	virtual ~Bullet();
};

