#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;
#define N 1000

int dfs( int start, int parent, const int kNumber, vector< vector< int > > &adj ) // which returns number of nodes to be left
{
    vector<int> children;

//    if( adj[start].size() - 1 < kNumber && parent != 0 )
//        return 1;

    for( int i = 0; i < adj[start].size(); ++i )
    {
        if( adj[start][i] != parent )
        {
            int nodesCountInChild = dfs( adj[start][i], start, kNumber, adj );
            children.push_back( nodesCountInChild );
        }
    }

    if( children.size() >= kNumber )
    {
        sort( children.begin(), children.end(), greater<int>() );

        int nodeCount = 1;
        for( int i = 0; i < kNumber; ++i )
            nodeCount += children[i];

        return nodeCount;
    }
    else return 1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);

    int testCases;
    cin >> testCases;
    vector< vector< int > > adj;
    for( int t = 1; t <= testCases; ++t )
    {
        int nodes, kNumber;
        cin >> nodes >> kNumber;
        //cout << "nodes in tree = " << nodes << "; number K = " << kNumber << endl;
        adj.clear();
        adj.assign( nodes+1, vector<int>() );
        for( int i = 0; i < nodes-1; ++i )
        {
            int nodeA, nodeB;
            cin >> nodeA >> nodeB;
            adj[nodeA].push_back(nodeB);
            adj[nodeB].push_back(nodeA);
        }
        cout << "Case " << t << ": " << dfs( 1, 0, kNumber, adj ) << '\n';
    }

    return 0;
}
