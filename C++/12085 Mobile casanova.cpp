#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <sstream>
using namespace std;

string getRangeToAppend( string first, string last )
{
    string range="-";
    bool writeToRange = false;
    for( unsigned j = 0; j < first.size(); ++j )
    {
        if( last[j] != first[j] )
            writeToRange = true;

        if( writeToRange )
            range += last[j];
    }
    return range;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);

	int setSize, testCase=0;

	while(cin >> setSize)
	{
        if( setSize == 0 )
            break;

        // input
        vector<int> numbers;
        while( setSize-- )
        {
            int number;
            cin >> number;
            numbers.push_back(number);
        }

        // calculations
        vector<string> result;
        bool inSequence = false;
        int firstInSequence, sequenceLength;
        stringstream entry("");

        for( unsigned i = 0; i < numbers.size(); ++i )
        {
            if( inSequence )
            {
                if( numbers[i] == firstInSequence + sequenceLength )
                {
                    ++sequenceLength;
                    continue;
                }
                else
                {
                    if( sequenceLength > 1 )
                    {
                        string first = entry.str();
                        stringstream tmp;
                        tmp << "0" << numbers[i-1];
                        string last = tmp.str();

                        string range = getRangeToAppend( first, last );

                        entry << range;
                    }

                    result.push_back( entry.str() );
                    entry.str("");
                    inSequence = false;
                }
            }

            if( !inSequence )
            {
                firstInSequence = numbers[i];
                sequenceLength = 1;
                entry << "0" << numbers[i];
                inSequence = true;
            }
        }

        if( sequenceLength > 1 )
        {
            string first = entry.str();
            stringstream tmp;
            tmp << "0" << numbers[numbers.size()-1];
            string last = tmp.str();

            string range = getRangeToAppend( first, last );

            entry << range;
        }

        result.push_back( entry.str() );
        entry.str("");
        inSequence = false;

        cout << "Case " << ++testCase << ":\n";
        for( unsigned i = 0; i < result.size(); ++i )
            cout << result[i] << endl;
        cout << endl;
	}

	return 0;
}
