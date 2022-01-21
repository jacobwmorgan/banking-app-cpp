#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include <iomanip> 
#include <algorithm>
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
bool isNumber(const std::string& str);


int main(int argc, char *argv[])
{
	std::vector <Account*> accounts;
	Account* currentlySelected = NULL;
	int currentlySelectedIndex = 0;
	std::vector <std::string> parameters;
	std::string userCommand;
	std::cout << "~~~ Welcome to LincBank! ~~~\n";

	while(userCommand != "exit")
	{
		parameters.clear();
		while(true)
		{
			if(currentlySelected != NULL)
			{
				std::cout << std::fixed << std::setprecision(2);
				std::cout <<"\nSelected Account: " << currentlySelected->getType() << " | Index : " << std::to_string(currentlySelectedIndex+1) << " | Balance : " << currentlySelected->getBalance();
			}
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
		for (int i = 0; i < userCommand.length(); i++)
		{
			if(userCommand[i]>= 'A' && userCommand[i]<='Z')
			{
				userCommand[i] = userCommand[i]+32;
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
			if(parameters.size() > 3 || parameters.size() < 2)
			{
				InvalidInput();
			}
			else
			{
				if(parameters[1].compare("1") == 0)
				{
					int currentAmount = 0;
					for (int i = 0; i < accounts.size(); i++)
					{
						if (accounts[i]-> getType() == "Current")
						{
							currentAmount++;
						}
					}
					if(currentAmount > 0)
					{
						std::cout << "!You already have a current account!\n";
					}
					else
					{
						float depotMoney = 0;
						if(parameters.size() > 2)
						{
							if(isNumber(parameters[2]) == false) InvalidInput();
							else
							{
								depotMoney = std::stof(parameters[2]);
								Account* current = new Current(depotMoney);
								accounts.push_back(current);
								currentlySelected = accounts[accounts.size()-1];
								currentlySelectedIndex = accounts.size()-1;
							}
						}
						else
						{
							Account* current = new Current(depotMoney);
							accounts.push_back(current);
							currentlySelected = accounts[accounts.size()-1];
							currentlySelectedIndex = accounts.size()-1;
						}
						
					}
				}
				else if(parameters[1].compare("2") == 0)
				{
					float depotMoney = 0;
					if (parameters.size() > 2)
					{
						depotMoney = std::stof(parameters[2]);
					}
					Account* current = new Saving(depotMoney,false);
					accounts.push_back(current);
					currentlySelected = accounts[accounts.size()-1];
					currentlySelectedIndex = accounts.size()-1;
				}
				else if(parameters[1].compare("3") == 0)
				{
					int isaAmount = 0;
					for (int i = 0; i < accounts.size(); i++)
					{
						if(accounts[i]->getType() == "ISA Savings" )
						{
							isaAmount ++;
						}
					}
					if(isaAmount > 1)
					{
						std::cout<< "You already have an ISA Account!\n";
					}
					else
					{
						if(parameters.size() < 3) std::cout << "Please provide how much money you want to put into your ISA\n ~Type options to view the commands~\n  ";
						else
						{
							if(std::stof(parameters[2]) < 500) std::cout << "Please deposit 500 or more to make an ISA Savings account\n";
							else
							{
								Account* current = new Saving(std::stof(parameters[2]),true);
								accounts.push_back(current);
								currentlySelected = accounts[accounts.size()-1];
								currentlySelectedIndex = accounts.size()-1;
							}
						}
					}
					
				}
				else
				{
					InvalidInput();
				}
			}
			
		}
		else if (command.compare("view") == 0)
		{
			//display an account according to an index (starting from 1)
			// alternatively , display all accounts if no index is provided
			if (parameters.size() > 2) InvalidInput();
			else if(parameters.size() < 2)
			{
				if(accounts.size() != 0)
				{
					for (int i = 0; i < accounts.size(); i++)
					{
						std::cout << i+1 << " : " << accounts[i]->getType() << " Account\n";
					}
				}
				else
				{
					std::cout << "You have no accounts\nLearn how to make some by typing options\n";
				}
			}
			else
			{
				if(isNumber(parameters[1]) == false) InvalidInput();
				else
				{
					if(stoi(parameters[1]) == 0) InvalidInput();
					else
					{
						int accountsSize = accounts.size() -1;
						if(accountsSize < stoi(parameters[1])-1) InvalidInput();
						else
						{
							accounts[stoi(parameters[1])-1] -> display();
							accounts[stoi(parameters[1])-1]->displayHistory();
							currentlySelected = accounts[stoi(parameters[1])-1];
							currentlySelectedIndex = stoi(parameters[1])-1;
						}
					}
				}
			}
			
		}
		else if (command.compare("withdraw") == 0)
		{
			if(parameters.size() != 2) InvalidInput();
			else
			{
				if(currentlySelected == NULL) std::cout << "There is no account selected\nView an account to select that account\n";
				else
				{
					if(isNumber(parameters[1]) == false) InvalidInput();
					else
					{
						currentlySelected->withdraw(std::stof(parameters[1]));
					}
				}
			}
		}
		else if (command.compare("deposit") == 0)
		{
			if(parameters.size() != 2) InvalidInput();
			else
			{
				if(currentlySelected == NULL) std::cout << "There is no account selected\nView an account to select that account\n";
				else
				{
					if(isNumber(parameters[1]) == false) InvalidInput();
					else
					{
						currentlySelected->deposit(std::stof(parameters[1]));
					}
				}
			}
		}
		else if (command.compare("transfer") == 0)
		{
			if(parameters.size() != 4) InvalidInput();
			else
			{
				bool PASSFLAG = true;
				for (int i = 1; i < parameters.size(); i++)
				{
					if(isNumber(parameters[i]) == false)
					{
						InvalidInput();
						PASSFLAG = false;
						break;
					}
				}
				if(PASSFLAG == true)
				{
					float amount = std::stof(parameters[3]);
					if(stoi(parameters[1]) -1 > accounts.size() || stoi(parameters[2] ) -1 > accounts.size()) InvalidInput();
					else
					{
						if(accounts[stoi(parameters[1]) -1]->getType() == "Current")
						{
							if(accounts[stoi(parameters[1]) -1]->getBalance() == 0)
							{
								float tempOverDraft = accounts[stoi(parameters[1]) -1] -> overdraft;
								if(tempOverDraft == 0 || tempOverDraft - amount < 0)std::cout << "Not enough money in account\n";
								else
								{
									accounts[stoi(parameters[1])-1]->withdraw(amount);
									accounts[stoi(parameters[2])-1]->deposit(amount);
								}
							}
							else
							{
								accounts[stoi(parameters[1])-1]->withdraw(amount);
								accounts[stoi(parameters[2])-1]->deposit(amount);
							}

						}
						else
						{
							float tempBalance = accounts[stoi(parameters[1])-1] -> getBalance();
							if(tempBalance - amount < 0) std::cout << "Not enough money in account";
							else
							{
								accounts[stoi(parameters[1])-1]->withdraw(amount);
								accounts[stoi(parameters[2])-1]->deposit(amount);
							}
						}
					}
				}
				
			}
		}
		else if (command.compare("project") == 0)
		{
			if(parameters.size() != 2) InvalidInput();
			else
			{
				if (currentlySelected->getType() == "Savings" || currentlySelected->getType() == "ISA Savings")
				{
					if(isNumber(parameters[1]) == false) InvalidInput();
					else
					{
						currentlySelected -> displayInterest(std::stof(parameters[1]));
					}
				}
				else InvalidInput();
			}
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
	std::cout << "Invalid Input\n~Type options to view the commands~\n";
}

bool isNumber(const std::string& str)
{
	for (char const &c : str)
	{
		if(std::isdigit(c)==0)return false;
	}
	return true;
}

