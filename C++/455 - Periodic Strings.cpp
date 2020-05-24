/* its AC but iirc its actually not 100% correct */
#include <iostream>
#include <string>
using namespace std;
bool findPeriod( string &str, string &word )
{
    unsigned int i,k;
    for( i = 0, k = 0; i < word.size(); ++i, ++k )
    {
        if( k == str.size() )
            k = 0;
        if( str[k] != word[i] )
            return 0;
    }
    if( k == str.size() )
        return 1;
    else return 0;
}
int main()
{
    unsigned int testCases, answer;
    string input, tmp;
    cin >> testCases;
    while( testCases-- )
    {
        cin >> input;
        answer = input.size();
        for( unsigned int i = 1; i <= input.size()/2; ++i )
        {
            tmp = "";
            for( unsigned int k = 0; k < i; ++k )
                tmp += input[k];
//            cout << tmp << endl;
            if( findPeriod( tmp, input ) )
            {
                answer = tmp.size();
//                cout << "exited on " << tmp << endl;
                break;
            }
        }
        cout << answer << endl;
        if( testCases >= 1 )
            cout << endl;
    }
    return 0;

}
