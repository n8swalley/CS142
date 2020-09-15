//********************************************************************************************
// Program 2 - While Loop Code
// Author: N8 Swalley
// Date: 
//
// 
//********************************************************************************************
#include <iostream>
#include <iomanip>

using namespace std; 

int main()
{
	int enteredAge = 0; 
	float avgAge = 0.0;
	int enteredIncome = 0;
	int numPeople = 0;
	int numPeopleOlderThan21 = 0;
	int sumOfAges = 0;
	
	while (enteredAge != -1){
	cout << "Enter in the persons age or -1 to exit: " << endl;
	cin >> enteredAge;
	if (enteredAge != -1) 
	{
		cout << "Enter the income of the person: " << endl;
		cin >> enteredIncome;
		
		sumOfAges = sumOfAges + enteredAge;
		numPeople++;
	}
	if (enteredAge >= 21)
	{
		numPeopleOlderThan21++;
	}
	}

cout << sumOfAges << endl;
cout << numPeople << endl;
avgAge = (float)sumOfAges/(float)numPeople;
cout << "Average person age is " << fixed << setprecision(3) << avgAge << endl;

		
	return 0;
	}