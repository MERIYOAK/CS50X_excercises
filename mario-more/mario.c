#include <cs50.h>
#include <stdio.h>

void PyramidMaker(int height);

int main (void)
{   int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    PyramidMaker(height);
}
void PyramidMaker(int height)
{
   for(int i = 1; i <= height; i++ )
        {  /*for spaces*/
        for(int spaces = height - i; spaces > 0; spaces--)
        {
            printf(" ");
        }
          /*for the left triangle*/
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
          /* for the middle gap*/
        printf("  ");
         /*this is for the right triangle*/
        for(int k = 1; k <= i; k++)
        {
             printf("#");
        }
        printf("\n");
        }
}








