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
	
	vector <int> output(input.size());
	for (int i = 0; i < input.size(); i++)
	{
		int product = 1;
		for (int j = 0; j < input.size(); j++)
		{
			if (i != j)
				product *= input[j];
		}
		output[i] = product;
	}
	return output;
}

int main()
{
	vector <int> testInput = {1, 7, 3, 4};
	print_vector(getProductsOfAllIntsExceptAtIndex(testInput));

	return 0;
}