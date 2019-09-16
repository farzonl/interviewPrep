import assert from 'assert';
import { composeRanges } from './index.js';

describe('compute the sequential ranges in sorted array', function() {
    it('basic test', function() {
        assert.deepEqual([ '-1->2', '6->7', '9' ], composeRanges([-1, 0, 1, 2, 6, 7, 9]));
    });
});