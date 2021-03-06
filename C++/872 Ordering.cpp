#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <sstream>
using namespace std;
#define N 26
bool visited[N], usedVariables[N];
bool adj[N][N];
void falseAll()
{
    for( unsigned int i = 0; i < N; ++i )
    {
        visited[i] = false;
        usedVariables[i] = false;
        for( unsigned int j = 0; j < N; ++j )
            adj[i][j] = false;
    }
}
void dfs( int index, const int length, string result, bool &foundOrder )
{
    if( index == length )
    {
        cout << result[0];
        for( int i = 1; i < length; ++i )
            cout << ' ' << result[i];
        cout << '\n';

        foundOrder = true;

        return;
    }

    for( int i = 0; i < N; ++i )
    {
        if( usedVariables[i] == true && !visited[i] )
        {
            for( int j = 0; j < N; ++j )
            {
                if( adj[i][j] && visited[j] )
                {
                    return;
                }
            }

            visited[i] = true;
            //result += 'A' + i;
            result[index] = i + 'A';
            dfs( index + 1, length, result, foundOrder );
            visited[i] = false;
        }
    }
}

int main()
{
    //freopen("872.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);

    int testCases;
    cin >> testCases;

    cin.get();
    cin.ignore();

    while( testCases-- )
    {
        falseAll();

        string variables;

        getline( cin, variables );
        stringstream stringStream = stringstream( variables );

        int usedVariablesCount = 0;
        for( char c; stringStream >> c; ++usedVariablesCount )
            usedVariables[ c - 'A' ] = true;

        char letterA, lessThan, letterB;
        getline( cin, variables );
        stringStream = stringstream( variables );
        while( stringStream >> letterA >> lessThan >> letterB )
        {
            adj[ letterA - 'A' ][ letterB - 'A' ] = 1;
        }

        cin.get();
        //cin.ignore();

        bool foundOrder = false;
        string ans = "";
        for( int i = 0; i < usedVariablesCount; ++i )
            ans += ' ';

        dfs( 0, usedVariablesCount, ans, foundOrder );

        if( !foundOrder )
            cout << "NO" << '\n';

        if( testCases )
            cout << '\n';

    }
    return 0;
}
