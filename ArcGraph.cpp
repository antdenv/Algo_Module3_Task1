#include "ArcGraph.h"

ArcGraph::ArcGraph(IGraph *graph):
        count(graph->VerticesCount()), edges(count)
{
    vector<int> vertices;

    for (int i=0; i < count; i++) {
        vertices = graph->GetNextVertices(i);
        for (int j: vertices)
            AddEdge(i, j);

        vertices.clear();
    }
}

void ArcGraph::AddEdge(int from, int to) {
    for (const auto& edge: edges) {
        if (edge.first == from && edge.second == to)
            return;
    }

    edges.emplace_back(std::make_pair(from, to));
}

size_t ArcGraph::VerticesCount() const {
    return count;
}

vector<int> ArcGraph::GetNextVertices(int vertex) const {
    vector<int> vertices;

    for(const auto& edge: edges) {
        if (edge.first == vertex)
            vertices.push_back(edge.second);
    }
    return vertices;
}

vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    vector<int> vertices;

    for(const auto& edge: edges) {
        if (edge.second == vertex)
            vertices.push_back(edge.first);
    }
    return vertices;
}