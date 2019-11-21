/*Copyright: Dongyeong Kim,KOREA DIGITAL MEDIA HIGHSCHOOL*/
/*IMPORTANT: PLEASE DO NOT PRESS ENTER WITH NO LETTERS WHILE PLAYING GAME*/

#define _CRT_SECURE_NO_WARNINGS//FOR USING SCANF IN NO WARNING
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include <time.h>
#include "Crypto.h"

char Plaintext[100] = "THISISHMSHOODWEAREUNDERATTACKEDBYGERMANNAVALBATTLESHIPBISMARKPLEASEMAKEQUICKHELPTOTHISNAVALSHIP";//plaintext will be encrypted.
char Plain_Ori_Text[100] = "THISISHMSHOODWEAREUNDERATTACKEDBYGERMANNAVALBATTLESHIPBISMARKPLEASEMAKEQUICKHELPTOTHISNAVALSHIP";//plaintext for comparing and proving.
char* Addr = Plaintext; //Get an Address(Pointer)-for pointing the Plaintext memory.
char* Addr2; //Get an Address(Pointer)

void textcolor(int color_number){//Changing the Letter Color Function
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}
//gotoxy Function
void gotoxy(int x, int y) {//Changing the Position(just gotoxy function)
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
int main() {
	while (1) {

		// 30~50 Main layout
		system("mode con cols=60 lines=40");
	next://identifier for replaying
		system("cls");
		char starting_mode;
		textcolor(2);
		gotoxy(19, 3);
		printf("ROOM 40");
		gotoxy(20, 5);
		printf("HELLO");
		gotoxy(13, 7);
		printf("WELCOME TO THE ROOM 40");
		gotoxy(5, 10);
		printf("YOU WILL MEET THE VARIOUS CODES OVER THE ERA");
		gotoxy(10, 20);
		printf("IF YOU WANT TO START, PRESS Y");
		gotoxy(10, 21);
		printf("IF YOU WANT TO LOAD THE GAME, PRESS L");
		gotoxy(10, 24);
		printf("IF YOU WANT TO QUIT THE GAME, PRESS Q\n");//~48;instruction and start page of this game.
		textcolor(4);
		while (1) {//THE START OF GAME PROCESS
			scanf(" %c", &starting_mode);// Select the Starting Mode, the modes(Q,Y,L) are existed. 
			 // SELECT START MODE
			if (starting_mode == 'Q'){exit(0);} // SELECT Q -> QUIT
			else if (starting_mode == 'Y') // SELECT Y -> Start the NEW GAME
			{
				system("cls");
				nty://identifier for Playing 'L' MODE.
				char ExpectedText[100];//Array for storing the EXPECTED_TEXT(EXPECTED_PLAIN_TEXT).
				Caesar(Addr, rand() % 26);//Plaintext will be encrypted.
				printf("\nExpected_TEXT:");
				scanf("%s", ExpectedText);//Guessing the EXPECTED_TEXT(EXPECTED_PLAIN_TEXT).
				Addr2 = ExpectedText;//Make Addr2 Pointer point the address of ExpectedText(INPUT_DATA or EXPECTED_PLAIN_TEXT)
				int oper; oper = strcmp(Addr2, Plain_Ori_Text);//Comparing for checking the sameness of original Plaintext and Expected Plaintext(INPUT_DATA)

				if (oper != 0)// If not same;
				{
					PlaySound(NULL, 0, 0);//stop the playing sound
					char q;//Variable for checking keep playing or not
					system("cls");
					printf("FAILED!\nIF YOU WANT TO REPLAY, PRESS R\nIF YOU WANT TO QUIT, PRESS ANYTHING WITHOUT R");
					FILE* fp;//FILE POINTER FOR SAVING DATA.
					fp = fopen("save.dat", "wb");//Variable for checking keep playing or not
					fwrite(Addr2, sizeof(char), strlen(Addr) - 1, fp);//SAVING THE DATA BY FILE LENGTH.
					fclose(fp);//CLOSE THE FILE POINTER
					scanf(" %c", &q);//Check will replay or Quit.
					if (q == 'R') { goto next; }//IF PRESS R, WIll MAKE IT MOVE TO next, on 32 lines, for replaying the game.
					else { exit(0); }//Otherelse will quit the game genuinely.

				}
				else
				{
					PlaySound(NULL, 0, 0);//Stop the Playing sound.
					char q;//Variable for checking keep playing or not
					system("cls");
					printf("SUCCESS!\nIF YOU WANT TO REPLAY, PRESS R\nIF YOU WANT TO QUIT, PRESS ANYTHING WITHOUT R");
					scanf(" %c", &q);//GET A VARIABLE
					//Check THE MODE(WILL REPLAY OR NOT)
					if (q == 'R') { goto next; }//IF 'R', REPLAY
					else { exit(0); }//IF NOT 'R', WILL NOT REPLAY

				}
				
			}//DONE NEW PLAY MODE(Y MODE)

			else if (starting_mode == 'L')//LOAD THE PREVIOUS WRONG DATA 
			{
				system("cls");
				char k;
				printf("Previous Wrong Input Text: ");
				char SAVED_Char=' ';//PRESET CHAR DATA FOR AVOIDING ERRORS ON WHILE FUNCTION.
				FILE* fp;// For Opening File; File Pointer
				fp = fopen("save.dat","rb");//Open the SAVED FILE.
				while(SAVED_Char!='\0')//BEFORE MEET NULL,
				{
					fread(&SAVED_Char, sizeof(char), 1, fp);//READ AND SAVE THE DATA FROM .dat FILE,
					printf("%c", SAVED_Char);//AND PRINT IT.
				}
				printf("\n");
				goto nty;//GOTO THE PARTIAL Y MODE, AFTER PRINTING THE PREVIOUS WRONG EXPECTED PLAINTEXT.
			} // END THE LOADING GAME DATA AND GOTO PLAY MODE(PARTIAL Y MODE)

			else{ printf("INPUT CHARACTER IS NOT VALID"); }//FOR IGNORING OTHER INPUTS
		}
	}
}
