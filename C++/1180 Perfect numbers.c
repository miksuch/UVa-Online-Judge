#include <iostream>
#include <vector>
#define N 131072 // 2^17
using namespace std;
vector<bool> primeNumbers;
void findPrimeNumbers()
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
    string line;
    getline( cin, line );

    return 0;
}
