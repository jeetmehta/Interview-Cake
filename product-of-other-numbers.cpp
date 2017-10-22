#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector <int> arr)
{
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
}

vector <int> getProductsOfAllIntsExceptAtIndex(vector <int> input)
{
	if (input.size() <= 1)
		return input;

	// Products from left side
	int leftRunningProduct = 1;
	vector <int> leftProducts(input.size());
	for (int i = 0; i < input.size(); i++)
	{
		leftProducts[i] = leftRunningProduct;
		leftRunningProduct *= input[i];
	}

	// Combine with right side to get final result
	int rightRunningProduct = 1;
	for (int i = input.size() - 1; i >= 0; i--)
	{
		leftProducts[i] *= rightRunningProduct;
		rightRunningProduct *= input[i];
	}

	return leftProducts;
}

int main()
{
	vector <int> testInput = {1, 7, 3, 4};
	print_vector(getProductsOfAllIntsExceptAtIndex(testInput));

	return 0;
}