#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool customCompare( string const &left, string const &right )
{
    unsigned int i = 0;
    while( left[i] == right[i] )
        ++i;
    return left[i] < right[i];
}
int main()
{
    unsigned int i, c, k;
    vector< string > dictionary, answer;
    vector< vector< char > > letters;
    string tmp;
    char check[30];
    bool flag;
    cin >> tmp;
    dictionary.push_back(tmp);
    i = 0;
    letters.push_back( vector< char >() );
    letters[i].assign( 30, 0 );
    for( c = 0; c < tmp.size(); ++c )
        ++letters[i][ tmp[c] - 'a'];
    ++i;

    while( tmp != "XXXXXX" )
    {
        dictionary.push_back(tmp);
        letters.push_back( vector< char >() );
        letters[i].assign( 30, 0 );
        for( c = 0; c < tmp.size(); ++c )
            ++letters[i][ tmp[c] - 'a'];
        ++i;
        cin >> tmp;
    }

    cin >> tmp;
    while( tmp != "XXXXXX" )
    {
        flag = 0;
        for( c = 0; c < 30; ++c )
            check[c] = 0;
        for( c = 0; c < tmp.size(); ++c )
            ++check[ tmp[c] - 'a'];
        for( k = 0; k < dictionary.size(); ++k )
        {
            for( c = 0; c < 30; ++c )
            {
                if( check[c] != letters[k][c] )
                    break;
            }
            if( c == 30 )
            {
//                cout << dictionary[k] << endl;
                answer.push_back( dictionary[k] );
                flag = 1;
            }
        }
        if( !flag )
            cout << "NOT A VALID WORD" << endl;
        else
        {
            sort( answer.begin(), answer.end(), &customCompare );
            for( k = 0; k < answer.size(); ++k )
                cout << answer[k] << endl;
            answer.clear();
        }
        cout << "******" << endl;
        cin >> tmp;
    }
    letters.clear();
    dictionary.clear();

    return 0;
}
