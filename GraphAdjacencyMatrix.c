#include <stdio.h>
int adjMatrix[10][10];

void initGraph (int vertices) {
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

void addEdge (int src, int dest) {
    adjMatrix[src] [dest] = 1;
    adjMatrix[dest][src] = 1;
}

void printGraph (int vertices) {
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices = 5;
    initGraph (vertices);

    addEdge(0,1);
    addEdge(0,2);
    addEdge(0,3);
    addEdge (1,2);
    addEdge (1,2);
    addEdge(1,4);
    addEdge (2,3);
    addEdge(3,4);

    printf("Adjacency Matrix: \n");
    printGraph(vertices);

    return 0;
}