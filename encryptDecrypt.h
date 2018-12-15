/*
Name : Junaid Masood & Mustufa Hameed
REG : CS151025 & cs151020
Project : Secret Service Cipher System 
*/

#ifndef PROJECT_H
#define PROJECT_H

#include "login.h"

class Login;
class EncryptionDecryption {
	private:
		char ch ;
		string outputstring;
		string inputstring;
		string encpass;
		string decpass;
		string id;
		string emailid;
		int enckey;
		int deckey;
		int enckey1;
		int deckey1;
		int temp;
		char tempc;
		void doEncryption(); //function to do Encryption on morse cipher
		void doDecryption(); //function to do Decryption on morse ciper
		void doEncryption1(); //function to do Encryption on caeser cipher
		void doDecryption1();//function to do Decryption on caeser ciper
		void doEncryption2(); //function to do Encryption on vigenere cipher
		void doDecryption2();//function to do Decryption on vigenere ciper
		
		Login login ;
	public:
	string key ;
		EncryptionDecryption(); //initializer Default Constructor
		EncryptionDecryption(string); //parameterized constructor
		void setInputString(string ); //it will set input string
		~EncryptionDecryption();
		int checkEncPass(string);//to check password for encryption
		int checkDecPass(string);//to check password for decryption
		int checkEncPass1(string);
		int checkDecPass1(string);
		int checkEncPass2(string);
		int checkDecPass2(string);
		void getOutputString(); //get the encrypted string
		bool confirm(Login log);
		char openfile(string fileName );//it is to read option from file
		string decryptsetter(string fileName);//to read encryption string from fie
		void setOption(char ch);//it is to set option to file
		void emailGetter(string id);//it is used to set user mail
};
#endif