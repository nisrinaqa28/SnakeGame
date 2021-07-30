#include "../SnakeAlpha.h"
extern obstacle *head_obs;
extern segment *ptr_body;
extern DataPemain dt;
extern int BatasScore;
extern int ScoreMakanan;
extern int Level;	// untuk keberadaan level di mode normal

/** Initial State dan Operasi Modul */

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

void gameToWin(int &nextLevel, bool &levelUp, int &survivalWon){
	// naik level di mode normal
		bool win = false;
		int x,y;
		if(GameMode == NORMAL_MODE){	
			switch(Level){
				case LEVEL_1:{
					levelUp = (nextLevel == 5) ? true : false;
					break;
				}
				case LEVEL_2:{
					levelUp = (nextLevel == 10) ? true : false;
					break;
				}
				case LEVEL_3:{
					if(nextLevel == 15){
						game = false;
						Level = 1;
						pop_all();
						cleardevice();
						initwindow(BATAS_KANAN,BATAS_BAWAH, "WIN");	// Area console grafik
						clearviewport();
						readimagefile("Image\\Arena\\win.jpg",0,0,BATAS_KANAN,BATAS_BAWAH);
						mciSendString("close mp3",NULL,0,NULL);	
						mciSendString("open \"Music\\WIN.mp3\" type mpegvideo alias mp3",NULL,0,NULL);
    					mciSendString("play mp3",NULL,0,NULL);
						while (!win){
							getmouseclick(WM_LBUTTONDOWN, x, y);
							if ((x>520)&&(x<840)&&(y>515)&&(y<660)){
								menu();
								win = true;
							}	
						}
					}
					break;
				}
				
			}
			if(levelUp){		
				Level++;
				delay(500);
				cleardevice();
				delay(100);
				pop_all();
				delay(750);
				cleardevice();
				normalMode();
			}
		}else{
			if(GameMode == SURVIVAL_MODE){
				if(survivalWon == ((ARENA_KANAN*ARENA_BAWAH)/(BLOK*BLOK)) - (INITIAL_SNAKE_SIZE)){	// jika map sudah tertutup dengan semua segment snake, maka if(true)
					game = false;
					pop_all();
					cleardevice();
					initwindow(BATAS_KANAN,BATAS_BAWAH, "WIN");	// Area console grafik
					clearviewport();
					readimagefile("Image\\Arena\\win.jpg",0,0,BATAS_KANAN,BATAS_BAWAH);
					mciSendString("close mp3",NULL,0,NULL);	
					mciSendString("open \"Music\\WIN.mp3\" type mpegvideo alias mp3",NULL,0,NULL);
					mciSendString("play mp3",NULL,0,NULL);
					while (!win){
						getmouseclick(WM_LBUTTONDOWN, x, y);
						if ((x>520)&&(x<840)&&(y>515)&&(y<660)){
							rekapPlayer();
							win = true;
						}	
					}
				}
			}
		}
}

bool gameOver(int x, int y){
	bool gameOverCheck;
	if(GameMode == NORMAL_MODE){
			gameOverCheck = (status_collision(x,y) || hit_obs(x,y)) ? true : false;
			mciSendString("close mp3",NULL,0,NULL);	
			mciSendString("open \"Music\\Gameover.mp3\" type mpegvideo alias mp3",NULL,0,NULL);
			mciSendString("play mp3",NULL,0,NULL);
		}else{
			if(GameMode == SURVIVAL_MODE){
				gameOverCheck = (status_collision(x,y) || check_wall_through()) ? true : false;
				mciSendString("close mp3",NULL,0,NULL);	
				mciSendString("open \"Music\\Gameover.mp3\" type mpegvideo alias mp3",NULL,0,NULL);
				mciSendString("play mp3",NULL,0,NULL);
			}
		}
	return gameOverCheck;
}

void specialFoodnSnake(bool &foodIsGone, int &sumGone, int xFood, int yFood, int x, int y){
	if(foodIsGone){	// untuk makanan spesial hilang (survivalmode)
			sumGone++;
			if(sumGone % 25 == 0 && xFood != x && yFood != y){	// jika melebihi 25 pergerakan snake, maka food ilang
				foodIsGone = false;
				readimagefile("Image\\Snake\\bg.jpg", xFood*BLOK, yFood*BLOK, xFood*BLOK+IMAGE ,yFood*BLOK+IMAGE);
			}else{
				if(xFood == x && yFood == y){	// jika special food dimakan
					foodIsGone = false;
					mciSendString("close mp3",NULL,0,NULL);	
					mciSendString("open \"Music\\Makan.mp3\" type mpegvideo alias mp3",NULL,0,NULL);
    				mciSendString("play mp3",NULL,0,NULL);
					ScoreMakanan = ScoreMakanan + 10;
					TampilScore(dt, ScoreMakanan, 0, 0);
				}
			}
		}
}

void initial_snake(int snakeSize){
	int i;
	for(i = 10; i < snakeSize + BLACKSPRITE + 10; i++){
		push(i,10);	// Push snake beserta koordinat pada consolenya
	}
}
	
