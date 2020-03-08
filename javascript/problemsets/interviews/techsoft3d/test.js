import assert from 'assert';
import {
    countLargerChildValues,
    countFarthestRepeatOfSubstring
} from './index.js';


describe('Tech Soft 3D interview questions on Codility', function() {
    it('Codility Q2', function() {
        let t1 = { x: 10, l: { x: 5, l: { x: 3 }, r: { x: 8 } }, r: { x: 20,
            l: { x: 15 }, r: { x: 25 } } };
        assert.equal(countLargerChildValues(t1), 3);
        let t2 = { x: 4, l: { x: 5, l: { x: 6 }, r: { x: 8 } }, r: { x: 8,
            l: { x: 10 }, r: { x: 25 } } };
        assert.equal(countLargerChildValues(t2), 7);
    });
    it('Codility Q3', function() {
        assert.equal(countFarthestRepeatOfSubstring(
            'hehe that was the funniest thing'), 22);
        assert.equal(countFarthestRepeatOfSubstring(
            'tgaattcgcggcaagtagat'), 16);
    });
});
