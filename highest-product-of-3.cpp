#include <iostream>
#include <vector>
#include <algorithm>

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
	// Sort the array - O(nlogn)
	sort(arr.begin(), arr.end());

	// Return the greater of the two products (LHS and RHS) -> done to acount for positive products from negative numbers
	int negProduct = arr[0] * arr[1] * arr[arr.size() - 1];
	int posProduct = arr[arr.size() - 1] * arr[arr.size() - 2] * arr[arr.size() - 3];
	return (negProduct > posProduct) ? negProduct : posProduct;
}

int main()
{
	vector <int> testInput = {-10, -10, 1, 3, 2};
	cout << getHighestProductOf3(testInput) << endl;

	return 0;
}