#include "../SnakeAlpha.h"

extern obstacle *head_obs;
extern char obstaclePic[];
/**
	Nilai awal untuk struct pointer yang menunjuk kebagian ujung-ujung segment snakenya			*/
extern segment *head;

void coordinate_obs_1(){
	
	int x = 5;
	int y = 11;
	int i;
	for(i = 0; i < 10; i++){
		create_obs(x,y);
		x++;
	}
	
	x = 26;
	for(i; i < 20; i++){
		create_obs(x,y);
		x++;
	}	
	
	x = 15;
	y = 18;
	for(i; i < 30; i++){
		create_obs(x,y);
		x++;
	}		
}

void coordinate_obs_2(){
	int i;
	int x = 5;
	int y = 13;
	// kiri atas point bawah
	
	for(i = 0; i < 2; i++){
		create_obs(x,y);
		y--;
	}
	for(i; i < 10; i++){
		create_obs(x,y);
		x++;
	}
	for(i; i < 13; i++){
		create_obs(x,y);
		y++;
	}	
	
	// kanan atas point bawah
	x = 29;
	y -= 1;		
	for(i; i < 15; i++){
		create_obs(x,y);
		y--;
	}	
	for(i; i < 24; i++){
		create_obs(x,y);
		x++;
	}
	for(i; i < 27; i++){
		create_obs(x,y);
		y++;
	}
		
	
	// kanan bawah point atas
	y += 2;
	for(i; i < 29; i++){
		create_obs(x,y);
		y++;
	}	
	for(i; i < 38; i++){
		create_obs(x,y);
		x--;
	}
	for(i; i < 41; i++){
		create_obs(x,y);
		y--;
	}		
	
	
	// kiri bawah point atas
	y += 1;
	x = 5;
	for(i; i < 43; i++){
		create_obs(x,y);
		y++;
	}	
	for(i; i < 51; i++){
		create_obs(x,y);
		x++;
	}
	for(i; i < 54; i++){
		create_obs(x,y);
		y--;
	}
	
	// tengah
	y -= 1;
	x += 4;	
	for(i; i < 63; i++){
		create_obs(x,y);
		x++;
	}
	x -= 4;
	y += 1;
	for(i; i < 66; i++){
		create_obs(x,y);
		x--;
	}	
}

void coordinate_obs_3(){
	int i;
	
	// kiri
	int x = 13;
	int y = 24;
	for(i = 0; i < 11; i++){
		create_obs(x,y);
		y--;
	}	
	for(i; i < 24; i++){
		create_obs(x,y);
		x--;
	}	
	
	// kanan
	x = 28;
	y = 7;
	for(i; i < 33; i++){
		create_obs(x,y);
		y++;
	}	
	for(i; i < 49; i++){
		create_obs(x,y);
		x++;
	}		
}

void create_obs(int x, int y){
	obstacle *node;
	obstacle *P;
	node = (obstacle*)malloc(sizeof(obstacle));
	node->next = NULL;
	node->xCoordinate = x;
	node->yCoordinate = y;
	// Jika obs (linked list) masih kosong
	if(head_obs == NULL){
		head_obs = node;
	}
	// Jika obs sudah ada
	else{
		P = head_obs;
		while(P->next != NULL){
			P = P->next;
		}
		P->next = node;
	}
}

void display_obs(){
	obstacle *P;
	P = head_obs;
	while(P != NULL){
		readimagefile(obstaclePic, P->xCoordinate*BLOK, P->yCoordinate*BLOK, P->xCoordinate*BLOK+IMAGE, P->yCoordinate*BLOK+IMAGE);
		P = P->next;
	}
}

void pop_obs(){
	obstacle *P;
	if(head_obs->next = NULL){
		free(head_obs);
		head = NULL;
	}
	else{
		P = head_obs;
		head_obs = head_obs->next;
		P->next = NULL;
		free(P);
	}
}

bool hit_obs(int x, int y){

	obstacle *P = head_obs;
	
	while(P->next != NULL){
		if(P->xCoordinate == x && P->yCoordinate == y){
			return TOUCHING;
		}
		P = P->next;
	}
	return NOTTOUCHING;
}

int getHeight(bst *root) {
	if (root == NULL) return 0;
	return root->height;
}

int getBalanceFactor(bst *root) {
	if (root == NULL) return 0;
	return (getHeight(root->left) - getHeight(root->right));
}

bst *rightRotate(bst *y) {
	bst *x = y->left;
	bst *B = x->right;
	
	// rotate
	x->right = y;
	y->left = B;
	
	y->height = MAX(getHeight(y->left), getHeight(y->right)) + 1;
	x->height = MAX(getHeight(x->left), getHeight(x->right)) + 1;
	
	return x;
}

bst *leftRotate(bst *x) {
	bst *y = x->right;
	bst *B = y->left;
	
	// rotate
	y->left = x;
	x->right = B;
	
	x->height = MAX(getHeight(x->left), getHeight(x->right)) + 1;
	y->height = MAX(getHeight(y->left), getHeight(y->right)) + 1;
	
	return y;
}

