#include <iostream> 
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);

	int testCase;
	cin >> testCase;
	
	string result;
	while (testCase--)
	{
		cin >> result;
		int counter = 0; int totalScore = 0;
		for (unsigned i = 0; i < result.size(); ++i)
		{
			if (result[i] == 'O')
			{
				++counter;
				totalScore += counter;
			}
			else counter = 0;
		}
		cout << totalScore << "\n";
	}

	return 0;
}