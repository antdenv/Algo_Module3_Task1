#pragma once
#include "IGraph.h"
using std::vector;
using std::set;

class SetGraph: public IGraph {
public:
    explicit SetGraph(size_t size): count(size), in(size), out(size) {}
    SetGraph(const IGraph* graph);
    void AddEdge(int from, int to) override;
    size_t VerticesCount() const override;
    vector<int> GetNextVertices(int vertex) const override;
    vector<int> GetPrevVertices(int vertex) const override;

private:
    size_t count;
    vector<set<int>> in;
    vector<set<int>> out;
};
