#include <iostream>
#include <vector>
using namespace std;
int main()
{
    unsigned int ladiesN, heightsN, tmp, found, idx, k;
    bool flag;
    vector< unsigned int > lady;
    cin >> ladiesN;
    while( ladiesN-- )
    {
        cin >> tmp;
        lady.push_back(tmp);
    }
    cin >> heightsN;
    while( heightsN-- )
    {
        cin >> tmp;
        found = 0;
        flag = 0;
        if( tmp > lady.back() )
        {
            lady.push_back( tmp );
            flag = 1;
            idx = lady.size() - 1;
        }
        else // ( lady[found] != tmp )
        {
            idx = found;
            for(; idx < lady.size(); ++idx )
            {
                if( lady[idx] == tmp )
                    break;
                if( lady[idx] > tmp )
                {
                    flag = 1;
                    break;
                }
            }
            if( flag )
                lady.insert( lady.begin() + idx, tmp );

        }
        found = idx;
        if( lady[found] == tmp )
        {
            if( found == 0 )
                cout << "X";
            else cout << lady[found-1];
            cout << " ";
            for( k = found; k < lady.size(); ++k )
            {
                if( lady[k] != tmp )
                {
                    cout << lady[k];
                    break;
                }
            }
            if( k == lady.size() )
                cout << "X";
            cout << endl;
        }
        if( flag )
            lady.erase( lady.begin() + idx );
    }
    return 0;
}