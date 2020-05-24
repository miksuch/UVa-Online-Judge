/* if you were looking for quality code - i`m so sorry */
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
vector< int > isLeaf, isLeafNext;
vector< bool > isLeafBool;
vector< int > edgeA, edgeB;
vector< vector< int > > adjacent;
vector< int > worstRoots;
int bestRoots[2], heightOfTree;
unsigned int N;
void leavesElimination( bool first )
{
    ++heightOfTree;
    if( edgeA.size() > 2 )
    {
        int checkForStar[2], flag = 1, theStar;
        bool isStar = 1;
        isLeafNext = isLeaf;
        for( unsigned int i = 0; i < edgeA.size(); ++i )
        {
            if( isLeaf[ edgeA[i] ] == 1 ||  isLeaf[ edgeB[i] ] == 1 )
            {
                if( flag == 1)
                {
                    checkForStar[0] = edgeA[i];
                    checkForStar[1] = edgeB[i];
                    flag = 2;
                }
                else if( flag == 2 )
                {
                    if( edgeA[i] == checkForStar[0] || edgeB[i] == checkForStar[0] )
                        theStar = checkForStar[0];
                    else if( edgeA[i] == checkForStar[1] || edgeB[i] == checkForStar[1] )
                        theStar = checkForStar[1];
                    else isStar = 0;
                    ++flag;
                }
                else if( theStar != edgeA[i] && theStar != edgeB[i] )
                    isStar = 0;
                //cout << "Found entered leaf: " << edgeA[i] << " " << edgeB[i] << endl;
                if( first )
                {
                    if( isLeaf[ edgeA[i] ] == 1 )
                        isLeafBool[ edgeA[i] ] = 1; // potentially worst roots
                    else
                        isLeafBool[ edgeB[i] ] = 1;
                }
                --isLeafNext[ edgeA[i] ];
                --isLeafNext[ edgeB[i] ];
                edgeA.erase( edgeA.begin() + i );
                edgeB.erase( edgeB.begin() + i );
                --i;
            }
        }
        isLeaf = isLeafNext;
        if( isStar )
        {
            cout << "Best Roots  : " << theStar << endl;
            bestRoots[0] = theStar;
        }
        else leavesElimination( 0 );
        return;
    }
    else if( edgeA.size() == 2 )
    {
        isLeaf.assign( N+1, 0);
        ++isLeaf[ edgeA[0] ];
        ++isLeaf[ edgeA[1] ];
        ++isLeaf[ edgeB[0] ];
        ++isLeaf[ edgeB[1] ];
        if( isLeaf[ edgeA[0] ] == 2 )
        {
            cout << "Best Roots  : " << edgeA[0] << endl;
            bestRoots[0] = edgeA[0];
        }
        else if( isLeaf[ edgeA[1] ] == 2 )
        {
            cout << "Best Roots  : " << edgeA[1] << endl;
            bestRoots[0] = edgeA[1];
        }
        else
        {
             cout << "Best Roots  : " << edgeB[0] << endl;
             bestRoots[0] = edgeB[0];
        }

    }
    else if( edgeA[0] > edgeB[0] )
    {
        cout << "Best Roots  : " << edgeB[0] << " " << edgeA[0] << endl;
        bestRoots[0] = edgeB[0]; bestRoots[1] = edgeA[0];
    }
    else
    {
        cout << "Best Roots  : " << edgeA[0] << " " << edgeB[0] << endl;
        bestRoots[0] = edgeB[0]; bestRoots[1] = edgeA[0];
    }
    return;
}
void getWorst( int cameFrom, int cameTo, int level )
{
    ++level;
    for( unsigned int i = 0; i < adjacent[cameTo].size(); ++i )
    {
        if( adjacent[cameTo][i] != cameFrom )
        {
            if( isLeafBool[ adjacent[cameTo][i] ] == 1 && level >= heightOfTree )
                worstRoots.push_back( adjacent[cameTo][i] );
            else getWorst( cameTo, adjacent[cameTo][i], level );
        }
    }
}
int main()
{
    unsigned int connections, node, nodeCounter, checkA, checkB, first;
    int star;
    bool special;
    vector< bool > basic;

    vector< vector< bool > > repeat;
    while( cin >> N )
    {
        heightOfTree = 0;
        basic.assign( N+1, 0);
        first = 1; special = 1;
        repeat.assign( N+1, basic );
        isLeaf.assign( N+1, 0);
        isLeafBool.assign( N+1, 0);
        adjacent.assign( N+1, vector<int>() );
        nodeCounter = 1;
        while( nodeCounter <= N )
        {
            cin >> connections;
            while( connections-- )
            {
                cin >> node;
                if( repeat[ nodeCounter ][ node ] == 0 )
                {
                    if( first <= 2 ) // because of check for star
                    {
                        if( first == 1 )
                        {
                            checkA = nodeCounter;
                            checkB = node;
                            star = checkA;
                        }
                        else if( nodeCounter == checkA || node == checkA )
                            star = checkA;
                        else if( nodeCounter == checkB || node == checkB )
                            star = checkB;
                        else special = 0;
                        ++first;
                    }
                    else if( special ) // check for star
                    {
                        if( star != node && star != nodeCounter )
                            special = 0;
                    }
                    edgeA.push_back( nodeCounter );
                    ++isLeaf[ nodeCounter ];
                    edgeB.push_back( node );
                    ++isLeaf[ node ];
                    repeat[ nodeCounter ][ node ] = 1;
                    repeat[ node ][ nodeCounter ] = 1;
                }
                adjacent[nodeCounter].push_back(node);
            }
            ++nodeCounter;
        }
        if( !special )
        {

            int maximum = 0;
            bestRoots[1] = 0;
            leavesElimination( 1 );//cout << "heightL " << heightOfTree << endl;
            getWorst( 0, bestRoots[0], 0 );
            if( bestRoots[1] != 0 )
                getWorst( 0, bestRoots[1], 0 );
            sort( worstRoots.begin(), worstRoots.end() );
            vector<int>::iterator ip = unique( worstRoots.begin(), worstRoots.end() );
            worstRoots.resize( distance(worstRoots.begin(), ip));
            cout << "Worst Roots :";
            for( unsigned int i = 0; i < worstRoots.size(); ++i )
                cout << " " << worstRoots[i];
        }
        else // this works, its for when tree is a star, because leaves elimination cant deal with it if its only level one tree
        {
            cout << "Best Roots  : " << star << endl;
            cout << "Worst Roots :";
            for( unsigned int i = 0; i < edgeA.size() ; ++i )
            {
                if( edgeA[i] != star )
                    worstRoots.push_back( edgeA[i] );
                else worstRoots.push_back( edgeB[i] );
            }
            sort( worstRoots.begin(), worstRoots.end() );
            for( unsigned int i = 0; i < worstRoots.size(); ++i )
                cout << " " << worstRoots[i];

        }
        cout << endl;
        edgeA.clear();
        edgeB.clear();
        repeat.clear();
        isLeaf.clear();
        basic.clear();
        worstRoots.clear();

    }
    return 0;
}
