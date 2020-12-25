import assert from 'assert';
import { addEdge, buildGraphNode } from './index.js';

describe('Google Tests', function() {
    it('test Graph construction', function() {
        let g1 = buildGraphNode('hand');
        assert.deepEqual(g1.value, 'hand');
        assert.deepEqual(g1.neighbors.length, 0);
    }),
    it('test Edge construction', function() {
        let g1 = buildGraphNode('hand');
        assert.deepEqual(g1.value, 'hand');
        assert.deepEqual(g1.neighbors.length, 0);
        let g2 = buildGraphNode('inches');
        assert.deepEqual(g2.neighbors.length, 0);
        assert.deepEqual(g2.value, 'inches');
        addEdge(g2, .4, g1);
        assert.deepEqual(g2.neighbors.length, 1);
        assert.deepEqual(g1.neighbors.length, 0);
        assert.deepEqual(g2.neighbors[0].value, .4);
        assert.deepEqual(g2.neighbors[0].node.value, 'hand');
    }),

    it('test conversion construction', function() {
        let hand = buildGraphNode('hand');
        let inches = buildGraphNode('inches');
        let inches = buildGraphNode('foot');
        let cm = buildGraphNode('cm');
        let meters = buildGraphNode('m');
        let kmeters = buildGraphNode('km');
        addEdge(inches, .4, hand);
        addEdge(inches, 2.54, cm);
        addEdge(meters, 100, cm);
        addEdge(kmeters, 100, meters);
    });
});
