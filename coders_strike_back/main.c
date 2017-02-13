#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define CLOSE_DIST 5000
#define ANGLE_CONST 40 // 40%
#define DIST_CONST 0.012 // 60%

float setAcc(int a, int dist);
float getDistBetweenPoints(int x1, int y1, int x2, int y2);

int main()
{
    int x, y; // position of the pod
    int opponentX, opponentY; // position of the opponent
    int nextCheckpointX, nextCheckpointY; // position of the next check point
    int nextCheckpointDist; // distance to the next checkpoint
    int nextCheckpointAngle; // angle between your pod orientation and the direction of the next checkpoint
    int lastCheckpointX, lastCheckpointY; // position of the last checkpoint
    int distBetwCheckpoints; // distance between the checkpoint you just arrived to and the next one
    float acc; // float acceleration value
    int intacc; // int acceleration value
    int boost = 1;
    
    scanf("%d%d%d%d%d%d", &x, &y, &nextCheckpointX, &nextCheckpointY, &nextCheckpointDist, &nextCheckpointAngle);
    scanf("%d%d", &opponentX, &opponentY);
    lastCheckpointX = nextCheckpointX; lastCheckpointY = nextCheckpointY;
    // game loop
    do 
    {
        acc = setAcc(nextCheckpointAngle, nextCheckpointDist);
        intacc = (int)roundf(acc);
        if(intacc == 100 && boost == 1)
        {
            printf("%d %d BOOST\n", nextCheckpointX, nextCheckpointY);
            boost = 0;
        }
        
        printf("%d %d %d\n", nextCheckpointX, nextCheckpointY, intacc); // OUTPUT
        fprintf(stderr, "Distance between checkpoints: %d, Last checkpoint: (%d, %d), NextCP: (%d, %d), Distance: %d, Angle: %d", distBetwCheckpoints, lastCheckpointX, lastCheckpointY, nextCheckpointX, nextCheckpointY, nextCheckpointDist, nextCheckpointAngle);
        
        scanf("%d%d%d%d%d%d", &x, &y, &nextCheckpointX, &nextCheckpointY, &nextCheckpointDist, &nextCheckpointAngle);
        scanf("%d%d", &opponentX, &opponentY);
    } while (1);

    return 0;
}

float setAcc(int a, int dist)
{
    if(dist > CLOSE_DIST)
        dist = CLOSE_DIST;
    return ((-(1/810)*(a^2) + ANGLE_CONST) + DIST_CONST*dist);
}

float getDistBetweenPoints(int x1, int y1, int x2, int y2)
{
    return sqrt(abs((x2-x1)^2)+abs((y2-y1)^2));
}