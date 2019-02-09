import assert from 'assert';
import { getNthPrime } from './index.js';

describe('Test sieves', function() {
    it('test sieves', function() {
        assert.equal(7927, getNthPrime(1001));
    });
});
