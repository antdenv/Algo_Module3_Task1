#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(size_t size): count(size), edges(size) {
    for (vector<bool>& edge: edges) {
        edge.assign(count, false);
    }
}

MatrixGraph::MatrixGraph(const IGraph *graph) {
    MatrixGraph(graph->VerticesCount());
    vector<int> vertices;

    for (int i=0; i < count; i++) {
        vertices = graph->GetNextVertices(i);
        for (int j: vertices)
            AddEdge(i, j);

        vertices.clear();
    }
}

void MatrixGraph::AddEdge(int from, int to) {
    edges[from][to] = true;
}

size_t MatrixGraph::VerticesCount() const {
    return count;
}

vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    vector<int> vertices;

    for (int i=0; i < count; i++) {
        if (edges[i][vertex])
            vertices.push_back(i);
    }

    return vertices;
}

vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    vector<int> vertices;

    for (int i=0; i < count; i++) {
        if (edges[vertex][i])
            vertices.push_back(i);
    }

    return vertices;
}