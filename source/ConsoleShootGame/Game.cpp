#include "pch.h"
#include "Game.h"
#include <time.h>


Game::Game()
{
	srand(time(NULL));
	NewGame();
	GameLoop();
}
Game::~Game()
{
}
void Game::GameLoop() {
	while (playing)
	{
		KeypadControl();
		EraseBullets();
		EraseEnemyShips();
		ErasePrize();

		PushBullet();
		PushEnemyShip();
		PushPrize();

		CreatePrize();
		DrawPrize();
		

		DrawBullet();
		DrawEnemyShip();

		DrawMainShip();

		CreateEnemyShip();

		ItIsHit();
		ShipCollision();
		CatchPrize();

		rlutil::locate(1, SCENEHEIGHT+1);
		cout << "Skor:" << score << "  Yukari:" << UPKEY << " Asagi:" << DOWNKEY << " Ates:" << SHOOTKEY << " Reset:" << RESETKEY;
		
		
		rlutil::msleep(SCENEREFRESHRATE);
	}
}
void Game::NewGame() {
	rlutil::cls();
	prize.live = false;
	score = 0;
	rlutil::hidecursor();
	DrawBorder();
	mainShip.setValues(1, SCENEHEIGHT/2, 2); //Main ship baþlangýç x ,y ,r
	DrawMainShip();
	playing = true;
}


void Game::DrawBorder() {
	for (int x = 1; x <= SCENEWIDTH; x++) {
		rlutil::setColor(8);
		rlutil::locate(x, 1);
		cout << BORDERCHARACTER;
		rlutil::locate(x, SCENEHEIGHT );
		cout << BORDERCHARACTER;
	}
	for (int y = 1; y <= SCENEHEIGHT; y++) {
		rlutil::locate(1, y);
		cout << BORDERCHARACTER;
		rlutil::locate(SCENEWIDTH , y);
		cout << BORDERCHARACTER;
	}
	rlutil::setColor(7);
}

