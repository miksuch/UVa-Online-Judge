
#include <stdio.h>
int main()
{
    double Point[4][2],Reference[1][2],Answer[1][2];
    while( scanf( "%lf %lf %lf %lf %lf %lf %lf %lf", &Point[0][0], &Point[0][1], &Point[1][0], &Point[1][1], &Point[2][0], &Point[2][1], &Point[3][0], &Point[3][1] ) != EOF )
    {
        if( Point[0][0] == Point[2][0] && Point[0][1] == Point[2][1] )
        {
            Answer[0][0] = Point[3][0] + ( Point[0][0] - Point[1][0] ) * (-1);
            Answer[0][1] = Point[3][1] + ( Point[0][1] - Point[1][1] ) * (-1);
        }
        else if( Point[0][0] == Point[3][0] && Point[0][1] == Point[3][1] )
        {
            Answer[0][0] = Point[2][0] + ( Point[0][0] - Point[1][0] ) * (-1);
            Answer[0][1] = Point[2][1] + ( Point[0][1] - Point[1][1] ) * (-1);
        }
        else if( Point[1][0] == Point[2][0] && Point[1][1] == Point[2][1] )
        {
            Answer[0][0] = Point[3][0] + ( Point[1][0] - Point[0][0] ) * (-1);
            Answer[0][1] = Point[3][1] + ( Point[1][1] - Point[0][1] ) * (-1);
        }
        else
        {
            Answer[0][0] = Point[0][0] + ( Point[1][0] - Point[2][0] ) * (-1);
            Answer[0][1] = Point[0][1] + ( Point[1][1] - Point[2][1] ) * (-1);
        }
        printf( "%.3lf %.3lf \n", Answer[0][0], Answer[0][1] );
    }
    return 0;
}

