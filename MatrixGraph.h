#pragma once
#include "IGraph.h"

class MatrixGraph: public IGraph {
public:
    explicit MatrixGraph(size_t size);
    MatrixGraph(const IGraph* graph);
    void AddEdge(int from, int to) override;
    size_t VerticesCount() const override;
    vector<int> GetNextVertices(int vertex) const override;
    vector<int> GetPrevVertices(int vertex) const override;

private:
    size_t count;
    vector<vector<bool>> edges;
};
