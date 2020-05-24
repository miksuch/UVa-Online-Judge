#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
int main()
{
    string command;
    vector< queue< unsigned int > > teamQ;
    vector< unsigned int > teamTemplate, teamOrder;
    unsigned int scenarioNumber = 1, numberOfTeams, capacity, member, i;
    while( cin >> numberOfTeams )
    {
        if( numberOfTeams == 0 )
            break;
        teamTemplate.assign( 1000000, 1048576 );
        teamQ.assign( numberOfTeams + 1, queue< unsigned int >() );
        while( numberOfTeams-- )
        {
            cin >> capacity;
            while( capacity-- )
            {
                cin >> member;
                teamTemplate[member] = numberOfTeams;
            }
        }
        cout << "Scenario #" << scenarioNumber << endl;
        while( cin >> command )
        {
            if( command == "STOP" )
                break;
            else if( command == "ENQUEUE" )
            {
                cin >> member;
                for( i = 0; i < teamOrder.size(); ++i )
                    if( teamTemplate[member] == teamOrder[i] )
                        break;

                if( i == teamOrder.size() )
                    teamOrder.push_back( teamTemplate[member] );

                teamQ[ teamTemplate[member] ].push( member );
            }
            else // command == "DEQUEUE"
            {
                cout << teamQ[ teamOrder.front() ].front() << endl;
                teamQ[ teamOrder.front() ].pop();
                if( teamQ[ teamOrder.front() ].empty() )
                    teamOrder.erase( teamOrder.begin() );
            }
        }
        cout << endl;
        teamOrder.clear();
        teamQ.clear();
        teamTemplate.clear();
        ++scenarioNumber;
    }
    return 0;
}
