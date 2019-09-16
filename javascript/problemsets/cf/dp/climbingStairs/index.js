function climbingStairs(n) {
    /*if (n < 0) {
        return 0;
    }
    else if (n == 0) {
        return 1;
    }
    else {
        return climbingStairs(n - 1) + climbingStairs(n - 2);
    }*/
    let arr = new Array(n+1);
    return climbingStairsMemoHelper(n, arr);
}

function climbingStairsMemoHelper(nSteps, memoArr) {
    if (nSteps < 0) {
        return 0;
    }
    
    else if (nSteps == 0) {
        return 1;
    }
    
    else if (memoArr[nSteps] === undefined) {
        memoArr[nSteps] = climbingStairsMemoHelper(nSteps - 1, memoArr)
            + climbingStairsMemoHelper(nSteps - 2, memoArr);
    }

    return memoArr[nSteps];
    
}

export { climbingStairs }