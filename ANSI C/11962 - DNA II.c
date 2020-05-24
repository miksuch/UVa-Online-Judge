#include <stdio.h>
#include <string.h>
int main()
{
    unsigned int testCases,i, power;
    int idx;
    unsigned long long int answer, powerOfFour;
    char sequence[31];
    scanf( "%u", &testCases );
    i = 1;
    while( i <= testCases )
    {
        scanf( "%s", sequence );
        idx = strlen( sequence ) - 1;
        printf( "Case %d: (%d:", i, strlen( sequence ) );
        power = 0; answer = 0;
        answer = 0;
        while( idx >= 0 )
        {

            if( power == 0 )
                powerOfFour = 1;
            else
                powerOfFour *= 4;
            if( sequence[idx] == 'A' );
            else if( sequence[idx] == 'C' )
            {
                answer = answer + powerOfFour;
            }
            else if( sequence[idx] == 'G' )
            {
                answer = answer + 2 * powerOfFour;
            }
            else
            {
                answer = answer + 3 * powerOfFour;
            }
            ++power;
            --idx;
        }
        printf( "%llu)\n", answer);
        ++i;
    }
    return 0;
}
