/*
rainfallStats.cpp
Zachary Elmore
6/18/16
Enter your county and check to see the total and average rainfall for the year.
*/

#include <iostream>
#include<string>
#include <iomanip>
using namespace std;

int main()
{
	string countyName;
	double avgRainfall = 0;
	double totalRainfall = 0;
	double lowestRainfall;
	double highestRainfall;
	string driestMonth;
	string wettestMonth;
	string monthNames[] = { "January", "Febuary", "March", "April", "May", "June", "July", "August", "September",
		"October", "November", "December" };
	double monthlyTotals[12];

	cout << "\nEnter the name of your county: " << endl; //user inputs thier county name
	cin >> countyName;

	cout << "\nEnter the rainfall for each month\n" << endl;

	for (int i = 0; i < 12; i++) //user inputs the amount of rain for each month
	{
		cout << monthNames[i] << ": ";
		cin >> monthlyTotals[i];

		while (monthlyTotals[i] < 0)
		{
			cout << "Please enter a number for " << monthNames[i] << endl;
			cin >> monthlyTotals[i];
		}
	}

	for (int i = 0; i < 12; i++) //finds the total rainfall for the year
	{
		totalRainfall = totalRainfall + monthlyTotals[i];
	}

	avgRainfall = totalRainfall / 12; //finds the average rainfall for the year

	highestRainfall = monthlyTotals[0]; //arrays to find the wettest and driest months
	wettestMonth = monthNames[0];
	lowestRainfall = monthlyTotals[0];
	driestMonth = monthNames[0];

	for (int i = 1; i < 12; i++)
	{
		if (monthlyTotals[i] > highestRainfall) //array to find the wettest month
		{
			highestRainfall = monthlyTotals[i];
			wettestMonth = monthNames[i];
		}

		if (monthlyTotals[i] < lowestRainfall) //array to find the driest month
		{
			lowestRainfall = monthlyTotals[i];
			driestMonth = monthNames[i];
		}
	}


	cout << "\nAnnual Rain Report for " << countyName << " County." << endl; //output of the chart

	cout << "\nTotal rainfall: " << totalRainfall << " inches." << endl;

	cout << "Average rainfall: " << avgRainfall << " inches." << endl;

	cout << "The least fell in " << driestMonth << ", with " << lowestRainfall << " inches." << endl;

	cout << "The most fell in " << wettestMonth << ", with " << highestRainfall << " inches." << endl;

	cin.ignore();
	cin.get();
	return 0;
}