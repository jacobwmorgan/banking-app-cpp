#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include <iomanip> 
#include "Account.h"
#include "Current.h"
//#include "Saving.h"

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
	std::vector <std::string> parameters;
	std::string userCommand;

	std::cout << "~~~ Welcome to LincBank! ~~~ \n";
	//Account account;
	Current current;
	current.deposit(145114.1212);
	current.display();
	return 0;

}