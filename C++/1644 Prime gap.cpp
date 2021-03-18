#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <cmath>
using namespace std;

#define N 1299709
vector<bool> isPrime;
void init_numbers()
{
    isPrime.assign(N+1, true);
    isPrime[0]=false;
    isPrime[1]=false;

    for( int i = 2; i <= sqrt(N)+1; ++i )
    {
        if( isPrime[i] == true )
        {
            for( int j = i+i; j < isPrime.size(); j += i )
            {
                isPrime[j] = false;
            }
        }
    }
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);

	int k;
	init_numbers();

	while(cin >> k)
	{
	    if( k == 0 )
            break;
        else if( isPrime[k] == true || k < 2 )
            cout << "0\n";
        else
        {
            int leftPrime, rightPrime, primeGap = 0;

            leftPrime = rightPrime = k;

            while( !isPrime[leftPrime] )
            {
                ++primeGap;
                --leftPrime;
            }
            while( !isPrime[rightPrime] )
            {
                ++primeGap;
                ++rightPrime;
            }
            cout << primeGap << endl;
        }
	}

	return 0;
}
