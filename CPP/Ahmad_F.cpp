#include "../SnakeAlpha.h"

extern segment *ptr_body;
extern int Level;	// untuk keberadaan level di mode normal

/**
	Nilai awal untuk gambar bagian segment snake												*/
extern char snakeHead[];
extern char snakeBody[];
extern char snakeTail[];

/**
	Nilai awal untuk struct pointer yang menunjuk kebagian ujung-ujung segment snakenya			*/
extern segment *head;
extern segment *tail;

/**
	Variabel untuk mode game {1 : untuk mode normal, 2 : untuk mode survival}					*/
extern int GameMode;	

/**
	Variabel mengecek apabila permainan harus diberhentikan atau tetap berjalan					*/
extern bool game;
extern int arrow;


void normalMode(){						// di menu
	GameMode = NORMAL_MODE;
	arrow = VK_RIGHT;
	initwindow(BATAS_KANAN,BATAS_BAWAH, "NORMAL MODE");	// Area console grafik
	readimagefile("Image\\Arena\\kolom1.jpg", BATAS_KIRI, BATAS_ATAS, BATAS_KANAN, LAYER_BAR);
	readimagefile("Image\\Arena\\kolom2.jpg", BATAS_KIRI, BATAS_ATAS + LAYER_BAR, BATAS_KANAN, BATAS_BAWAH);
	readimagefile("Image\\Arena\\kolom3.jpg", BATAS_KIRI + BLOK_ARENA, BATAS_ATAS + LAYER_BAR + BLOK_ARENA, BATAS_KANAN - BLOK_ARENA, BATAS_BAWAH - BLOK_ARENA);
	readimagefile("Image\\Arena\\score.bmp", 170, 20, 370, 60);
	readimagefile("Image\\Arena\\soundon.gif", 1170, 20, 1230, 70);
	readimagefile("Image\\Arena\\pause.gif", 1240, 20, 1300, 70);
	readimagefile("Image\\Arena\\normal.bmp", 520, 180, 785, 210);
	readimagefile("Image\\Arena\\levelup.bmp", 670, 20, 870, 60);
	gameplay();
	pop_all();
}

void survivalMode(){					// di menu
	GameMode = SURVIVAL_MODE;
	arrow = VK_RIGHT;
	bst* root = NULL;
    stack *top = NULL;
	bool pause = false;
	int x,y;
	initwindow(BATAS_KANAN,BATAS_BAWAH, "SURVIVAL MODE");	// Area console grafik
	readimagefile("Image\\Arena\\kolom1.jpg", BATAS_KIRI, BATAS_ATAS, BATAS_KANAN, LAYER_BAR);
	readimagefile("Image\\Arena\\kolom2.jpg", BATAS_KIRI, BATAS_ATAS + LAYER_BAR, BATAS_KANAN, BATAS_BAWAH);
	readimagefile("Image\\Arena\\kolom3.jpg", BATAS_KIRI + BLOK_ARENA, BATAS_ATAS + LAYER_BAR + BLOK_ARENA, BATAS_KANAN - BLOK_ARENA, BATAS_BAWAH - BLOK_ARENA);
	readimagefile("Image\\Arena\\score.bmp", 170, 20, 370, 60);
	readimagefile("Image\\Arena\\highscore.bmp", 620, 20, 920, 60);
	readimagefile("Image\\Arena\\soundon.gif", 1170, 20, 1230, 70);
	readimagefile("Image\\Arena\\pause.gif", 1240, 20, 1300, 70);
	readimagefile("Image\\Arena\\survival.bmp", 520, 180, 785, 210);
	convertRekapFileToBST(root);
	convertInorderToStack(root, top);
	
	DataPemain dataPemain;
	if (top != NULL) dataPemain = getDataHighestScore(top);
	else dataPemain.FileScore = 0;
	TampilScore(dataPemain, dataPemain.FileScore, 0, 500);
	stackPopAll(top);
	bstDeleteTree(root);
	/*while (!pause){
    	getmouseclick(WM_LBUTTONDOWN, x, y);

    	if((x>1250)&&(x<1310)&&(y>20)&&(y<70)){
    		readimagefile("Image\\Arena\\paused.jpg", 0, 0, BATAS_KANAN, BATAS_BAWAH);
    		if((x>480)&&(x<895)&&(y>320)&&(y<420)){
    			pause = true;
			}else if ((x>480)&&(x<895)&&(y>490)&&(y<590)){
				menu();
				pause = true;
			}
        }
	}*/
	gameplay();
	cleardevice();
	getchar();
	pop_all();
}

