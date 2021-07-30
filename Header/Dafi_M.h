#ifndef Dafi_M_H
#define Dafi_M_H

/**
	Procedure untuk menampilkan obstacle																	*/
void display_obs();

/**
	Procedure untuk mengisi coordinat obstacle pada linked list												*/
void coordinate_obs_1();
void coordinate_obs_2();
void coordinate_obs_3();

/**
	Procedure untuk cek apabila snake menabrak obstacle														*/
bool hit_obs(int x, int y);

/**
	Procedure untuk membuat linked list																		*/
void create_obs(int x, int y);

/**
	Procedure menghapus linked list obs																		*/
void pop_obs();

//avl
int getHeight(bst *root);

int getBalanceFactor(bst *root);

bst *leftRotate(bst *x);

bst *rightRotate(bst *y);

#endif
