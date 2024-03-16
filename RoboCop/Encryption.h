/**
* @author Serhat Aydin
* @date 28.12.2023
* @brief encrypt and decrypt the given number according to the encryption algorithm
* 
* Encryption class encrypts and decrypts the given number according to the encryption algorithm.
*/

#pragma once
class Encryption{
public:
	//! this function encrypts the given number
	int encrypt(int n);
	//! this function decrypts the given number	
	int decrypt(int n);
};

