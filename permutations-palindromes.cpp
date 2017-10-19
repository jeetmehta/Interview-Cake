#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

bool isPermutationPalindrome(string input)
{
	unordered_map <char, int> occurences;
	
	for (int i = 0; i < input.length(); i++)
	{
		if (occurences.find(input[i]) == occurences.end())
			occurences.insert(make_pair(input[i], 1));
		else
			occurences[input[i]]++;
	}

	unordered_map<char, int>::iterator it = occurences.begin();
	bool singleOccurenceExists = false;
	for (it; it <= occurences.end(); it++)
	{
		if (!singleOccurenceExists && it->second == 1)
			singleOccurenceExists = true;
		else if (singleOccurenceExists && it->second == 1)
			return false;
	}
	return true;
}

int main()
{
	string test = "ivicc";
	cout << isPermutationPalindrome(test) << endl;
	return 0;
}