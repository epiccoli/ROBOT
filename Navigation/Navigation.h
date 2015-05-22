#include <stdio.h>
#include <limits.h>
#include "Navigation.cpp"
#define V 9

int minDistance(int dist[], bool sptSet[]);

int printSolution(int dist[], int n);

void dijkstra(int [V][V], int src);