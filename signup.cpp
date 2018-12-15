#include<iostream>
#include<iomanip>
#include<string.h>
#include<dos.h>
#include <fstream>
#include <time.h>
using namespace std;
#include "encryptDecrypt.h"
/*
Name : Junaid Masood & Mustufa Hameed
REG : CS151025 & cs151020
Project : Secret Service Cipher System 
*/

#include "login.h"
#include "signup.h"
#include "signin.h"

Signup::Signup() 
{
	// default constructor 
}

Signup::Signup(string s_name,string s_id,string s_password):Login(s_name ,s_id , s_password)
{}
void Signup::write() 
{
	ofstream file("idpassword.txt",std::fstream::app);
	if(!file)
	{
		cout << "FILE NOT FOUND" << endl ;
	}
	else {
		time_t currentTime; // time function
	    time(&currentTime);
		file << endl << name << endl ;   // writting into file 
		file << id 	 << endl ;
		file << password << endl ;
		file << ctime(&currentTime);
		
	}
	file.close();
}
void Signup::makeAccount(string s_name,string s_id,string s_password) 
{		
	
	id = s_id;				// initializing  
	name = s_name ;
	password  = s_password; 
	write() ;
}