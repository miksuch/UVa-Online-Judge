#include <iostream>
#include <vector>
using namespace std;
int main()
{
    unsigned int N, tests;
    int x, number;
    vector<string> command;
    string input;
    cin >> N;
    while( N-- )
    {
        x = 0;
        cin >> tests;
        while( tests-- )
        {
            cin >> input;
            if( input == "LEFT" || input == "RIGHT" )
                command.push_back(input);
            else
            {
                cin >> input >> number;
                --number;
                command.push_back( command[number] );
            }
        }
        for( unsigned int i = 0; i < command.size(); ++i )
        {
            if( command[i] == "RIGHT" )
                ++x;
            else --x;
        }
        cout << x << endl;
        command.clear();
    }
    return 0;
}
