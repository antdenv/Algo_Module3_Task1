/*
    Дан базовый интерфейс для представления ориентированного графа:
    struct IGraph {
        virtual ~IGraph() {}
	    // Добавление ребра от from к to.
        virtual void AddEdge(int from, int to) = 0;
	    virtual int VerticesCount() const  = 0;
        virtual std::vector<int> GetNextVertices(int vertex) const = 0;
        virtual std::vector<int> GetPrevVertices(int vertex) const = 0;
    };

    Необходимо написать несколько реализаций интерфейса:
    ListGraph, хранящий граф в виде массива списков смежности,
    MatrixGraph, хранящий граф в виде матрицы смежности,
    SetGraph, хранящий граф в виде массива хэш-таблиц/сбалансированных деревьев поиска,
    ArcGraph, хранящий граф в виде одного массива пар {from, to}.
    Также необходимо реализовать конструктор, принимающий const IGraph&. Такой конструктор должен скопировать переданный граф в создаваемый объект.
    Для каждого класса создавайте отдельные h и cpp файлы.
    Число вершин графа задается в конструкторе каждой реализации.
*/

#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"
#include "ArcGraph.h"
#include "IGraph.h"

#include "time.h"
#include "iostream"
#include "random"

using std::cout;
using std::endl;

void fillGraph(IGraph *graph, const size_t count) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1, count);
    std::uniform_real_distribution<double> operation(1, 3);

    for (int i=0; i < count; i++) {
        switch ((int)operation(mt)) {
            case 1:
                graph->AddEdge((int)dist(mt), (int)dist(mt));
                break;
            case 2:
                graph->GetNextVertices((int)dist(mt));
                break;
            case 3:
                graph->GetPrevVertices((int)dist(mt));
                break;
            default:
                break;
        }
    }
}

void func() {
    size_t testCount = 10000;

    ListGraph graphL(testCount);
    clock_t time = clock();
    fillGraph(&graphL, testCount);
    cout << (double)(clock() - time) / CLOCKS_PER_SEC << endl;

    ArcGraph graphA(testCount);
    time = clock();
    fillGraph(&graphA, testCount);
    cout << (double)(clock() - time) / CLOCKS_PER_SEC << endl;

    MatrixGraph graphM(testCount);
    time = clock();
    fillGraph(&graphM, testCount);
    cout << (double)(clock() - time) / CLOCKS_PER_SEC << endl;

    SetGraph setGraph(testCount);
    time = clock();
    fillGraph(&setGraph, testCount);
    cout << (double)(clock() - time) / CLOCKS_PER_SEC << endl;

    ListGraph lGraph1(&graphA);
    ListGraph lGraph2(&graphM);
    ListGraph lGraph3(&setGraph);
    ArcGraph aGraph1(&graphL);
    ArcGraph aGraph2(&graphM);
    ArcGraph aGraph3(&setGraph);
    MatrixGraph mGraph1(&graphL);
    MatrixGraph mGraph2(&graphA);
    MatrixGraph mGraph3(&setGraph);
    SetGraph setGraph1(&graphL);
    SetGraph setGraph2(&graphA);
    SetGraph setGraph3(&graphM);
}

int main() {
    func();
    return 0;
}
