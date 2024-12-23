#include "SetGraph.h"
#include <cassert>

SetGraph::SetGraph(int vertexCount){
    assert(vertexCount > 0);
    adjacencySets.resize(vertexCount);
}

SetGraph::SetGraph(const IGraph& graph){
    int vertexCount = graph.VerticesCount();
    adjacencySets.resize(vertexCount);
    for (int i = 0; i < vertexCount; ++i) {
        std::vector<int> nextVertices = graph.GetNextVertices(i);
        for (int to : nextVertices) {
            adjacencySets[i].insert(to);
        }
    }
}

void SetGraph::AddEdge(int from, int to){
    assert(from >= 0 && from < adjacencySets.size());
    assert(to >= 0 && to < adjacencySets.size());
    adjacencySets[from].insert(to);
}

int SetGraph::VerticesCount() const{
    return adjacencySets.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const{
    assert(vertex >= 0 && vertex < adjacencySets.size());
    std::vector<int> result;
    for (int nVertex : adjacencySets[vertex]){
        result.push_back(nVertex);
    }
    return result;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const{
    assert(vertex >= 0 && vertex < adjacencySets.size());
    std::vector<int> result;
    for (int i = 0; i < adjacencySets.size(); i++){
        bool found = false;
        for (int neighbor : adjacencySets[i]) {
            if (neighbor == vertex) {
                found = true;
                break;
            }
        }
        if (found) {
            result.push_back(i);
        }
    }
    return result;
}