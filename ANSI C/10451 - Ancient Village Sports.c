#include <stdio.h>
#include <math.h>
int main()
{
    int caseNumber = 1;
    double pi= 2*acos(0), area, bigRadius, smallRadius, ans1, ans2, n;
    while( scanf( "%lf %lf", &n, &area ) && n > 2 )
    {
        bigRadius = (2 * area) / ( n * sin(2*pi/n) );
        smallRadius = area / ( n * tan( pi/n ) );
        ans1 = bigRadius * pi - area;
        ans2 = area - smallRadius * pi;
        printf( "Case %d: %.5lf %.5lf\n", caseNumber, ans1, ans2 );
        ++caseNumber;
    }
    return 0;
}
