/*
Name : Junaid Masood & Mustufa Hameed
REG : CS151025 & cs151020
Project : Secret Service Cipher System 
*/

#ifndef SIGNUP_H
#define SIGNUP_H

class Signup : public Login{
	
		
	protected :
		
		
	public :
		Signup() ;  // default constructor 
		Signup(string s_name,string s_id,string s_password);  // paramertirzed constructor 
		void write() ;
		void makeAccount(string s_name,string s_id,string s_password) ;
};

#endif 