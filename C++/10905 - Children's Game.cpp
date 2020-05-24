#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool customCompare( string const &left, string const &right )
{
    unsigned int i = 0;
    string test1 = left + right,test2 = right + left;
    for( ; i < test1.size(); ++i )
        if( test1[i] != test2[i] )
            return test1[i] > test2[i];
    return 1;
}
int main()
{
    vector< string > numbers, answer;
    string tmp;
    unsigned int tests;
    cin >> tests;
    while( tests != 0 )
    {
        while( tests-- )
        {
            cin >> tmp;
            numbers.push_back(tmp);
        }
        sort( numbers.begin(), numbers.end(), &customCompare );
//        tmp ="";
        for( unsigned int i = 0; i < numbers.size() ; ++i )
            cout << numbers[i];
        cout << endl;
        numbers.clear();
        cin >> tests;
    }

    return 0;
}
