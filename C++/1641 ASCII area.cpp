#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);

	int height, width;

	while (	cin >> height >> width )
	{
        int full = 0, half = 0;
        string line;
        while( height-- )
        {
            cin >> line;
            bool inPolygon = false;
            for( unsigned i = 0; i < line.size(); ++i )
            {
                if( line[i] == '/' || line[i] == '\\' )
                {
                    inPolygon = inPolygon^1; // switch state
                    ++half;
                }
                else if( line[i] == '.' && inPolygon )
                    ++full;
            }
        }
        cout << full + (half>>1) << '\n';
	}

	return 0;
}
