
import assert from 'assert';
import { isUnque, isUnqueOn2, isUnqueNLogN } from './index.js';

describe('Test basic isUnique', function() {
    it('should return not unique', function () {
        assert.equal(isUnque('hello'), false);
    });
    it('should return not unique', function() {
        assert.equal(isUnque('0asdf0'), false);
    });
    it('should return unique', function() {
        assert.equal(isUnque('asdf_qwerty'), true);
    });
});

describe('Test O(n^2) isUnique', function() {
    it('should return not unique', function() {
        assert.equal(isUnqueOn2('hello'), false);
    });
    it('should return not unique', function() {
        assert.equal(isUnqueOn2('0asdf0'), false);
    });
    it('should return unique', function() {
       assert.equal(isUnqueOn2('asdf_qwerty'), true);
    });
});

describe('Test O(n log(n) ) isUnique', function() {
    it('should return not unique', function() {
        assert.equal(isUnqueNLogN('hello'), false);
    });
    it('should return not unique', function() {
        assert.equal(isUnqueNLogN('0asdf0'), false);
    });
    it('should return unique', function() {
       assert.equal(isUnqueNLogN('asdf_qwerty'), true);
    });
});