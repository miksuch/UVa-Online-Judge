#include <iostream>
#define N 10
using namespace std;
int digitsArray[N];
inline void arrayClear()
{
    for( unsigned i = 0; i < N; ++i )
        digitsArray[i] = 0;
}
int main()
{

    int tSize, number;
    cin >> tSize;
    while( tSize-- )
    {
        cin >> number;
        arrayClear();

        for( int i = 1; i <= number; ++i )
        {
            int counter = i;
            while( counter )
            {
                ++digitsArray[counter%10];
                counter /= 10;
            }
        }

        for( unsigned i = 0; i < N; ++i, cout << " " )
            cout << digitsArray[i];
        cout << endl;


    }

    return 0;
}
