#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#define N 5843
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

    priority_queue< long long, vector<long long>, greater<long long> > buffer;
    vector< long long > humbleNumbers;

    /// generation
    buffer.push(1);
    for( unsigned i = 0; i < N; ++i )
    {
        long long humbleNumber = buffer.top();

        while( buffer.top() == humbleNumber  && !buffer.empty() ) // removing repeats which will happen because 2*3 3*2 will both be generated below
            buffer.pop();

        buffer.push(humbleNumber * 2);
        buffer.push(humbleNumber * 3);
        buffer.push(humbleNumber * 5);
        buffer.push(humbleNumber * 7);

        humbleNumbers.push_back( humbleNumber );
    }

    int humbleNumNum;
    while( cin >> humbleNumNum )
    {
        if( humbleNumNum == 0 )
            break;
        else
        {
            string suffix = "th";
            int r = humbleNumNum%100;
            switch( r%10 )
            {
            case 1:
                if( r != 11 )
                    suffix = "st";
                break;
            case 2:
                if( r != 12 )
                    suffix = "nd";
                break;
            case 3:
                if( r != 13 )
                    suffix = "rd";
                break;
            default:
                break;
            }

            cout << "The " << humbleNumNum << suffix  + " humble number is " << humbleNumbers[humbleNumNum-1] << ".\n";
        }
    }

	return 0;
}
