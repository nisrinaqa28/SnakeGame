#include "SnakeAlpha.h"

obstacle *head_obs;
segment *ptr_body;
DataPemain dt;
DataPemain dataPemain;
DataPemain dataTop4[4];
char obstaclePic[] = "Image\\Obstacle\\obstacle.jpg";
int BatasScore = 0;
int ScoreMakanan = 0;
int Level = 1;	// untuk keberadaan level di mode normal

/** Initial State dan Operasi Modul */

/**
	Nilai awal untuk gambar bagian segment snake												*/
char snakeHead[] = "Image\\Snake\\kepala_kanan.bmp";
char snakeBody[] = "Image\\Snake\\body1.bmp";
char snakeTail[] = "Image\\Snake\\ekor_kiri.bmp";

/**
	Nilai awal untuk struct pointer yang menunjuk kebagian ujung-ujung segment snakenya			*/
segment *head = NULL;
segment *tail = NULL;

/**
	Variabel untuk mode game {1 : untuk mode normal, 2 : untuk mode survival}					*/
int GameMode;	

/**
	Variabel mengecek apabila permainan harus diberhentikan atau tetap berjalan					*/
bool game;
int arrow;
foods food;

int main(){
	initwindow(BATAS_KANAN,BATAS_BAWAH, "SNAKE ALPHA");	// Area console grafik
	loadGame();
	
	return 0;
}
