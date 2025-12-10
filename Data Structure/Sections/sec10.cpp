#include <bits/stdc++.h>
using namespace std;

struct Vertex {
    char label;
    bool visited;
    Vertex(char l = ' ') : label(l), visited(false) {}
};

const int MAX = 5;
int adjMatrix[MAX][MAX];
vector<Vertex> vertices;
int vertexCount = 0;

void addVertex(char label) {
    vertices.emplace_back(label);
    vertexCount++;
}

void addEdge(int start, int end) {
    // undirected example (set both). for directed graph set only adjMatrix[start][end] = 1;
    adjMatrix[start][end] = 1;
    adjMatrix[end][start] = 1;
}

void displayVertex(int v) {
    cout << vertices[v].label << ' ';
}

/* DFS using explicit stack */
void depthFirstSearch() {
    if (vertexCount == 0) return;
    // reset visited
    for (int i = 0; i < vertexCount; ++i) vertices[i].visited = false;

    vector<int> stack;
    vertices[0].visited = true;
    displayVertex(0);
    stack.push_back(0);

    while (!stack.empty()) {
        int top = stack.back();
        int unvisited = -1;
        for (int i = 0; i < vertexCount; ++i) {
            if (adjMatrix[top][i] == 1 && !vertices[i].visited) {
                unvisited = i;
                break;
            }
        }
        if (unvisited == -1) {
            stack.pop_back();
        } else {
            vertices[unvisited].visited = true;
            displayVertex(unvisited);
            stack.push_back(unvisited);
        }
    }
    cout << endl;
}

/* BFS using queue */
void breadthFirstSearch() {
    if (vertexCount == 0) return;
    // reset visited
    for (int i = 0; i < vertexCount; ++i) vertices[i].visited = false;

    queue<int> q;
    vertices[0].visited = true;
    displayVertex(0);
    q.push(0);

    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int i = 0; i < vertexCount; ++i) {
            if (adjMatrix[v][i] == 1 && !vertices[i].visited) {
                vertices[i].visited = true;
                displayVertex(i);
                q.push(i);
            }
        }
    }
    cout << endl;
}

int main() {
    // init adjacency matrix to 0
    for (int i = 0; i < MAX; ++i)
        for (int j = 0; j < MAX; ++j)
            adjMatrix[i][j] = 0;

    // vertices: S(0), A(1), B(2), C(3), D(4)
    addVertex('S'); // 0
    addVertex('A'); // 1
    addVertex('B'); // 2
    addVertex('C'); // 3
    addVertex('D'); // 4

    // edges (undirected example like في المثال)
    addEdge(0, 1); // S-A
    addEdge(0, 2); // S-B
    addEdge(0, 3); // S-C
    addEdge(1, 4); // A-D
    addEdge(2, 4); // B-D
    addEdge(3, 4); // C-D

    cout << "Depth First Search: ";
    depthFirstSearch();

    cout << "Breadth First Search: ";
    breadthFirstSearch();

    return 0;
}
