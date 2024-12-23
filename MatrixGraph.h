#ifndef MATRIXGRAPH_H
#define MATRIXGRAPH_H

#include "graph.h"

class MatrixGraph : public IGraph {
public:
    MatrixGraph(int vertexCount);
    MatrixGraph(const IGraph& graph);

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::vector<bool>> adjacencyMatrix;
};

#endif 