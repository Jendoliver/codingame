#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int mountainH; // represents the height of one mountain.
    int maxHi, maxH; // index of the highest mountaint, height of the highest mountaint
    int i;
    // game loop
    while (1) 
    {
        i = 0;
        maxH = 0;
        for (; i < 8; i++) 
        {
            scanf("%d", &mountainH);
            if(mountainH > maxH)
            {
                maxH = mountainH;
                maxHi = i;
            }      
        }
        printf("%d\n", maxHi); // The index of the mountain to fire on.
    }
    return 0;
}