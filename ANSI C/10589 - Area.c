#include <stdio.h>
int main()
{
    int N,M,realN;
    double a, x, y, distance, area;
    scanf( "%d %lf", &N, &a );
    while( N != 0 )
    {
        area = 0; M=0; realN = N;
        while( realN > 0 )
        {
            scanf( "%lf %lf", &x, &y );
            distance = x*x + y*y;
            if( distance <= a*a )
                {
                    distance = x*x + (a - y)*(a - y);
                    if( distance <= a*a )
                    {
                        distance = (a - x)*(a - x) + (a - y) *(a - y);
                        if( distance <= a*a )
                        {
                            distance = (a - x)*(a - x) + y*y;
                            if( distance <= a*a )
                                ++M;
                        }
                    }
                }
            --realN;
        }
        area = M*a*a/N;
        if( area <= 0 )
            area = area * (-1);
        printf( "%lf\n", area);
        scanf( "%d %lf", &N, &a );
    }
    return 0;
}
