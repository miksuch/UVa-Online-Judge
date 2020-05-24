#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    int words, length, idx;
    string word;
    vector< string > morphs;
    while( cin >> words >> length )
    {
        morphs.assign( length + 1, "" );
        cin >> word; // starting word
        morphs[0] = word;
        cin >> word; // end result
        morphs[ length ] = word;
        words -= 2;
        while( words-- )
        {
            cin >> word;
            idx = 0;
            for( unsigned int i = 0; i < length; ++i )
            {
                if( word[i] != morphs[0][i] )
                    ++idx;
            }
            morphs[idx] = word;
        }
        for( unsigned int i = 0; i < morphs.size(); ++i )
            cout << morphs[i] << endl;
    }
    return 0;
}

