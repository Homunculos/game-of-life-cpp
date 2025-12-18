#include <iostream>
#include <stdlib.h>
#include <time.h>
#include<windows.h>
const int maxWidth = 100;
const int maxHeight = 100;
void creatingTheWorld (int [maxWidth][maxHeight] , int , int );
void changingTheWorld (int [maxWidth][maxHeight] ,int ,int );
void printingTheWorld (int [maxWidth][maxHeight], int , int );
int countingNeighbors (const int  [maxWidth][maxHeight] , int , int , int , int);
using namespace std;

int main()
{
    int width , height ;
    cin >> width >> height;
    int world[maxWidth][maxHeight];
    creatingTheWorld(world,width,height);
    while (1)
    {
        printingTheWorld(world,width,height);
        changingTheWorld(world,width,height);

    }
}
void creatingTheWorld (int world[maxWidth][maxHeight] , int w , int h)
{
    srand(time(0));
    for (int i = 0 ; i < w ; i++)
        for (int j = 0 ; j < h ; j++)
        {
            world[i][j] = rand() % 2;
        }

 }
int countingNeighbors(const int world[maxWidth][maxHeight] , int w , int h ,int x ,int y)
{
    int count = 0;
    for (int i = -1 ; i <=1 ; i ++)
        for (int j = -1 ; j < 2 ; j++)
        {
            if (i==0 && j == 0)
                continue;
        int dy = y + j;
        int dx = x + i;
            if (world [dx][dy] == 1)
                count++;
        }
    return count;
}
void changingTheWorld (int world [maxWidth][maxHeight] , int w , int h)
{
    int newWorld [w][h];
    for (int i = 0 ; i < w ; i++ )
        for(int j = 0 ; j < h ; j++)
        {
            int neighbors = countingNeighbors(world,w,h,i,j);
            if (world[i][j])
            {
                newWorld[i][j] = (neighbors == 2 || neighbors == 3);
            }
            else
            {
                newWorld[i][j] = (neighbors == 3);
            }
        }
     for (int i = 0 ; i < w ; i++ )
        for(int j = 0 ; j < h ; j++)
            world [i][j] = newWorld[i][j];
}
void printingTheWorld (int world[maxWidth][maxHeight],int w , int h)
{
    system("cls");
     for (int i = 0 ; i < w ; i++ )
     {

        for(int j = 0 ; j < h ; j++)
            {
                cout << (world[i][j] ? "@ " : ". ");
            }
        cout << endl;
     }
    Sleep(500);
}