void inisialisasi_image_snake(){		// di gameplay
	strcpy(snakeHead,"Image\\Snake\\kepala_kanan.bmp");
	strcpy(snakeBody,"Image\\Snake\\kepala_kanan.bmp");
	strcpy(snakeTail,"Image\\Snake\\ekor_kiri.bmp");
}	

bool check_wall_through(){				// di gameplay
	segment *ptr = head;
	bool status = false;
	if(ptr->xCoordinate*BLOK + IMAGE > BATAS_KANAN - BLOK_ARENA){
		status = true;
	}else{
		if(ptr->xCoordinate*BLOK < BATAS_KIRI + BLOK_ARENA){
			status = true;
		}
		else{
			if(ptr->yCoordinate*BLOK + BLOK_ARENA > BATAS_BAWAH - BLOK_ARENA){
				status = true;
			}
			else{
				if(ptr->yCoordinate*BLOK < BATAS_ATAS + LAYER_BAR + BLOK_ARENA){
					status = true;
				}
			}
		}
	}
	return status;
}

void key_state(){
	if(GetAsyncKeyState(VK_RIGHT) && arrow != VK_LEFT){
		arrow = VK_RIGHT;
		strcpy(snakeHead, "Image\\Snake\\kepala_kanan.bmp");
	}
	else if(GetAsyncKeyState(VK_LEFT) && arrow != VK_RIGHT){
		arrow = VK_LEFT;
		strcpy(snakeHead, "Image\\Snake\\kepala_kiri.bmp");
	}
	else if (GetAsyncKeyState(VK_UP) && arrow != VK_DOWN){
		arrow = VK_UP;
		strcpy(snakeHead, "Image\\Snake\\kepala.bmp");
	}
	else if(GetAsyncKeyState(VK_DOWN) && arrow != VK_UP){
		arrow = VK_DOWN;
		strcpy(snakeHead, "Image\\Snake\\kepala_bawah.bmp");
	}
}

void body(){
	switch(ptr_body->headArrow){
		case VK_RIGHT : {
			strcpy(snakeBody, "Image\\Snake\\body1.bmp");
			break;
		}
		case VK_LEFT : {
			strcpy(snakeBody, "Image\\Snake\\body1.bmp");
			break;
		}
		case VK_UP :{
			strcpy(snakeBody, "Image\\Snake\\body.bmp");
			break;
		}
		case VK_DOWN : {
			strcpy(snakeBody, "Image\\Snake\\body.bmp");
			break;
		}
	}
	if (ptr_body->prev->xCoordinate != ptr_body->next->xCoordinate && ptr_body->prev->yCoordinate != ptr_body->next->yCoordinate){
		if (ptr_body->prev->headArrow == VK_RIGHT && ptr_body->headArrow == VK_UP || ptr_body->prev->headArrow == VK_DOWN && ptr_body->headArrow == VK_LEFT)
			strcpy(snakeBody, "Image\\Snake\\belok_bawah.bmp");
		else if(ptr_body->prev->headArrow == VK_RIGHT && ptr_body->headArrow == VK_DOWN || ptr_body->prev->headArrow == VK_UP && ptr_body->headArrow == VK_LEFT)
			strcpy(snakeBody, "Image\\Snake\\belok_kanan.bmp");
		else if(ptr_body->prev->headArrow == VK_LEFT && ptr_body->headArrow == VK_UP || ptr_body->prev->headArrow == VK_DOWN && ptr_body->headArrow == VK_RIGHT)
			strcpy(snakeBody, "Image\\Snake\\belok_kiri.bmp");
		else if(ptr_body->prev->headArrow == VK_LEFT && ptr_body->headArrow == VK_DOWN || ptr_body->prev->headArrow == VK_UP && ptr_body->headArrow == VK_RIGHT)
			strcpy(snakeBody, "Image\\Snake\\belok_atas.bmp");
	}
	
}

