#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
vector< unsigned int > cd;
unsigned int counter;
double limit;
bool gotcha( unsigned int val, unsigned int start, unsigned int end )
{
    ++counter;
    if( counter > limit + 1 )
        return 0;
    //cout << "what";
    unsigned int middle = ( end + start ) / 2;
    if( val == cd[middle] )
        return 1;
    else if( val < cd[middle] )
    {
        if( gotcha( val, start, middle ) )
            return 1;
        else return 0;
    }
    else
    {
        if( gotcha( val, middle, end ) )
            return 1;
        else return 0;
    }
    return 0;

}
int main()
{
    unsigned int jacks, jills, value, answer;

    cin >> jacks >> jills;
    while( jacks != 0 && jills != 0 )
    {
        limit = log2( jacks );
        answer = 0;
        while( jacks-- )
        {
            cin >> value;
            cd.push_back( value );
        }
        while( jills-- )
        {
            //cout << "hello" << endl;
            cin >> value;
            counter = 0;
            if( gotcha( value, 0, cd.size() ) )
                ++answer;
        }
        cd.clear();
        cout << answer << endl;
        cin >> jacks >> jills;

    }

    return 0;
}
