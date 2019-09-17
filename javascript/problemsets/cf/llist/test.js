import assert from 'assert';
import { isListPalindrome, createListFromArr,
         creatArrFromList, removeKFromList } from './index.js';

describe('remove all k value from list', function() {
    it('edge case empty array', function() {
        let l = createListFromArr([]);
        let ans = creatArrFromList(removeKFromList(l, 3));
        assert.deepEqual([], ans);
    });
    it('basic test', function() {
        let l = createListFromArr([3, 1, 2, 3, 4, 5]);
        let ans = creatArrFromList(removeKFromList(l, 3));
        assert.deepEqual([1, 2, 4, 5], ans);
    });
    it('edge case array length 1 no removal', function() {
        let l = createListFromArr([1]);
        let ans = creatArrFromList(removeKFromList(l, 3));
        assert.deepEqual([1], ans);
    });
    it('edge case array length 1 with removal', function() {
        let l = createListFromArr([3]);
        let ans = creatArrFromList(removeKFromList(l, 3));
        assert.deepEqual([], ans);
    });
    it('no removal', function() {
        let l = createListFromArr([1, 2, 3, 4, 5, 6, 7]);
        let ans = creatArrFromList(removeKFromList(l, 10));
        assert.deepEqual([1, 2, 3, 4, 5, 6, 7], ans);
    });
    it('remove first only', function() {
        let l = createListFromArr([1000, 10, 10]);
        let ans = creatArrFromList(removeKFromList(l, 1000));
        assert.deepEqual([10, 10], ans);
    });

    it('remove back only', function() {
        let l = createListFromArr([10, 10, 1000]);
        let ans = creatArrFromList(removeKFromList(l, 1000));
        assert.deepEqual([10, 10], ans);
    });

    it('remove middle only', function() {
        let l = createListFromArr([10, 1000, 10]);
        let ans = creatArrFromList(removeKFromList(l, 1000));
        assert.deepEqual([10, 10], ans);
    });

    it('complete removal', function() {
        let l = createListFromArr([1000, 1000]);
        let ans = creatArrFromList(removeKFromList(l, 1000));
        assert.deepEqual([], ans);
    });

    it('isPalindrome simple', function() {
        let l = createListFromArr([1, 2, 1]);
        assert.ok(isListPalindrome(l));
        l = createListFromArr([1, 1]);
        assert.ok(isListPalindrome(l));
        l = createListFromArr([1]);
        assert.ok(isListPalindrome(l));
        l = createListFromArr([1, 1, 1]);
        assert.ok(isListPalindrome(l));
        l = createListFromArr([1, 2, 2, 1]);
        assert.ok(isListPalindrome(l));
        l = createListFromArr([1, 1, 2, 2, 2, 1, 1]);
        assert.ok(isListPalindrome(l));

        l = createListFromArr([1, 2, 2, 2, 2, 1]);
        assert.ok(isListPalindrome(l));

        l = createListFromArr([1, 2, 2, 3]);
        assert.ok(!isListPalindrome(l));
    });
});
