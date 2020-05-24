#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct stats
{
    string TeamName ="";
    string UpperCase ="";
    int Points=0;
    int Wins=0;
    int GoalDiff=0;
    int GoalsScored=0;
    int GoalsLost=0;
    int TimesPlayed=0;
    int Ties=0;
    int Losses=0;
};
string upper_case( string str )
{
    for( unsigned int i = 0; i < str.size(); ++i )
    {
        if( str[i] >= 'a' && str[i] <= 'z' )
            str[i] = str[i] - 32;
    }
    return str;
}
string get_team( string str, bool which )
{
    if( !which )
    {
        unsigned int i = 0;                                               // dla lewej
        while( i < (str.size() - 2) )
        {
            if( str[i] == '#' )
                break;
            ++i;
        }
        str = str.substr( 0, i );
    }
    else
    {
        unsigned int i = str.size() - 1;                                  // dla prawej
        while( i > 2 )
        {
            if( str[i] == '#' )
                break;
            --i;
        }
        str = str.substr( i + 1 );
    }
    return str;
}
void update_stats( string MatchResults, stats *TeamRecord, int &TeamCount )
{
    string TeamN = get_team( MatchResults, 0 );
    unsigned int i;
    int ScoreL, ScoreR, right, left;
    for( left = 0; left < TeamCount; ++left )
        if( TeamN == TeamRecord[ left ].TeamName )         // dla lewej
            break;
    TeamN = get_team( MatchResults, 1 );
    for( right = 0; right < TeamCount; ++right )
        if( TeamN == TeamRecord[ right ].TeamName )         // dla prawej
            break;
    for( i = 0; i < MatchResults.size(); ++i )
        if( MatchResults[i] == '@' )
            break;
    if( MatchResults[ i - 2 ] == '#' ) // gdy wynik jednocyfrowy dla lewej
        ScoreL = MatchResults[ i - 1 ] - '0';
    else
        ScoreL = (MatchResults[ i - 2 ] - '0')*10 + (MatchResults[ i - 1 ] - '0'); // biorę dwucyfrową liczbę
    if( MatchResults[ i + 2 ] == '#' ) // gdy wynik jednocyfrowy dla prawej
        ScoreR = MatchResults[ i + 1 ] - '0';
    else
        ScoreR = (MatchResults[ i + 1 ] - '0')*10 + (MatchResults[ i + 2 ] - '0'); // biorę dwucyfrową liczbę

    TeamRecord[ left ].GoalsScored += ScoreL;
    TeamRecord[ left ].GoalsLost += ScoreR;
    TeamRecord[ right ].GoalsScored += ScoreR;
    TeamRecord[ right ].GoalsLost += ScoreL;
    if( ScoreL > ScoreR )
    {
        TeamRecord[ left ].Wins += 1;
        TeamRecord[ left ].Points += 3;
        TeamRecord[ right ].Losses += 1;
    }
    else if( ScoreL < ScoreR )
    {
        TeamRecord[ right ].Wins += 1;
        TeamRecord[ right ].Points += 3;
        TeamRecord[ left ].Losses += 1;
    }
    else // REMIS
    {
        TeamRecord[ left ].Points += 1;
        TeamRecord[ right ].Points += 1;
        TeamRecord[ right ].Ties += 1;
        TeamRecord[ left ].Ties += 1;
    }
    TeamRecord[ left ].TimesPlayed += 1;
    TeamRecord[ right ].TimesPlayed += 1;

}
bool custom_compare( stats const &left, stats const &right )
{
    if( left.Points != right.Points )
        return left.Points > right.Points;
    if( left.Wins != right.Wins )
        return left.Wins > right.Wins;
    if( left.GoalDiff != right.GoalDiff )
        return left.GoalDiff > right.GoalDiff;
    if( left.GoalsScored != right.GoalsScored )
        return left.GoalsScored > right.GoalsScored;
    if( left.TimesPlayed != right.TimesPlayed )
        return left.TimesPlayed < right.TimesPlayed;
    else
    {
        unsigned int i = 0;
        while( left.UpperCase[i] == right.UpperCase[i] )
            ++i;
        return left.UpperCase[i] < right.UpperCase[i];
    }
}
void update_goaldiff( stats *TeamRecord, int &TeamCount )
{
    for( int i = 0; i < TeamCount; ++i )
        TeamRecord[i].GoalDiff = TeamRecord[i].GoalsScored - TeamRecord[i].GoalsLost;
}
int main()
{
    stats *pointer;
    string TournamentName, TempStr;
    int TournamentCount, TeamCount, GamesPlayed, i;
    cin >> TournamentCount;
    cin.ignore();
    while( TournamentCount-- )
    {

        //cout << "ENTER THE NAME OF THE TOURNAMENT: ";
        getline( cin, TournamentName );
        //cout << "TOURNAMENT NAME: " << TournamentName << endl;

        cin >> TeamCount;
        cin.ignore();
        i = TeamCount;
        stats *TeamRecord = new stats[ TeamCount ];
        pointer = TeamRecord;
        //cout << TeamRecord << endl;

        while( TeamCount-- )
        {
            //cout << "ENTER THE TEAM NAME: ";
            getline( cin, TempStr );
            TeamRecord[ TeamCount ].TeamName = TempStr;
            TeamRecord[ TeamCount ].UpperCase = upper_case( TempStr );
            //cout << "TEAM NAME: " << TeamRecord[ TeamCount ].TeamName << endl;
        }
        TeamCount = i;
        //cout << "ENTER NUMBER OF GAMES PLAYED: ";
        cin >> GamesPlayed;
        cin.ignore();
        while( GamesPlayed-- )
        {
            //cout << "ENTER THE MATCH RECORD: ";
            getline( cin, TempStr );
            update_stats( TempStr, TeamRecord, TeamCount );
        }
        update_goaldiff( TeamRecord, TeamCount );
        sort( pointer, pointer + TeamCount, &custom_compare );
        cout << TournamentName << endl;
        i = 0;
        while( i < TeamCount )
        {
            cout <<i+1<<") "<<TeamRecord[i].TeamName<<" "<<TeamRecord[i].Points<<"p, "<<TeamRecord[i].TimesPlayed<<"g ("<<
            TeamRecord[i].Wins<<"-"<<TeamRecord[i].Ties<<"-"<<TeamRecord[i].Losses<<"), "<<TeamRecord[i].GoalDiff<<"gd ("<<TeamRecord[i].GoalsScored<<"-"<<TeamRecord[i].GoalsLost<<")"<<endl;
            //cout << i + 1 << ") " << TeamRecord[i].TeamName << endl;
            ++i;
        }
        cout << endl;
        delete[] TeamRecord;
    }

    return 0;
}

