#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
ofstream couta("isTree.txt");
vector< vector < int > > roadTable;
vector< int > potentialRoots;
bool isLoop( int idx, vector< bool > visited )
{
    if( visited[idx] == 1 )
        return 1;
    else visited[idx] = 1;
    for( unsigned int i = 0; i < roadTable.size(); ++i )
    {
        if( roadTable[i][1] == roadTable[idx][0] )
        {
            if( isLoop( i, visited) == 1 )
                return 1;
        }
    }
    return 0;
}
bool isTree()
{
    if( roadTable.size() == 0 )
        return 1;
    for( unsigned int i = 0; i < roadTable.size(); ++i )
    {
            if( roadTable[i].size() > 2 )
                return 0;
    }
    sort( potentialRoots.begin(), potentialRoots.end() );
    unique( potentialRoots.begin(), potentialRoots.end() );
    unsigned int idx = 1;
    while( idx < potentialRoots.size() )
    {
        if( potentialRoots[idx] <= potentialRoots[idx-1] )
            potentialRoots.erase( potentialRoots.begin() + idx );
        else ++idx;
    }
    if( potentialRoots.size() == 0 )
        return 0;
//    cout <<"potential roots:" << potentialRoots.size() << endl;
//    for( unsigned int i = 0 ; i < potentialRoots.size(); ++i )
//    {
//        cout << potentialRoots[i] << " ";
//    }
//    cout << endl;
    unsigned int zeroAppearances = 0;
    bool appeared;
    for( unsigned int i = 0; i < potentialRoots.size(); ++i )
    {
        appeared = 0;
        for( unsigned int k = 0; k < roadTable.size(); ++k )
        {
            if( roadTable[k].front() == potentialRoots[i] )
            {
                appeared = 1;
                break;
            }
        }
        if( !appeared )
        {
            ++zeroAppearances;
            if( zeroAppearances > 1 )
            {
                return 0;
            }
        }
    }
    if( zeroAppearances != 1 )
        return 0;
    // loop detector
    vector< bool > visited;
    for( unsigned int i = 0; i < roadTable.size(); ++i )
    {
        visited.assign( roadTable.size(), 0 );
        if( isLoop( i, visited ) == 1 )
            return 0;
        visited.clear();
    }
    return 1;
}
int main()
{
    int from, to, caseNumber = 1;
    bool flag = 0;
    while( cin >> from >> to )
    {
        if( to < 0 && from < 0 )
            break;
        if( to == 0 && from == 0 ) // empty tree is an empty tree 
        {
            if( !flag ) // to save it from checking everything 
            {
                if( isTree() ) // check for loops like 1 2 | 2 1
                    cout << "Case " << caseNumber << " is a tree." << endl;
                else
                {
                    cout << "Case " << caseNumber << " is not a tree." << endl;
//                    couta << "it didnt pass isTree" << endl;
                }

            }
            else cout << "Case " << caseNumber << " is not a tree." << endl;
            roadTable.clear();
            potentialRoots.clear();
            ++caseNumber;
            flag = 0;
        }
        else
        {
            if( flag );
            else if( to == from ) // when there`s a "loop" on the node itself -> not a tree
                flag = 1;
            else
            {
                for( unsigned int i = 0; i < roadTable.size(); ++i )
                {
                    if( to == roadTable[i].front() )
                    {
                        flag = 1;
                        break;
                    }
                }
                roadTable.push_back( vector< int >() );
                roadTable.back().push_back( to );
                roadTable.back().push_back( from );
                potentialRoots.push_back( from );
            }
        }
    }
    return 0;
}
