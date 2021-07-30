#ifndef Ahmad_F_H
#define Ahmad_F_H

/**
	Procedure untuk menampilkan mode normal game															*/
void normalMode();

/**
	Procedure untuk menampilkan mode survival game															*/
void survivalMode();

/**
	Procedure untuk memberikan nilai image awal pada program												*/
void inisialisasi_image_snake();

/**
	Procedure untuk mengecek apakah ular menabrak batas arena												*/
bool check_wall_through();

/**	
	Procedure untuk menyesuaikan hasil dari inputan user terhadap arah snake agar arah snake berkondisi
	akhir serupa dengan inputan user.Dengan syarat bahwa: Apabila arah snake sedang kekanan, lalu user 
	menginputkan kearah kiri, maka pertintah tersebut ditolak												*/
void key_state();

/**
	Procedure untuk mengisikan gambar untuk variabel segment badan sesuai dari arah yang dilakukan
	segment sebelumnya (bagian kepala) setelah menerima inputan user										*/
void body();

/**
	Procedure untuk mengisikan gambar untuk variabel segment ekor sesuai dari arah yang dilakukan
	segment sebelumnya (bagian badan) setelah menerima inputan user											*/
void ekor();


/**
	Procedure untuk mengecek snake apabila melebihi map range yang telah disediakan dan jika snake
	melebihi map range, maka gambar snake akan diubah menjadi background, lalu akan ditampilkan 
	gambar "GAME OVER" sebagai konsekuensi snake yang melebihi map range. Dan game akan dihentikan.			*/
void wall_through(segment **ptr);


/**
	Function untuk mengecek kepala snake berada sama dengan bagian tubuh lainnya (badan atau ekor) 
	atau tidak																								*/
bool status_collision(int x, int y);

/** 
	Procedure untuk menampilkan game over saat kondisi snake mati											*/
void displayGameOver(int x, int y);

#endif
