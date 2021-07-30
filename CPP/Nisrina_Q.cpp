#include "../SnakeAlpha.h"


/**
	Variabel mengecek apabila permainan harus diberhentikan atau tetap berjalan					*/
extern bool game;

void music(){
	mciSendString("close mp3",NULL,0,NULL);	
    mciSendString("open \"Music\\Musik.mp3\" type mpegvideo alias mp3",NULL,0,NULL);
    mciSendString("play mp3",NULL,0,NULL);
}

void TampilNama(DataPemain &dataPemain, int newline, int spaces){
	int right = 0;
	int BatasNama = 0;
	do{
		printf("BatasNama == %d, %c\n", BatasNama, dataPemain.NamaPemain[BatasNama]);
		switch (dataPemain.NamaPemain[BatasNama])
		{											
				case 'a' : {
					readimagefile ("Image\\Abjad\\a.gif", spaces-350+right, newline+70, spaces-270+right, newline+150);
					break;
				}
				case 'b' : {
					readimagefile ("Image\\Abjad\\b.gif", spaces-350+right, newline+70, spaces-270+right, newline+150);
					break;
				}
				case 'c' : {
					readimagefile ("Image\\Abjad\\c.gif", spaces-350+right, newline+70, spaces-270+right, newline+150); 
					break;
				}
				case 'd' : {
					readimagefile ("Image\\Abjad\\d.gif", spaces-350+right, newline+70, spaces-270+right, newline+150); 
					break;
				}
				case 'e' : {
					readimagefile ("Image\\Abjad\\e.gif", spaces-350+right, newline+70, spaces-270+right, newline+150); 
					break;
				}case 'f' : {
					readimagefile ("Image\\Abjad\\f.gif", spaces-350+right, newline+70, spaces-270+right, newline+150);
					break;
				}
				case 'g' : {
					readimagefile ("Image\\Abjad\\g.gif", spaces-350+right, newline+70, spaces-270+right, newline+150);
					break;
				}
				case 'h' : {
					readimagefile ("Image\\Abjad\\h.gif", spaces-350+right, newline+70, spaces-270+right, newline+150); 
					break;
				}
				case 'i' : {
					readimagefile ("Image\\Abjad\\i.gif", spaces-350+right, newline+70, spaces-270+right, newline+150); 
					break;
				}
				case 'j' : {
					readimagefile ("Image\\Abjad\\j.gif", spaces-350+right, newline+70, spaces-270+right, newline+150); 
					break;
				}
				case 'k' : {
					readimagefile ("Image\\Abjad\\k.gif", spaces-350+right, newline+70, spaces-270+right, newline+150); 
					break;
				}
				case 'l' : {
					readimagefile ("Image\\Abjad\\l.gif", spaces-350+right, newline+70, spaces-270+right, newline+150); 
					break;
				}
				case 'm' : {
					readimagefile ("Image\\Abjad\\m.gif", spaces-350+right, newline+70, spaces-270+right, newline+150); 
					break;
				}
				case 'n' : {
					readimagefile ("Image\\Abjad\\n.gif", spaces-350+right, newline+70, spaces-270+right, newline+150); 
					break;
				}
				case 'o' : {
					readimagefile ("Image\\Abjad\\o.gif", spaces-350+right, newline+70, spaces-270+right, newline+150); 
					break;
				}
				case 'p' : {
					readimagefile ("Image\\Abjad\\p.gif", spaces-350+right, newline+70, spaces-270+right, newline+150); 
					break;
				}
				case 'q' : {
					readimagefile ("Image\\Abjad\\q.gif", spaces-350+right, newline+70, spaces-270+right, newline+150); 
					break;
				}
				case 'r' : {
					readimagefile ("Image\\Abjad\\r.gif", spaces-350+right, newline+70, spaces-270+right, newline+150); 
					break;
				}
				case 's' : {
					readimagefile ("Image\\Abjad\\s.gif", spaces-350+right, newline+70, spaces-270+right, newline+150); 
					break;
				}
				case 't' : {
					readimagefile ("Image\\Abjad\\t.gif", spaces-350+right, newline+70, spaces-270+right, newline+150); 
					break;
				}
				case 'u' : {
					readimagefile ("Image\\Abjad\\u.gif", spaces-350+right, newline+70, spaces-270+right, newline+150); 
					break;
				}
				case 'v' : {
					readimagefile ("Image\\Abjad\\v.gif", spaces-350+right, newline+70, spaces-270+right, newline+150); 
					break;
				}
				case 'w' : {
					readimagefile ("Image\\Abjad\\w.gif", spaces-350+right, newline+70, spaces-270+right, newline+150); 
					break;
				}
				case 'x' : {
					readimagefile ("Image\\Abjad\\x.gif", spaces-350+right, newline+70, spaces-270+right, newline+150); 
					break;
				}
				case 'y' : {
					readimagefile ("Image\\Abjad\\y.gif", spaces-350+right, newline+70, spaces-270+right, newline+150); 
					break;
				}
				case 'z' : {
					readimagefile ("Image\\Abjad\\z.gif", spaces-350+right, newline+70, spaces-270+right, newline+150); 
					break;
				}
				case '0' : { 
					break;
				}
			}
		right += 80;
		BatasNama++;
	}while(dataPemain.NamaPemain[BatasNama] != '\0');
}

