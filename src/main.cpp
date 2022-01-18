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



// TODO
// 1.) COMMENT CODE I HAVE RN
// 2.) DO THE UI 
// 3.) WRITE REPORT

void InvalidInput();


int main(int argc, char *argv[])
{
	std::vector <Account> accounts;
	std::vector <std::string> parameters;
	std::string userCommand;
	std::cout << "~~~ Welcome to LincBank! ~~~\n";

	while(userCommand != "exit")
	{
		parameters.clear();
		while(true)
		{
			std::cout << "\n>>> ";
			std::getline(std::cin,userCommand);
			if (userCommand == "")
			{
					InvalidInput();
			}
			else
			{
					break;
			}
		}
			
		char* cstr = new char[userCommand.length() + 1];
		strcpy(cstr,userCommand.c_str());
		char* token;
		token = strtok(cstr, " ");
		while (token != NULL)
		{
			parameters.push_back(token);
			token = strtok(NULL, " ");
		}

		std::string command = parameters[0];

		if(command.compare("options") == 0)
		{
			std::cout << "open [type] [initial deposit]: open a current(1) , savings(2), or ISA(3) account\nview[index]: view balance and recent transactions\nwithdraw [amount]: withdraw funds from most recently viewed account\ndeposit [amount]: deposit funds into most recently viewed account\ntransfer [source] [destination] [amount]: transfer funds between accounts\nproject [years]: project balance forward in time\nexit: close this application\n";
		}
		else if (command.compare("open") == 0)
		{	
			if(parameters.size() > 3)
			{
				InvalidInput();
			}
			else
			{
				if(parameters[1].compare("1") == 0)
				{
					int currentAmount;
					for (int i = 0; i < accounts.size(); i++)
					{
						if (accounts[i]-> getType() == "Current")
						{
							currentAmount+=1;
						}
					}
					if(currentAmount > 1)
					{
						std::cout << "!You already have a current account!\n";
					}
					else
					{
						if(parameters.size > 2)
						{
							Current current = new Current(parameters[2]);
							accounts.push_back(current);
						}
						else
						{
							Current current = new Current(0);
							accounts.push_back(current);
						}
					}
					
					
				}
			}
			
		}
		else if (command.compare("view") == 0)
		{
			//display an account according to an index (starting from 1)
			// alternatively , display all accounts if no index is provided
		}
		else if (command.compare("withdraw") == 0)
		{
			//allow user to withdraw funds from an account
		}
		else if (command.compare("deposit") == 0)
		{
			// allow user to deposit funds into an account
		}
		else if (command.compare("transfer") == 0)
		{
			// allow user to transfer funds between accounts
			// i.e., a withdrawal followed by a deposit!
		}
		else if (command.compare("project") == 0)
		{
			// compute compound interest t years into the future
		}
		
		//else if (command.compare("search"))
		//{
		//	allow users to search their account history for a transaction
		//  (this is a stretch task)
		//}
		else
		{
			if(command.compare("exit") != 0)
			{
				InvalidInput();
			}
		}
	}
	std::cout << "Press any key to quit...";
	std::getchar();
	// Saving* saving = new Saving();
	// int size = accounts.size();
	// saving -> setNumber(size+1);
	// accounts.push_back(saving);
	// saving -> deposit(100);
	// saving -> display();
	// saving -> displayInterest();
	// return 0;

}

void InvalidInput()
{
	std::cout << "Invalid Input\n~Type options or ? to view the commands~\n";
}