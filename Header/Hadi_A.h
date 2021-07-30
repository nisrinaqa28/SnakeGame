#ifndef Hadi_A_H
#define Hadi_A_H

/** 
	Procedure untuk menempatkan makanan secara acak di posisi yang tidak terisika oleh posisi ular			*/
void food_coordinate();

/**
	Procedure untuk menampilkan makanan ditempeat sesuai dengan nilai acak dari procedure food_coordinate()	*/
void food_display();

/**
	Procedure untuk menampilkan makanan khusus secara random dari food_coordinate()							*/
void special_food_display();

/**
	Procedure untuk kondisi yang akan terjadi apabila snake berhubungan dengan makanan biasa 
	pada NORMAL_MODE maupun SURVIVAL_MODE.
	Apabila snake dapat memakanan makanan biasa, maka tubuh snake akan bertambah panjang satu segemen		*/
void foodnSnake(int &sumFood, int &xFood, int &yFood, int x, int y, bool &foodIsGone, int &sumGone, int &nextLevel, int &survivalWon);

stack *stackAlloc(DataPemain x);
void stackPush(stack *(&top), DataPemain node);
void stackPop(stack *(&top));
void stackPopAll(stack *(&top));
void stackPrintTop4(stack *top);

DataPemain getDataHighestScore(stack *top);
void convertInorderToStack(bst *node, stack*(&top));

#endif
