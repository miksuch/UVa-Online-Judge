#include <iostream>
#include <utility>
#include <vector>
#include <math.h>
#include <fstream>
#include <iomanip>
using namespace std;
ofstream couta("filename.txt");
vector< pair< double, double > > point;
vector< bool > connected;
vector< vector<double> > distances;
vector< vector< pair< int, double > > > closestIdx;
bool connectionLayout[103][103];
vector< pair< int, int> > foundUnconnected;
vector< int > idxs;
double answer;
double minDistance;
void clearLayour()
{
    for( unsigned int i = 0; i < point.size()+2; ++i )
    {
        for( unsigned int k = 0; k < point.size()+2; ++k )
            connectionLayout[i][k] = 0;
    }
}
void updateLayour( int x, int y )
{
    connectionLayout[x][y]=1;
    connectionLayout[y][x]=1;
    for( unsigned int i = 0; i < point.size(); ++i )
    {
        if( connectionLayout[i][y] == 1 && i != x && connectionLayout[i][x] == 0 )
            updateLayour( i, x );
    }
}
void printLayour()
{
    for( unsigned int i = 0; i < point.size() + 1; ++i )
    {
        for( unsigned int k = 0; k < point.size() + 1; ++k )
            couta << connectionLayout[i][k] << "|";
        couta << endl;
    }
}
void getDistances( double x, double y, int pointIdx )
{

    minDistance = 2147483647;
    for( unsigned int i = 0 ; i < point.size() ; ++i )
    {
        if( i != pointIdx )
        {
            // distance between points with indexes of pointIdx and i
            distances[ pointIdx ][ i ] = sqrt( ( x - point[i].first ) * ( x - point[i].first ) + ( y - point[i].second ) * ( y - point[i].second ) );
            if( distances[ pointIdx ][ i ] <= minDistance )
            {
                if( distances[ pointIdx ][ i ] < minDistance )
                {
                    closestIdx[ pointIdx ].clear();
                    minDistance = distances[ pointIdx ][ i ];
                }
                closestIdx[ pointIdx ].push_back( make_pair( i, minDistance ) );
            }
        }

    }
//    couta << "STORED" << endl;
}
int main()
{
    unsigned int testCases, freckles, i, k, tmp, counter, test;
    double x, y;
    bool unconnected, fine;
    vector< double > filler;
    vector< vector< int > > disconnected;
    cin >> testCases;
    counter = 1;
    while( counter <= testCases )
    {
        if( counter > 1 )
            couta << endl;
        cin >> freckles;
        filler.assign( freckles, 0 );
        distances.assign( freckles, filler );
        connected.assign( freckles, 0 );
        test = 0;
        while( freckles-- )
        {
            cin >> x >> y;
            point.push_back( make_pair( x, y ));
        }
        closestIdx.assign( point.size(), vector< pair< int, double > >() );
        for( i = 0; i < point.size(); ++i )
            getDistances( point[i].first, point[i].second, i );
        clearLayour();
        unconnected = 1;
        while( unconnected )
        {
            for( k = 0; k < connected.size(); ++k )
            {
                if( !connected[k] )
                    break;
            }
            tmp = k;
            if( closestIdx[k].empty() )
            {
                break;
            }
            else
            {
                answer += closestIdx[k].front().second;
                updateLayour( k, closestIdx[k].front().first );
                connected[ k ] = 1;
                connected[ closestIdx[k].front().first ] = 1;
                closestIdx[k].erase( closestIdx[k].begin() );
                ++test;
            }

            unconnected = 0;
            for( k = tmp; k < connected.size(); ++k )
            {
                if( !connected[k] )
                {
                    unconnected = 1;
                    break;
                }
            }
        }
//        printLayour();
        // second part where i connect the possible "scattered" parts
        fine = 0;
        while( !fine )
        {
            for( i = 0; i < point.size(); ++i )
            {
                for( k = 0; k < point.size() ; ++k )
                {
                    if( connectionLayout[i][k] == 0 && i != k  )
                        foundUnconnected.push_back( make_pair( i, k ) );
                }
            }
            if( foundUnconnected.empty() )
                fine = 1;
            else
            {
                minDistance = 2147483647;
                for( i = 0; i < foundUnconnected.size(); ++i )
                {
                    if( distances[ foundUnconnected[i].first ][ foundUnconnected[i].second ] < minDistance )
                    {
                        tmp = i;
                        minDistance = distances[ foundUnconnected[i].first ][ foundUnconnected[i].second ];
                    }
                }
                answer += minDistance;
                updateLayour( foundUnconnected[tmp].first, foundUnconnected[tmp].second );
                foundUnconnected.clear();
            }

        }

//        printLayour();
        cout << setprecision(2) << fixed << answer << endl;
//        printf( "%.2f\n", answer );
        clearLayour();
        //foundUnconnected.clear();
        connected.clear();
        point.clear();
        closestIdx.clear();
        distances.clear();
        disconnected.clear();
        answer = 0;
        ++counter;
    }
    return 0;
}
