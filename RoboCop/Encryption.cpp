#include "Encryption.h"
#include <iostream>

/*
* \param n is the number to be encrypted
* \return encrypted number
*/
int Encryption::encrypt(int n) {
	//! obtains the digits of number
	int a = n / 1000;
	int b = (n % 1000) / 100;
	int c = (n % 100) / 10;
	int d = n % 10;
	//! Replaces each digit with the result of adding 7 to the digit and getting the remainder after dividing the new value by 10.
	a = (a + 7) % 10;
	b = (b + 7) % 10;
	c = (c + 7) % 10;
	d = (d + 7) % 10;
	return (c * 1000 + d * 100 + a * 10 + b);   // swap a-c and b-d; generate result number 
}

/*
* \param n is the number to be decrypted
* \return decrypted number
*/
int Encryption::decrypt(int n){
	//! obtains the digits of number
	int a = n / 1000;
	int b = (n % 1000) / 100;
	int c = (n % 100) / 10;
	int d = n % 10;
	//! Replaces each digit with the result of substract 7 to the digit and getting the remainder after dividing the new value by 10. 
	a = (a + 3) % 10;
	b = (b + 3) % 10;
	c = (c + 3) % 10;
	d = (d + 3) % 10;
	return (c * 1000 + d * 100 + a * 10 + b); // swap a-c and b-d; generate result number
}