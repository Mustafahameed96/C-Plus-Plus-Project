/*
Name : Junaid Masood & Mustufa Hameed
REG : CS151025 & cs151020
Project : Secret Service Cipher System 
*/

#ifndef LOGIN_H
#define LOGIN_H

class Login{
	
	protected :
		string name ;
		string id ;
		string password ;
	public :
		Login();  										 // default constructor 
		Login(string name ,string Id , string pass);  	 // parameterized constructor 
		void SetIdPass(string name ,string Id , string pass);
		string getId();        							 // getters setters 
		string getPass();
		string getName();
        bool Check(string Id) ; 

};

#endif