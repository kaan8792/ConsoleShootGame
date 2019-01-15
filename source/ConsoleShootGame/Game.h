#pragma once

#include <Windows.h>
#include "MainShip.h"
#include "EnemyShip.h"
#include "Prize.h"

class Game
{
public:
	bool playing; //Oyun döngüsü aktif mi
	const char	UPKEY = 'W';		//Yukarý hareket için tuþ seçimi.
	const char	DOWNKEY = 'S';		//Aþaðý hareket için tuþ seçimi.
	const char	SHOOTKEY = 'K';		//Ateþ etmek için tuþ seçimi.
	const char	RESETKEY = 'R';		//Oyunu yeniden aslatan tus.
	const char	BORDERCHARACTER = 219; //Sýnýr çizgisi karakteri.
	const int SCENEHEIGHT = rlutil::trows() - 2; //Sahne yüksekliði
	const int SCENEWIDTH = rlutil::tcols() - 1;  //Sahne geniþliði
	const int SCENEREFRESHRATE = 50;   //Kac milisaniyede bir sahne yenilenecek bir bakýma fps sabitleme. 1 sn 1000ms olduðuna göre 1000/refreshrate = fps dir.

	MainShip mainShip;

	static const int MAXENEMYSHIP = 8; //Sahnedeki max düþman sayýsý.
	EnemyShip enemyShips[MAXENEMYSHIP];//Düþman gemilerinin dizisi.
	const int ENEMYSHIPR = 1; // Düþman gemilerinin yarýçapý.
	const int MAXLIVESENEMY = 3; //Düþmanýn max caný.
	const int CREATEENEMYRATE = 500; //Yeni düþman oluþturmak için geçemesi gereken zaman.
	const char ENEMYCHARACTER = 178; //Düþmanlarýn sahnedeki karakterleri.
	int lastCreateEnemy = CREATEENEMYRATE; // Son düþmandan beri geçen süre.

	char keys[256]; //Hangi tuþa basýldýðýný tutan dizi.

	int score; // Skoru tutan deðiþken.

	Prize prize;	//Ödül oluþturmak.
	const int PRIZERATE = 2000;//Ödül kaç saniyede bir oluþacaðý.
	int lastCreatePrize = PRIZERATE; //Ödül en son ne zaman oluþtu.
	

	Game();
	virtual ~Game();

	void GameLoop();	   //Oyun döngüsü.
	void ReadKeypad();     //Tuþa basýldýðýný diziye yazan fonksiyon
	void KeypadControl();  //Tuþa basýlmýþsa gerekli görevi yerine getiren fonksiyon
	void NewGame();        //Yeni oyun baþlat.
	void DrawBorder();     //Kenarlýklarý çiz.
	void DrawMainShip();   //Gemiyi sahneye yerkeþtir.
	void DrawBullet();     //Mermileri sahneye çiz.
	void PushBullet();     //Uygunsa mermileri ilerlet.
	void EraseBullets();   //Mermileri ekrandan siler.
	void CreateEnemyShip();//Uygunsa Düþman oluþtur.
	void DrawEnemyShip();  //Düþmanlarý çiz
	void PushEnemyShip();  //Düþmanlarý ittir.
	void EraseEnemyShips();//Düþman gemileri ekrandan siler.
	double DistanceBetweenTwoPoints(int, int, int, int); //Ýki nokta arasýndaki uzaklýk.
	void ItIsHit();        //Mermi Düþman uçaðýný vurdu mu? Vurduysa yapýlacaklar.
	void ShipCollision();  //Main ship ile enemy ship çarpýþmasýný kontrol et.
	void CreatePrize();	   //Uygunsa ödül oluþtur.
	void DrawPrize();      //Ödülü ekrana çiz.
	void ErasePrize();     //Ödülü ekrandan sil.
	void PushPrize();	   //Ödülü ittir.
	void CatchPrize();     //Ödülü yakaladý mý?
};

