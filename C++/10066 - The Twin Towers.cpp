#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main()
{
    unsigned int heightOne, heightTwo, i, k, caseCounter = 1 ;
    int biggestTower, tmp;
    vector< int > towerOne, towerTwo, longestSequence;
    cin >> heightOne >> heightTwo;
    while( heightOne != 0 && heightTwo != 0 )
    {
        for( i = 1; i <= heightOne; ++i )
        {
            cin >> tmp;
            towerOne.push_back(tmp);
        }
        for( i = 1; i <= heightTwo; ++i )
        {
            cin >> tmp;
            towerTwo.push_back(tmp);
            longestSequence.push_back(0);
        }
        k = 0;  tmp = 0;
        while( k < towerOne.size() )
        {
            biggestTower = 0;
            i = 0;
            while( i < towerTwo.size() )
            {
                if( towerOne[k] == towerTwo[i] )
                {
                    if( longestSequence[i] <= biggestTower )
                        longestSequence[i] = biggestTower + 1;
                    else
                        biggestTower = longestSequence[i];
                    if( longestSequence[i] > tmp )
                        tmp = longestSequence[i];
                }
                else if( longestSequence[i] > biggestTower )
                    biggestTower = longestSequence[i];
                ++i;
            }
            ++k;
        }
        biggestTower = tmp;
        cout << "Twin Towers #" << caseCounter << " " << endl << "Number of Tiles : " << biggestTower << endl << endl;
        towerOne.clear(); towerTwo.clear(); longestSequence.clear();
        ++caseCounter;
        cin >> heightOne >> heightTwo;
    }
    return 0;
}
