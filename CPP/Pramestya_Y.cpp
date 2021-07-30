#include "../SnakeAlpha.h"

extern int BatasScore;

void InputScore(DataPemain &dataPemain, int score){
	int ratusan, puluhan, satuan, ribuan;
	ribuan = score / 1000;
	ratusan = (score - ribuan * 1000)/ 100;
	puluhan = (score - ribuan * 1000 - ratusan * 100) / 10;
	satuan = (score - ribuan * 1000 - ratusan * 100 - puluhan * 10);
	dataPemain.ScoreAkhir[DIGIT_RIBUAN] = ribuan;
	dataPemain.ScoreAkhir[DIGIT_RATUSAN] = ratusan;
	dataPemain.ScoreAkhir[DIGIT_PULUHAN] = puluhan;
	dataPemain.ScoreAkhir[DIGIT_SATUAN] = satuan;
}

void TampilScore(DataPemain &dataPemain, int score, int newline, int spaces){
	int i;
	int delta = 0;
	int right = 0;
	if (newline != 0) delta = 20;// apabila bagian cek highscore
			
	InputScore(dataPemain, score);
	for (BatasScore = DIGIT_RIBUAN; BatasScore < 4; BatasScore++){
		if (BatasScore == DIGIT_RIBUAN){
			printf("ribuan: %d  ", dataPemain.ScoreAkhir[DIGIT_RIBUAN]);
			if (newline == 0) readimagefile("Image\\Arena\\kolom1.jpg", 100, 70, 200, 170);
			switch (dataPemain.ScoreAkhir[DIGIT_RIBUAN])
			{											
				case 0 : {
					readimagefile ("Image\\Score\\angka0.gif", spaces+100-right, newline+70, spaces+200-delta-right, newline+170-delta);
					break;
				}
				case 1 : {
					readimagefile ("Image\\Score\\angka1.gif", spaces+100-right, newline+70, spaces+200-delta-right, newline+170-delta);
					break;
				}
				case 2 : {
					readimagefile ("Image\\Score\\angka2.gif", spaces+100-right, newline+70, spaces+200-delta-right, newline+170-delta); 
					break;
				}
				case 3 : {
					readimagefile ("Image\\Score\\angka3.gif", spaces+100-right, newline+70, spaces+200-delta-right, newline+170-delta); 
					break;
				}
				case 4 : {
					readimagefile ("Image\\Score\\angka4.gif", spaces+100-right, newline+70, spaces+200-delta-right, newline+170-delta); 
					break;
				}case 5 : {
					readimagefile ("Image\\Score\\angka5.gif", spaces+100-right, newline+70, spaces+200-delta-right, newline+170-delta);
					break;
				}
				case 6 : {
					readimagefile ("Image\\Score\\angka6.gif", spaces+100-right, newline+70, spaces+200-delta-right, newline+170-delta);
					break;
				}
				case 7 : {
					readimagefile ("Image\\Score\\angka7.gif", spaces+100-right, newline+70, spaces+200-delta-right, newline+170-delta); 
					break;
				}
				case 8 : {
					readimagefile ("Image\\Score\\angka8.gif", spaces+100-right, newline+70, spaces+200-delta-right, newline+170-delta); 
					break;
				}
				case 9 : {
					readimagefile ("Image\\Score\\angka9.gif", spaces+100-right, newline+70, spaces+200-delta-right, newline+170-delta); 
					break;
				}
			}
		}
		else if (BatasScore == DIGIT_RATUSAN){
			printf("ratusan: %d  ", dataPemain.ScoreAkhir[DIGIT_RATUSAN]);
			if (newline == 0) readimagefile("Image\\Arena\\kolom1.jpg", 200, 70, 300, 170);
			switch (dataPemain.ScoreAkhir[DIGIT_RATUSAN])
			{											
				case 0 : {
					readimagefile ("Image\\Score\\angka0.gif", spaces+200-right, newline+70, spaces+300-delta-right, newline+170-delta);
					break;
				}
				case 1 : {
					readimagefile ("Image\\Score\\angka1.gif", spaces+200-right, newline+70, spaces+300-delta-right, newline+170-delta);
					break;
				}
				case 2 : {
					readimagefile ("Image\\Score\\angka2.gif", spaces+200-right, newline+70, spaces+300-delta-right, newline+170-delta); 
					break;
				}
				case 3 : {
					readimagefile ("Image\\Score\\angka3.gif", spaces+200-right, newline+70, spaces+300-delta-right, newline+170-delta); 
					break;
				}
				case 4 : {
					readimagefile ("Image\\Score\\angka4.gif", spaces+200-right, newline+70, spaces+300-delta-right, newline+170-delta); 
					break;
				}case 5 : {
					readimagefile ("Image\\Score\\angka5.gif", spaces+200-right, newline+70, spaces+300-delta-right, newline+170-delta);
					break;
				}
				case 6 : {
					readimagefile ("Image\\Score\\angka6.gif", spaces+200-right, newline+70, spaces+300-delta-right, newline+170-delta);
					break;
				}
				case 7 : {
					readimagefile ("Image\\Score\\angka7.gif", spaces+200-right, newline+70, spaces+300-delta-right, newline+170-delta); 
					break;
				}
				case 8 : {
					readimagefile ("Image\\Score\\angka8.gif", spaces+200-right, newline+70, spaces+300-delta-right, newline+170-delta); 
					break;
				}
				case 9 : {
					readimagefile ("Image\\Score\\angka9.gif", spaces+200-right, newline+70, spaces+300-delta-right, newline+170-delta); 
					break;
				}
			}
		} 
		else if  (BatasScore == DIGIT_PULUHAN){
			printf("puluhan: %d  ", dataPemain.ScoreAkhir[DIGIT_PULUHAN]);
			if (newline == 0) readimagefile("Image\\Arena\\kolom1.jpg", 300, 70, 400, 170);
			switch (dataPemain.ScoreAkhir[DIGIT_PULUHAN]){
				case 0 : {
					readimagefile ("Image\\Score\\angka0.gif", spaces+300-right, newline+70, spaces+400-delta-right, newline+170-delta); 
					break;
				}
				case 1 : {
					readimagefile ("Image\\Score\\angka1.gif", spaces+300-right, newline+70, spaces+400-delta-right, newline+170-delta);
					break;
				}case 2 : {
					readimagefile ("Image\\Score\\angka2.gif", spaces+300-right, newline+70, spaces+400-delta-right, newline+170-delta); 
					break;
				}
				case 3 : {
					readimagefile ("Image\\Score\\angka3.gif", spaces+300-right, newline+70, spaces+400-delta-right, newline+170-delta);
					break;
				}
				case 4 : {
					readimagefile ("Image\\Score\\angka4.gif", spaces+300-right, newline+70, spaces+400-delta-right, newline+170-delta); 
					break;
				}
				case 5 : {
					readimagefile ("Image\\Score\\angka5.gif", spaces+300-right, newline+70, spaces+400-delta-right, newline+170-delta);
					break;
				}
				case 6 : {
					readimagefile ("Image\\Score\\angka6.gif", spaces+300-right, newline+70, spaces+400-delta-right, newline+170-delta); 
					break;
				}
				case 7 : {
					readimagefile ("Image\\Score\\angka7.gif", spaces+300-right, newline+70, spaces+400-delta-right, newline+170-delta);
					break;
				}
				case 8 : {
					readimagefile ("Image\\Score\\angka8.gif", spaces+300-right, newline+70, spaces+400-delta-right, newline+170-delta); 
					break;
				}
				case 9 : {
					readimagefile ("Image\\Score\\angka9.gif", spaces+300-right, newline+70, spaces+400-delta-right, newline+170-delta);
					break;
				}
			}
		} 
		else if  (BatasScore == DIGIT_SATUAN){
			printf("satuan: %d  \n", dataPemain.ScoreAkhir[DIGIT_SATUAN]);
			if (newline == 0) readimagefile("Image\\Arena\\kolom1.jpg", 400, 70, 500, 170);
			switch (dataPemain.ScoreAkhir[DIGIT_SATUAN]){
				case 0 : 
				{
					readimagefile ("Image\\Score\\angka0.gif", spaces+400-right, newline+70, spaces+500-delta-right, newline+170-delta); 
					break;
				}
				case 1 : {
					readimagefile ("Image\\Score\\angka1.gif", spaces+400-right, newline+70, spaces+500-delta-right, newline+170-delta); 
					break;
				}
				case 2 : 
				{
					readimagefile ("Image\\Score\\angka2.gif", spaces+400-right, newline+70, spaces+500-delta-right, newline+170-delta); 
					break;
				}
				case 3 : {
					readimagefile ("Image\\Score\\angka3.gif", spaces+400-right, newline+70, spaces+500-delta-right, newline+170-delta); 
					break;
				}
				case 4 : 
				{
					readimagefile ("Image\\Score\\angka4.gif", spaces+400-right, newline+70, spaces+500-delta-right, newline+170-delta); 
					break;
				}
				case 5 : {
					readimagefile ("Image\\Score\\angka5.gif", spaces+400-right, newline+70, spaces+500-delta-right, newline+170-delta); 
					break;
				}
				case 6 : 
				{
					readimagefile ("Image\\Score\\angka6.gif", spaces+400-right, newline+70, spaces+500-delta-right, newline+170-delta); 
					break;
				}
				case 7 : {
					readimagefile ("Image\\Score\\angka7.gif", spaces+400-right, newline+70, spaces+500-delta-right, newline+170-delta); 
					break;
				}
				case 8 : 
				{
					readimagefile ("Image\\Score\\angka8.gif", spaces+400-right, newline+70, spaces+500-delta-right, newline+170-delta); 
					break;
				}
				case 9 : {
					readimagefile ("Image\\Score\\angka9.gif", spaces+400-right, newline+70, spaces+500-delta-right, newline+170-delta); 
					break;
				}
			}
		}
		right += 20;
	}	
}

