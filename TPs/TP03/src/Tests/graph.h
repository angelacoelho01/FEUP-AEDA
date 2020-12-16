#include <iostream>
#include <vector>


using namespace std;


template <class N, class E>
class Edge;

template<class N>
class NodeAlreadyExists;

template<class N>
class NodeDoesNotExist;

template<class N>
class EdgeAlreadyExists;

template<class N>
class EdgeDoesNotExist;


template <class N, class E>
class Node {
public:
    N info;
    vector< Edge<N,E> > edges;
    Node(N inf) {
        info = inf;
    }
};


template <class N, class E>
class Edge {
public:
    E value;
    Node<N,E> *destination;
    Edge(Node<N,E> *dest, E val) {
        value = val;
        destination = dest;
    }
};


template <class N, class E>
class Graph {
    vector<Node<N,E> *> nodes;
public:
    Graph() : nodes(vector<Node<N,E>*>()){}

    ~Graph(){
        for(auto node : nodes)
            delete node;
    }

    Graph & addNode(const N &inf){
        for(auto const& node : nodes){
            if(node->info == inf)
                throw NodeAlreadyExists<N>(inf);
        }
        nodes.push_back(new Node<N,E>(inf));
        return *this;
    }

    Graph & addEdge(const N &begin, const N &end, const E &val){
        Node<N,E>* firstNode = nullptr, *lastNode = nullptr;
        for(const auto& node : nodes){
            for(const auto& edge : node->edges){
                if((node->info == begin) && (edge.destination)->info == end)
                    throw EdgeAlreadyExists<N>(begin, end);
            }
            if(node->info == begin)
                firstNode = node;
            else if(node->info == end)
                lastNode = node;
        }

        if(firstNode == nullptr || lastNode == nullptr)
            throw NodeDoesNotExist<N>(begin);
        firstNode->edges.push_back(Edge<N,E>(lastNode,val));
        return *this;
    }

    Graph & removeEdge(const N &begin, const N &end){
        for(const auto& beginNode : nodes){
            if(beginNode->info == begin){
                for(auto it = (beginNode->edges).begin(); it != (beginNode->edges).end(); ++it){
                    if((it->destination)->info == end) {
                        (beginNode->edges).erase(it);
                        return *this;
                    }
                }
                throw EdgeDoesNotExist<N>(begin, end);
            }
        }
        throw NodeDoesNotExist<N>(begin);
    }

    E & edgeValue(const N &begin, const N &end){
        for (const auto& beginNode: nodes){
            if (beginNode->info == begin){
                for (auto& edge: beginNode->edges) {
                    if (edge.destination->info == end) {
                        return edge.value;
                    }
                }
                throw EdgeDoesNotExist<N>(begin, end);
            }
        }
        throw NodeDoesNotExist<N>(begin);

    }

    unsigned numEdges(void) const{
        unsigned totalEdges = 0;
        for(const auto& n : nodes){
            totalEdges += (n->edges).size();
        }
        return totalEdges;
    }

    unsigned numNodes(void) const{
        return nodes.size();
    }

    void print(std::ostream &os) const{
        for(const auto & n : nodes){
            os << "( " << n->info;
            for(const auto & e : n->edges)
                os << "[ " << (e.destination)->info << " " << e.value << "] ";
            os << ") ";
        }
    }
};

template <class N, class E>
std::ostream & operator<<(std::ostream &out, const Graph<N,E> &g)
{g.print(out); return out;}


// exception NodeAlreadyExists
template <class N>
class NodeAlreadyExists
{
public:
    N info;
    NodeAlreadyExists(N inf) { info=inf; }
};
template <class N>
std::ostream & operator<<(std::ostream &out, const NodeAlreadyExists<N> &no)
{ out << "Node already exists: " << no.info; return out; }


// exception NodeDoesNotExist
template <class N>
class NodeDoesNotExist {
public:
    N info;
    NodeDoesNotExist(N inf) {
        info = inf;
    }
};

template <class N>
std::ostream & operator<<(std::ostream &out, const NodeDoesNotExist<N> &no)
{ out << "Node does not exist: " << no.info; return out; }


// exception EdgeAlreadyExists
template<class N>
class EdgeAlreadyExists
{
public:
    N nBegin, nEnd;
    EdgeAlreadyExists(const N &begin, const N &end)
    {
        nBegin = begin;
        nEnd = end;
    }
};

template<class N>
std::ostream & operator<<(std::ostream &out, const EdgeAlreadyExists<N> &e)
{ out << "Edge already exists: " << e.nBegin << " , " << e.nEnd; return out;}


// exception EdgeDoesNotExist
template<class N>
class EdgeDoesNotExist
{
public:
    N nBegin, nEnd;
    EdgeDoesNotExist(const N &begin, const N &end) {
        nBegin = begin;
        nEnd = end;
    }
};

template<class N>
std::ostream & operator<<(std::ostream &out, const EdgeDoesNotExist<N> &e)
{out << "Edge does not exist: " << e.nBegin << " , " << e.nEnd; return out;}