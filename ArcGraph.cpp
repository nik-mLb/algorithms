#include "ArcGraph.h"
#include <cassert>

ArcGraph::ArcGraph(int vertexCount):vertexCount(vertexCount){}

ArcGraph::ArcGraph(const IGraph& graph){
    vertexCount = graph.VerticesCount();
    for (int i = 0; i < vertexCount; ++i) {
        std::vector<int> nextVertices = graph.GetNextVertices(i);
        for (int to : nextVertices) {
            edges.emplace_back(i, to);
        }
    }
}

void ArcGraph::AddEdge(int from, int to){
    assert(from >= 0 && from < vertexCount);
    assert(to >= 0 && to < vertexCount);
    edges.emplace_back(from, to);
}

int ArcGraph::VerticesCount() const{
    return vertexCount;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const{
    std::vector<int> result;
    for (auto& edge : edges){
        if (edge.first == vertex) {
            result.push_back(edge.second);
        }
    }
    return result;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const{
    std::vector<int> result;
    for (auto& edge : edges){
        if (edge.second == vertex) {
            result.push_back(edge.first);
        }
    }
    return result;
}