/* TLE garbage */
#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <algorithm>
using namespace std;
ofstream couta("medieval.txt");
struct Road
{
    unsigned int nodeA, nodeB, cost;
};
bool byCost( Road &left, Road &right )
{
    return left.cost < right.cost;
}
int main()
{
    unsigned int junctions, roads, A, B, length, spendings, savings, darkRoad, roadToLight;
    vector< bool > connected;
    Road tmp;
    vector< Road > road;
    while ( cin >> junctions >> roads )
    {
        if( !junctions && !roads )
            break;
        spendings = 0;
        connected.assign( junctions, 0 );
        while( roads-- )
        {
            cin >> A >> B >> length;
            tmp = { A, B, length };
            road.push_back( tmp );
            spendings += length;
        }

        sort( road.begin(), road.end(), &byCost );
        //
        savings = road.front().cost;
        connected[ road.front().nodeB ] = 1;
        connected[ road.front().nodeA ] = connected[ road.front().nodeB ];
        darkRoad = 1; 
        junctions -= 2; // because i already connected two of them
        while( junctions-- )
        {
            roadToLight = darkRoad;
            while( connected[ road[ roadToLight ].nodeA ] == connected[ road[ roadToLight ].nodeB ] ) // looking for connection to be made
                ++roadToLight;

            // marking as connected and lighted
            connected[ road[ roadToLight ].nodeB ] = 1;
            connected[ road[ roadToLight ].nodeA ] = connected[ road[ roadToLight ].nodeB ];
            savings += road[ roadToLight ].cost;

            if( roadToLight == darkRoad ) //
                ++darkRoad;

        }
        couta << spendings - savings << endl;
        connected.clear();
        road.clear();
    }
}