void inputName(DataPemain &dataPemain) {
	char key;
	int right = 0;
	int value = 0;
	int i = 0;
	while (key != ENTER) {  // carriage return (/r atau enter key)
		switch (value) {
			case KEY_A: {
				if (i <= 4) {
					readimagefile ("Image\\Abjad\\a.gif", 480+right, 465, 560+right, 545);
					dataPemain.NamaPemain[i] = 'a';
					right += 80;
					i++;
				}
				break;
			}
			case KEY_B: {
				if (i <= 4) {
					readimagefile ("Image\\Abjad\\b.gif", 480+right, 465, 560+right, 545);
					dataPemain.NamaPemain[i] = 'b';
					right += 80;
					i++;
				}
				break;
			}
			case KEY_C: {
				if (i <= 4) {
					readimagefile ("Image\\Abjad\\c.gif", 480+right, 465, 560+right, 545);
					dataPemain.NamaPemain[i] = 'c';
					right += 80;
					i++;
				}
				break;
			}
			case KEY_D: {
				if (i <= 4) {
					
					readimagefile ("Image\\Abjad\\d.gif", 480+right, 465, 560+right, 545);
					dataPemain.NamaPemain[i] = 'd';
					right += 80;
					i++;
				}
				break;
			}
			case KEY_E: {
				if (i <= 4) {
					
					readimagefile ("Image\\Abjad\\e.gif", 480+right, 465, 560+right, 545);
					dataPemain.NamaPemain[i] = 'e';
					right += 80;
					i++;
				}
				break;
			}
			case KEY_F: {
				if (i <= 4) {
					readimagefile ("Image\\Abjad\\f.gif", 500+right, 460, 580+right, 540);
					dataPemain.NamaPemain[i] = 'f';
					right += 80;
					i++;
				}
				break;
			}
			case KEY_G: {
				if (i <= 4) {
					readimagefile ("Image\\Abjad\\g.gif", 500+right, 460, 580+right, 540);
					dataPemain.NamaPemain[i] = 'g';
					right += 80;
					i++;
				}
				break;
			}
			case KEY_H: {
				if (i <= 4) {
					readimagefile ("Image\\Abjad\\h.gif", 500+right, 460, 580+right, 540);
					dataPemain.NamaPemain[i] = 'h';
					right += 80;
					i++;
				}
				break;
			}
			case KEY_I: {
				if (i <= 4) {
					readimagefile ("Image\\Abjad\\i.gif", 500+right, 460, 580+right, 540);
					dataPemain.NamaPemain[i] = 'i';
					right += 80;
					i++;
				}
				break;
			}
			case KEY_J: {
				if (i <= 4) {
					readimagefile ("Image\\Abjad\\j.gif", 500+right, 460, 580+right, 540);
					dataPemain.NamaPemain[i] = 'j';
					right += 80;
					i++;
				}
				break;
			}
			case KEY_K: {
				if (i <= 4) {
					readimagefile ("Image\\Abjad\\k.gif", 500+right, 460, 580+right, 540);
					dataPemain.NamaPemain[i] = 'k';
					right += 80;
					i++;
				}
				break;
			}
			case KEY_L: {
				if (i <= 4) {
					readimagefile ("Image\\Abjad\\l.gif", 500+right, 460, 580+right, 540);
					dataPemain.NamaPemain[i] = 'l';
					right += 80;
					i++;
				}
				break;
			}
			case KEY_M: {
				if (i <= 4) {
					readimagefile ("Image\\Abjad\\m.gif", 500+right, 460, 580+right, 540);
					dataPemain.NamaPemain[i] = 'm';
					right += 80;
					i++;
				}
				break;
			}
			case KEY_N: {
				if (i <= 4) {
					readimagefile ("Image\\Abjad\\n.gif", 500+right, 460, 580+right, 540);
					dataPemain.NamaPemain[i] = 'n';
					right += 80;
					i++;
				}
				break;
			}
			case KEY_O: {
				if (i <= 4) {
					readimagefile ("Image\\Abjad\\o.gif", 500+right, 460, 580+right, 540);
					dataPemain.NamaPemain[i] = 'o';
					right += 80;
					i++;
				}
				break;
			}
			case KEY_P: {
				if (i <= 4) {
					readimagefile ("Image\\Abjad\\p.gif", 500+right, 460, 580+right, 540);
					dataPemain.NamaPemain[i] = 'p';
					right += 80;
					i++;
				}
				break;
			}
			case KEY_Q: {
				if (i <= 4) {
					readimagefile ("Image\\Abjad\\q.gif", 500+right, 460, 580+right, 540);
					dataPemain.NamaPemain[i] = 'q';
					right += 80;
					i++;
				}
				break;
			}
			case KEY_R: {
				if (i <= 4) {
					readimagefile ("Image\\Abjad\\r.gif", 500+right, 460, 580+right, 540);
					dataPemain.NamaPemain[i] = 'r';
					right += 80;
					i++;
				}
				break;
			}
			case KEY_S: {
				if (i <= 4) {
					readimagefile ("Image\\Abjad\\s.gif", 500+right, 460, 580+right, 540);
					dataPemain.NamaPemain[i] = 's';
					right += 80;
					i++;
				}
				break;
			}
			case KEY_T: {
				if (i <= 4) {
					readimagefile ("Image\\Abjad\\t.gif", 500+right, 460, 580+right, 540);
					dataPemain.NamaPemain[i] = 't';
					right += 80;
					i++;
				}
				break;
			}
			case KEY_U: {
				if (i <= 4) {
					readimagefile ("Image\\Abjad\\u.gif", 500+right, 460, 580+right, 540);
					dataPemain.NamaPemain[i] = 'u';
					right += 80;
					i++;
				}
				break;
			}
			case KEY_V: {
				if (i <= 4) {
					readimagefile ("Image\\Abjad\\v.gif", 500+right, 460, 580+right, 540);
					dataPemain.NamaPemain[i] = 'v';
					right += 80;
					i++;
				}
				break;
			}
			case KEY_W: {
				if (i <= 4) {
					readimagefile ("Image\\Abjad\\w.gif", 500+right, 460, 580+right, 540);
					dataPemain.NamaPemain[i] = 'w';
					right += 80;
					i++;
				}
				break;
			}
			case KEY_X: {
				if (i <= 4) {
					readimagefile ("Image\\Abjad\\x.gif", 500+right, 460, 580+right, 540);
					dataPemain.NamaPemain[i] = 'x';
					right += 80;
					i++;
				}
				break;
			}
			case KEY_Y: {
				if (i <= 4) {
					readimagefile ("Image\\Abjad\\y.gif", 500+right, 460, 580+right, 540);
					dataPemain.NamaPemain[i] = 'y';
					right += 80;
					i++;
				}
				break;
			}
			case KEY_Z: {
				if (i <= 4) {
					readimagefile ("Image\\Abjad\\z.gif", 500+right, 460, 580+right, 540);
					dataPemain.NamaPemain[i] = 'z';
					right += 80;
					i++;
				}
				break;
			}
			case SPACE: {
				if (i <= 4) {
					dataPemain.NamaPemain[i] = '0';
					right += 80;
					i++;
				}
				break;
			}
			case BACKSPACE : {
				if (i >= 1) {
					right -= 80;
					readimagefile ("Image\\Arena\\backspace.jpg", 500+right, 470, 580+right, 550);
					i--;
					dataPemain.NamaPemain[i] = '\0';
				}
				break;
			}
			
		}
		if (i >= 5) i = 5;
		if (i <= 0) i = 0;
		
		key = getch();
		key = tolower(key);
		value = (int)key;
	}
	for (i = i; i < 9; i++) 
		dataPemain.NamaPemain[i] = '\0';

}
