#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    unsigned long long capacity, collectionSize;
    unsigned int bits;
    while( cin >> collectionSize >> bits )
    {
        capacity = 0;
        for( unsigned int i = 0; i <= bits; ++i )
            capacity += pow( 2, i );
        if( collectionSize <= capacity )
            cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
