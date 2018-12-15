/*
Name : Junaid Masood & Mustufa Hameed
REG : CS151025 & cs151020
Project : Secret Service Cipher System 
*/

#include<iostream>
#include<iomanip>
#include<string.h>
#include<dos.h>
#include <fstream>
#include <time.h>
#include<windows.h>
using namespace std;
#include "encryptDecrypt.h"
#include "login.h"
#include "signup.h"
#include "signin.h"

//Use this function to do Encryption


void EncryptionDecryption::doEncryption() {
	for(int i=0;i<inputstring.size();i++) {
		temp = (int)inputstring[i];
		temp = temp + enckey;
		tempc = (char)temp;
		outputstring += tempc;
		
		}
				
		ofstream out1 ; // out is a file 
		out1.open("record.txt", ios::app) ;
		out1<<"From: "<<id<<endl;
		cout<<"Enter the Email id You want to send your mail to"<<endl;
		cin>>emailid;
		out1<<"To: "<<emailid<<endl;
		out1.close();	
		
		
		
		ofstream out ; // out is a file 
		out.open("record.txt", ios::app) ;
		
		time_t currentTime; // time function
	    time(&currentTime);
		out<<"The following data is encrypted by Morse code cipher on "<<ctime(&currentTime);
		
		out << inputstring<<endl ;
		out<<endl<<endl;
		out.close();
		ofstream file("encryption.txt");
	if(!file)
	{
		cout << " not found " << endl ;       // writing into encryption file
	}	
	else {
		
		file << outputstring << endl;
		
	}
		file.close();
		
		
		

}
void EncryptionDecryption::doEncryption1() {
	for(int i=0;i<inputstring.size();i++) {
		temp = (int)inputstring[i];
		temp = temp + enckey1;
		tempc = (char)temp;
		outputstring += tempc;
	}
		
			
		ofstream out1 ; // out is a file 
		out1.open("record.txt", ios::app) ;
		out1<<"From:"<<id<<endl;
		cout<<"Enter the Email id You want to send your mail to"<<endl;
		cin>>emailid;
		out1<<"To:"<<emailid<<endl;
		out1.close();	
	
	
	
	
		ofstream out ; // out is a file 
		out.open("record.txt", ios::app) ;
		
		time_t currentTime; // time function
	    time(&currentTime);
		out<<"The following data is encrypted by Caeser cipher on "<<ctime(&currentTime);
	
		out << inputstring<<endl ;
		out<<endl<<endl;
		out.close();
		ofstream file("encryption.txt");
	if(!file)
	{
		cout << " not found " << endl ;       // writing into encryption file
	}	
	else {
		
		file << outputstring << endl;
		
	}
		file.close();
		
		

}


void EncryptionDecryption::doEncryption2() {
		key ="VIGNERECIPHER";
		
	
		  for (int i = 0, j = 0; i < inputstring.length(); ++i)
            {
                char c = inputstring[i];

                if (c >= 'a' && c <= 'z')
                    c += 'A' - 'a';
                else if (c < 'A' || c > 'Z')
                    continue;

                outputstring += (c + key[j] - 2 * 'A') % 26 + 'A';
                j = (j + 1) % key.length();
            }
			
			
			
		ofstream out1 ; // out is a file 
		out1.open("record.txt", ios::app) ;
		out1<<"From: "<<id<<endl;
		cout<<"Enter the Email id You want to send your mail to"<<endl;
		cin>>emailid;
		out1<<"To: "<<emailid<<endl;
		out1.close();	
			
			
	
		ofstream out ; // out is a file 
		out.open("record.txt", ios::app) ;
		
		time_t currentTime; // time function
	    time(&currentTime);
		out<<"The following data is encrypted by Vignere cipher on "<<ctime(&currentTime);
		
		out << inputstring<<endl ;
		out<<endl<<endl;
		out.close();
		ofstream file("encryption.txt");
	if(!file)
	{
		cout << " not found " << endl ;       // writing into encryption file
	}	
	else {
		
		file << outputstring << endl;
		
	}
		file.close();
		
		

}


//End of encryption function

//Use this function to do Decryption
void EncryptionDecryption::doDecryption() {
	for(int i=0;i<inputstring.size();i++) {
		temp = (int)inputstring[i];
		temp = temp + deckey;
		tempc = (char)temp;
		outputstring += tempc;
		}


}
void EncryptionDecryption::doDecryption1() {
	for(int i=0;i<inputstring.size();i++) {
		temp = (int)inputstring[i];
		temp = temp + deckey1;
		tempc = (char)temp;
		outputstring += tempc;
		}


}



