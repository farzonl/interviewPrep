import assert from 'assert';
import { RobHouse } from './index.js';

describe('compute total for best houses to rob', function() {
    it('basic test', function() {
        assert.equal(4, RobHouse([1,2,3,1]));
    });
    it('basic test 2', function() {
        assert.equal(12, RobHouse([2,7,9,3,1]));
    });
    it('edge case test', function() {
        // basis steps 2 should be max of index 0 and 1.
        assert.equal(14, RobHouse([4, 1, 2, 7, 5, 3, 1]));
    });

});