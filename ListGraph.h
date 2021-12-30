#pragma once
#include "IGraph.h"
using std::list;

class ListGraph: public IGraph {
public:
    explicit ListGraph(size_t size): count(size), in(size), out(size) {}
    ListGraph(const IGraph* graph);
    void AddEdge(int from, int to) override;
    size_t VerticesCount() const override;
    vector<int> GetNextVertices(int vertex) const override;
    vector<int> GetPrevVertices(int vertex) const override;

private:
    size_t count;
    vector<list<int>> in;
    vector<list<int>> out;
};
