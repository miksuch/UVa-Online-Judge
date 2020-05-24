#include <iostream>
#include <string>
using namespace std;
string number;
unsigned int whoWins()
{
    int moves = 0;
    for( unsigned int i = 0; i < number.size(); ++i )
        if( ( number[i] - '0' ) % 3 == 0 )
            ++moves;
    return moves;
}
int main()
{
    unsigned int testCases, digitSum, counter;
    bool flag;
    cin >> testCases;
    counter = 1;
    while( counter <= testCases )
    {
        cin >> number;
        digitSum = 0;
        if( number.size() == 1 )
            cout << "Case " << counter <<": S" << endl;
        else
        {
            for( unsigned int i = 0; i < number.size(); ++i )
                digitSum += number[i] - '0';

            if( digitSum%3 == 0 )
            {
                if( whoWins() % 2 == 1 )
                    cout << "Case " << counter <<": S" << endl;
                else cout << "Case " << counter <<": T" << endl;
            }
            else
            {
                flag = 0;
                for( unsigned int i = 0; i < number.size() && !flag ; ++i )
                    if( ( digitSum - ( number[i] - '0' ) ) % 3 == 0 )
                        flag = 1;
                if( !flag )
                    cout << "Case " << counter <<": T" << endl;
                else if( whoWins() % 2 == 0 )
                    cout << "Case " << counter <<": S" << endl;
                else cout << "Case " << counter <<": T" << endl;
            }
        }
        ++counter;
    }
    return 0;

}
