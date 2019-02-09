
import assert from 'assert';
import { sumSquares, squareOfSums, sumSquareDiff } from './index.js'

describe('sum of multiples', function() {
    it('Find the sum of each number squared.', function () {
        assert.equal(385, sumSquares(10));
        assert.equal(338350, sumSquares(100));
    });
    it('Find the square of the sum', function () {
        assert.equal(3025, squareOfSums(10));
        assert.equal(25502500, squareOfSums(100));
    });
    it('Find the diff', function () {
        assert.equal(2640, sumSquareDiff(10));
        // https://projecteuler.net/problem=6
        assert.equal(25164150, sumSquareDiff(100));
    });

});
