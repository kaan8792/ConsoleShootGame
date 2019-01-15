#pragma once
class EnemyShip
{
public:

	int x;
	int y;
	int r;
	int lives;
	char enemyCharacter = 178;


	EnemyShip();
	void SetData(int, int, int, int, char);
	void DrawShip();
	void EraseShip();
	virtual ~EnemyShip();
};

