#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

class TempTracker
{
	private:
		int numTemps = 0;
		int maxTemp = -1;
		int minTemp = 111;
		int runningSum = 0;
		int lastTemp = -1;
		int maxOccurences = 1;
		int numOccurences = 1;
		int mode = 1;

	public:
		TempTracker();
		void insert(int temp);
		int getMax();
		int getMin();
		double getMean();
		int getMode();		
};

TempTracker::TempTracker(){};

void TempTracker::insert(int temp)
{
	if (temp > maxTemp)
		maxTemp = temp;

	if (temp < minTemp)
		minTemp = temp;

	runningSum += temp;
	numTemps++;

	if (temp == lastTemp)
		numOccurences++;

	if (numOccurences > maxOccurences)
	{
		maxOccurences = numOccurences;
		mode = temp;
	}

	lastTemp = temp;

}

int TempTracker::getMax()
{
	return maxTemp;
}

int TempTracker::getMin()
{
	return minTemp;
}

double TempTracker::getMean()
{
    return double(runningSum) / double(numTemps);
}

int TempTracker::getMode()
{
    return (mode > 1) ? mode : lastTemp;
}

int main()
{
	TempTracker tracker = TempTracker();
	for (int i = 0; i < 4; i++)
	{
		tracker.insert(i);
	}
	
	cout << "Max Temperature: " << tracker.getMax() << endl;
	cout << "Min Temperature: " << tracker.getMin() << endl;
	cout << "Mean Temperature: " << tracker.getMean() << endl;
	cout << "Mode Temperature: " << tracker.getMode() << endl;

	return 0;
}