void ekor(){
	segment *ptr;
	ptr = tail;
	switch(ptr->prev->prev->headArrow){
		case VK_RIGHT : {
			strcpy(snakeTail, "Image\\Snake\\ekor_kiri.bmp");
			break;
		}
		case VK_LEFT : {
			strcpy(snakeTail, "Image\\Snake\\ekor_kanan.bmp");
			break;
		}
		case VK_UP : {
			strcpy(snakeTail, "Image\\Snake\\ekor_bawah.bmp");
			break;
		}
		case VK_DOWN : {
			strcpy(snakeTail, "Image\\Snake\\ekor.bmp");
			break;
		}
	}
}

void wall_through(segment **ptr){

	if ((*ptr)->xCoordinate*BLOK + IMAGE > BATAS_KANAN  - BLOK_ARENA){
		if (GameMode  == NORMAL_MODE){		// Bisa nembus untuk gameplay normal mode
			(*ptr)->xCoordinate = BLOK_ARENA / BLOK;	
		}
		readimagefile("Image\\Arena\\kolom2.jpg", BATAS_KANAN - BLOK_ARENA, BATAS_ATAS + LAYER_BAR, BLOK_ARENA, BATAS_BAWAH);
	}
	if((*ptr)->xCoordinate*BLOK < BATAS_KIRI + BLOK_ARENA){
		if (GameMode == NORMAL_MODE){
			(*ptr)->xCoordinate = (BATAS_KANAN - BLOK_ARENA - BLOK)/BLOK;
		}
		readimagefile("Image\\Arena\\kolom2.jpg", BATAS_KIRI, BATAS_ATAS + LAYER_BAR, BATAS_KIRI + BLOK_ARENA, BATAS_BAWAH);
	}
	if ((*ptr)->yCoordinate * BLOK + BLOK_ARENA > BATAS_BAWAH - BLOK_ARENA){
		if(GameMode == NORMAL_MODE){
			(*ptr)->yCoordinate = (BATAS_ATAS + LAYER_BAR + BLOK_ARENA)/BLOK;
		}
		readimagefile("Image\\Arena\\kolom2.jpg", BATAS_KIRI, BATAS_BAWAH - BLOK_ARENA, BATAS_KANAN, BATAS_BAWAH);
	}
	
	if ((*ptr)->yCoordinate * BLOK < BATAS_ATAS + LAYER_BAR + BLOK_ARENA){
		if (GameMode == NORMAL_MODE){
			(*ptr)->yCoordinate = (BATAS_BAWAH - IMAGE - BLOK_ARENA)/BLOK;
		}
		readimagefile("Image\\Arena\\kolom2.jpg", BATAS_KIRI, LAYER_BAR, BATAS_KANAN, LAYER_BAR + BLOK_ARENA);
		if (GameMode == NORMAL_MODE) readimagefile("Image\\Arena\\normal.bmp", 520, 180, 785, 210);
		if (GameMode == SURVIVAL_MODE) readimagefile("Image\\Arena\\survival.bmp", 520, 180, 785, 210);
	}
	
}

bool status_collision(int x, int y){
	segment *ptr = head;
	while(ptr->next != NULL){
		if(ptr->xCoordinate == x && ptr->yCoordinate == y){
			return TOUCHING;
		}
		ptr = ptr->next;
	}
	return NOTTOUCHING;
}

void displayGameOver(int x, int y){
	int i;
	bool gameover = false;
	if(gameOver(x,y)){
			for(i = 0; i < 5; i++){
				strcpy(snakeHead, "Image\\Snake\\bg.jpg");
				strcpy(snakeBody, "Image\\Snake\\bg.jpg");
				strcpy(snakeTail, "Image\\Snake\\bg.jpg");
				display();
			}
			Level = 1;
			game = false;
			strcpy(snakeHead, "Image\\Snake\\bg.jpg");
			pop_all();
			cleardevice();
			initwindow(BATAS_KANAN,BATAS_BAWAH, "GAME OVER");	// Area console grafik
			clearviewport();
			readimagefile("Image\\Arena\\gameover.jpg",0,0,BATAS_KANAN,BATAS_BAWAH);
			while (!gameover){
				getmouseclick(WM_LBUTTONDOWN, x, y);
				if ((x>520)&&(x<840)&&(y>515)&&(y<660)){
					if(GameMode == SURVIVAL_MODE){
						closegraph();
						rekapPlayer();
					}else if (GameMode == NORMAL_MODE){
						menu();
					}
					gameover = true;
				}	
			}																			
		}
}


