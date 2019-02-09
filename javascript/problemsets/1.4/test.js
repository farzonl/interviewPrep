import assert from 'assert';
import { anagram, anagramNlogN } from './index.js';

describe('Test basic anagram', function() {
    it('should return not anagram b\\c of size', function() {
        assert.equal(anagram('hello', 'hi'), false);
    });
    it('should return not anagram  b\\c of unexpected char', function() {
        assert.equal(anagram('hell', 'heck'), false);
    });
    it('should return not anagram b\\c too many expected char', function() {
        assert.equal(anagram('aples', 'apple'), false);
    });
    it('should return not anagram b\\c too few expected char', function() {
        assert.equal(anagram('apple', 'aples'), false);
    });
});

describe('Test basic anagram', function() {
    it('should return anagram', function() {
        assert.equal(anagram('elloh', 'hello'), true);
    });
    it('should return anagram', function() {
        assert.equal(anagram('asdf', 'fdas'), true);
    });
});

describe('Test nlog(n) anagram', function() {
    it('should return not anagram b\\c of size', function() {
        assert.equal(anagramNlogN('hello', 'hi'), false);
    });
    it('should return not anagram  b\\c of unexpected char', function() {
        assert.equal(anagramNlogN('hell', 'heck'), false);
    });
    it('should return not anagram b\\c too many expected char', function() {
        assert.equal(anagramNlogN('aples', 'apple'), false);
    });
    it('should return not anagram b\\c too few expected char', function() {
        assert.equal(anagramNlogN('apple', 'aples'), false);
    });
});

describe('Test nlog(n) anagram', function() {
    it('should return anagram', function() {
        assert.equal(anagramNlogN('elloh', 'hello'), true);
    });
    it('should return anagram', function() {
        assert.equal(anagramNlogN('asdf', 'fdas'), true);
    });
});
