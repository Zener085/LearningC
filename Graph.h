#ifndef LEARNINGC_GRAPH_H
#define LEARNINGC_GRAPH_H

#include <list>
#include <vector>

using namespace std;

template <class V, class E>
class Graph {
public:
    class Vertex {
        V key;
        Vertex* ref;

    public:
        explicit Vertex(V key) {
            this->key = key;
            this->ref = this;
        }

        explicit Vertex() = default;

        bool operator == (Vertex v) {
            return v.ref == this->ref;
        }
    };

    class Edge {
        E weight;
        Vertex from, to;
        Edge* ref;
    public:
        Edge(E weight, Vertex from, Vertex to) {
            this->weight = weight;
            this->from = from;
            this->to = to;
            this->ref = this;
        }

        explicit Edge() = default;

        bool operator == (Edge e) {
            return e.ref == this->ref;
        }
    };

    list<Vertex> vertices;
    list<Edge> edges;

    [[maybe_unused]] Vertex insertVertex(V key) {
        Vertex v(key);
        this->vertices.push_back(v);

        return v;
    }

    [[maybe_unused]] Edge insertEdge(E weight, Vertex from, Vertex to) {
        Edge e(weight, from, to);
        this->edges.push_back(e);

        return e;
    }

    [[maybe_unused]] vector<Edge> incidentEdges(Vertex v) {
        vector<Edge> incEdges;

        for (Edge e : this->edges)
            if (e.from == v || e.to == v)
                incEdges.push_back(e);

        return incEdges;
    }

    [[maybe_unused]] int degree(Vertex v) {
        return incidentEdges(v).size();
    }

    bool areAdjacent(Vertex u, Vertex v) {
        vector<Edge> edgesU = incidentEdges(u);
        vector<Edge> edgesV = incidentEdges(v);

        if (edgesU.size() > edgesV.size()) return areAdjacent(v, u);

        for (Edge e : this->edges)
            if ((e.from == v && e.to == u) || (e.from == u && e.to == v)) return true;

        return false;
    }

    void removeEdge(Edge e) {
        this->edges.remove(e);
    }

    void removeVertex(Vertex v) {
        this->vertices.remove(v);

        vector<Edge> edgesV = incidentEdges(v);
        for (Edge e : edgesV)
            removeEdge(e);
    }

    void print() {}
};

#endif //LEARNINGC_GRAPH_H
