#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int light[2]; // the position of the light of power
    int Tpos[2]; // Thor's starting position
    int dif[2]; // difference between Tpos and light
    scanf("%d%d%d%d", &light[0], &light[1], &Tpos[0], &Tpos[1]); // get the positions

    // game loop
    while (1) 
    {
        int remainingTurns; // The remaining amount of turns Thor can move. Do not remove this line.
        scanf("%d", &remainingTurns);
        while(remainingTurns)
        {
            dif[0] = light[0] - Tpos[0]; dif[1] = light[1] - Tpos[1];
            if(abs(dif[0]) == abs(dif[1])) // if T and L are on a diagonal (optimal case)
            {
                if(dif[0] > 0) // East Cases
                {
                    Tpos[0]++;
                    if(dif[1] > 0) // SE
                    {
                        Tpos[1]++;
                        printf("SE\n");
                    }
                    else
                    {
                        Tpos[1]--;
                        printf("NE\n");
                    }
                }
                else // West Cases
                {
                    Tpos[0]--;
                    if(dif[1] > 0) // SW
                    {
                        Tpos[1]++;
                        printf("SW\n");
                    }
                    else
                    {
                        Tpos[1]--;
                        printf("NW\n");
                    }
                }
            }
            else // if T and L are not on a diagonal, go to the closest one moving N,E,S,W
            {
                if(abs(dif[0]) > abs(dif[1])) // if the difference is bigger on X axis
                {
                    if(dif[0] > 0) // E
                    {
                        Tpos[0]++;
                        printf("E\n");
                    }
                    else
                    {
                        Tpos[0]--;
                        printf("W\n");
                    }
                }
                else
                {
                    if(dif[1] > 0)
                    {
                        Tpos[1]++;
                        printf("S\n");
                    }
                    else
                    {
                        Tpos[1]--;
                        printf("N\n");
                    }
                }
            }
            remainingTurns--;
        }
        printf("You ran out of time!");
        return 0;
    }
    return 0;
}