
#include "pch.h"
#include "Game.h"

void ChangeConsoleSize(int width, int height) {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); 
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}


int main()
{
	ChangeConsoleSize(850, 450);//Konsol boyutunu ayarlama
	Game game; // Oyun oluştur
	
}

