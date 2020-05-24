/* NOT ACCEPTED - long strings are killing it (TLE) ? */
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
ofstream couta( "secret.txt");
int main()
{
    string input;
    unsigned int testCases, hold, best, m, i;
    int k;
    cin >> testCases;
    while( testCases-- )
    {
        cin >> input;
        best = 1;
        for( i = 1; i < input.size(); ++i )
        {
            if( input[i] == input[0] )
            {
                hold = 1;
                for( k = i - 1, m = 1; k >= 0 && m < input.size() ; --k, ++m )
                {
                    if( input[m] == input[k] )
                    {
                        ++hold;
                    }
                    else break;

                }
                if( hold > best )
                    best = hold;
            }
        }
        for( k = best-1; k >= 0; --k )
            cout << input[k];
        cout << endl;
    }
    return 0;
}
