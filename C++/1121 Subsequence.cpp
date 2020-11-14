#include <iostream>
#include <algorithm>
#define N 100001
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);

    unsigned tSize, sumToMatch;
    while (cin >> tSize >> sumToMatch)
    {

        unsigned sequence[N];
        for( unsigned i = 0; i < tSize; ++i )
            cin >> sequence[i];

        unsigned currentSum = 0, bestLength = N;
        for( unsigned i = 0, leftIterator = 0; i < tSize && bestLength != 1; ++i )
        {
            currentSum += sequence[i];
            while( currentSum >= sumToMatch ) // dont have to check for left < i because then the sum just will get to 0, left = i, bestLength = 1 and it will move on
            {
                bestLength = std::min( bestLength, i - leftIterator );
                currentSum -= sequence[ leftIterator ];
                ++leftIterator;
            }
        }

        if( bestLength == N )
            cout << 0 << '\n';
        else cout << bestLength+1 << '\n';
    }

    return 0;
}