void menu(){
	game = true;	// untuk memulai game kembali
	bool kembali = false;
	bool tampilskor = true;
	int x=0, y=0;
	int musicTime = 0;
    bst* root = NULL;
    stack *top = NULL;
    
    music();
    closegraph();
    initwindow(BATAS_KANAN,BATAS_BAWAH, "MAIN MENU");
    clearviewport();
	setviewport(0, 0, getmaxx(), getmaxy(), 1);
    swapbuffers();

	readimagefile("Image\\Menu\\menu.jpg", 0, 0, BATAS_KANAN, BATAS_BAWAH);
	swapbuffers();
	while(1){
		musicTime++;
		
		getmouseclick(WM_LBUTTONDOWN, x, y);
		//masuk ke permainan
		if((x>460)&&(x<900)&&(y>300)&&(y<355)){
        	clearviewport();
			setviewport(0, 0, getmaxx(), getmaxy(), 1);

        	readimagefile("Image\\Menu\\menu2.jpg",0,0,BATAS_KANAN,BATAS_BAWAH);
		    swapbuffers();

		    while (!kembali){
		    	getmouseclick(WM_LBUTTONDOWN, x, y);
		
		    	if((x>1240)&&(x<1320)&&(y>20)&&(y<100)){
		            kembali = true;
		            menu();
		        }else if((x>465)&&(x<900)&&(y>305)&&(y<360)){
		        	clearviewport();
					setviewport(0, 0, getmaxx(), getmaxy(), 1);
					closegraph();	
		        	normalMode();
		        	swapbuffers();
				}else if((x>465)&&(x<900)&&(y>390)&&(y<450)){
					clearviewport();
					setviewport(0, 0, getmaxx(), getmaxy(), 1);
					closegraph();	
		        	survivalMode();
		        	swapbuffers();
				}
			}
			kembali = true;
			
        }
        //Menampilkan High Score
        else if((x>460)&&(x<900)&&(y>390)&&(y<440)){
		    clearviewport();
			setviewport(0, 0, getmaxx(), getmaxy(), 1);

        	readimagefile("Image\\Menu\\highscore.jpg",0,0,BATAS_KANAN,BATAS_BAWAH);
		    swapbuffers();

		    while (!kembali){
		    	getmouseclick(WM_LBUTTONDOWN, x, y);
				
				if (tampilskor){
					convertRekapFileToBST(root);
					convertInorderToStack(root, top);
					stackPrintTop4(top);
					stackPopAll(top);
					bstDeleteTree(root);
					tampilskor = false;
				}
				
		    	if((x>20)&&(x<130)&&(y>650)&&(y<760)){
		            kembali = true;
		        }
			}
			menu();
        }
        //Menampilkan how to play
        else if((x>460)&&(x<900)&&(y>470)&&(y<530)){
		    clearviewport();
			setviewport(0, 0, getmaxx(), getmaxy(), 1);

        	readimagefile("Image\\Menu\\howtoplay.jpg",0,0,BATAS_KANAN,BATAS_BAWAH);
		    swapbuffers();


		    while (!kembali){
		    	getmouseclick(WM_LBUTTONDOWN, x, y);

		    	if((x>20)&&(x<130)&&(y>650)&&(y<760)){
		            kembali = true;
		        }
			}
			menu();
		//Menampilkan About Us
		}else if((x>460)&&(x<900)&&(y>560)&&(y<610)){
		    clearviewport();
			setviewport(0, 0, getmaxx(), getmaxy(), 1);

        	readimagefile("Image\\Menu\\aboutus.jpg",0,0,BATAS_KANAN,BATAS_BAWAH);
		    swapbuffers();


		    while (!kembali){
		    	getmouseclick(WM_LBUTTONDOWN, x, y);

		    	if((x>20)&&(x<130)&&(y>650)&&(y<760)){
		            kembali = true;
		        }
			}
			menu();
		}
        //Menampilkan exit
        else if((x>460)&&(x<900)&&(y>645)&&(y<700)){
        	exit (0);
        }
        
        if(musicTime >= 950){
        	music();
        	musicTime = 0;
		}
		delay(50); //digunakan untuk mengurangi kecepatan iterasi musicTime
	}
}

void loadGame (){
	readimagefile("Image\\Loading\\load0.jpg", 0, 0, BATAS_KANAN, BATAS_BAWAH);
	delay(250);
	readimagefile("Image\\Loading\\load10.jpg", 0, 0, BATAS_KANAN, BATAS_BAWAH);
	delay(250);
	readimagefile("Image\\Loading\\load20.jpg", 0, 0, BATAS_KANAN, BATAS_BAWAH);
	delay(250);
	readimagefile("Image\\Loading\\load30.jpg", 0, 0, BATAS_KANAN, BATAS_BAWAH);
	delay(250);
	readimagefile("Image\\Loading\\load40.jpg", 0, 0, BATAS_KANAN, BATAS_BAWAH);
	delay(250);
	readimagefile("Image\\Loading\\load50.jpg", 0, 0, BATAS_KANAN, BATAS_BAWAH);
	delay(250);
	readimagefile("Image\\Loading\\load60.jpg", 0, 0, BATAS_KANAN, BATAS_BAWAH);
	delay(250);
	readimagefile("Image\\Loading\\load70.jpg", 0, 0, BATAS_KANAN, BATAS_BAWAH);
	delay(250);
	readimagefile("Image\\Loading\\load80.jpg", 0, 0, BATAS_KANAN, BATAS_BAWAH);
	delay(250);
	readimagefile("Image\\Loading\\load90.jpg", 0, 0, BATAS_KANAN, BATAS_BAWAH);
	delay(250);
	readimagefile("Image\\Loading\\load100.jpg", 0, 0, BATAS_KANAN, BATAS_BAWAH);
	delay(250);
	menu();
}
