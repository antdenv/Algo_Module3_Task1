#pragma once
#include <vector>
#include <list>
#include <set>
#include <utility>

using std::vector;

struct IGraph {
    virtual ~IGraph() {};
    virtual void AddEdge(int from, int to) = 0;
    virtual size_t VerticesCount() const  = 0;
    virtual vector<int> GetNextVertices(int vertex) const = 0;
    virtual vector<int> GetPrevVertices(int vertex) const = 0;
};
