#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class TempTracker
{
	private:
		vector <int> temperatures;
		map <int, int> freq;
		int maxTemp = -1;
		int minTemp = 111;
		int runningSum = 0;

	public:
		TempTracker();
		void insert(int temp);
		int getMax();
		int getMin();
		double getMean();
		int getMode();		
};

void TempTracker::insert(int temp)
{
	if (temp > maxTemp)
		maxTemp = temp;

	if (temp < minTemp)
		minTemp = temp;

	runningSum += temp;

	if (freq.find(temp) == freq.end())
		freq.insert(make_pair(temp, 1));
	else
		freq[temp]++;

	temperatures.push_back(temp);
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
	return (double)(runningSum / temperatures.size());
}

int TempTracker::getMode()
{
    std::vector <pair <int, int>> results(1);
	std::partial_sort_copy(
    	freq.begin(), freq.end(), 
    	results.begin(), results.end(), 
    	[](const pair <int, int> &lhs, const pair <int, int> &rhs) { return lhs.second > rhs.second; }
	);
    return results[0].second;
}

int main()
{
	return 0;
}