#include <iostream>
#include <queue>
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"
#include "ArcGraph.h"

void BFS(const IGraph& graph, int vertex, void (*visit)(int)) {
    std::vector<bool> visited(graph.VerticesCount(), false);
    std::queue<int> bfsQueue;
    bfsQueue.push(vertex);
    visited[vertex] = true;

    while (!bfsQueue.empty()) {
        int current = bfsQueue.front();
        bfsQueue.pop();
        visit(current);

        std::vector<int> adjList = graph.GetNextVertices(current);
        for (int i = 0; i < adjList.size(); ++i) {
            if (!visited[adjList[i]]) {
                bfsQueue.push(adjList[i]);
                visited[adjList[i]] = true;
            }
        }
    }
}

int main() {
    IGraph* mainGraph = new ListGraph(7);
    mainGraph->AddEdge(0, 1);
    mainGraph->AddEdge(0, 3);
    mainGraph->AddEdge(0, 4);
    mainGraph->AddEdge(1, 2);
    mainGraph->AddEdge(1, 3);
    mainGraph->AddEdge(2, 5);
    mainGraph->AddEdge(3, 4);
    mainGraph->AddEdge(3, 5);
    mainGraph->AddEdge(3, 6);
    mainGraph->AddEdge(4, 6);
    mainGraph->AddEdge(6, 5);

    ListGraph listGraph(*mainGraph);
    MatrixGraph matrixGraph(*mainGraph);
    SetGraph setGraph(*mainGraph);
    ArcGraph arcGraph(*mainGraph);

    std::cout << "BFS for all types graphs:" << std::endl;
    std::cout << "ListGraph:" << std::endl;
    BFS(listGraph, 0, [](int vertex) { std::cout << vertex << ", "; });
    std::cout << std::endl << "MatrixGraph:" << std::endl;
    BFS(matrixGraph, 0, [](int vertex) { std::cout << vertex << ", "; });
    std::cout << std::endl << "SetGraph:" << std::endl;
    BFS(setGraph, 0, [](int vertex) { std::cout << vertex << ", "; });
    std::cout << std::endl << "ArcGraph:" << std::endl;
    BFS(arcGraph, 0, [](int vertex) { std::cout << vertex << ", "; });
    std::cout << std::endl;

    delete mainGraph;
    return 0;
}

//g++ main.cpp ListGraph.cpp MatrixGraph.cpp SetGraph.cpp ArcGraph.cpp -o main && ./main