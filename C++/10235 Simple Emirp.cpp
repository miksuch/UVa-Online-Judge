#include <iostream>
#include <vector>
#define N 1000001
using namespace std;
vector<bool> primeNumbers;
void loadPrimes()
{
    primeNumbers.assign( N, true );
    primeNumbers[0] = primeNumbers[1] = false;
    for( unsigned int i = 2; i < N; ++i )
    {
        if( primeNumbers[i] == true )
            for( unsigned int j = i+i; j < N; j = j+i )
                primeNumbers[j] = false;
    }
}
int main()
{
	ios_base::sync_with_stdio(0);

    loadPrimes();
    int number;
    while( cin >> number )
    {
        if( primeNumbers[number] == true )
        {
            int rev = 0, tmp = number;
            while( tmp != 0 )
            {
                rev = rev*10 + tmp%10;
                tmp /= 10;
            }
            if( primeNumbers[rev] == true && rev != number )
                cout << number << " is emirp.\n";
            else cout << number << " is prime.\n";
        }
        else cout << number << " is not prime.\n";
    }

	return 0;
}

