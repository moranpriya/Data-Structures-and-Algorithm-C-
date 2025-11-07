#include <stdio.h>
#include <stdlib.h>

struct Gnode {
    int vertex;
    struct Gnode *next;
};

struct Gnode* adjList[10];

void initGraph(int vertices) {
    for(int i = 0; i < vertices; i++) {
        adjList[i] = NULL;
    }
}

struct Gnode* createNode(int vert) {
    struct Gnode* new_gnode = (struct Gnode*)malloc(sizeof(struct Gnode));
    new_gnode -> vertex = vert;
    new_gnode->next = NULL;
    return new_gnode;
}

void addEdge(int src, int dest) {
    struct Gnode* new_dnode = createNode (dest);
    new_dnode -> next = adjList[src];
    adjList[src] = new_dnode;

    struct Gnode* new_snode = createNode(src);
    new_snode -> next = adjList[dest];
    adjList[dest] = new_snode;
}

void displayGraph(int vertices) {
    for(int i = 0; i < vertices; i++) {
        struct Gnode* temp = adjList[i];
    
        printf("Vertex: %d ", i);

    while(temp != NULL) {
        printf("-> %d", temp -> vertex);
        temp = temp -> next;
    }
    printf("\n");
    }
}

int main() {
    int vertices = 5;

    initGraph(vertices);
    addEdge(0,1);
    addEdge(0,2);
    addEdge(0,3);
    addEdge (1,2);
    addEdge(1,2);
    addEdge (1,4);
    addEdge(2,3);
    addEdge(3,4);

    displayGraph(vertices);

    return 0;
}