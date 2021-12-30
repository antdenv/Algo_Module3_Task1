#include "SetGraph.h"

SetGraph::SetGraph(const IGraph* graph):
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

void SetGraph::AddEdge(int from, int to) {
    in[to].insert(from);
    out[from].insert(to);
}

size_t SetGraph::VerticesCount() const {
    return count;
}

vector<int> SetGraph::GetNextVertices(int vertex) const {
    vector<int> vertices;
    for (int i: in[vertex])
        vertices.push_back(i);

    return vertices;
}

vector<int> SetGraph::GetPrevVertices(int vertex) const {
    vector<int> vertices;
    for (int i: out[vertex])
        vertices.push_back(i);

    return vertices;
}