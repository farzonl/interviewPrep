import assert from 'assert';
import { m3Or5 } from './index.js'

describe('sum of multiples', function() {
    it('Find the sum of all the multiples of 3 or 5 below 10.', function () {
        assert.equal(23, m3Or5(10));
    });
    it('Find the sum of all the multiples of 3 or 5 below 1000.', function () {
        assert.equal(233168, m3Or5(1000));
    });

});
