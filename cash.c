#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float o;
    int c = 0;
    printf("O hai, ");
    do
    {
        printf("How much is owed?\n");
        o = (float)get_float();
    }
    while(o < 0);
    
    o = roundf((o*100));
    
    while(o >= 25)
        {
        c = c + 1;
        o = o - 25;
        
        }
     while(o >= 10)
        {
        c = c + 1;
        o = o - 10;
        }
     while(o >= 5)
        {
        c = c + 1;
        o = o - 5;
        
        }
     while(o >= 1)
        {
        c = c + 1;
        o = o - 1;
        }
      
    printf("%d\n", c);
}
