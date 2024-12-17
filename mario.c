#include<stdio.h>
#include<cs50.h>
int main(void)
{
    int h;         int n =1;
    do
    { h = get_int("how is high?  ");
    }
    while( h > 8 || h < 1);
/*   for(int q = 0 ;q < h ;q++)
    {
        for(int a= h-n; a > 0; a--)
{
    printf(" ");
}
        for(int x=0 ; x < n; x++)
{
    printf("#");
}
    printf("  ");
for(int z=0 ; z < n; z++)
{
    printf("#");
}
n++;
printf("\n");
    }
}
*/
 for (int i = 1; i <= h; i++)
    {
        printf("%*s%s  %s\n", h - i, "", &"########"[8 - i], &"########"[8 - i]);
    }

    return 0;
}
