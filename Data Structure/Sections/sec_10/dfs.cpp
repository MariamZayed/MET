#include <iostream>
using namespace std;

#define MAX 5

struct Vertex {
    char label;
    bool visited;
};

// الستاك كل شغلانتها انها تخزن اندكس الفيرتكس الي موجوده في الجراف, يعني لو جراف موجود فيه 3 فيرتكس, فاول فيرتكس هيكون اندكس
//  زيرو, وتاني فيرتكس انندكس 1 وتالت فيرتكس اندكس 2 
int stack[MAX];
int top = -1;

// vertices
Vertex* lstVertices[MAX];

// adjacency matrix
int adjMatrix[MAX][MAX];

// number of vertices
int vertexCount = 0;

/* Stack functions */
void push(int item) {
    stack[++top] = item;
}

int pop() {
    return stack[top--];
}

int peek() {
    return stack[top];
}

bool isStackEmpty() {
    return top == -1;
}

/* Graph functions */
void addVertex(char label) {
    Vertex* vertex = new Vertex();
    vertex->label = label;
    vertex->visited = false;
    lstVertices[vertexCount++] = vertex;
}

void addEdge(int start, int end) {
    adjMatrix[start][end] = 1;
    adjMatrix[end][start] = 1;
}

void displayVertex(int vertexIndex) {
    cout << lstVertices[vertexIndex]->label << " ";
}

int getAdjUnvisitedVertex(int vertexIndex) {
    for (int i = 0; i < vertexCount; i++) {
        if (adjMatrix[vertexIndex][i] == 1 && lstVertices[i]->visited == false) {
            return i;// اول مهيلاقي الفيرتكس المطلوبه, الفور لوب هيقف ويرجع الاندكس بتاع الفرتكس
        }
    }
    return -1; // الحالة الوحيده تكون -1  لما تكون الصف الي احنا فيه يكون كل الفيرتكسيز  الفيزيتيد بتاعها = ترو
}       


void depthFirstSearch() {
    // جملة تحفظها: ابدأ من أول فيرتكس، وخليه نقطة الرجوع. وبما ان نقطة الرجوع هى الساس ومش هتتغير فاحنا الي بندخلها بادينا
    lstVertices[0]->visited = true;
    displayVertex(0);
    push(0);// اول عنصر هيخش في الستاك هيكون ديما الاندكس بتاعه رقم زيرو,

    while (!isStackEmpty()) {
        int unvisitedVertex = getAdjUnvisitedVertex(peek());

        if (unvisitedVertex == -1) {
            pop();
        } else {
            lstVertices[unvisitedVertex]->visited = true;
            displayVertex(unvisitedVertex);
            push(unvisitedVertex);
        }
    }

    // reset visited flags
    for (int i = 0; i < vertexCount; i++) {
        lstVertices[i]->visited = false;
    }
}

int main() {
\\\\\\    // initialize adjacency matrix
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            adjMatrix[i][j] = 0;
        }
    }

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

    cout << "Depth First Search: ";
    depthFirstSearch();

    return 0;
}
