#ifndef __Snake_Alpha_H
#define __Snake_Alpha_H

/*
	Header
*/
#include <graphics.h>
#include <time.h>
#include <mmsystem.h>
//#include<ctime>
/*
	Window Game
*/
#define IMAGE 30
#define BLOK 30
#define BATAS_KIRI 0
#define BATAS_KANAN 1350
#define BATAS_ATAS 0
#define BATAS_BAWAH 780

/*
	Ukuran Arena
*/
#define LAYER_BAR 180
#define BLOK_ARENA 30
#define ARENA_KANAN 1290
#define ARENA_BAWAH 540

/*
	Inisialisasi Score
*/
#define DIGIT_SATUAN 3
#define DIGIT_PULUHAN 2
#define DIGIT_RATUSAN 1
#define DIGIT_RIBUAN 0

/*
	Keadaan Saat
*/
#define TOUCHING true
#define NOTTOUCHING false
#define BLACKSPRITE 1
#define NORMAL_MODE 1
#define SURVIVAL_MODE 2
#define INITIAL_SNAKE_SIZE 3
#define LEVEL_1 1
#define LEVEL_2 2
#define LEVEL_3 3

/*
	Read Keyboard
	
*/
#define KEY_A 97
#define KEY_B 98
#define KEY_C 99
#define KEY_D 100
#define KEY_E 101
#define KEY_F 102
#define KEY_G 103
#define KEY_H 104
#define KEY_I 105
#define KEY_J 106
#define KEY_K 107
#define KEY_L 108
#define KEY_M 109
#define KEY_N 110
#define KEY_O 111
#define KEY_P 112
#define KEY_Q 113
#define KEY_R 114
#define KEY_S 115
#define KEY_T 116
#define KEY_U 117
#define KEY_V 118
#define KEY_W 119
#define KEY_X 120
#define KEY_Y 121
#define KEY_Z 122
#define BACKSPACE 0x8
#define ENTER 0xD
#define SPACE 32

#define MAX(a,b) ((a > b) ? a : b)

/*
	Struktur Data
*/

/** Deklarasi Variabel dan Prototype */


/**
	Struktur untuk menampung data tiap segment dari snake													*/
struct segment{
	int xCoordinate; 
	int yCoordinate;
	int headArrow;
	segment *next, *prev;
};

/**
	Variabel global sebagai temporary variabel segement snake												*/


/**
	Variabel global sebagai arah dari snake pada saat input keyboard (GetAsyncKeyState) 					*/


/**
	Struktur untuk menampung data makanan																	*/
struct foods{
	int xCoordinate;
	int yCoordinate;
};


/**
	Struktur untuk menampung data koodinat obstacle pada NORMAL_MODE										*/
struct obstacle{
	int xCoordinate;
	int yCoordinate;
	obstacle *next;
};


/**
	Sruktur untun menampung data pemain ketika gameplay														*/
struct DataPemain{
	char NamaPemain[9];
	int ScoreAkhir[3];
	int FileScore;
};


/**
	Struktur sorting score pemain																			*/
struct bst{
	DataPemain dataPemain;
	int height;
	bst *left,
		*right;
};

struct stack{
	DataPemain dataPemain;
	stack *next;
};

/*
	Header Kelompok
*/
#include "Header\\Ahmad_F.h"
#include "Header\\Dafi_M.h"
#include "Header\\Hadi_A.h"
#include "Header\\M_Alfat.h"
#include "Header\\Nisrina_Q.h"
#include "Header\\Pramestya_Y.h"


#endif
