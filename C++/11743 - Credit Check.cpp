#include <iostream>
#include <string>
using namespace std;
int main()
{
    string CCNumber[4];
    unsigned int testCases, Digit, sum;
    cin >> testCases;
    while( testCases-- )
    {
        sum = 0;
        for( unsigned int i = 0; i < 4; ++i )
        {
            cin >> CCNumber[i];
            Digit = 2*( ( CCNumber[i][0] - '0' ) );
            sum += ( Digit / 10 ) + Digit % 10;
            Digit = 2*( ( CCNumber[i][2] - '0' ) );
            sum += ( Digit / 10 ) + Digit % 10;
            Digit = ( CCNumber[i][1] - '0' );
            sum += Digit;
            Digit = ( CCNumber[i][3] - '0' );
            sum += Digit;

        }
//        cout << "sum : " << sum <<  endl;
        if( sum%10 == 0 )
            cout << "Valid" << endl;
        else cout << "Invalid" << endl;
    }
    return 0;
}
