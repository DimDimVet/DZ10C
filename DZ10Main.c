#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define VolStop 2584 // Task1
#define VolStart 0   // Task1
#define VolStep 1    // Task1
#define SizeRows 5   // Task2
#define SizeCols 5   // Task2
#define VolMax 10    // 127;  // Task2
#define OpenCells(x, y) void openCells(int x, int y)

#define StartTask1 printf("Task1 -> Fibonacci\t")
#define StopTask1 printf("\nStop Task1\n")

#define BOARD board
#define ARR [SizeRows][SizeCols]
#define LinkARR **board

void Task1(int volStop, int volStart, int volStep, bool isZeroItaration); // Фибоначчи
void Task2(int volMax);
int **fullArr(int (*arr)[SizeCols], int sizeRows, int sizeCols, int volMax);
void writeConsoleArr(int (*arr)[SizeCols], int sizeRows);                    // Task2
int pressButton(int volMax);                                                 // Task2
void findCells(int input, int (*arr)[SizeCols], int sizeCols, int sizeRows); // Task2
void openCells(int x, int y);                                                // Task2

void main()
{
    printf("Run DZ9\n\n");
    Task1(VolStop, VolStart, VolStep, true);
    Task2(VolMax);
}

void Task1(int volStop, int volStart, int volStep, bool isZeroItaration)
{

    if (isZeroItaration)
    {
        StartTask1;
    }

    if (volStart > volStop)
    {
        StopTask1;
        return;
    }

    printf("%d\t", volStart);
    Task1(volStop, volStep, volStart + volStep, false);
}

void Task2(int volMax)
{
    printf("\nTask2 start\n");

    int BOARD ARR;
    LinkARR = fullArr(BOARD, SizeRows, SizeCols, volMax);
    int sizeTemp=SizeRows;
    
    writeConsoleArr(BOARD, SizeRows);

    int input = pressButton(volMax);

    findCells(input, BOARD, SizeCols, SizeRows);
}

int **fullArr(int (*arr)[SizeCols], int sizeRows, int sizeCols, int volMax)
{
    srand(time(0));

    for (int i = 0; i < sizeCols; i++)
    {
        for (int j = 0; j < sizeRows; j++)
        {
            *(*(arr + i) + j) = rand() % volMax;
        }
    }

    return **arr;
}

int pressButton(int volMax)
{
    int input;
    printf("In volume 0 - %d: ", volMax);
    scanf("%d", &input);
    return input;
}

void findCells(int input, int (*arr)[SizeCols], int sizeCols, int sizeRows)
{
    for (int i = 0; i < sizeCols; i++)
    {
        for (int j = 0; j < sizeRows; j++)
        {
            if (*(*(arr + i) + j) == input)
            {
                OpenCells(i, j);
                *(*(arr + i) + j) = 1;
            }
            else
            {
                *(*(arr + i) + j) = 0;
            }
        }
    }

    writeConsoleArr(arr, sizeRows);
}

void writeConsoleArr(int (*arr)[SizeCols], int sizeRows)
{

    for (int i = 0; i < SizeCols; i++)
    {
        for (int j = 0; j < SizeRows; j++)
        {
           printf("|%d|", *(*(arr + i) + j));
        }
        printf("\n");
    }
}

void openCells(int x, int y)
{
    printf("Open cells (%d, %d)\n", x, y);
}
