//**************************************************
// 
// Author: N8 Swalley
// Date: Tuesday, 22-October 2019
//
// This program gives the user commands for their candy database!
//**************************************************
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

void commands() 
{
	cout << "Here is a list of commands: " << endl;
	cout << "E - Eat a piece of candy" << endl;
	cout << "T - Trick or Treat: get a piece of candy" << endl;
	cout << "I - Inventory listing" << endl;
	cout << "C - List candy types" << endl;
	cout << "M - Print this menu of commands" << endl;
	cout << "S - Save to the file candy.dat" << endl;
	cout << "L - Load from the file candy.dat" << endl;
	cout << "Q - Quit this program" << endl;
	
}

void eat(int candy[])
{
	int candyChoice = 0;
	cout << "Please enter the candy type (1-6):" << endl;
	cin >> candyChoice;
	
	if (candy[candyChoice-1] == 0 || (candyChoice < 1 || candyChoice > 6)) // takes care of invalid inputs
	{
		cout << "ERROR - You don't have any candy of that type." << endl;
	}
	
	else
	{
		candy[candyChoice-1]--;
		cout << "Candy has been eaten!" << endl;
	}
	
}

void trickOrTreat(int candy[])
{
	int candyChoice = 0;
	cout << "Please enter the candy type (1-6):" << endl;
	cin >> candyChoice;
	
	if (candyChoice < 1 || candyChoice > 6)
	{
		cout << "Error- That type doesn't exist." << endl; // takes care of invalid inputs
	}
	
	else
	{
		candy[candyChoice-1]++;
		cout << "You recieved a piece of candy!" << endl;
	}
}

void inventory(int candy[])
{
	int numCandies = 0;
		
	cout << "Candy Corn:		" << candy[0] << endl;
	cout << "Licorice:               " << candy[1] << endl;
	cout << "Jaw Breakers:		" << candy[2] << endl;
	cout << "Peanutbutter Cups:	" << candy[3] << endl;
	cout << "M&Ms:		        " << candy[4] << endl;
	cout << "Other:		        " << candy[5] << endl;
	
	for (int loopVar1=0; loopVar1 < 6; loopVar1++)
	{
		if (candy[loopVar1] > 0)
		{
		numCandies += candy[loopVar1];
		}

	}	
	
	if (numCandies == 1)
	{
		cout << "You have " << numCandies << " piece of candy." << endl; // accounts for case where user only has 1 piece of candy and makes it gramatically correct. 
	}
	
	else
	{
		cout << "You have " << numCandies << " pieces of candy." << endl;
	}
}

void candyTypes()
{
	cout << "#1 Candy Corn" << endl;
	cout << "#2 Licorice" << endl;
	cout << "#3 Jaw Breakers"<< endl;
	cout << "#4 Peanutbutter Cups" << endl;
	cout << "#5 M&Ms" << endl;
	cout << "#6 Other" << endl;
	
}

void fileSave(int candy[])
{
 ofstream outputStreamHandler;
	
	outputStreamHandler.open("candy.dat");
	for (int loopVar2=0; loopVar2 < 6; loopVar2++)
	{
		outputStreamHandler << candy[loopVar2]  << endl;
	}
	
	outputStreamHandler.close();
	
	cout << "Data saved to file" << endl;

}

void fileLoad(int candy[])
{
	ifstream inputStreamHandler;
	
	cout << "Loading file:" << endl;
	inputStreamHandler.open("candy.dat");
	
	if (inputStreamHandler.fail())
	{
		cout << "ERROR - Unable to load file" << endl;
	
	}
	
	else
	{
		for (int loopVar3=0; loopVar3 < 6; loopVar3++)
		{
			inputStreamHandler >> candy[loopVar3];
	
		}
		cout << "File loaded successfully" << endl;
	}

	inputStreamHandler.close();	
	
}

int main()
{
	string userChoice = " "; // Normally, a char would work here but I went with a string to account for errors easier
	int candy[6] = {0,0,0,0,0,0}; // I have 7 elements in the array so that way I don't have to confuse myself trying to get each index
	
	cout << "🎃👻️🦇🍬 Welcome to the Halloween Program! 🍬🦇👻🎃" << endl;
	commands();
	
	while (userChoice != "Q")
	{
		cout << "Command ->";
		cin >> userChoice;
		if (userChoice == "E")
		{
			eat(candy);
		}
		else if (userChoice == "T")
		{
			trickOrTreat(candy);
		}
		else if (userChoice == "I")
		{
			inventory(candy);	
		}
		else if(userChoice == "C")
		{
			candyTypes();
		}
		else if(userChoice == "M")
		{
			commands();
		}
		else if(userChoice == "S")
		{
			fileSave(candy);
		}
		else if(userChoice == "L")
		{
			fileLoad(candy);
		}
		else if(userChoice == "Q")
		{
			cout << "🎃👻🦇🍬 HAPPY HALLOWEEN! 🍬🦇👻🎃" << endl;
		}
		
		else // takes care of instances where user gives invalid response
		{
			cout << "ERROR - Please enter a valid command" << endl;
		}	
		
	}
}
