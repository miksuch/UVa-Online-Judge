#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <unordered_map>
#define N 51
using namespace std;
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
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);

	int connections, testCase = 0;
	while( cin >> connections )
	{

        if( !connections )
            break;

        resetAdjMat();
	    unordered_map< string, int > umap;
	    int idIterator = 0;
        while( connections-- )
        {
            string nodeA, nodeB;
            cin >> nodeA >> nodeB;

            if( umap.find(nodeA) == umap.end() )
                umap[nodeA] = idIterator++;

            if( umap.find(nodeB) == umap.end() )
                umap[nodeB] = idIterator++;

            if( nodeB != nodeA )
            {
                adj[ umap[nodeA] ][ umap[nodeB] ] = 1;
                adj[ umap[nodeB] ][ umap[nodeA] ] = 1;
            }
            else
            {
                adj[ umap[nodeA] ][ umap[nodeB] ] = 0;
                adj[ umap[nodeB] ][ umap[nodeA] ] = 0;
            }

        }

        int numOfNodes = idIterator;
        for( int intermediateId = 0; intermediateId < numOfNodes; ++intermediateId )
            for( int i = 0; i < numOfNodes; ++i )
                for( int j = 0; j < numOfNodes; ++j )
                    adj[i][j] = min( adj[i][j], adj[i][intermediateId] + adj[intermediateId][j] );

        string queryNode;
        int ttl;
        while( cin >> queryNode >> ttl )
        {
            if( queryNode == "0" && !ttl )
                break;

            int answer;
            if( umap.find(queryNode) == umap.end() )
            {
                answer = numOfNodes;
            }
            else
            {
                answer = 0;
                for( int i = 0; i < numOfNodes; ++i )
                    if( adj[ umap[queryNode] ][i] > ttl )
                        ++answer;
            }

            cout << "Case " << ++testCase << ": " << answer << " nodes not reachable from node " << queryNode << " with TTL = " << ttl << ".\n";
        }
        umap.clear();

	}

	return 0;
}
