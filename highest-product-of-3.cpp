#include <iostream>
#include <vector>

using namespace std;

pair <int, int> getMaxPair(vector <int> arr)
{
	int maxValue = 0;
	int maxIndex = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] > maxValue)
		{
			maxIndex = i;
			maxValue = arr[i];
		}
	}
	return make_pair(maxIndex, maxValue);
}

int getHighestProductOf3(vector <int> arr)
{
	int highestProduct = 1;
	for (int i = 0; i < 3; i++)
	{
		pair <int, int> maxPair = getMaxPair(arr);
		highestProduct *= maxPair.second;
		arr.erase(arr.begin() + maxPair.first);
	}
	return highestProduct;
}

int main()
{
	vector <int> testInput = {1, 7, 3, 4, 6, 5, 2, 8};
	cout << getHighestProductOf3(testInput) << endl;

	return 0;
}