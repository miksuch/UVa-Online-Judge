#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <unordered_map>
#include <iomanip>
#define N 101
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

    int testCase = 0;

    unordered_map< string, int > umap;
    resetAdjMat();
    int idIterator = 0;
    string nodeA, nodeB;
    cout << fixed << setprecision(3);
    while( cin >> nodeA >> nodeB )
    {
        if( nodeA == "0" && nodeB == "0" ) // answer section
        {
            int numOfNodes = idIterator;
            for( int intermediateId = 0; intermediateId < numOfNodes; ++intermediateId )
                for( int i = 0; i < numOfNodes; ++i )
                    for( int j = 0; j < numOfNodes; ++j )
                        adj[i][j] = min( adj[i][j], adj[i][intermediateId] + adj[intermediateId][j] );

            double answer=0;
            for( int i = 0; i < numOfNodes; ++i )
                for( int j = 0; j < numOfNodes; ++j )
                    answer += adj[i][j]; // [i][j] when i==j is just 0 so its fine

            answer /= (numOfNodes)*(numOfNodes-1); // possible pairs
            cout << "Case " << ++testCase << ": average length between pages = " << answer << " clicks\n";

            cin >> nodeA >> nodeB;
            if( nodeA == "0" && nodeB == "0" ) // end of tests
                break;
            else // next test case
            {
                idIterator = 0;
                umap.clear();
                resetAdjMat();
            }
        }

        // input processing
        if( umap.find(nodeA) == umap.end() )
            umap[nodeA] = idIterator++;

        if( umap.find(nodeB) == umap.end() )
            umap[nodeB] = idIterator++;

        adj[ umap[nodeA] ][ umap[nodeB] ] = 1;

    }

    return 0;
}
