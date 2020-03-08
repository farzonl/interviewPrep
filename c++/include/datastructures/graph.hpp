#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

#include <set>
#include <vector>
#include <linkedList.hpp>

template <typename T> class GNode {
  T _data;
  std::set<GNode<T> *> neighbors;
public:
  GNode(T data) : _data(data) {}
  const T Data() const { return _data; }
  const std::set<GNode<T> *>& getNeighbors() const { return neighbors; }
  void insert(GNode<T> *node) { neighbors.insert(node); }
};

class GSearch {
    public:
        template <typename T>
        static  std::vector<T> dfs(GNode<T> *node);
        template <typename T>
        static  std::vector<T> bfs(GNode<T> *node);

    private:
        GSearch() = delete;
        template <typename T>
        static  std::vector<T> search(GNode<T> *node, List<GNode<T>*> &container);
};

template <typename T>
std::vector<T> GSearch::search(GNode<T> *node, List<GNode<T>*> &container) {
    std::vector<T> order;
    if (node == nullptr) {
        return order;
    }
    std::set<GNode<T> *> visited;
    container.push(node);
    while (!container.empty())
    {
        GNode<T> *curr = container.peek();
        container.pop();

        visited.insert(curr);

        for (const auto &neighbor : curr->getNeighbors())
        {
            if (neighbor && !visited.count(neighbor)) {
                container.push(neighbor);
            }
        }
        order.push_back(curr->Data());
    }
    return order;
}

template <typename T>
std::vector<T> GSearch::bfs(GNode<T> *node) {
    Queue<GNode<T>*> queue;
    return GSearch::search(node, queue);
}
template <typename T>
std::vector<T> GSearch::dfs(GNode<T> *node) {
    Stack<GNode<T>*> stack;
    return GSearch::search(node, stack);
}

#endif //__GRAPH_HPP__