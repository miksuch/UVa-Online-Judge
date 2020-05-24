#include <iostream>
using namespace std;
int main()
{
    unsigned int a[31], b[31], testCases, n;
    a[0]=1; a[1]=1;
    for( unsigned int i = 2; i < 31; i++ )
        a[i] = 2 * a[i-2] + a[i-1];

    b[0]=1; b[1]=1; b[2]=3; b[3]=1;

    for( unsigned int i = 4; i < 31; i++ )
        b[i] = b[i-2] + 2 * b[i-4];

    cin >> testCases;
    while( testCases-- )
    {
        cin >> n;
        cout << ( ( a[n] - b[n] ) / 2 ) + b[n] << endl;
    }
    return 0;
}
