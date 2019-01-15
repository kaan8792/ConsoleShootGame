#pragma once

#include <Windows.h>
#include "MainShip.h"
#include "EnemyShip.h"
#include "Prize.h"

class Game
{
public:
	bool playing; //Oyun d�ng�s� aktif mi
	const char	UPKEY = 'W';		//Yukar� hareket i�in tu� se�imi.
	const char	DOWNKEY = 'S';		//A�a�� hareket i�in tu� se�imi.
	const char	SHOOTKEY = 'K';		//Ate� etmek i�in tu� se�imi.
	const char	RESETKEY = 'R';		//Oyunu yeniden aslatan tus.
	const char	BORDERCHARACTER = 219; //S�n�r �izgisi karakteri.
	const int SCENEHEIGHT = rlutil::trows() - 2; //Sahne y�ksekli�i
	const int SCENEWIDTH = rlutil::tcols() - 1;  //Sahne geni�li�i
	const int SCENEREFRESHRATE = 50;   //Kac milisaniyede bir sahne yenilenecek bir bak�ma fps sabitleme. 1 sn 1000ms oldu�una g�re 1000/refreshrate = fps dir.

	MainShip mainShip;

	static const int MAXENEMYSHIP = 8; //Sahnedeki max d��man say�s�.
	EnemyShip enemyShips[MAXENEMYSHIP];//D��man gemilerinin dizisi.
	const int ENEMYSHIPR = 1; // D��man gemilerinin yar��ap�.
	const int MAXLIVESENEMY = 3; //D��man�n max can�.
	const int CREATEENEMYRATE = 500; //Yeni d��man olu�turmak i�in ge�emesi gereken zaman.
	const char ENEMYCHARACTER = 178; //D��manlar�n sahnedeki karakterleri.
	int lastCreateEnemy = CREATEENEMYRATE; // Son d��mandan beri ge�en s�re.

	char keys[256]; //Hangi tu�a bas�ld���n� tutan dizi.

	int score; // Skoru tutan de�i�ken.

	Prize prize;	//�d�l olu�turmak.
	const int PRIZERATE = 2000;//�d�l ka� saniyede bir olu�aca��.
	int lastCreatePrize = PRIZERATE; //�d�l en son ne zaman olu�tu.
	

	Game();
	virtual ~Game();

	void GameLoop();	   //Oyun d�ng�s�.
	void ReadKeypad();     //Tu�a bas�ld���n� diziye yazan fonksiyon
	void KeypadControl();  //Tu�a bas�lm��sa gerekli g�revi yerine getiren fonksiyon
	void NewGame();        //Yeni oyun ba�lat.
	void DrawBorder();     //Kenarl�klar� �iz.
	void DrawMainShip();   //Gemiyi sahneye yerke�tir.
	void DrawBullet();     //Mermileri sahneye �iz.
	void PushBullet();     //Uygunsa mermileri ilerlet.
	void EraseBullets();   //Mermileri ekrandan siler.
	void CreateEnemyShip();//Uygunsa D��man olu�tur.
	void DrawEnemyShip();  //D��manlar� �iz
	void PushEnemyShip();  //D��manlar� ittir.
	void EraseEnemyShips();//D��man gemileri ekrandan siler.
	double DistanceBetweenTwoPoints(int, int, int, int); //�ki nokta aras�ndaki uzakl�k.
	void ItIsHit();        //Mermi D��man u�a��n� vurdu mu? Vurduysa yap�lacaklar.
	void ShipCollision();  //Main ship ile enemy ship �arp��mas�n� kontrol et.
	void CreatePrize();	   //Uygunsa �d�l olu�tur.
	void DrawPrize();      //�d�l� ekrana �iz.
	void ErasePrize();     //�d�l� ekrandan sil.
	void PushPrize();	   //�d�l� ittir.
	void CatchPrize();     //�d�l� yakalad� m�?
};

