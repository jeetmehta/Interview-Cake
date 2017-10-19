#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

bool isPermutationPalindrome(string input)
{
	unordered_set <char> oddOccurences;
	
	for (int i = 0; i < input.length(); i++)
	{
		if (oddOccurences.find(input[i]) != oddOccurences.end())
			oddOccurences.erase(input[i]);
		else
			oddOccurences.insert(input[i]);
	}

	return (oddOccurences.size() <= 1) ? 1 : 0;
}

int main()
{
	string test = "ivicc";
	cout << isPermutationPalindrome(test) << endl;
	return 0;
}