#include <stdio.h>
int main()
{
    int n,k,N, answer;
    scanf( "%d", &N );
    while( N > 0 )
    {
        scanf( "%d %d", &n, &k );
        answer = k ^ (k / 2);
        printf( "%d\n", answer);
        --N;
    }

    return 0;
}
