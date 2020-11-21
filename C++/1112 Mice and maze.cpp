#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <unordered_map>
#define N 101
using namespace std;
int adj[N][N];
void resetAdjMat()
{
    for( unsigned i = 0; i < N; ++i )
        for( unsigned j = 0; j < N; ++j )
            adj[i][j] = 1000000000;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);

	int testCases;
	cin >> testCases;
	while( testCases-- )
	{

        int numOfCells, exit, ttl, connections;
        cin >> numOfCells >> exit >> ttl >> connections;
        --exit;

        resetAdjMat();
        while( connections-- )
        {
            int from, to, t;
            cin >> from >> to >> t;

            adj[--from][--to] = t;
        }

        for( int intermediateId = 0; intermediateId < numOfCells; ++intermediateId )
            for( int i = 0; i < numOfCells; ++i )
                for( int j = 0; j < numOfCells; ++j )
                    adj[i][j] = min( adj[i][j], adj[i][intermediateId] + adj[intermediateId][j] );

        int answer = 0;
        for( int i = 0; i < numOfCells; ++i )
        {
            if( adj[i][exit] <= ttl || i == exit )
                ++answer;
        }
        cout << answer << '\n';
        if( testCases )
            cout << '\n';
	}

	return 0;
}
