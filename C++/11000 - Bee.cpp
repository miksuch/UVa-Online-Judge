#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    int N;
    while( cin >> N )
    {
        if( N < 0 )
            break;

        long long f = 1;
        long long m = 0;
        for( int i = 0; i < N; ++i )
        {
            long long fPrevious = f;
            long long mPrevious = m;
            f = mPrevious + 1;
            m = fPrevious + mPrevious;
        }
        cout << m << " " << m+f << '\n';

    }
    return 0;
}
