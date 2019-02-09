import assert from 'assert';
import { sieves } from './index.js';

describe('Test sieves', function() {
    it('test sieves', function() {
        assert.deepEqual(sieves(100),
            [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31,
                37, 41, 43, 47, 53, 59, 61, 67, 71, 73,
                79, 83, 89, 97]);
    });
});
