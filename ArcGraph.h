#pragma once
#include "IGraph.h"
using std::pair;

class ArcGraph: public IGraph {
public:
    explicit ArcGraph(size_t size): count(size), edges(size) {};
    ArcGraph(IGraph *graph);
    void AddEdge(int from, int to) override;
    size_t VerticesCount() const override;
    vector<int> GetNextVertices(int vertex) const override;
    vector<int> GetPrevVertices(int vertex) const override;

private:
    size_t count;
    vector<pair<int, int>> edges;
};