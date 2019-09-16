import assert from 'assert';
import { climbingStairs } from './index.js';

describe('compute stair climb', function() {
    it('1 stair', function() {
        assert.equal(1, climbingStairs(1));
    });
    it('2 stairs', function() {
        assert.equal(2, climbingStairs(2));
    });
    it('4 stairs', function() {
        assert.equal(5, climbingStairs(4));
    });
    it('13 stairs', function() {
        assert.equal(377, climbingStairs(13));
    });
    it('17 stairs', function() {
        assert.equal(2584, climbingStairs(17));
    });
    it('20 stairs', function() {
        assert.equal(10946, climbingStairs(20));
    });
    it('26 stairs', function() {
        assert.equal(196418, climbingStairs(26));
    });
    it('28 stairs', function() {
        assert.equal(514229, climbingStairs(28));
    });
    it('38 stairs', function() {
        assert.equal(63245986, climbingStairs(38));
    });
    it('42 stairs', function() {
        assert.equal(433494437, climbingStairs(42));
    });
});
