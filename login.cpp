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
#include <conio.h>
using namespace std;
#include "encryptDecrypt.h"
#include "login.h"
#include "signup.h"
#include "signin.h"

Login::Login()
{
	// defalut constructor 
}
Login::Login(string name ,string Id , string pass)
{
	//parameterized constructor 
	this->name = name ;
	this->id = Id;
	this->password = pass ;
	
}

void Login::SetIdPass(string name , string Id , string pass)
{
	//setter 
	this->name = name ;
	this->id = Id;
	this->password = pass ;
	
}
string Login::getId()
{
	//return id;
	return id ;
}
string Login::getPass()
{
	//return password;
	return password ;
}
string Login::getName()
{
	//return name  ;
	return name ;
}
bool Login::Check(string Id)				// to check id pass
{																 
	string time ;
	string temp ;
	ifstream file("idpassword.txt");   		//filing starting from here  <-
	if(!file)       						// !file means "file not found"  
	{
		cout << " not found " << endl ; 
	}
	else 
	{
		getline(file,name);   				// to ignore space 
		while(!file.eof())
		{
			getline(file,name);  			//reading name from file 
			getline(file,id);	 			//reading id from file 	
			getline(file,password);			//reading password from file 
			getline(file,time);				//reading time from file 
			getline(file,temp);				//to ignore space   
		
		if(id == Id)    					// comparing id's
			{								// this part is for efficient password input system 
				string array = "                                                        ";
				string temp= "                                                          ";	
				int size = password.size();
				char a ;
				int count =0  ;
				int i = -1;
				int j = 0;
				
				cout << "Password : "  ;
					while(j<size)                          // if user input a single character it ouput *
					{
						a=getch();
						if( (a>='a' && a<='z') ||  (a>='A' && a<='Z') || (a>='0' && a<='9'))   
						{
							array[++i] = a ;

							cout << "*" ;
							j++;
						}
						if(a == '\b')
						{
							if(i>=0)
							{   --j;
								--i;
								cout << "\b \b" ;
							}
							else {
								cout << "\b \b" ;
							}
						}
						if(a=='\r')
						{

							break ;
						}
					}
					for(int i = 0 ; i < size ; i++)
					{
						if(array[i] == password[i] )          // comparing each character 
						{
							count++;
						}
					}
					
					if(count == size )
					{
						cout<<endl  <<"Approved"<< endl ;    			 // password match
						return true ;
					}
					else{
						cout<<endl<<" Password or Id incorrect "<<endl;  // password does not match 
						return false ;
					}
				}	
		}
			return false ;
	}
}