void coordinate_modifier(int &x, int &y){
	switch(arrow){
		case VK_LEFT:{
			x = head->xCoordinate - 1;
			y = head->yCoordinate;
			break;
		}
		case VK_RIGHT:{
			x = head->xCoordinate + 1;
			y = head->yCoordinate;
			break;
		}
		case VK_UP:{
			x = head->xCoordinate;
			y = head->yCoordinate - 1;
			break;
		}
		case VK_DOWN:{
			x = head->xCoordinate;
			y = head->yCoordinate + 1;
			break;
		}
	}	
}

void push(int x, int y){
	segment *node = (segment*)malloc(sizeof(segment));
	node->next = NULL;
	node->prev = NULL;
	node->headArrow = arrow;
	node->xCoordinate = x;
	node->yCoordinate = y;
	
	// Jika snake (linked list) masih kosong
	if(head == NULL){
		head = tail = node;
	}
	// Jika snake sudah ada, pasangkan segment ke head
	else{
		node->next = head;
		head->prev = node;
		head = node;
	}
}

void pop(){
	if(head == tail){
		free(head);
		head = tail = NULL;
	}
	else{			
		tail = tail->prev; 
        free(tail->next);
        tail->next = NULL;
	}
}

void pop_all(){
	while(head != NULL){
		pop();
	}
	if(GameMode == NORMAL_MODE){
		while(head_obs != NULL){
			pop_obs();
		}
	}
}

void display(){
	bool check = true;
	segment *ptr = head;
	while(ptr != NULL){
		if(check){
			readimagefile(snakeHead, ptr->xCoordinate*BLOK, ptr->yCoordinate*BLOK, ptr->xCoordinate*BLOK+IMAGE ,ptr->yCoordinate*BLOK+IMAGE);
			check = false;
			ptr_body = head->next;
		}
		else{	
			if(ptr->next == NULL){
				readimagefile("Image\\Arena\\kolom3.jpg", ptr->xCoordinate*BLOK, ptr->yCoordinate*BLOK, ptr->xCoordinate*BLOK+IMAGE, ptr->yCoordinate*BLOK+IMAGE);
			}
			else{
				if(ptr->next->next == NULL){
					ekor();
					readimagefile(snakeTail, ptr_body->xCoordinate*BLOK, ptr_body->yCoordinate*BLOK, ptr_body->xCoordinate*BLOK+IMAGE, ptr_body->yCoordinate*BLOK+IMAGE);
				}
				else{
					body();
					readimagefile(snakeBody, ptr->xCoordinate*BLOK, ptr->yCoordinate*BLOK, ptr->xCoordinate*BLOK+IMAGE, ptr->yCoordinate*BLOK+IMAGE);
					ptr_body = ptr_body->next;
				}
			}
		}
		wall_through(&ptr);
		ptr = ptr->next;
	}
}

void gameplay(){
	srand(time(NULL));
	music();
	inisialisasi_image_snake();																	
	int xFood, yFood;	// wadah koordinat spesial food, kegunaannya untuk print background ketika sudah saatnya makanan spesial harus dihilangkan
	int sumFood = 0;	// menampilkan makanan spesial setiap 5x snake makan makanan biasa
	int sumGone;	// untuk mmenghitung makanan spesial agar hilang jika sudah teralalu lama
	bool foodIsGone = false;	// untuk menghilangkan makanan spesial
	int nextLevel = 0;	// untuk snake bisa naik level
	bool levelUp = false; // untuk snake bisa naik level (untuk level 1 dan level 2)
	int survivalWon = 0; // untuk game berakhir, ada yg menang di survival mode
	bool gameOverCheck = false;
	if(Level == 1){	// ngecek kalo game nya baru mulai score nya di nol kan lagi
		BatasScore = 0;																					
		ScoreMakanan = 0;
	}																		
	initial_snake(INITIAL_SNAKE_SIZE);	// panjang segment awal sepanjang snakeSize
	int x, y;	// Wadah koordinat ular
	TampilScore(dt, ScoreMakanan, 0, 0);
	if(GameMode == NORMAL_MODE){
		switch(Level){
			case LEVEL_1:{
				coordinate_obs_1();
				break;
			}
			case LEVEL_2:{
				coordinate_obs_2();
				break;
			}
			case LEVEL_3:{
				coordinate_obs_3();
				break;
			}
		}
		display_obs();		
	}
	food_coordinate();
	food_display();
	int musicTime = 0;
	while(game){
		musicTime++;
		key_state();
		coordinate_modifier(x,y);
		displayGameOver(x, y);
		foodnSnake(sumFood, xFood, yFood, x, y, foodIsGone, sumGone, nextLevel, survivalWon);
		
		push(x, y);
		display();
		specialFoodnSnake(foodIsGone, sumGone, xFood, yFood, x, y);
		gameToWin(nextLevel, levelUp, survivalWon);
		delay(50);
		if(musicTime >= 750){	
			music();
			musicTime = 0;
		}
	}
}

