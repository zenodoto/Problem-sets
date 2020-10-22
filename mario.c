#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    int s;
    int b;
    
    do
    {
        printf("Hight: ");
        h = get_int();
    }
    while(h < 0 || h > 23);
    
    for(int row = 0; row < h; row++)
    {
        for(s = h - (row + 2); s >= 0 ; s--)
        {
            printf(" ");
        }
        for(b = 0; b < row + 2; b++)
        {
            printf("#");
        }
        printf("\n");
    }
}