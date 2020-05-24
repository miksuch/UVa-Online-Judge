#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;
int main()
{
    string command;
    unsigned int popCount, commandsCount, caseNumber = 1, emergencyNumber;
    vector< unsigned int > emergencyQ, displayQ, normalQ;
    vector< bool > inEmergency;
    cin >> popCount >> commandsCount;
    while( popCount != 0 || commandsCount != 0 )
    {
        inEmergency.assign( popCount + 1, 0 );
        for( unsigned int i = 1; i <= popCount && i <= commandsCount ; ++i )
            normalQ.push_back( i );
        while( commandsCount > 0 )
        {
            cin >> command;
            if( command == "N" )
            {
                if( !emergencyQ.empty() )
                {
                    displayQ.push_back( emergencyQ.front() );
                    inEmergency[ emergencyQ.front() ] = 0;
                    for( unsigned int i = 0; i < normalQ.size(); ++i )
                    {
                        if( emergencyQ.front() == normalQ[ i ] )
                        {
                            normalQ.erase( normalQ.begin() + i );
                            normalQ.push_back( emergencyQ.front() );
                            break;
                        }
                    }
                    emergencyQ.erase( emergencyQ.begin() );
                }
                else
                {
                        displayQ.push_back( normalQ.front() );
                        normalQ.push_back( normalQ.front() );
                        normalQ.erase( normalQ.begin() );
                }
            }
            else
            {
                cin >> emergencyNumber;
                if( inEmergency[ emergencyNumber ] )
                {
                    for( unsigned int i = 0; i < emergencyQ.size(); ++i )
                    {
                        if( emergencyNumber == emergencyQ[ i ] )
                        {
                            emergencyQ.erase( emergencyQ.begin() + i );
                            break;
                        }
                    }
                }
                emergencyQ.emplace( emergencyQ.begin(), emergencyNumber );
                inEmergency[ emergencyNumber ] = 1;
            }
            --commandsCount;
        }
        cout << "Case " << caseNumber << ":" << endl;
        while( !displayQ.empty() )
        {
            cout << displayQ.front() << endl;
            displayQ.erase( displayQ.begin() );
        }
        ++caseNumber;
        inEmergency.clear();
        emergencyQ.clear();
        displayQ.clear();
        normalQ.clear();
        cin >> popCount >> commandsCount;
    }
    return 0;
}
