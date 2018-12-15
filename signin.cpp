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
using namespace std;
#include "encryptDecrypt.h"
#include "login.h"
#include "signup.h"
#include "signin.h"

Signin::Signin()
{
    // default constructor 
}
Signin::Signin(string id , string password)
{	// paramterized constructor 
	this-> id  = id ;
	this-> password = password;
}
