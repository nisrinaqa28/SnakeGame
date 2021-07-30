#include "../SnakeAlpha.h"
extern DataPemain dt;
extern int ScoreMakanan;

/**
	Variabel untuk mode game {1 : untuk mode normal, 2 : untuk mode survival}					*/
extern int GameMode;	
extern foods food;

void food_coordinate(){
	if(GameMode == SURVIVAL_MODE){
		do{
			food.xCoordinate = (rand() % (BATAS_KANAN - BLOK_ARENA - BLOK_ARENA)/ BLOK) + BLOK_ARENA/BLOK;
			food.yCoordinate = (rand() % (BATAS_BAWAH - LAYER_BAR - BLOK_ARENA - BLOK_ARENA)/BLOK) + (LAYER_BAR + BLOK_ARENA)/BLOK;
		}while(status_collision(food.xCoordinate, food.yCoordinate));
	}else{
		if(GameMode == NORMAL_MODE){
			do{
				food.xCoordinate = (rand() % (BATAS_KANAN - BLOK_ARENA - BLOK_ARENA)/ BLOK) + BLOK_ARENA/BLOK;
				food.yCoordinate = (rand() % (BATAS_BAWAH - LAYER_BAR - BLOK_ARENA - BLOK_ARENA)/BLOK) + (LAYER_BAR + BLOK_ARENA)/BLOK;
			}while((status_collision(food.xCoordinate, food.yCoordinate)) || (hit_obs(food.xCoordinate, food.yCoordinate)));
		}
	}
	if(food.xCoordinate < (IMAGE + BLOK_ARENA)/BLOK || 
	   food.xCoordinate > (BATAS_KANAN - BLOK_ARENA - IMAGE)/BLOK || 
	   food.yCoordinate > (BATAS_BAWAH - IMAGE - BLOK_ARENA - IMAGE)/BLOK || 
	   food.yCoordinate < (BATAS_ATAS + LAYER_BAR + BLOK_ARENA + IMAGE)/BLOK){
		food_coordinate();
	}
} 

void food_display(){
	readimagefile("Image\\Food\\telur.bmp", food.xCoordinate*BLOK, food.yCoordinate*BLOK, food.xCoordinate*BLOK+IMAGE ,food.yCoordinate*BLOK+IMAGE);
}

void special_food_display(){
	readimagefile("Image\\Food\\daging.gif", food.xCoordinate*BLOK, food.yCoordinate*BLOK, food.xCoordinate*BLOK+IMAGE ,food.yCoordinate*BLOK+IMAGE);
}

void foodnSnake(int &sumFood, int &xFood, int &yFood, int x, int y, bool &foodIsGone, int &sumGone, int &nextLevel, int &survivalWon){
	if(food.xCoordinate == x && food.yCoordinate == y){	// jika koordinat kepala snake sama dengan makanan normal, maka tidak usah di pop(menghilangkan satu segment)
			if(GameMode == SURVIVAL_MODE){
				sumFood = sumFood + 1;
				if(sumFood % 5 == 0){
					food_coordinate();
					xFood = food.xCoordinate;
					yFood = food.yCoordinate;
					special_food_display();
					foodIsGone = true;
					sumGone = 1;
				}
			}
			food_coordinate();
			food_display();
			mciSendString("close mp3",NULL,0,NULL);	
			mciSendString("open \"Music\\Makan.mp3\" type mpegvideo alias mp3",NULL,0,NULL);
    		mciSendString("play mp3",NULL,0,NULL);
			ScoreMakanan = ScoreMakanan + 5;
			(GameMode == NORMAL_MODE) ? nextLevel++ : survivalWon++;
			if (GameMode == NORMAL_MODE) printBarLevel(nextLevel);
			// nextLevel adalh wadah untuk snake naik level di NORMAL_MODE
			// survivalWon adalah wadah untuk cek apakah map telah dipenuhi oleh segmen di SURVIVAL_MODE
			TampilScore(dt, ScoreMakanan, 0, 0);
		}else{	// jika koordinat kepala snake tidak sama dengan makanan normal, maka segmen di pop agar snake terasa seperti maju dan akan di push kembali di madul gameplay
			pop();
		}
}

stack *stackAlloc(DataPemain x) {
	stack *newNode;
	newNode = (stack *)malloc(sizeof(stack));
	if (newNode != NULL) {
		strcpy(newNode->dataPemain.NamaPemain, x.NamaPemain);
		newNode->dataPemain.FileScore = x.FileScore;
		newNode->next = NULL;
	}
	return newNode;
}

void stackPush(stack *(&top), DataPemain node) {
	stack *newNode = NULL;
	if (top == NULL)
		top = stackAlloc(node);
	else {
		newNode = stackAlloc(node);
		newNode->next = top;
		top = newNode;
	}
} 

void stackPop(stack *(&top)) {
	stack *temp = top;
	if (top != NULL) {
		top = top->next;
		temp->next = NULL;
		free(temp);
	}
}
 
void stackPopAll(stack *(&top)) {
	while (top != NULL) 
		stackPop(top);
}

void stackPrintTop4(stack *top) {
	int i = 1;
	int newline = 160; // untuk menggeser skor kearah bawah
	int spaces = 650; // untuk menggeser skor kearah kanan
	Sleep(150);
	printf("\nTop 4 Score with Stack\n");
	initwindow(BATAS_KANAN,BATAS_BAWAH, "Highscore");	// Area console grafik
	readimagefile("Image\\Menu\\highscore.jpg",0,0,1350,780);
	while (top != NULL && i <= 4) {
		printf("%s\t|%d\n", top->dataPemain.NamaPemain, top->dataPemain.FileScore);
		TampilNama(top->dataPemain, newline, spaces);
		TampilScore(top->dataPemain, top->dataPemain.FileScore, newline, spaces);
		top = top->next;
		i++;
		Sleep(250);
		newline += 110; // pertambahan kelipatan pergeseran ke arah bawah pada top 4 score
	}
}

DataPemain getDataHighestScore(stack *top) {
	return top->dataPemain;
}

void convertInorderToStack(bst *node, stack*(&top)) {
	if (node != NULL) {
		convertInorderToStack(node->left, top);
		stackPush(top, node->dataPemain);
		convertInorderToStack(node->right, top);
	}	
}