void Game::DrawMainShip() {
	mainShip.DrawShip();
}
void Game::ReadKeypad() {
	for (int i = 0; i < 256; i++)
	{
		keys[i] = (char)(GetAsyncKeyState(i) >> 8);
	}
}
void Game::KeypadControl() {
	ReadKeypad();
	if (keys[UPKEY] != 0)
	{
		if (mainShip.y > mainShip.r + 2)
		{
			mainShip.EraseShip();
			mainShip.y--;
			DrawMainShip();
		}

	}
	if (keys[DOWNKEY] != 0)
	{
		if (mainShip.y < SCENEHEIGHT - (mainShip.r + 1))
		{
			mainShip.EraseShip();
			mainShip.y++;
			DrawMainShip();
		}

	}
	if (keys[SHOOTKEY] != 0)
	{
		mainShip.Shoot();
	}
	if (keys[RESETKEY] != 0)
	{
		NewGame();
	}
}
void Game::DrawBullet() {
	for (int i = 0; i < mainShip.MAXBULLET; i++)
	{
		if (mainShip.bullets[i].live)
		{
			mainShip.bullets[i].DrawBullet();
		}
	}
}
void Game::PushBullet() {
	for (int i = 0; i < mainShip.MAXBULLET; i++) {
		if (mainShip.bullets[i].live)
		{
			if (mainShip.bullets[i].x < (SCENEWIDTH - 2))
			{
				mainShip.bullets[i].x++;
			}
			else
			{
				mainShip.bullets[i].EraseBullet();
				mainShip.bullets[i].live = false;
			}
		}
	}
}
void Game::EraseBullets() {
	for (int i = 0; i < mainShip.MAXBULLET; i++) {
		if (mainShip.bullets[i].live)
		{
			mainShip.bullets[i].EraseBullet();
		}
	}
}
void Game::CreateEnemyShip() {
	if (lastCreateEnemy <= 0)
	{
		for (int i = 0; i < MAXENEMYSHIP; i++) {
			if (enemyShips[i].lives<1)
			{
				enemyShips[i].SetData(
					SCENEWIDTH - (ENEMYSHIPR + 1),//x
					(ENEMYSHIPR + 2) + (rand() % (SCENEHEIGHT - (ENEMYSHIPR + 3))),//y
					ENEMYSHIPR,//r
					(rand()%MAXLIVESENEMY)+1,//lives
					ENEMYCHARACTER//Character
				);
				break;
			}
		}
		lastCreateEnemy = CREATEENEMYRATE;
	}
	else
	{
		lastCreateEnemy = lastCreateEnemy - SCENEREFRESHRATE;
	}
}
void Game::DrawEnemyShip() {
	for (int i = 0; i < MAXENEMYSHIP; i++) {
		if (enemyShips[i].lives>0)
		{
		 enemyShips[i].DrawShip();
		}
	}
}
void Game::PushEnemyShip() {
	int xEnd = ENEMYSHIPR + 2;
	for (int i = 0; i < MAXENEMYSHIP; i++) {
		if (enemyShips[i].lives > 0){
		
			if (enemyShips[i].x <= xEnd)
			{
				enemyShips[i].EraseShip();
				enemyShips[i].lives = 0;
			}
			else {
				enemyShips[i].x--;
			}
		}
	}
}
void Game::EraseEnemyShips() {
	for (int i = 0; i < MAXENEMYSHIP; i++) {
		if (enemyShips[i].lives > 0) {
			enemyShips[i].EraseShip();
		}
	}
}
double Game::DistanceBetweenTwoPoints(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
void Game::ItIsHit() {
	int bx, by;
	int ex, ey, er;
	for (int b = 0; b < mainShip.MAXBULLET; b++)
	{
		if (mainShip.bullets[b].live)
		{
			bx = mainShip.bullets[b].x;
			by = mainShip.bullets[b].y;
			for (int e = 0; e < MAXENEMYSHIP; e++) {
				if (enemyShips[e].lives>0)
				{
					ex = enemyShips[e].x;
					ey = enemyShips[e].y;
					er = enemyShips[e].r;
					if ((DistanceBetweenTwoPoints(bx, by, ex, ey) - 0.55) <= er)
					{
						mainShip.bullets[b].EraseBullet();
						mainShip.bullets[b].live = false;
						if (enemyShips[e].lives == 1) {
							enemyShips[e].EraseShip();
							enemyShips[e].lives--;
						}
						else
						{
							enemyShips[e].EraseShip();
							enemyShips[e].lives--;
							enemyShips[e].DrawShip();
						}
						score++;
					}
				}
			}
		}
	}
}
void Game::ShipCollision() {
	int sx, sy, sr;
	int ex, ey, er;
	sx = mainShip.x;
	sy = mainShip.y;
	sr = mainShip.r;
	for (int i = 0; i < MAXENEMYSHIP; i++) {
		if (enemyShips[i].lives>0)
		{
			ex = enemyShips[i].x;
			ey = enemyShips[i].y;
			er = enemyShips[i].r;
			if ((DistanceBetweenTwoPoints(sx, sy, ex, ey) - 1) < sr + er)
			{
				rlutil::cls();
				rlutil::locate(SCENEWIDTH/2-10, SCENEHEIGHT/2-2);
				cout << "Game Over";
				rlutil::locate(SCENEWIDTH / 2 - 10, SCENEHEIGHT/2);
				cout << "Score:" << score;
				rlutil::locate(SCENEWIDTH / 2 - 10, SCENEHEIGHT/2+2);
				cout << "Press Enter To Quit...\n";
				rlutil::setColor(0);
				cin.ignore();
				for (int k = 0; k < MAXENEMYSHIP; k++) {
					if (enemyShips[k].lives > 0)
					{
						enemyShips[k].EraseShip();
						enemyShips[k].lives = 0;
					}
				}
				for (int u = 0; u < mainShip.MAXBULLET; u++) {
					if (mainShip.bullets[u].live)
					{
						mainShip.bullets[u].EraseBullet();
						mainShip.bullets[u].live = false;
					}
				}
				playing = false;
				rlutil::setColor(7);

			}
		}
	}
}
void Game::CreatePrize() {
	if (lastCreatePrize <= 0)
	{
		if (!prize.live)
		{
			prize.setData(
				SCENEWIDTH - 1,//x
				2 + (rand() % (SCENEHEIGHT - 2)),//y
				true//live
			);
		}
		lastCreatePrize = PRIZERATE;
	}
	else
	{
		lastCreatePrize = lastCreatePrize - SCENEREFRESHRATE;
	}
}
void Game::DrawPrize() {
	if (prize.live) {
		prize.DrawPrize();
	}
}
void Game::ErasePrize() {
	if (prize.live) {
		prize.ErasePrize();
	}
}
void Game::PushPrize() {
	if (prize.live) {
		if (prize.x<=2)
		{
			prize.ErasePrize();
			prize.live = false;
		}
		else {
			prize.x--;
		}
	}
}
void Game::CatchPrize() {
	if (prize.live) {
		if (DistanceBetweenTwoPoints(mainShip.x, mainShip.y, prize.x, prize.y) - 1.5 < mainShip.r)
		{
			prize.live = false;
			prize.ErasePrize();
			score = score + prize.prizeValue;
		}
	}
}

