#include <iostream>
#include <cmath>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{

	ios_base::sync_with_stdio(0);

    int testCases;
    cin >> testCases;
    while( testCases-- )
    {
        int testSize, dnaLength;
        cin >> testSize >> dnaLength;

        vector< string > dnaStrings;
        while( testSize-- )
        {
            string dna;
            cin >> dna;
            dnaStrings.push_back( dna );
        }
        vector< pair< int, char > > counter;

        int consensusError = 0;
        string consensus="";
        for( unsigned i = 0; i < dnaLength; ++i )
        {
            counter.push_back( make_pair( 0, 'A') );
            counter.push_back( make_pair( 0, 'C') );
            counter.push_back( make_pair( 0, 'G') );
            counter.push_back( make_pair( 0, 'T') );

            for( unsigned j = 0; j < dnaStrings.size(); ++j )
            {
                if( dnaStrings[j][i] == 'A' )
                    counter[0].first++;
                else if( dnaStrings[j][i] == 'C' )
                    counter[1].first++;
                else if( dnaStrings[j][i] == 'G' )
                    counter[2].first++;
                else // ( dnaStrings[j][i] == 'T' )
                    counter[3].first++;
            }

            sort( counter.begin(), counter.end(),
                  []( pair< int, char > &left, pair< int, char > &right ) -> bool
            {
                if( left.first != right.first )
                    return left.first > right.first;
                else return (int)left.second < (int)right.second;

            }
                );


            consensus += counter[0].second;
            for( unsigned k = 1; k < counter.size(); ++k )
                consensusError += counter[k].first;

            counter.clear();
        }

        cout << consensus << '\n' << consensusError << '\n';

        dnaStrings.clear();
    }


    return 0;
}
