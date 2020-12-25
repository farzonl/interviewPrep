/**
 * The graph node
 * @typedef {Object} GraphNode
 * @property {string} value - Indicates type of node.
 * @property {Array<Edge>} neighbors - Indicates edges on this node
 */

 /**
  * @description Constructor for GraphNode
  * @param {string} v
  * @return {GraphNode}
  */
function buildGraphNode(v) {
    let g = { value: v, neighbors: [] };
    return g;
}
 /**
 * The edge definition
 * @typedef {Object} Edge
 * @property {number} value - Indicates value of node.
 * @property {GraphNode} node1 - Indicates first node
 * @property {GraphNode} node2 - Indicates second node
 */

 /**
  * @description This function adds an edge to a graph node.
  * @param {GraphNode} n1 start node
  * @param {number} v  edge weight
  * @param {GraphNode} n2 end node
  */
function addEdge(n1, v, n2) {
    let e = { value: v, node: n2 };
    n1.neighbors.push(e);
}

/**
 * @description A function that aggreates and multiplies the path from start
 * to end by the start value.
 * @param {numvber} value the value of the start node.
 * @param {GraphNode} startNode the start node of the conversion
 * @param {GraphNode} endNode the ending node of the conversion
 * @return {number} conversion value
 */
function getConversion(value, startNode, endNode) {
    return 0;
}

export { addEdge, buildGraphNode, getConversion };
