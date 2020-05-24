#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
bool roadTable[30][30];
vector< string > foundPaths;
void printRoads()
{
    for( unsigned int i = 0; i < 26; ++i )
    {
        for( unsigned int k = 0; k < 26; ++k )
            cout << roadTable[i][k] << " ";
        cout << endl;
    }
}
void clearRoads()
{
    for( unsigned int i = 0; i < 30; ++i )
    {
        for( unsigned int k = 0; k < 30; ++k )
            roadTable[i][k] = 0;
    }
}
void travel( int origin, int destination, string path, bool visited[] )
{
    visited[ origin ] = 1;

    for( unsigned int i = 0; i < 30; ++i )
    {
        if( roadTable[origin][i] != 0 )
        {
            if( i == destination )
            {
//                cout << "FOUND DESTINATION FROM : " << char(origin+'A') << " TO : " << char(destination+'A')<< endl;
                foundPaths.push_back( path + char(destination + 'A') );
            }
            else if( !visited[i] )
            {
//                cout << "from : " << char(origin+'A') << " to : " << char(i+'A') << endl;
                travel( i, destination, path + char(i + 'A'), visited );
            }
        }
    }
}
int main()
{
    bool visited[30];
    string city1,city2,tmp;
    unsigned int testCases, pairs, queries, origin, destination, i, best;
    cin >> testCases;
    while( testCases-- )
    {
        clearRoads();
        cin >> pairs >> queries;
        while( pairs-- )
        {
            cin >> city1 >> city2;
            roadTable[ city1[0] - 'A' ][ city2[0] - 'A' ] = 1;
            roadTable[ city2[0] - 'A' ][ city1[0] - 'A' ] = 1;
        }
        while( queries-- )
        {
            cin >> city1 >> city2;
            origin = city1[0] - 'A';
            destination = city2[0] - 'A';
            tmp = ""; tmp += city1[0];
            travel( origin, destination, tmp, visited );
            for( i = 0; i < 30; ++i )
                        visited[i] = 0;
            best = 256;
            for( i = 0; i < foundPaths.size(); ++i )
            {
                if( foundPaths[i].size() < best )
                {
                    best = foundPaths[i].size();
                    tmp = foundPaths[i];
                }
            }
            cout << tmp << endl;
            foundPaths.clear();
        }
        cout << endl;
    }
    return 0;
}

