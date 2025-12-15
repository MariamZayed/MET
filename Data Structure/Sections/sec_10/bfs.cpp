#include <iostream>
using namespace std;

#define MAX 5

struct Vertex {
    char label;
    bool visited;
};

// ===== Queue variables =====
int queue[MAX];
int front = 0;
int rear = -1;
int queueItemCount = 0;

// ===== Graph variables =====
struct Vertex* lstVertices[MAX];
int adjMatrix[MAX][MAX];
int vertexCount = 0;

// ===== Queue functions =====
void insert(int data) {
    queue[++rear] = data;
    queueItemCount++;
}

int removeData() {
    queueItemCount--;
    return queue[front++];
}

bool isQueueEmpty() {
    return queueItemCount == 0;
}

// ===== Graph functions =====
void addVertex(char label) {
    struct Vertex* vertex = (struct Vertex*) malloc(sizeof(struct Vertex));
    vertex->label = label;
    vertex->visited = false;
    lstVertices[vertexCount++] = vertex;
}

void addEdge(int start, int end) {
    adjMatrix[start][end] = 1;
    adjMatrix[end][start] = 1;   // undirected graph
}

void displayVertex(int vertexIndex) {
    cout << lstVertices[vertexIndex]->label << " ";
}

int getAdjUnvisitedVertex(int vertexIndex) {
    for (int i = 0; i < vertexCount; i++) {
        if (adjMatrix[vertexIndex][i] == 1 &&
            lstVertices[i]->visited == false)
            return i;
    }
    return -1;
}

// ===== BFS =====
void breadthFirstSearch() {
    // mark first node as visited
    lstVertices[0]->visited = true;
    displayVertex(0);
    insert(0);

    while (!isQueueEmpty()) {
        int tempVertex = removeData();

        int unvisitedVertex;
        while ((unvisitedVertex = getAdjUnvisitedVertex(tempVertex)) != -1) {
            lstVertices[unvisitedVertex]->visited = true;
            displayVertex(unvisitedVertex);
            insert(unvisitedVertex);
        }
    }

    // reset visited
    for (int i = 0; i < vertexCount; i++) {
        lstVertices[i]->visited = false;
    }
}

// ===== main =====
int main() {
    int i, j;

    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++)
            adjMatrix[i][j] = 0;

    addVertex('S'); // 0
    addVertex('A'); // 1
    addVertex('B'); // 2
    addVertex('C'); // 3
    addVertex('D'); // 4

    addEdge(0, 1); // S-A
    addEdge(0, 2); // S-B
    addEdge(0, 3); // S-C
    addEdge(1, 4); // A-D
    addEdge(2, 4); // B-D
    addEdge(3, 4); // C-D

    cout << "Breadth First Search: ";
    breadthFirstSearch();

    return 0;
}
