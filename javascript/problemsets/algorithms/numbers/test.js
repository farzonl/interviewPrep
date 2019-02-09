import 'babel-polyfill';
import assert from 'assert';
import { gcd, lcm, lcm2, lcm3, lcm4, SmallestMultiple } from './index.js'


describe('compute gcd', function() {
    it('SmallestMultiple', function () {
        assert.equal(232792560, SmallestMultiple(20));
    });
    it('gcd', function () {
        assert.equal(14, gcd(98, 56));
        // edge cases
        assert.equal(0, gcd(0, 0));
        assert.equal(0, gcd(0, 1));
        assert.equal(0, gcd(1, 0));
    });
    it('lcm', function () {
        // 4 8 12 16 20
        // 10 20
        assert.equal(20, lcm(4, 10));
        assert.equal(20, lcm2(4, 10));
        assert.equal(20, lcm3(4, 10));
        assert.equal(20, lcm4(4, 10));

        assert.equal(15, lcm(5, 3));
        assert.equal(15, lcm2(5, 3));
        assert.equal(15, lcm3(5, 3));
        assert.equal(15, lcm4(5, 3));

        assert.equal(12, lcm(4, 3));
        assert.equal(12, lcm2(4, 3));
        assert.equal(12, lcm3(4, 3));
        assert.equal(12, lcm4(4, 3));

        assert.equal(6, lcm(2, 3));
        assert.equal(6, lcm2(2, 3));
        assert.equal(6, lcm3(2, 3));
        assert.equal(6, lcm4(2, 3));
    });
});
