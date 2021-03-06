#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	//freopen("1753.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);

	int counter = 0;
    long double segments, totalTime;
	while ( cin >> segments >> totalTime )
	{
        vector< long double > distances;
        vector< long double > speeds;

        while( segments-- )
        {
            long double d, s;
            cin >> d >> s;
            distances.push_back( d );
            speeds.push_back( s );
        }

        // binary search
        long double epsilon = 0.0000001, low = -100000000, high = low*(-1), mid, previous = high;
        long double myTime = 0;
        while( high >= low )
        {
            mid = ( low + high ) / 2;

//            if( mid == previous )
//                break;
//            else previous = mid;

            myTime = 0;

            for( unsigned i = 0; i < distances.size(); ++i )
            {
                if( ( speeds[i] + mid ) <= 0 ) // it should be always positive
                {
                    myTime = 10000000;
                    break;
                }

                myTime += distances[i] / ( speeds[i] + mid );
            }

            if( abs( myTime - totalTime ) <= epsilon )
                break;
            else if( (myTime - totalTime) < 0 )
                high = mid;//-epsilon;
            else low = mid;//+epsilon;
        }
        cout << fixed << setprecision(9) << mid << '\n';
	}

	return 0;
}
