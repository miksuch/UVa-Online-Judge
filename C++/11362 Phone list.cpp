#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);

	int testCase;
	cin >> testCase;

	while (testCase--)
	{

        vector<string> phoneNumbers;
        phoneNumbers.clear();

        int testSize;
        cin >> testSize;

        while(testSize--)
        {
            string phoneNumber;
            cin >> phoneNumber;
            phoneNumbers.push_back(phoneNumber);
        }

        sort(phoneNumbers.begin(), phoneNumbers.end());

        bool consistent = true;
        for( int i = 1; i < phoneNumbers.size() && consistent; ++i )
        {
            int j = 0;
            while( j < phoneNumbers[i-1].size() && j < phoneNumbers[i].size() )
            {
                if( phoneNumbers[i-1][j] == phoneNumbers[i][j] )
                {
                    ++j;
                }
                else break;
            }

            if( j == phoneNumbers[i-1].size() )
                consistent = false;
        }

        if( !consistent )
            cout << "NO\n";
        else cout << "YES\n";
	}

	return 0;
}
