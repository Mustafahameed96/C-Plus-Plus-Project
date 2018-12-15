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
#include<windows.h>
int main()
{	
	system("CLS");  // clear the screen
	string s_name ;	// s stands for signup 
	string s_id ;  
	string s_password;
	string s_cpassword; // c is for check again password 
	bool s_check = true ;
	bool l_check = true ; // l is for login
	string id ;
	string password ;
	bool condition = false  ; // to check password is correct or not 
	string str ;
	string inputstring;
	string pass;
	char ch;
	bool quit=false;
	int decide = 0;
	string fileName="option.txt";
	
	
	//creating objects
	EncryptionDecryption O1; 
	Signin si ;
	Signup su ;
	
	//programing is starting from here   <- 
	while(l_check)
					// Menu
	{		    cout<<"\20*************************************WELCOME TO SECRET SERVICE CIPHER SYSTEM******************************************\20\n";
				cout<<"1.SignIn  \n";
				cout<<"2.SignUp \n";
				cout<<"3.Exit  \n";
				cin >> decide ;     //decide is for choosing options 
			switch(decide)
			{
				case 1:	
					// signIn part 
					system("CLS"); //clear the screen
					cout<<"\20*************************************WELCOME TO SECRET SERVICE CIPHER SYSTEM******************************************\20\n"; //menu
					cout << "SIGNIN :" << endl ;
					cout << "_______" << endl << endl ; 
					cout << "NOTE : You Have Only One Attempt "<< endl ;
					cout << "_________________________________ " << endl ;
					cout << "Enter Your Id : " ; // validations to check for the true id I.e @.co
					getline(cin,id); // for ignorance();
					getline(cin,id);
					condition = si.Check(id);  // to check whether id /pass is correct or not 
					l_check = false ;   // l is for login i.e " login check " 
					break ;
				case 2:
						//signUp part 
						s_check = true ; // s is for signup 
						system("CLS"); // clears the screen 
						cout<<"\20*************************************WELCOME TO SECRET SERVICE CIPHER SYSTEM*******************************************\20\n";
						cout << "SIGNUP :" << endl ;
						cout << "_______" << endl << endl ; 
						cout <<"Enter Your Name : "  ;    //input name 
						cin.ignore(); 
						getline(cin,s_name);
						
						cout << "Enter Your Id : " ;  // input id 
						getline(cin,s_id);							 
						
						
					while(s_check)
					{
						// this loop is validate to check password is correct or not 
						cout << "Enter Your Password : " ;
						getline(cin,s_password);    // input password 
						cout << "Enter Your Password again To Confirm : " ;
						getline(cin,s_cpassword);
						if(s_password == s_cpassword)    // for password confirmation 
						{
							cout << "You Successfully Made Your Id " << endl ;
							su.makeAccount(s_name,s_id,s_password); // to save id password 
							getch(); // for stopping the screen 
							system("CLS"); //clear the screen 
							s_check = false ;
						}
						else {
							cout << "password doesn't Match" << endl ;
						}
					}
					
					break ;
				
				case 3 :
					// exit part 
					return 0;
					break ;
				
				default :
					//default part 
					cout << "WRONG INPUT " << endl ;
					break ;
			} //switch case end here <- 
	} // login loop end here         <- 
	//login parts is ending here     <- 
	
	//encryption decryption part is starting from here   <- 
	if(condition)
	{	
	getch();
	O1.emailGetter(id); // i have used this function to get the sender email id
	system("CLS")		;

			while(!quit)
			{
				system("CLS");	
				cout<<"\20*************************************WELCOME TO SECRET SERVICE CIPHER SYSTEM******************************************\20\n";
				cout<<"\20************************************* MAIN MENU******************************************\20\n";
				cout << "1. Encryption\n";
				cout << "2. Check Any Encrypted Messages To Decrypt\n";
				cout << "3. Quit\n";
				quit = false;
				cout << "\nEnter the choice to perform the task";
				cout << "\nEnter 1 or 2 or 3: "<<endl;
				cin >> ch;


				switch(ch)
				{			

						case '1':  											// main case 1
							system("CLS");
							cout<<"\20*************************************WELCOME TO SECRET SERVICE CIPHER SYSTEM******************************************\20\n";
							cout<<"ENCRYPTION MENU"<<endl;
							cout <<"______________" << endl << endl ; 
							cout<< endl<<"Choose Type Of Encryption " <<endl<<endl ;
							cout<<"1.Caeser Cipher"<<endl;
							cout<<"2.Morse Cipher"<<endl;
							cout<<"3.Vignere Cipher"<<endl;
							cin>>ch;
							O1.setOption(ch);
						switch(ch){
							case '1': 										// sub case 1
							cout << "Enter Message to Encrypt: " << endl ;
							cin.ignore(); 									
							getline(cin, inputstring);

							O1.setInputString(inputstring); 				//set the encryption text and proceed it to encrypter function so it can encrypt
							
							cout << "Enter the password to proceed Encryption: " << endl;
							getline(cin, pass);

							if(O1.checkEncPass1(pass)==1) { 				//check encryption password and then do encryption if the password is correct
								O1.getOutputString();
								getch();
									system("CLS")		;
							}
							else {
								break;
							}

							break;  // sub-case 1 end 
							
							case '2': // sub case 2
							cout << "Enter Message to Encrypt: ";
							
							cin.ignore();
							getline(cin, inputstring);

							O1.setInputString(inputstring); //set the encryption text
							
							cout << "Enter the password to proceed Encryption: ";
							getline(cin, pass);

							if(O1.checkEncPass(pass)==1) { //check encryption password and then do encryption if the password is correct
								O1.getOutputString();
									getch();
									system("CLS")		;
								
							}
							else {
								break;
							} 

							break; // sub-case 2 end


							
							case '3': // sub case 2
							cout << "Enter message to Encrypt: ";
							
							cin.ignore();
							getline(cin, inputstring);

							O1.setInputString(inputstring); //set the encryption text
							
							cout << "Enter the password to proceed Encryption: ";
							getline(cin, pass);

							if(O1.checkEncPass2(pass)==1) { //check encryption password and then do encryption if the password is correct
								O1.getOutputString();
									getch();
									system("CLS")		;
							}
							else {
								break;
							} 

							break;




							
						}
						break ;
						case '2': // main case 2
							
							system("CLS");
							cout<<"\20*************************************WELCOME TO SECRET SERVICE CIPHER SYSTEM******************************************\20\n";
							cout<<"INBOX"<<endl;
							cout<<"______" << endl << endl ; 
						
						    ///////////////////////////////////////////////////////////////////////////////////
							ch=O1.openfile(fileName);// it will automatically detect the type of encryption u have dont before and will do it according than
							
							
							switch(ch){
							case '1':
							cin.ignore(); 
							
							inputstring = O1.decryptsetter("encryption.txt");
							cout<<"You have a message "<<endl;
							cout<<inputstring<<endl;
							O1.setInputString(inputstring); //set the decryption string
							
							cout << "Enter the password to proceed Decryption: ";
							getline(cin, pass);

							if(O1.checkDecPass1(pass)==1) { //check decryption password and then do decryption if the password is correct
								O1.getOutputString();
									getch();
									system("CLS")		;
							}
							else {
								break;
							}
							

							break; // case 1 end 
						
							case '2':
								cin.ignore();
							
								inputstring = O1.decryptsetter("encryption.txt");
								cout<<"You have a message "<<endl;
							cout<<inputstring<<endl;
								O1.setInputString(inputstring); 
										cout << "Enter the password to proceed Decryption: ";
										
										getline(cin, pass);

										if(O1.checkDecPass(pass)==1) { //check decryption password and then do decryption if the password is correct
										O1.getOutputString();
										getch();
										system("CLS")		;
									}
								else {
								break;
							}
									break ;
									
									
						case '3':
								cin.ignore();
								
								inputstring = O1.decryptsetter("encryption.txt");
								cout<<"You have a message "<<endl;
							cout<<inputstring<<endl;
								O1.setInputString(inputstring); 
										cout << "Enter the password to proceed Decryption: ";
										
										getline(cin, pass);

										if(O1.checkDecPass2(pass)==1) { //check decryption password and then do decryption if the password is correct
										O1.getOutputString();
											getch();
											system("CLS")		;
									}
								else {
								break;
							}
									break ;			
									
									
								}
								break ;

							/////////////////////////////////////////////////////////////////////
						case '3': // main case 3
								cout<< "Exiting the program";
								return 0;
								quit=true;
								break;
						case '\n':
						case '\t':
						case ' ':
								break;
						default:
								cout<<"Wrong Choice";
								quit=false;
								break;
				}
				cout << "\n\n";
		}
	}
	
	else{
		cout<< "You Entered Wrong Id" <<endl;
		cout<<"Exiting The Program"<<endl;
		
	}
   
   getch();
	return 0;
}
