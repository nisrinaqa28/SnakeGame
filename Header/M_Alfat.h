#ifndef M_Alfat_H
#define M_Alfat_H

/**
	Procedure untuk menaikan permainan ke level selanjutnya pada NORMAL_MODE sekaligus kondisi menang 
	di NORMAL_MODE dan SURVIVAL_MODE																		*/
void gameToWin(int &nextLevel, bool &levelUp, int &survivalWon);

/**
	Function untuk mengecek apakah gameover atau tidak, jika ya, maka akan mengembalikan nilai true.
	Pada function ini terbagi menjadi 2 pengecekan, satu untuk NORMAL_MODE dan satu lagi
	untuk SURVIVAL_MODE																						*/
bool gameOver(int x, int y);

/**
	Procedure untuk kondisi yang akan terjadi apabila snake berhubungan dengan makanan spesial 
	pada SURVIVAL_MODE.
	-Apabila snake tidak dapat memakan makana spesial selama 25 pergerakan, maka makanan spesial 
	akan dihilangkan						
	-Apabila snake dapat memakan makanan spesial, maka skor akan ditambah dengan 10. Namun, 
	tidak akan menambah panjang segmen ular																	*/
void specialFoodnSnake(bool &foodIsGone, int &sumGone, int xFood, int yFood, int x, int y);

/**
	Procedure untuk membuat jumlah segment ular berdasarkan inputan snakeSize yang diterima					*/
void initial_snake(int snakeSize);

/**
	Procedure untuk merubah koordinat dari hasil arah snake yang sedang berlangsung				
	Kodisi ular:
	- Ular mengarah ke kiri ditandai dengan nilai x yang semakin mengecil
	- Ular mengarah ke kanan ditandai dengan nilai x yang semakin membesar
	- Ular mengarah ke atas ditandai dengan nilai y yang semain mengecil
	- Ular mengarah ke bawah ditandai dengan nilai y yang semakin membesar									*/
void coordinate_modifier(int &x, int &y);

/**
	Procedure untuk menampilkan (displaying) snake ke layar (console grafik). Dengan syarat tampilan
	segment yang dikeluarkan:
	- segment pertama yang ditampilkan adalah bagian kepala
	- segment terakhir yang ditampilakan adalah bagian background map
	- segment sebelah terakhir yang ditampilkan adalah bagian ekor
	- segment tengah (sisanya) adalah bagian badan															*/
void display();

/**
	Procedure untuk menambahkan segment snake dibagian awal (head). 
	x dan y merupakan koordinat segment snake yang dibuat													*/
void push(int x, int y);

/**
	Procedure untuk menghapus segment snake dibagian akhir (tail)											*/
void pop();

/** 
	Procedure untuk menghapus seluruh segment snake (looping) dengan cara menghapus satu persatu dari
	bagian akhir (tail). Procedure ini ditujukan apabila game telah selesai (game over)						*/
void pop_all();

/**
	Procedure untuk gameplay snake mode survival (bermain sampai layar penuh oleh snake)					*/
void gameplay();

void rekapPlayer();
void convertRekapFileToBST(bst *(&root));
void printBarLevel(int nextLevel);

void bstDeleteTree(bst *node);
void bstInsert(bst *(&root), DataPemain node);
bst *bstAlloc(DataPemain x);
#endif
