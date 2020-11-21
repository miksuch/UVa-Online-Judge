#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;
int getSignIdx( string bloodType )
{
    if( bloodType[1] == 'B' ) // AB type
        return 2;
    else return 1;
}
vector< string > getChildMarkers( string parent1, string parent2 )
{
    vector<string> result;
    if( parent1 == parent2 )
    {
        if( parent1.size() == 1 )
        {
            result.push_back("O"); // O O and always possible for the rest

            if( parent1 != "O" ) // A A, B B
                result.push_back(parent1);
        }
        else // AB AB
        {
            result.push_back("AB");
            result.push_back("B");
            result.push_back("A");
        }
    }
    else
    {
        if( parent1 == "O" ) // setup
        {
            parent1 = parent2;
            parent2 = "O";
        }

        if( parent2 == "O" )
        {
            if( parent1 == "AB" ) // AB O
            {
                result.push_back("B");
                result.push_back("A");
            }
            else // A O, B O
            {
                result.push_back( "O" );
                result.push_back( parent1 );
            }
        }
        else // A B, AB A, AB B
        {
            if( parent1 != "AB" && parent2 != "AB" )
                result.push_back("O");

            result.push_back("AB");
            result.push_back("B");
            result.push_back("A");
        }
    }
    return result;
}
vector< string > getChildFactors( string parent1, string parent2 )
{
    if( parent1 == "-" && parent2 == "-" )
        return {"-"};
    else return {"-","+"};
}
vector< string > getParentMarkers( string child )
{
    if ( child == "A" || child == "B" )
        return {"O","AB","B","A"};
    else if ( child == "AB" )
        return {"AB","B","A"};
    else if ( child == "O" )
        return {"O","B","A"};
    else
        return {};
}
vector< string > getParentFactors( string parent, string child )
{
    if( parent == "-" && child == "+" )
        return {"+"};
    else return {"-","+"};
}
string answer( vector<string> markers, vector<string> factors )
{
    if( markers.empty() )
        return "IMPOSSIBLE";

    vector< string > v;
    for( unsigned i = 0; i < markers.size(); ++i )
        for( unsigned j = 0; j < factors.size(); ++j )
            v.push_back( markers[i] + factors[j] );

//    sort(v.begin(), v.end(), []( const string &left, const string &right )
//         {
//            if( left )
//         }
//          );

    if( v.size() == 1 )
        return v[0];

    string ans = "";

    ans += "{" + v[0];
    for( unsigned i = 1; i < v.size(); ++i )
        ans += ", " + v[i];
    ans += "}";
    return ans;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);

    int testCase = 0;
    string bloodType1, bloodType2, bloodTypeChild;
    while( cin >> bloodType1 >> bloodType2 >> bloodTypeChild )
    {
        if( bloodType1 == "E" )
            break;

        ++testCase;

        /* possible child from bloodtype 1 2 */
        if( bloodTypeChild == "?" )
        {
            string factor1, factor2, marker1, marker2;
            int idx1 = getSignIdx( bloodType1 );
            int idx2 = getSignIdx( bloodType2 );
            factor1 = bloodType1.substr( idx1 );
            factor2 = bloodType2.substr( idx2 );
            marker1 = bloodType1.substr( 0, idx1 );
            marker2 = bloodType2.substr( 0, idx2 );
            vector<string> answerMarkers = getChildMarkers( marker1, marker2 );
            vector<string> answerFactors = getChildFactors( factor1, factor2 );

            cout << "Case " << testCase << ": " << bloodType1 << ' ' << bloodType2 << ' ' << answer( answerMarkers, answerFactors ) << '\n';

            continue;
        }

        /* possible bloodtype 2 from bloodtype 1 and child */
        bool switcheroo = false;
        if( bloodType1 == "?" )
        {
            switcheroo = true;
            bloodType1 = bloodType2;
            bloodType2 = "?";
        }
        if( bloodType2 == "?" )
        {
            string parentFactor, childFactor, parentMarker, childMarker;
            int idx1 = getSignIdx( bloodType1 );
            int idx2 = getSignIdx( bloodTypeChild );
            parentFactor = bloodType1.substr( idx1 );
            childFactor = bloodTypeChild.substr( idx2 );
            parentMarker = bloodType1.substr( 0, idx1 );
            childMarker = bloodTypeChild.substr( 0, idx2 );

            vector<string> answerFactors = getParentFactors( parentFactor, childFactor );
            vector<string> answerMarkers;

            vector<string> possibleMarkers = getParentMarkers( childMarker ); // pool of possible parents
            for( unsigned i = 0; i < possibleMarkers.size(); ++i ) // checking if given parent is on the list
            {
                if( parentMarker == possibleMarkers[i] ) // if he is then check possible other parent
                {
                    for( unsigned j = 0; j < possibleMarkers.size(); ++j ) // pairing given parent with other possible parents
                    {
                        vector<string> possibleChildren =  getChildMarkers( parentMarker, possibleMarkers[j] );
                        for( unsigned k = 0; k < possibleChildren.size(); ++k )
                        {
                            if( childMarker == possibleChildren[k] ) // checking if this pairing of parents can have given child
                            {
                                answerMarkers.push_back( possibleMarkers[j] );
                                break;
                            }
                        }
                    }
                }
            }


            if( switcheroo )
                cout << "Case " << testCase << ": " << answer( answerMarkers, answerFactors ) << ' ' << bloodType1 << ' ' << bloodTypeChild << '\n';
            else
                cout << "Case " << testCase << ": " << bloodType1 << ' ' << answer( answerMarkers, answerFactors ) << ' ' << bloodTypeChild << '\n';

        }

    }

    return 0;
}
