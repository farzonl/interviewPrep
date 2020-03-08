#include "graphSearch.hpp"
#include <set>
#include <stack>

std::vector<vertex*>& graph::adjacentEdges(const vertex &v) {
    
} 

void graphSearch::dfs(graph &G, const vertex &v) {
    std::stack<const vertex*> S;
    std::set<const vertex*> visited;
    typedef std::vector<vertex*>::iterator edgeIter;
    S.push(&v);
    const vertex* currV = nullptr;
    while(!S.empty()) {
        currV = S.top();
        S.pop();
        if (visited.find(currV) == visited.end()) {
            visited.insert(currV);
            std::vector<vertex*> ae  = G.adjacentEdges(v);
            for (edgeIter it = ae.begin() ; it != ae.end(); ++it) {
                S.push(*it);
            }

        }

    }
}