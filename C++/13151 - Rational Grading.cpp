#include <string>
#include<bits/stdc++.h>
#include <fstream>
using namespace std;
ofstream couta("2.txt");
int powerof( int x, int power )
{
    int answer = 1;
    for( unsigned int i = 0; i < power; ++i )
        answer *= x;
    return answer;
}
int main()
{
    string number, command;
    int operations, current, studentCurrent, mark, power;
    cin >> number >> operations;
    while( operations != 0 )
    {
        mark = 0;
        current = 0;
        if( number[0] != '0' ) //decimal
            current = atoi( number.c_str() );
        else if( number[1] != 'x' ) //octa
        {
            power = 0;
            for( unsigned int i = number.size()-1; i >= 1; --i )
            {
                current += (number[i] - '0') * powerof( 8, power );
                ++power;
            }
        }
        else //hexa
        {
            power = 0;
            for( unsigned int i = number.size()-1; i >= 2; --i )
            {
                if( number[i] > '9' )
                    current += (number[i] - 'A' + 10 ) * powerof( 16, power );
                else current += (number[i] - '0') * powerof( 16, power );
                ++power;
            }
        }
//        cout << current << endl;
        while( operations-- )
        {
            cin >> command >> studentCurrent;
            if( command[0] == '+' ) //pre
            {
                ++current;
                if( current == studentCurrent )
                    ++mark;
                current = studentCurrent;
            }
            else if( command[0] == '-' )
            {
                --current;
                if( current == studentCurrent )
                    ++mark;
                current = studentCurrent;
            }
            else if( command.size() == 1 )
            {
//                cout << current << command << studentCurrent << endl;
                if( current == studentCurrent )
                    ++mark;
                current = studentCurrent;
            }
            else if( command[2] == '+' )
            {
                if( current == studentCurrent )
                    ++mark;
                current = studentCurrent + 1;
            }
            else
            {
                if( current == studentCurrent )
                    ++mark;
                current = studentCurrent - 1;
            }

        }
        cout << mark << endl;
        cin >> number >> operations;
    }
    return 0;
}
