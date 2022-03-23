#include <iostream>
#include <string>
#include "Graph.h"

typedef string V;
typedef int E;

using namespace std;

int main() {
    auto* g = new Graph<V, E>();
    Graph<V, E>::Vertex msk = g->insertVertex("Moscow");
    Graph<V, E>::Vertex kzn = g->insertVertex("Kazan");
    Graph<V, E>::Vertex tms = g->insertVertex("Tomsk");

    Graph<V, E>::Edge mskkzn = g->insertEdge(10, msk, kzn);


    return 0;
}