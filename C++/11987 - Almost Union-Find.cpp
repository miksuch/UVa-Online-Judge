#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
using namespace std;
bool joinSets( unsigned int a, unsigned int b, vector< vector< unsigned int > > &v )
{
    if( v[a].front() == v[b].front() )
            return 1; // already in same sets
    else if( v[a].front() != a && v[b].front() == b )
    {
        vector< unsigned int > tmp = v[ v[a].front() ];
        v[ v[a].front() ].clear(); v[ v[a].front() ].push_back( b );
        for( unsigned int i = 0; i < tmp.size(); ++i )
            v[ tmp[i] ].front() = b;
        v[b].insert( v[b].end(), tmp.begin(), tmp.end() );
        return 1;
    }
    else if( v[a].front() == a && v[b].front() != b )
    {
        vector< unsigned int > tmp = v[ v[b].front() ];
        v[ v[b].front() ].clear(); v[ v[b].front() ].push_back( a );
        for( unsigned int i = 0; i < tmp.size(); ++i )
            v[ tmp[i] ].front() = a;
        v[a].insert( v[a].end(), tmp.begin(), tmp.end() );
        return 1;
    }
    else if( v[a].front() == a && v[b].front() == b )
    {
        vector< unsigned int > tmp = v[ v[b].front() ];
        v[ v[b].front() ].clear(); v[ v[b].front() ].push_back( a );
        for( unsigned int i = 0; i < tmp.size(); ++i )
            v[ tmp[i] ].front() = a;
        v[a].insert( v[a].end(), tmp.begin(), tmp.end() );
        return 1;
    }
    else // v[a].front() != a && v[b].front() != b - when they both point to some other sets
    {
        vector< unsigned int > tmp = v[ v[b].front() ];
        v[ v[b].front() ].clear(); v[ v[b].front() ].push_back( v[a].front() );
        for( unsigned int i = 0; i < tmp.size(); ++i )
            v[ tmp[i] ].front() = v[a].front();
        v[ v[a].front() ].insert( v[ v[a].front() ].end(), tmp.begin(), tmp.end() );
        return 1;
    }
    return 0;
}
unsigned int findElement( unsigned int element, vector< unsigned int > &v )
{
    unsigned int idx = 0;
    for( ; idx < v.size(); ++idx )
    {
        if( v[idx] == element )
            break;
    }
    return idx;
}
bool moveElement( unsigned int a, unsigned int b, vector< vector< unsigned int > > &v ) // move a to b
{
    if( v[a].front() == v[b].front() )
        return 1; // already in same sets
    else if( v[a].front() != a && v[b].front() == b ) // no problem with that
    {
        unsigned int idx = findElement( a, v[ v[a].front() ] );
        v[ v[a].front() ].erase( v[ v[a].front() ].begin() + idx );
        v[a].front() = b;
        v[b].push_back( a );
        return 1;
    }
    else if( ( v[a].front() == a && v[b].front() != b ) || ( v[a].front() == a && v[b].front() == b ) ) // because these come down to same operations
    {
        if( v[a].size() == 1 )
        {
            v[a].front() = v[b].front();
            v[ v[b].front() ].push_back( a );
        }
        else
        {
            vector< unsigned int > tmp = v[a];
            v[a].clear();
            v[a].push_back( v[b].front() );
            v[ v[b].front() ].push_back( a );
            tmp.erase( tmp.begin() );
            for( unsigned int i = 1; i < tmp.size(); ++i )
                v[ tmp[i] ].front() = tmp.front();
            v[ tmp.front() ].clear();
            v[ tmp.front() ].insert( v[ tmp.front() ].begin(), tmp.begin(), tmp.end() );
        }
        return 1;
    }
    else // v[a].front() != a && v[b].front() != b - when they both point to some other sets
    {
        unsigned int idx = findElement( a, v[ v[a].front() ] );
        v[ v[a].front() ].erase( v[ v[a].front() ].begin() + idx );
        v[a].front() = v[b].front();
        v[ v[b].front() ].push_back( a );
        return 1;
    }
    return 0;
}
void checkoutSet( unsigned int a, vector< vector < unsigned int > > &v )
{
    unsigned int answerSum = 0;
    for( unsigned int i = 0; i < v[ v[a].front() ].size(); ++i )
        answerSum += v[ v[a].front() ][i];
    cout << v[ v[a].front() ].size() << " " << answerSum << endl;
}
int main()
{
    unsigned int commandId, n, commands, elementA, elementB;
    vector< vector < unsigned int > > sets;
    while( cin >> n >> commands )
    {
        sets.assign( n + 1, vector< unsigned int > () );
        for( unsigned int i = 1; i <= n; ++i ) // as specified
            sets[i].push_back( i );

        while( commands-- )
        {
            cin >> commandId;
            switch( commandId )
            {
            case 1:
//                cout << "Union operation; enter two elements: ";
                cin >> elementA >> elementB;
                if( joinSets( elementA, elementB, sets ) );
//                    cout << "joining set of " << elementA << " to set of " << elementB <<" successful" << endl;
//                else cout << "something went wrong" << endl;
//                printSets( sets );
                break;
            case 2:
                cin >> elementA >> elementB;
                if( moveElement( elementA, elementB, sets ) );
//                    cout << "moving " << elementA << " to " << elementB <<" successful" << endl;
//                else cout << "something went wrong" << endl;
//                printSets( sets );
                break;
            case 3:
                cin >> elementA;
                checkoutSet( elementA, sets );
                break;
            default:
                break;
            }
        }
        sets.clear();
    }
    return 0;
}
