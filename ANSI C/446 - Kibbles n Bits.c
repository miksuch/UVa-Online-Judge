#include <stdio.h>
#include <string.h>
#include <math.h>
unsigned int powerof16( unsigned int x )
{
    unsigned int i = 1, y = 1;
    if( x == 0 )
        return 1;
    else
    {
        while( i <= x )
        {
            y = y * 16;
            ++i;
        }
        return y;
    }
}
int main()
{
    unsigned int testCases, sizeA, sizeB, tmp, answer, numA, numB, power16;
    int i, k;
    char sign, a[4], b[4], binary[13];
    scanf( "%u", &testCases );
    while( testCases-- )
    {
        scanf( "%s %c %s", a, &sign, b );
        answer = 0;
        numA = 0; numB = 0;
        sizeA = strlen(a);
        sizeB = strlen(b);
        for( i = 0; i < sizeA; ++i )
        {
            tmp = a[i] - '0';
            if( tmp >= 17 )
                tmp -= 7;
            power16 = powerof16( sizeA - 1 - i );
            numA += tmp * power16 ;
        }
        for( i = 0; i < sizeB; ++i )
        {
            tmp = b[i] - '0';
            if( tmp >= 17 )
                tmp -= 7;
            power16 = powerof16( sizeB - 1 - i );
            numB += tmp * power16 ;
        }

        for( k = 0; k < 12; ++k )
            binary[k] = '0';
        binary[12] = '\0';
        if( sign == '+' )
            answer = numA + numB;
        else answer = numA - numB;
        k = 11;
        while( numA != 0 )
        {
            if( numA%2 )
                binary[k] = '1';
            else binary[k] = '0';
            --k;
            numA = numA/2;
        }
        printf( "0%s %c ", binary, sign );
        for( k = 0; k < 12; ++k )
            binary[k] = '0';
        binary[12] = '\0';
        k = 11;
        while( numB != 0 )
        {
            if( numB%2 )
                binary[k] = '1';
            else binary[k] = '0';
            --k;
            numB = numB/2;
        }
        printf( "0%s = %u\n", binary, answer );
    }
    return 0;
}
