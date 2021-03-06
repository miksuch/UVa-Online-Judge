#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
#define N 1000
void bfs( int start, int numOfPeople, const vector< vector< int > > &v )
{
    bool visited[N];
    for(int i = 0; i < N; i++)
        visited[i] = 0;

    queue<int> q;

    visited[start] = 1;
    q.push(start);

    vector< int > honourLevels;
    honourLevels.assign( N, N*N );
    int honorLevel;
    honourLevels[start] = 0; // that would be don giovanni

    while( !q.empty() )
    {

        int node = q.front();
        q.pop();

        for( int i = 0; i < v[node].size(); ++i )
        {
            int idx = v[node][i];
            if( !visited[ idx ] )
            {
                visited[ idx ] = 1;
                q.push( idx );
                honourLevels[idx] = min( honourLevels[node]+1, honourLevels[idx] );
            }
        }
    }

    for( int i = 1; i < numOfPeople; ++i )
        cout << honourLevels[i] << '\n';
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);

	int testCase;
	cin >> testCase;

	while (testCase--)
	{
	    vector< vector< int > > dances;

	    dances.assign( N, vector<int>() );
        int numOfPeople, numOfPairs;
        cin >> numOfPeople >> numOfPairs;
        while( numOfPairs-- )
        {
            int personA, personB;
            cin >> personA >> personB;
            dances[personA].push_back( personB );
            dances[personB].push_back( personA );
        }
        bfs( 0, numOfPeople, dances );
        if( testCase )
            cout << '\n';
	}

	return 0;
}
