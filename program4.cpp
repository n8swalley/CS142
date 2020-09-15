 //********************************************************************************************
// Program 4 - While Loop Code
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
	int numOfAccidents = 0;
	float costPerYear = 0.0;
	float baseAmount = 0.0;
	float costPerMonth = 0.0;
	
	cout << "Enter in the persons age: " << endl;
	cin >> enteredAge;
	if (enteredAge >= 16 && enteredAge <= 20) 
	{
		baseAmount = 3000.00;
		
	}
	else if (enteredAge >= 21 && enteredAge <= 24)
	{
		baseAmount = 1800.00;
		
	}
	else if (enteredAge >= 74)
	{
		baseAmount = 2000.00;
	}
	else
	{
		baseAmount = 1200.00;
	}
	costPerYear = baseAmount * 0.07 * ((float)numOfAccidents + baseAmount);
	costPerMonth = costPerYear/12.0;
		
	return 0;
	}