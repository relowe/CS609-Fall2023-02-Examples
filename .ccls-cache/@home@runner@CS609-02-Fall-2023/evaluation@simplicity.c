#include <stdio.h>

int main()
{
    /* 32 keywords is good,
        but tersness can complicate things */
    int x=0;
    const char *msg="hello, world\n";

    // two ways to add 5 to x
    x = x + 5;
    x += 5;

    // add 1 to x
    x=0;
    printf("%d\n", x = x + 1);
    printf("%d\n", x += 1);
    printf("%d\n", x++);
    printf("%d\n", ++x);
    printf("%d\n", x);

    // why we have this operator
    x=0;
    while(msg[x]) {
        putchar(msg[x++]);
    }


    printf("%d\n", x+5);
    printf("%s\n", msg+5);
    printf("%c\n", msg[0]+5);

    struct {
    int x;
    int y;
    } my_struct;

    printf("%d\n", my_struct+5);
}