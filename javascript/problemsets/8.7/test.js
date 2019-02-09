
import assert from 'assert';
import { longestIncSubsec } from './index.js';

describe('Test longestSubsec', function() {
    it('test lss', function () {
        assert.deepEqual(longestIncSubsec([10, 22, 9, 33, 21, 50, 41, 60, 80]),
            [10, 22, 33, 50, 60, 80]);
        assert.deepEqual(longestIncSubsec([3, 10, 2, 1, 20]), [3, 10, 20]);
        //assert.deepEqual(longestIncSubsec([0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]),
        //    [0, 2, 6, 9, 11, 15]);
    });
});