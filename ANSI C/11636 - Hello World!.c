#include <stdio.h>
int main()
{
    int N, i, answer, casenumber = 1;
    scanf( "%d", &N );
    while( N > 0 )
    {
        i=1; answer = 0;
        while( i < N )
        {
            i = i * 2;
            ++answer;
        }
        printf( "Case %d: %d\n", casenumber, answer);
        scanf( "%d", &N );
        ++casenumber;
    }
    return 0;
}









