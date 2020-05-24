#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int main()
{
    int caseNumber, i, best, travelTime, tests, tmp, hours, minutes;
    char spacing;
    pair<int, int> currentTime,busTime;
    cin >> caseNumber;
    i = 1;
    while( i <= caseNumber )
    {
        cin >> tests >> currentTime.first >> spacing >> currentTime.second;
        best = 65536;
        while( tests-- )
        {
            cin >> busTime.first >> spacing >> busTime.second >> travelTime;
            hours = busTime.first - currentTime.first;
            minutes = busTime.second - currentTime.second ;
            if( hours < 0 || ( hours == 0 && minutes < 0 ))
                tmp = ( ( 24 - currentTime.first ) + busTime.first )*60 + minutes + travelTime;
            else tmp = hours*60 + busTime.second - currentTime.second + travelTime;
            if( tmp < best )
                best = tmp;
        }
        cout << "Case " << i << ": " << best << endl;
        ++i;
    }
    return 0;
}

