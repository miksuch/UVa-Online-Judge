#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> a;
    bool semafor=0;
    int n, rsize, counter = 0, swaps = 0, i, j, posortowane = 0;

    while( cin >> n )
    {
        counter = 0; swaps = 0; posortowane = 0; semafor = 0;
        //cin >> n;
        rsize = n;
        while( rsize > 0 )
        {
            cin >> j;
            a.push_back( j );
            --rsize;
        }

        for( i = 0; i < ( n - 1 ) ; ++i )
        {
            semafor = 1;
            for( j = n - 1 ; j >= (i + 1)  ; --j )
            {
                if( a[j-1] > a[j] )
                {
                    swap( a[j-1], a[j] );
                    ++swaps;
                    semafor = 0;
                }
                else
                {
                    semafor = 1;
                    ++posortowane;
                }
                ++counter;
            }
            if( semafor && posortowane == n - 1 ) // jesli liczby byly dobrze ustawione to mamy posortowany ciag i wychodzimy
                break;
            else if( semafor ) // jeśli para była posortowana to skracam liczbe iteracji
                ++i;
        }
        //cout << endl;
//        for( i = 0; i < n; ++i )
//            cout << a[i] << ", ";
        //cout << endl << "LICZBA POROWNAN: " << counter << endl;
        cout << endl << "Minimum exchange operations : " << swaps << endl;
        a.clear();
    }
    return 0;
}

