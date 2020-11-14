#include <iostream>
#include <cmath>
#define N 20001
using namespace std;
int parent[N];
void refresh()
{
    for( unsigned i = 0; i < N; ++i )
        parent[i] = i;
}
long long distanceToCenter( int enterprise, long long d = 0 )
{
    if( parent[enterprise] == enterprise )
        return d;
    else return distanceToCenter( parent[enterprise], d + (abs( enterprise - parent[enterprise])%1000 ) );
}
int main()
{

	ios_base::sync_with_stdio(0);

    int testCases;
    cin >> testCases;
    while( testCases-- )
    {
        int numOfEnterprises;
        cin >> numOfEnterprises;

        refresh();

        char c;
        while( cin >> c )
        {
            if( c == 'O' )
                break;

            if( c == 'I' )
            {
                int from, to;
                cin >> from >> to;
                parent[from] = to;
            }
            else
            {
                int enterprise;
                cin >> enterprise;
                cout << distanceToCenter( enterprise ) << '\n';
            }
        }
    }
    return 0;
}
