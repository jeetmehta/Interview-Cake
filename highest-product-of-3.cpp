#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getHighestProductOf3(vector <int> arr)
{
	// Need atleast 3 numbers
    if (arr.size() < 3)
		return -1;

	// Return product of an array sized 3
	else if (arr.size() == 3)
		return arr[0] * arr[1] * arr[2];

	// Store lowest and second lowest values
	int lowestValue = 9999999999;
	int secondLowestValue = 999999999;

	// Store the top 3 highest values
	int highestValue = 0;
	int secondHighestValue = 0;
	int thirdHighestValue = 0;

	// Update lowest/highest values through an iteration in the array - O(n)
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] > highestValue)
		{
			thirdHighestValue = secondHighestValue;
			secondHighestValue = highestValue;
			highestValue = arr[i];
		}
		else if (arr[i] <= highestValue && arr[i] > secondHighestValue)
		{
			thirdHighestValue = secondHighestValue;
			secondHighestValue = arr[i];
		}
		else if (arr[i] <= secondHighestValue && arr[i] > thirdHighestValue)
			thirdHighestValue = arr[i];

		if (arr[i] < lowestValue)
			lowestValue = arr[i];
		else if (arr[i] >= lowestValue && arr[i] < secondLowestValue)
			secondLowestValue = arr[i];
	}
    
    // Return the greater product of the two (accounts for negative numbers that produce positive products)
	int negProduct = lowestValue * secondLowestValue * highestValue;
	int posProduct = highestValue * secondHighestValue * thirdHighestValue;
	return (negProduct > posProduct) ? negProduct : posProduct;
}

int main()
{
	vector <int> testInput = {-10, -8, 8, 7, 6, 5, 1, 3, 2};
	cout << getHighestProductOf3(testInput) << endl;

	return 0;
}