#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(string input)
{
	int left = 0;
	int right = input.length() - 1;

	while (left < right)
	{
		if (input[left] != input[right])
			return false;
		left++;
		right--;
	}
	return true;
}

int main()
{
	string test = "civic";
	cout << isPalindrome(test) << endl;
	return 0;
}