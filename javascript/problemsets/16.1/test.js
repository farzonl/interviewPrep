import assert from 'assert';
import {
    contigSeq,
    contigPosSeq
} from './index.js';



describe('16.1: contiguous Sequence tests', function() {
    it('contigSeq', function() {
        assert.equal(contigSeq([4,-3,5,-8,10,-11,8,-2,5,-3,5,-7]), 13);
        assert.equal(contigSeq([2,-1,3,-2,4,-2]), 6);
    });
    it('contigPosSeq', function() {
        assert.equal(contigPosSeq([4,-3,1,2,3,-1,2,3,4,-1,7]), 9);
    });
});
