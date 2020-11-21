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
        string dnaString;
        cin >> dnaString;

        vector< string > dnaStrings;
        for( unsigned i = 0; i < dnaString.size(); ++i )
        {
            string tmp1 = dnaString.substr( 0, i );
            string tmp2 = dnaString.substr( i );
            dnaStrings.push_back( tmp2 + tmp1 );
        }

        sort( dnaStrings.begin(), dnaStrings.end() );
        cout << dnaStrings.front() << '\n';
	}

	return 0;
}
