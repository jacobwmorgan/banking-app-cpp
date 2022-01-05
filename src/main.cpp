#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include <iomanip> 
#include "Account.h"
#include "Current.h"
#include "Saving.h"
//#include "Saving.h"
//g++ -I../include main.cpp Account.cpp Current.cpp Transaction.cpp InterestEarning.cpp
int main(int argc, char *argv[])
{
	/*
		MAIN MENU
		* ALL ACCOUNTS WILL SHOW HERE EG.*
		Jacob Morgan 221512 []
		Theo Morgan 125123 [X]
		Exit []



		USER MENU -
		*(Current Account Info )*
		Jacob Morgan 221512
		---------------------------------------------
		View Account info []
		Withdraw Funds [X]
		Deposit Funds []
		Transfer Funds []
		Project []
		History []
		Open New Account []
		LogOut []

	*/
	//std::vector <Account> accounts;
	// std::vector <std::string> parameters;
	// std::string userCommand;

	// std::cout << "~~~ Welcome to LincBank! ~~~ \n";
	// //Account account;
	// while (userCommand != "exit")
	// {
	// 	parameters.clear();
	// 	std::cout << "\n >>";
	// 	std::getline(std::cin, userCommand);
	// 	char* cstr = new char[userCommand.length()+1];
	// 	strcpy(cstr, userCommand.c_str());
	// 	char* token;
	// 	token = strtok(cstr, " ");

	// }
	Saving saving;
	saving.deposit(100);
	saving.display();
	saving.displayInterest();
	return 0;

}