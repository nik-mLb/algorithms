#include "MatrixGraph.h"
#include <cassert>

MatrixGraph::MatrixGraph(int vertexCount) {
    assert(vertexCount > 0);
    adjacencyMatrix.resize(vertexCount, std::vector<bool>(vertexCount, false));
}

MatrixGraph::MatrixGraph(const IGraph& graph){
    int vertexCount = graph.VerticesCount();
    adjacencyMatrix.resize(vertexCount, std::vector<bool>(vertexCount, false));
    for (int i = 0; i < vertexCount; i++){
        std::vector<int> nextVertices = graph.GetNextVertices(i);
        for (int to : nextVertices) {
            adjacencyMatrix[i][to] = true;
        }
    }
}

void MatrixGraph::AddEdge(int from, int to){
    assert(from >= 0 && from < adjacencyMatrix.size());
    assert(to >= 0 && to < adjacencyMatrix.size());
    adjacencyMatrix[from][to] = true;
}

int MatrixGraph::VerticesCount() const{
    return adjacencyMatrix.size();
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const{
    assert(vertex >= 0 && vertex < adjacencyMatrix.size());
    std::vector<int> result;
    for (int i = 0; i < adjacencyMatrix.size(); i++){
        if (adjacencyMatrix[vertex][i]) {
            result.push_back(i);
        }
    }
    return result;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const{
    assert(vertex >= 0 && vertex < adjacencyMatrix.size());
    std::vector<int> result;
    for (int i = 0; i < adjacencyMatrix.size(); i++){
        if (adjacencyMatrix[i][vertex]){
            result.push_back(i);
        }
    }
    return result;
}