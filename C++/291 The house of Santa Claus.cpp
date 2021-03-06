#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
using namespace std;
#define N 5
int graph[N][N] = {
    { 0, 1, 1, 0, 1 },
    { 1, 0, 1, 0, 1 },
    { 1, 1, 0, 1, 1 },
    { 0, 0, 1, 0, 1 },
    { 1, 1, 1, 1, 0 }
    };
vector< string > paths;
void dfs( int start, int edgesDrawn, string path )
{
    path += (char)('0'+(start+1));
    if( edgesDrawn == N+3 )
    {
        paths.push_back(path);
        return;
    }

    for( int i = 0; i < N; ++i )
    {
        if( graph[start][i] == 1 )
        {
            graph[start][i] = 0; // making sure i wont use same edge twice
            graph[i][start] = 0;
            dfs( i, edgesDrawn+1, path );
            graph[start][i] = 1; // fixing it back
            graph[i][start] = 1;
        }
    }
}
int main()
{
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);

    dfs( 0, 0, "" );

    //sort( paths.begin(), paths.end() );
    for( int i = 0; i < paths.size(); ++i )
        cout << paths[i] << '\n';

	return 0;

}
