#include "ListGraph.h"

ListGraph::ListGraph(const IGraph *graph):
        count(graph->VerticesCount()), in(count), out(count)
{
    vector<int> vertices;

    for (int i=0; i < count; i++) {
        vertices = graph->GetNextVertices(i);
        for (int j: vertices)
            AddEdge(i, j);

        vertices.clear();
    }
}

void ListGraph::AddEdge(int from, int to) {
    if (in.size() < out.size()) {
        for (int i: in[to]) {
            if (i == from) return;  //  a new edge (u,v) is only inserted if there was no path from v to u before
        }
    } else {
        for (int i: out[from]) {
            if (i == to) return;
        }
    }

    in[to].push_back(from);
    out[from].push_back(to);
}

size_t ListGraph::VerticesCount() const {
    return count;
}

vector<int> ListGraph::GetNextVertices(int vertex) const {
    vector<int> vertices;
    for (int i: in[vertex])
        vertices.push_back(i);

    return vertices;
}

vector<int> ListGraph::GetPrevVertices(int vertex) const {
    vector<int> vertices;
    for (int i: out[vertex])
        vertices.push_back(i);

    return vertices;
}