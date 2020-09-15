//**************************************************
// 
// Author: N8 Swalley
// Date: 9/25/2019
//
// This program asks the user to guess a number and insults them when they're too high or low. 
//**************************************************
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

int randomNum()
{
	srand(time(NULL));
	int mysteryNum = rand() % 100 + 1;
	return mysteryNum;
	
}

string insults()
{
		string insult;
		srand(time(NULL));
		int randint = rand() % 5;
		if (randint == 0)
		{
			insult = "you dirtbag!";
			return insult;
		}
		else if (randint == 1)
		{
			insult = "you butthead!";
			return insult;
		}
		else if (randint ==2)
		{
			insult = "you disgraceful scum!";
			return insult;
		}
		else if (randint ==3)
		{
			insult = "you pathetic loser!";
			return insult;
		}
		else if (randint ==4)
		{
			insult = "you imbecile!";
			return insult;
		}

}
	 	
void play()
{
	int numGuesses = 0;
	int quitorRestart = 0;
	int guess = 0;
	int mysteryNum = randomNum();

	cout << "***WELCOME TO THE GUESSING GAME!***" << endl;
	cout << "I have a number between 1 and 100. Can you guess it?" << endl;
	while(numGuesses > -1)
	{
		cout << "Enter your guess: ";
		cin >> guess;
		numGuesses++;
		
		if(guess > mysteryNum)
		{
			cout << "Too high, " << insults() << endl;
			//cout << "*Hint: the number is " << mysteryNum << "*" << endl;
		}
		
		else if(guess < mysteryNum)
		{
			cout << "Too low, " << insults() << endl;
			//cout << "*Hint: the number is " << mysteryNum << "*" << endl;
		}
		
		else 
		{  
			cout << "You Win!" << endl;
			cout << "It only took you " << numGuesses << " tries " << insults() << endl;
			break;
		}
	}
	
			cout << "Would you like to play again? Press 1 for yes or any other key for no!" << endl;
			cin >> quitorRestart;
			
			if (quitorRestart == 1)
			{
				play();
			}
			else 
			{
				cout << "Thanks for playing! Goodbye, " << insults() << endl;
			}
			
}

	
int main()
{

	play();

	return 0;
}
