//**************************************************
// 
// Author: N8 Swalley
// Date: Tuesday, 22-October 2019
//
// This program encrypts and decrypts text from a file provided by the user!
//**************************************************

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
using namespace std; 


string inputFile(string nameOfInputFile, string userInputText)
{
	ifstream fileToReadIn;
	string newNameOfInputFile = "";
	
	if(nameOfInputFile != "")
	{
		fileToReadIn.open(nameOfInputFile.c_str());
			
		if(fileToReadIn.fail())
		{
			cout << "ERROR: filename can't be found" << endl;
			cout << endl;
			cout << "Please enter a valid filename: ";
			cin >> newNameOfInputFile;
			cout << endl;
			inputFile(newNameOfInputFile, userInputText);
	
		}
		else
		{
			getline(fileToReadIn,userInputText);
		}
	}
	return userInputText;
	fileToReadIn.close();		
	
}

string outputFile(string nameOfOutputFile, string userInputText)
{
	ofstream fileToOutput;
	
	
	if(nameOfOutputFile != "")
	{
		fileToOutput.open(nameOfOutputFile.c_str());
		
		if(fileToOutput.fail())
		{
			cout << "Unable to output the message to that file" << endl;
			
		}
		else 
		{
			fileToOutput << userInputText << endl;
		}
	}
	return userInputText;
	fileToOutput.close();
}

void encryptInputText(string nameOfOutputFile, string userInputText, int shift)
{
	for(int loopVar1 = 0; loopVar1 < userInputText.length() ; loopVar1++)
	{
		shift = rand() % 26 ;
		if ((userInputText[loopVar1] >= 97 && userInputText[loopVar1] <= 122) )
		{
			if (userInputText[loopVar1] + shift > 122)
			{
				userInputText[loopVar1] = (userInputText[loopVar1] + shift) - (26); //or 58 if it must wrap to uppercase
				
			}	
			else
			{
				userInputText[loopVar1] += (shift);
			}
		}
		else if ((userInputText[loopVar1] >= 65 && userInputText[loopVar1] <= 90))
		{
			if (userInputText[loopVar1] + shift > 90)
			{
				userInputText[loopVar1] = (userInputText[loopVar1] + shift) - (26); // or + 6 if it must wrap to other set
				 
			}
			else
			{
				userInputText[loopVar1] += shift;  
			}
		} 
		
	}

	userInputText = outputFile(nameOfOutputFile, userInputText);
}

void decryptInputText(string nameOfOutputFile, string userInputText, int shift)
{
	for(int loopVar1 = 0; loopVar1 < userInputText.length() ; loopVar1++)
	{
		shift = rand() % 26 ;
		if ((userInputText[loopVar1] >= 97 && userInputText[loopVar1] <= 122) )
		{
			if (userInputText[loopVar1] - shift < 97)
			{
				userInputText[loopVar1] = (userInputText[loopVar1] - shift) + (26); //or - 6
			}	
			else
			{
				userInputText[loopVar1] -= shift;
			}
		}
		else if ((userInputText[loopVar1] >= 65 && userInputText[loopVar1] <= 90))
		{
			if (userInputText[loopVar1] - shift < 65)
			{
				
				userInputText[loopVar1] = (userInputText[loopVar1] - shift) + (26); //or 58
				
	
			}
			else
			{
				userInputText[loopVar1] -= shift; 
			}
		} 
		
	}
	
	userInputText = outputFile(nameOfOutputFile, userInputText);
	
} 
 
void runProgram()
{
	char encryptOrDecryptChoice = ' ';
	string userInputText = "";
	int shift = 0;
	int indexOfFirstSpace = 0;
	int indexOfPunctuation = 0;
	char choice = ' ';
	ofstream fileToOutput;
	ifstream fileToReadIn;
	string nameOfInputFile;
	string nameOfOutputFile;
	
	if(choice != 'n')
	{
		cout << "Enter the name of the file that contains the message: ";
		cin >> nameOfInputFile;
		cout << endl;
		userInputText = inputFile(nameOfInputFile, userInputText); 
		cout <<"Would you like to encrypt or decrypt? e/d: ";
		cin >> encryptOrDecryptChoice;
		cout << endl;
		cout << "Enter in the secret key: ";
		cin >> shift;
		srand(shift);
		shift = rand() % 26 ;
		cout << endl;
		cout << "Enter the name of the file to return the encoded message: ";
		cin >> nameOfOutputFile;
		cout << endl;
		if (encryptOrDecryptChoice == 'e')
		{
			encryptInputText(nameOfOutputFile, userInputText, shift);
			cout << "Message successfully encrypted!" <<endl;
			cout << endl;
			cout << "Would you like to encrypt or decrypt another message? y/n: ";
			cin >> choice;
			if (choice == 'y')
			{
				cout << endl;
				runProgram();
			}
		}
		else if (encryptOrDecryptChoice = 'd')
		{
			decryptInputText(nameOfOutputFile, userInputText, shift);
			cout << "Message successfully decrypted!" <<endl;
			cout << endl;
			cout << "Would you like to encrypt or decrypt another message? y/n: ";
			cin >> choice;
			if (choice == 'y')
			{
				cout << endl;
				runProgram();
			}			
		}
	}	
	
	if (choice == 'n')
	{
		cout << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "*********************Goodbye*********************" << endl;
		cout << "-------------------------------------------------" << endl;
		cout << endl;
	}
}

int main()
{	
	
	cout << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "*****Welcome to the Secret Message Program!******" << endl;	
	cout << "-------------------------------------------------" << endl;
	cout << endl;
	runProgram();
	
	return 0;
}