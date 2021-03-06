#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;
#define N 101
int adj[N][N];
void resetAdjMat()
{
    for( unsigned i = 0; i < N; ++i )
        for( unsigned j = 0; j < N; ++j )
            if( i == j )
                adj[i][j] = 0;
            else adj[i][j] = N*N;
}
int main()
{
	//freopen("11463.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);

	int testCases;
	cin >> testCases;

	for( int i = 1; i <= testCases; ++i )
	{
        int buildings, roads, start, meetup, buildingA, buildingB;
        resetAdjMat();
        cin >> buildings >> roads;
        while( roads-- )
        {
            cin >> buildingA >> buildingB; // they are numbered from 0 so its fine
            adj[buildingA][buildingB] = 1;
            adj[buildingB][buildingA] = 1;
        }
        cin >> start >> meetup;

        for( int intermediateId = 0; intermediateId < buildings; ++intermediateId )
            for( int i = 0; i < buildings; ++i )
                for( int j = 0; j < buildings; ++j )
                    adj[i][j] = min( adj[i][j], adj[i][intermediateId] + adj[intermediateId][j] );

        int time = -1;
        for( int i = 0; i < buildings; ++i )
        {
            time = max( time, adj[start][i] + adj[i][meetup] );
        }

        cout << "Case " << i << ": " << time << '\n';

	}

	return 0;
}
