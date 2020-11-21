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
            else adj[i][j] = N;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);

	int numOfPeople, numOfRelations, testCase = 0;
	while( cin >> numOfPeople >> numOfRelations )
	{

        if( !numOfPeople && !numOfRelations )
            break;

        resetAdjMat();
	    unordered_map< string, int > nameMap;
	    int idIterator = 0;
        while( numOfRelations-- )
        {
            string nameA, nameB;
            cin >> nameA >> nameB;

            if( nameMap.find(nameA) == nameMap.end() )
                nameMap[nameA] = idIterator++;

            if( nameMap.find(nameB) == nameMap.end() )
                nameMap[nameB] = idIterator++;

            adj[ nameMap[nameA] ][ nameMap[nameB] ] = 1;
            adj[ nameMap[nameB] ][ nameMap[nameA] ] = 1;

        }
        nameMap.clear();

        for( int intermediateId = 0; intermediateId < numOfPeople; ++intermediateId )
            for( int i = 0; i < numOfPeople; ++i )
                for( int j = 0; j < numOfPeople; ++j )
                    adj[i][j] = min( adj[i][j], adj[i][intermediateId] + adj[intermediateId][j] );

        int answer = 0;
        for( int i = 0; i < numOfPeople; ++i )
            for( int j = 0; j < numOfPeople; ++j )
                answer = max( answer, adj[i][j] );

        if( answer == N )
            cout << "Network " << ++testCase << ": DISCONNECTED\n\n";
        else cout << "Network " << ++testCase << ": " << answer << "\n\n";

	}

	return 0;
}
