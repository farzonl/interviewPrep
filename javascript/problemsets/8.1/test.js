import assert from 'assert';
import {
    tripleStep, tripleStepMemo, tripleStepPrecomputed,
    fibonacci, fibonacciMemo, fibonacciPrecomputed,
    factorial, factorialMemo, factorialPrecomputed, gcd
} from './index.js';

function time(funcPtr, parameterArr) {
    let begin = process.hrtime();
    funcPtr(...parameterArr);
    let diff = process.hrtime(begin);
    return diff[1];
}

function speedTest(fasterFunc, slowerFunc, parameterArr) {
    let fastTime = time(fasterFunc, parameterArr);
    let slowTime = time(slowerFunc, parameterArr);
    //console.log("fastTime: ", fastTime);
    //console.log("slowTime: ", slowTime);
    let resultBool = fastTime < slowTime;
    //console.log("fastTime < slowTime: ", resultBool);
    return resultBool;
    
}
describe('Test basic ', function() {
    it('should equal 1', function () {
        assert.equal(tripleStep(1), 1);
    });
    it('should return 2', function() {
        assert.equal(tripleStep(2), 2);
    });
    it('should return 4', function() {
        assert.equal(tripleStep(3), 4);
    });
    it('should equal 13', function () {
        assert.equal(tripleStep(5), 13);
    });
    it('should return 24', function() {
        assert.equal(tripleStep(6), 24);
    });
    it('should return 44', function() {
        assert.equal(tripleStep(7), 44);
    });
    it('should return 181997601', function() {
        assert.equal(tripleStepMemo(32), 181997601);
        //TODO specifit time it takes for tripleStep instead of computing it
        //assert.equal(true, speedTest(tripleStepMemo, tripleStep, [32]));
    });
    it('should be the same value', function() {
        assert.equal(tripleStepPrecomputed(33), tripleStepMemo(33));
    });

});

describe('Test fibonacci ', function() {
    it('should equal 0', function () {
        assert.equal(fibonacciMemo(0), 0);
        assert.equal(fibonacciMemo(0), fibonacci(0));
    });

    it('should equal 1', function () {
        assert.equal(fibonacciMemo(1), 1);
        assert.equal(fibonacciMemo(1), fibonacci(1));
    });
    it('should return 1', function() {
        assert.equal(fibonacciMemo(2), 1);
        assert.equal(fibonacciMemo(2), fibonacci(2));
    });
    it('should return 2', function() {
        assert.equal(fibonacciMemo(3), 2);
        assert.equal(fibonacciMemo(3), fibonacci(3));
    });
    it('should return 4', function() {
        assert.equal(fibonacciMemo(4), 3);
        assert.equal(fibonacciMemo(4), fibonacci(4));
    });
    it('should equal 5', function () {
        assert.equal(fibonacciMemo(5), 5);
        assert.equal(fibonacciMemo(5), fibonacci(5));
    });
    it('should return 8', function() {
        assert.equal(fibonacciMemo(6), 8);
        assert.equal(fibonacciMemo(6), fibonacci(6));
    });
    it('should return 13', function() {
        assert.equal(fibonacciMemo(7), 13);
        assert.equal(fibonacciMemo(7), fibonacci(7));
    });

    it('memoization should be faster', function () {
        assert.equal(true, speedTest(fibonacciMemo, fibonacci, [20]));
        assert.equal(true, speedTest(fibonacciMemo, fibonacci, [30]));
        //assert.equal(true, speedTest(fibonacciMemo, fibonacci, [47]));
        assert.equal(fibonacciPrecomputed(47), 2971215073);
    });
});

describe('Test factorial ', function() {
    it('should equal 1', function () {
        assert.equal(factorialMemo(0), 1);
        assert.equal(factorialMemo(0), factorial(0));
    });

    it('should equal 1', function () {
        assert.equal(factorialMemo(1), 1);
        assert.equal(factorialMemo(1), factorial(1));
    });
    it('should return 2', function() {
        assert.equal(factorialMemo(2), 2);
        assert.equal(factorialMemo(2), factorial(2));
    });
    it('should return 6', function() {
        assert.equal(factorialMemo(3), 6);
        assert.equal(factorialMemo(3), factorial(3));
    });
    it('should return 24', function() {
        assert.equal(factorialMemo(4), 24);
        assert.equal(factorialMemo(4), factorial(4));
    });
    it('should equal 120', function () {
        assert.equal(factorialMemo(5), 120);
        assert.equal(factorialMemo(5), factorial(5));
    });
    it('should return 720', function() {
        assert.equal(factorialMemo(6), 720);
        assert.equal(factorialMemo(6), factorial(6));
    });
    it('should return 5040', function() {
        assert.equal(factorialMemo(7), 5040);
        assert.equal(factorialMemo(7), factorial(7));
    });

    it('should return 2432902008176640000', function() {
        assert.equal(factorialPrecomputed(20), 2432902008176640000);
        assert.equal(factorialMemo(20), 2432902008176640000);
    });

    /*it('memoization should be neglegent', function () {
        //no speedup not enough reuse.
        assert.equal(true, speedTest(factorial, factorialMemo, [1000]));
        //assert.equal(true, speedTest(factorialPrecomputed, factorialMemo, [1000]));
    });*/
});

describe('Test gcd ', function() {
    it('should equal 6', function () {
        assert.equal(gcd(54, 24), 6);
        assert.equal(gcd(12,8), 4);
        
    });
});