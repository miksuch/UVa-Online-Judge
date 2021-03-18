#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <unordered_map>
using namespace std;

struct Edge {
int nodeA, nodeB, cost;
};

int findParent( vector<int> &parents, int child )
{
    if( parents[child] == -1 )
        return child;
    else return findParent( parents, parents[child] );
}

void makeUnion( vector< int > &parents, int setA, int setB )
{
    parents[setA] = setB;
}

bool hasCycle( vector<Edge> &g, int nodesCount )
{
    vector< int > parents;
    parents.assign( nodesCount, -1 );

    for( int i = 0; i < g.size(); ++i )
    {
        int parentA = findParent( parents, g[i].nodeA );
        int parentB = findParent( parents, g[i].nodeB );

        if( parentA == parentB )
            return true;
        else makeUnion( parents, parentA, parentB );
    }
    return false;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);

	int testCase;
	cin >> testCase;

	while (testCase--)
	{
        int numOfCities, numOfConnections;
        cin >> numOfCities >> numOfConnections;
        unordered_map< string, int > umap;

        umap.clear();
        int cityIdIterator = 0;

        vector< Edge > connections;

        while( numOfConnections-- )
        {
            string cityA, cityB;
            int cost;

            cin >> cityA >> cityB >> cost;

            if( umap.find(cityA) == umap.end() )
            {
                umap[cityA] = cityIdIterator++;
            }


            if( umap.find(cityB) == umap.end() )
            {
                umap[cityB] = cityIdIterator++;
            }

            Edge e;
            e.cost = cost;
            e.nodeA = umap[cityA];
            e.nodeB = umap[cityB];

            connections.push_back(e);
        }

        sort( connections.begin(), connections.end(), []( Edge &left, Edge &right )
             {
                 return left.cost < right.cost;
             });

        vector< Edge > mst;

        for( int i = 0; i < connections.size(); ++i )
        {
            mst.push_back( connections[i] );

            int cost = connections[i].cost;
            int a = connections[i].nodeB;
            int b = connections[i].nodeA;

            if( hasCycle( mst, numOfCities ) )
                mst.pop_back();

            if( mst.size() == numOfCities-1 )
                break;
        }

        int sum = 0;
        for( int i = 0; i < mst.size(); ++i )
            sum += mst[i].cost;

        cout << sum << endl;

        if( testCase )
            cout << endl;
	}

	return 0;
}
