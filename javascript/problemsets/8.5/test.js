import assert from 'assert';
import { rMultiply } from './index.js';

describe('Test basic multipy', function() {
    it('test multpy by 1', function() {
        for (let i = 0; i <= 15; i++) {
            for (let j = 0; i <= 12; i++) {
                assert.equal(rMultiply(i, j), i * j);
                assert.equal(rMultiply(j, i), j * i);
            }
        }
    });
});