void rekapPlayer(){
	bool input = false;
	int x,y;
	DataPemain dataPemain;
	initwindow(BATAS_KANAN,BATAS_BAWAH, "GAME OVER");	// Area console grafik
	readimagefile("Image\\Arena\\input.jpg",0,0,BATAS_KANAN,BATAS_BAWAH);
	TampilScore(dt, ScoreMakanan, 230, 390);
	inputName(dataPemain);
	dataPemain.FileScore = ScoreMakanan;
	FILE *fp;

	fp = fopen("score.txt", "a+");
	if (fp == NULL)
		printf("gagal\n");
	else {
		fprintf(fp, "%s\t%d\n", dataPemain.NamaPemain, dataPemain.FileScore);
		printf("file text: %s %d\n", dataPemain.NamaPemain, dataPemain.FileScore);
		printf("data tersimpan\n");
	}
	
	fclose(fp);
	
	while (!input){
		getmouseclick(WM_LBUTTONDOWN, x, y);
		if ((x>555)&&(x<805)&&(y>595)&&(y<710)){
			menu();
			input = true;
		}	
	}
}

void convertRekapFileToBST(bst *(&root)){
	int i = 0;
	int cnt;
	FILE *fr;
	DataPemain dataPemain;
	
	fr = fopen("score.txt", "r");
	if (fr == NULL) {
		printf("file tidak ada\n");
	}
	else {
		while (1) {
			cnt = fscanf(fr, "%s\t%d\n", &dataPemain.NamaPemain, &dataPemain.FileScore);
			if (cnt == -1)
				break;
			bstInsert(root, dataPemain);
		}
	}
	fclose(fr);
	
	
	printf("konversi rekap file ke BST sukses\n");
}

void printBarLevel(int nextLevel) {
	const int color[] = {GREEN, LIGHTGREEN, YELLOW, LIGHTRED, RED};
	int scale1 = 0,
		scale2 = 0,
		scale3 = 0;
	setcolor(BLACK);
	switch (Level) {
		case LEVEL_1: {
			scale1 = nextLevel - 1;
			rectangle(650+(scale1*50), 80, 700+(scale1*50), 130);
			setfillstyle(SOLID_FILL, color[scale1]);
			floodfill(651+(scale1*50), 81, BLACK);
			break;
		}
		case LEVEL_2: {
			if (nextLevel % 2 == 0) {
				scale2 = (nextLevel / 2) - 1;
				rectangle(650+(scale2*50), 80, 700+(scale2*50), 130);
				setfillstyle(SOLID_FILL, color[scale2]);
				floodfill(651+(scale2*50), 81, BLACK);
			}
			break;
		}
		case LEVEL_3: {
			if (nextLevel % 3 == 0) {
				scale3 = (nextLevel / 3) - 1;
				rectangle(650+(scale3*50), 80, 700+(scale3*50), 130);
				setfillstyle(SOLID_FILL, color[scale3]);
				floodfill(651+(scale3*50), 81, BLACK);
			}
			break;
		}
	}
	
}

bst *bstAlloc(DataPemain x) {
	bst *newNode;
	newNode = (bst *)malloc(sizeof(bst));
	if (newNode != NULL) {
		strcpy(newNode->dataPemain.NamaPemain, x.NamaPemain);
		newNode->dataPemain.FileScore = x.FileScore;
		newNode->left = newNode->right = NULL;
		newNode->height = 1;
	}
	return newNode;
}

void bstInsert(bst *(&root), DataPemain node) {
	if (root == NULL)
		root = bstAlloc(node);
	else if (node.FileScore > root->dataPemain.FileScore)
		bstInsert(root->right, node);
	else 
		bstInsert(root->left, node);
		
	// calculate balance factor for each node
	root->height = MAX(getHeight(root->left), getHeight(root->right)) + 1;
	int bFactor = getBalanceFactor(root);
	// if violoation, then rotate
	if (bFactor > 1 && node.FileScore < root->left->dataPemain.FileScore) { // LL bf = 2
		root = rightRotate(root);
	}
	if (bFactor < -1 && node.FileScore > root->right->dataPemain.FileScore) { // RR bf = -2
		root = leftRotate(root);
	}
	if (bFactor > 1 && node.FileScore > root->left->dataPemain.FileScore) { // LR bf = 2
		root->left = leftRotate(root->left);
		root = rightRotate(root);
	}
	if (bFactor < -1 && node.FileScore < root->right->dataPemain.FileScore) { // RL bf = -2
		root->right = rightRotate(root->right);
		root = leftRotate(root);
	}
	system("cls");
	bFactor = getBalanceFactor(root);
	printf("%d, bf = %d\n", root->dataPemain.FileScore, bFactor);

}

void bstDeleteTree(bst *node) {  
    if (node == NULL) 
		return;  
  
    bstDeleteTree(node->left);  
    bstDeleteTree(node->right);  
      
    free(node); 
}  
