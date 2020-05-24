#include <stdio.h>
union data
{
    int integer;
    char converse[4];
};
int main()
{
    union data u;
    char tmp;
    int input;
    while( scanf( "%d", &input ) != EOF )
    {
        u.integer = input;
        tmp = u.converse[0];
        u.converse[0] = u.converse[3];
        u.converse[3] = tmp;
        tmp = u.converse[1];
        u.converse[1] = u.converse[2];
        u.converse[2] = tmp;
        printf( "%d converts to %d\n", input, u.integer );
    }
    return 0;
}
