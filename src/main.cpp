#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include <iomanip> 
#include <algorithm>

//Including the headings for the classes I have made
#include "Account.h"
#include "Current.h"
#include "Saving.h"


//Decleration of methods used in this file
void InvalidInput(); //Throws an invalid input at the user
bool isNumber(const std::string& str); // Checks if a string is considered a number , this is used later to validate the input by the user


int main(int argc, char *argv[])
{
	std::vector <Account*> accounts; //Vector of Account pointers
	Account* currentlySelected = NULL; //Currently selected account pointer
	int currentlySelectedIndex = 0; // Index of account in vector
	std::vector <std::string> parameters; // User parameters
	std::string userCommand; // Command of the user
	std::cout << "~~~ Welcome to LincBank! ~~~\n";

	while(userCommand != "exit")
	{
		parameters.clear();
		while(true)
		{
			if(currentlySelected != NULL) //Checks if there is a currently selected account
			{
				std::cout << std::fixed << std::setprecision(2); //Formatting
				// Shows the user info about their currently selected account
				std::cout <<"\nSelected Account: " << currentlySelected->getType() << " | Index : " << std::to_string(currentlySelectedIndex+1) << " | Balance : " << currentlySelected->getBalance();
			}
			std::cout << "\n>>> ";
			std::getline(std::cin,userCommand);
			if (userCommand == "") //Checks if the user has put nothing , throws error
			{
					InvalidInput();
			}
			else
			{
					break;
			}
		}

		//Changes user input to lower case letters to avoid case sensitive commands
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

		//Outputs command list to the user
		if(command.compare("options") == 0) 
		{
			std::cout << "open [type] [initial deposit]: open a current(1) , savings(2), or ISA(3) account\nview[index]: view balance and recent transactions\nwithdraw [amount]: withdraw funds from most recently viewed account\ndeposit [amount]: deposit funds into most recently viewed account\ntransfer [source] [destination] [amount]: transfer funds between accounts\nproject [years]: project balance forward in time\nexit: close this application\n";
		}
		//Open command
		else if (command.compare("open") == 0)
		{	
			//Checks to see if the user has inputted the correct amount of parameters
			if(parameters.size() > 3 || parameters.size() < 2) InvalidInput();
			else
			{
				if(parameters[1].compare("1") == 0)
				{
					//Checks to see if there is a current account or not
					int currentAmount = 0;
					for (int i = 0; i < accounts.size(); i++)
					{
						//Checks if account type is a current account and adds to currentAmount
						if (accounts[i]-> getType() == "Current") currentAmount++;
					}
					if(currentAmount > 0) std::cout << "!You already have a current account!\n";
					else
					{
						//Temporary money
						float depotMoney = 0;
						if(parameters.size() > 2)// Checks if the user has deposited money
						{
							if(isNumber(parameters[2]) == false) InvalidInput(); // Checks to see if the 3rd parameter is a number
							else
							{
								//Creates a new current account and deposits the money
								depotMoney = std::stof(parameters[2]);
								Account* current = new Current(depotMoney);
								//Pushes current into accounts vector
								accounts.push_back(current);
								//Changes currenlty selected account to the new account
								currentlySelected = accounts[accounts.size()-1];
								currentlySelectedIndex = accounts.size()-1;
							}
						}
						else
						{
							//Creates a new current account and deposits the money
							Account* current = new Current(depotMoney);
								//Pushes current into accounts vector
							accounts.push_back(current);
							//Changes currenlty selected account to the new account
							currentlySelected = accounts[accounts.size()-1];
							currentlySelectedIndex = accounts.size()-1;
						}
						
					}
				}
				else if(parameters[1].compare("2") == 0) //Savings account
				{
					float depotMoney = 0;
					if (parameters.size() > 2) //Checks to see if the user has entered how much money they want to deposit
					{
						depotMoney = std::stof(parameters[2]);
					}
					//Creates a new savings account with the ISA
					Account* saving = new Saving(depotMoney,false); 	
					//Pushes saving into accounts
					accounts.push_back(saving);
					//Changes currently selected into the savings account
					currentlySelected = accounts[accounts.size()-1];
					currentlySelectedIndex = accounts.size()-1;
				}
				else if(parameters[1].compare("3") == 0) //Savings ISA
				{
					//Checks if an ISA account already exists
					int isaAmount = 0;
					for (int i = 0; i < accounts.size(); i++)
					{
						if(accounts[i]->getType() == "ISA Savings" )
						{
							isaAmount ++;
						}
					}
					if(isaAmount > 1) std::cout<< "You already have an ISA Account!\n";
					else
					{
						//Checks if user has provided money
						if(parameters.size() < 3) std::cout << "Please provide how much money you want to put into your ISA\n ~Type options to view the commands~\n  ";
						else
						{
							//Checks to see if the user has provided enough money (500)
							if(std::stof(parameters[2]) < 500) std::cout << "Please deposit 500 or more to make an ISA Savings account\n";
							else
							{
								//creates new Savings ISA account
								Account* savingIsa = new Saving(std::stof(parameters[2]),true);
								//Pushes new account into account vector
								accounts.push_back(savingIsa);
								//Changes currently selected to newly made account
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
			else if(parameters.size() < 2) //checks to see if the parameter size is 1
			{
				if(accounts.size() != 0) //Checks to see if they have any accounts open
				{
					//Displays all the accounts and their indexes in the account vectors
					for (int i = 0; i < accounts.size(); i++)
					{
						std::cout << i+1 << " : " << accounts[i]->getType() << " Account\n";
					}
				}
				else
				{
					//Tells the user they dont have any accounts 
					std::cout << "You have no accounts\nLearn how to make some by typing options\n";
				}
			}
			
			else // The user has provided with the account they want to view
			{
				//Checks if the user has provided a number
				if(isNumber(parameters[1]) == false) InvalidInput();
				else
				{
					//It can not be 0 since i am -1 any a -1 index doesnt exist in c++
					if(stoi(parameters[1]) == 0) InvalidInput();
					else
					{
						// Checks if the account is in the account vector
						int accountsSize = accounts.size() -1;
						if(accountsSize < stoi(parameters[1])-1) InvalidInput();
						else
						{
							//Displays history and info, also sets currently selected account
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
				//Checks if an account is selected
				if(currentlySelected == NULL) std::cout << "There is no account selected\nView an account to select that account\n";
				else
				{
					//
					if(isNumber(parameters[1]) == false) InvalidInput();
					else
					{
						//Withdraws from currently selected account
						currentlySelected->withdraw(std::stof(parameters[1]));
					}
				}
			}
		}
		else if (command.compare("deposit") == 0)
		{
			//Same checks are made for withdraw
			if(parameters.size() != 2) InvalidInput();
			else
			{
				//Checks if account is selected
				if(currentlySelected == NULL) std::cout << "There is no account selected\nView an account to select that account\n";
				else
				{
					if(isNumber(parameters[1]) == false) InvalidInput();
					else
					{
						// deposits entered amount into currently selected account
						currentlySelected->deposit(std::stof(parameters[1]));
					}
				}
			}
		}
		else if (command.compare("transfer") == 0)
		{
			//Checks if the right amount of parameters are given
			if(parameters.size() != 4) InvalidInput();
			else
			{
				bool PASSFLAG = true; //A flag to check if each parameter is a number
				for (int i = 1; i < parameters.size(); i++)
				{
					if(isNumber(parameters[i]) == false)
					{
						InvalidInput();
						PASSFLAG = false; //If one of the parameters is not a number it breaks and throws an error
						break;
					}
				}
				if(PASSFLAG == true)
				{
					float amount = std::stof(parameters[3]); //Amount they want to transfer
					if(stoi(parameters[1]) -1 > accounts.size() || stoi(parameters[2] ) -1 > accounts.size()) InvalidInput(); //Checks if accounts exist
					else
					{
						if(accounts[stoi(parameters[1]) -1]->getType() == "Current") //Checks account type
						{
							//Checks if they have enough money if not then the overdraft is used
							if(accounts[stoi(parameters[1]) -1]->getBalance() == 0)
							{
								float tempOverDraft = accounts[stoi(parameters[1]) -1] -> overdraft;
								if(tempOverDraft == 0 || tempOverDraft - amount < 0)std::cout << "Not enough money in account\n";
								else
								{
									//With draws from first account and deposits into second
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
						std::cout << "-----------\nCurrent Balance : "<< currentlySelected->getBalance() << "\nBalance in "<< parameters[1] << " years : ";
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

