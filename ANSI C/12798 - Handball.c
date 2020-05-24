#include <stdio.h>
int main()
{
    unsigned int players, matches, i, pointsScored, answer, ok;
    while( scanf( "%u %u", &players, &matches ) != EOF )
    {
        answer = 0;
        while( players-- )
        {
            ok = 0;
            for( i = 0; i < matches; ++i )
            {
                scanf( "%u", &pointsScored );
                if( pointsScored > 0 )
                    ++ok;
            }
            if( ok == matches )
                ++answer;
        }
        printf( "%u\n", answer );
    }
    return 0;
}