void EncryptionDecryption::doDecryption2() {


			key ="VIGNERECIPHER";
		

	
for (int i = 0, j = 0; i < inputstring.length(); ++i)
          


	  {
                char c = inputstring[i];

                if (c >= 'a' && c <= 'z')
                    c += 'A' - 'a';
                else if (c < 'A' || c > 'Z')
                    continue;

                outputstring += (c - key[j] + 26) % 26 + 'A';
                j = (j + 1) % key.length();
            }

}


//End of decryption function

void EncryptionDecryption::getOutputString() {
	
	
	outputstring += '\0';
	cout << "The Encrypted/Decrypted string is"  <<" : "<<outputstring << endl ;

	
	

		
			outputstring="";
}

//first check the password  and it should be bool
int EncryptionDecryption::checkEncPass(string pass) {
	//check password before encrypting
	if(pass!=encpass)
	{
		cout << endl << "The password you entered is Incorrect the, Encryption will not proceed.\nTry Again \n";
		return 0;
	}
	else {
		doEncryption();
		return 1;
	}
}
int EncryptionDecryption::checkEncPass1(string pass) {
	//check password before encrypting
	if(pass!=encpass)
	{
		cout << endl << "The password you entered is Incorrect the, Encryption will not proceed.\nTry Again \n";
		return 0;
	}
	else {
		doEncryption1();
		return 1;
	}
}

int EncryptionDecryption::checkEncPass2(string pass) {
	//check password before encrypting
	if(pass!=encpass)
	{
		cout << endl << "The password you entered is Incorrect the, Encryption will not proceed.\nTry Again \n";
		return 0;
	}
	else {
		doEncryption2();
		return 1;
	}
}


//first check the password
int EncryptionDecryption::checkDecPass(string pass) {
	//check password before encrypting
	if(pass!=decpass)
	{
		cout << endl << "The password you entered is Incorrect the, Decryption will not proceed.\nTry Again \n";
		return 0;
	}
	else {
		doDecryption();
		return 1;
	}
}
int EncryptionDecryption::checkDecPass1(string pass) {
	//check password before encrypting
	if(pass!=decpass)
	{
		cout << endl << "The password you entered is Incorrect the, Decryption will not proceed.\nTry Again \n";
		return 0;
	}
	else {
		doDecryption1();
		return 1;
	}
}

int EncryptionDecryption::checkDecPass2(string pass) {
	//check password before encrypting
	if(pass!=decpass)
	{
		cout << endl << "The password you entered is Incorrect the, Decryption will not proceed.\nTry Again \n";
		return 0;
	}
	else {
		doDecryption2();
		return 1;
	}
}



//Initializer
EncryptionDecryption::EncryptionDecryption() {
	inputstring = "";
	outputstring = "";
	encpass= "111"; //this is the password
	decpass= "000";
	enckey= 100; //this is the key
	deckey= -100 ;
	enckey1=2;
	deckey1=-2;
	temp= 0;
	tempc='\0';
}


EncryptionDecryption::EncryptionDecryption(string e) {
	inputstring = e;
}

bool EncryptionDecryption::confirm(Login log)
{
	login = log ;
	string Id;
	string pass ;
	ifstream file("idpassword.txt");
	if (!file)
	{
		cout << " not found " << endl;
		
	}
	else {
		
		file>> Id;
		file>> pass;
		
		if(login.Check(Id/*,pass*/))
		{
			return true ;
		}
		else {
			
			return false ;
		}
	
		
	}
}

void EncryptionDecryption::setInputString(string f ) {
	inputstring=f;
	
	
}

EncryptionDecryption::~EncryptionDecryption() {
}

char EncryptionDecryption::openfile(string fileName){
	
		ifstream in(fileName.c_str()) ;
		in>>ch;
		return ch;
}
string EncryptionDecryption::decryptsetter(string fileName){
	
		ifstream in(fileName.c_str()) ;
		in>>inputstring;
		return inputstring;
}
void EncryptionDecryption::setOption(char ch){
		ofstream out ; // out is a file 
		out.open("option.txt") ;
		out << ch<<endl ;
	
}
void  EncryptionDecryption::emailGetter(string id){
	
	this->id=id;
	
}
