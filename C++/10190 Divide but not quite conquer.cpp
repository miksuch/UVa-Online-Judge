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

	int m, n;
	vector< int > sequence;
	while( cin >> n >> m )
	{
        bool boring = ( n == 0 || n == 1 || m == 0 );

	    while( n != 1 && !boring )
	    {
	        sequence.push_back(n);
            if( n % m == 0 )
                n /= m;
            else boring = true;
            if( sequence.back() <= n )
                boring = true;
	    }

	if( boring )
            cout << "Boring!\n";
        else
        {
            for( unsigned int i = 0; i < sequence.size(); ++i )
                cout << sequence[i] << " ";
            cout << "1\n";
        }

	    sequence.clear();
	}

	return 0;
}
