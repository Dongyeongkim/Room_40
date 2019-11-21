#include "Crypto.h"
#include<stdio.h>
#include<Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

void Caesar(char* message,int key) //Caesar Function, input Message_Address(Pointer), Key = int
{
	char ch;
	int i;

	for (i = 0; message[i] != '\0'; ++i) { //before meet NULL, it will work.
		ch = message[i];

		if (ch >= 'a' && ch <= 'z') {
			ch = ch + key;

			if (ch > 'z') {
				ch = ch - 'z' + 'a' - 1;
			}

			message[i] = ch; //a~z encrypting
		}
		else if (ch >= 'A' && ch <= 'Z') {
			ch = ch + key;

			if (ch > 'Z') {
				ch = ch - 'Z' + 'A' - 1;
			}

			message[i] = ch;//A~Z(Capital Letter Encrypting
		}
		//~33 lines: Just Normal Caesar Cipher Code. 
	}
	printf("CIPHERTEXT:"); PlaySound(TEXT("Beepsound.wav"), NULL, SND_FILENAME|SND_ASYNC);//Play the Morse Code Sound
	for (int i = 0; message[i] != '\0'; i++) {
		Sleep(80);//Effect like translating the Morse to Letter
		printf("%c", message[i]);//Print the Ciphered Letter
	}

}
