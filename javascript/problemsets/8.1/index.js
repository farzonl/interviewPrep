
/**
 * Am algorithm that counts the number of steps one can take up an n step staircase
 * @param {Number} nSteps 
 */
function tripleStep(nSteps) {
    if (nSteps < 0) {
        return 0;
    }
    else if (nSteps == 0) {
        return 1;
    }
    else {
        return tripleStep(nSteps - 1) + tripleStep(nSteps - 2) + tripleStep(nSteps - 3);
    }
}

function tripleStepMemo(nSteps) {

    let arr = new Array(nSteps+1);
    return tripleStepMemoHelper(nSteps, arr);
}

function tripleStepPrecomputed(nSteps) {
    let arr = [0, 1, 2, 4, 7, 13, 24, 44, 81, 149, 274, 504, 927, 1705,
        3136, 5768, 10609, 19513, 35890, 66012, 121415, 223317, 410744,
        755476, 1389537, 2555757, 4700770, 8646064, 15902591, 29249425,
        53798080, 98950096, 181997601];
    
    return tripleStepMemoHelper(nSteps, arr);
}

function tripleStepMemoHelper(nSteps, memoArr) {
    if (nSteps < 0) {
        return 0;
    }
    
    else if (nSteps == 0) {
        return 1;
    }
    
    else if (memoArr[nSteps] === undefined) {
        memoArr[nSteps] = tripleStepMemoHelper(nSteps - 1, memoArr)
            + tripleStepMemoHelper(nSteps - 2, memoArr) + tripleStepMemoHelper(nSteps - 3, memoArr);
    }

    return memoArr[nSteps];
    
}

function fibonacci(n) {
    if (n === 0 || n === 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

function fibonacciMemo(n) {
    let arr = new Array(n+1);
    arr.length = n + 1;
    return fibonacciMemoHelper(n, arr);
}

function fibonacciMemoHelper(n, memoArr) {
    if (n === 0 || n === 1) {
        return n;
    }
    if (memoArr[n] === undefined) {
        memoArr[n] = fibonacciMemoHelper(n - 1, memoArr) + fibonacciMemoHelper(n - 2, memoArr);
    }
    return memoArr[n];
}

function fibonacciPrecomputed(n) {
    let arr = [0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765,
        10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269,
        2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986,
        102334155, 165580141, 267914296, 433494437, 701408733, 1134903170, 1836311903, 2971215073];
    return fibonacciMemoHelper(n, arr);
}

function factorial(n) {
    if(n == 1 || n==0) {
       return 1;
    }
    return factorial(n - 1) * n;
}

function factorialMemo(n) {
    let memoArr = new Array(n+1);
    let returnValue = factorialMemoHelper(n, memoArr);
    //console.log(memoArr);
    return returnValue;
}

function factorialPrecomputed(n) {
    let memoArr = [1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800,
        479001600, 6227020800, 87178291200, 1307674368000, 20922789888000,
        355687428096000, 6402373705728000, 121645100408832000, 2432902008176640000,
        51090942171709440000];
    return factorialMemoHelper(n, memoArr);
}

function factorialMemoHelper(n, memoArr) {
    if(n == 1 || n==0) {
       return 1;
    }
    if (memoArr[n] === undefined) {
        memoArr[n] = factorialMemoHelper(n - 1, memoArr) * n;
    }
    return memoArr[n];
}

// euclid's algorithm
// gcd(a,0) = a else
// gcd(a,b) = gcd(b,a % b)
function gcd(num1, num2) {
    if (num2 == 0) {
        return num1;
    }
    return gcd(num2, num1 % num2);
}

export {
    tripleStep, tripleStepMemo, tripleStepPrecomputed, fibonacci, fibonacciMemo, fibonacciPrecomputed,
    factorial, factorialMemo, factorialPrecomputed, gcd
};
