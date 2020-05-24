#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector< unsigned int > missiles, table;
    unsigned int counter = 1, foundMax, hold;
    int tmp, i, k;

    while( cin >> tmp )
    {
        if( tmp < 0 )
            break;
        else missiles.push_back( tmp );
        while( cin >> tmp )
        {
            if( tmp < 0 )
                break;
            missiles.push_back( tmp );
        }
        table.assign( missiles.size(), 1 );
        foundMax = 1;
        for( i = missiles.size() - 2; i >= 0; --i )
        {
            hold = 0;
            for( k = (i+1); k < missiles.size(); ++k )
            {
                if( missiles[i] >= missiles[k] )
                {
                    if( table[k] > hold )
                        hold = table[k];
                }
            }
            table[i] += hold;
            if( table[i] > foundMax )
                foundMax = table[i];
        }
//        for( unsigned int i = 0; i < table.size() ; ++i )
//            cout << table[i] << " : ";
//        cout << endl;
        cout << "Test #" << counter << ":" << endl << "  maximum possible interceptions: " << foundMax << endl << endl;
        missiles.clear();
        table.clear();
        ++counter;
    }

    return 0;
}