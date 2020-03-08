#ifndef __GRAPH__SEARCH_HPP__
#define __GRAPH__SEARCH_HPP__
#include <vector>
#include <string>

class vertex {
    public:
        vertex(std::string name) : name(name) {}
    private:
        std::string name;
};

class graph {
    public:
        std::vector<vertex*>& adjacentEdges(const vertex &v);
};

class graphSearch {
    private:
        graphSearch() = delete;
    public:
        static void dfs(graph &G, const vertex &v);
};

#endif // __GRAPH__SEARCH_HPP__