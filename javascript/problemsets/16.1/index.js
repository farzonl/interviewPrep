
/**
 * An algorithm that gets the sum of the largest positive contigous segment
 * @param {Array<Number>} A - an array of integers
 * @return {Number}
 */
// interview question for Tech Soft 3D
function contigPosSeq (A) {
    let maxSum = -1;
    let currSum = 0;
    for(let i =  0; i < A.length; i++) {
        if(A[i] < 0) {
            currSum = 0;
            continue;
        }
        currSum += A[i];
        maxSum = Math.max(currSum, maxSum);
    }
    return maxSum;
}

/**
 * An algorithm that gets the sum of the largest positive contigous segment
 * @param {Array<Number>} A - an array of integers
 * @return {Number}
 */
function contigSeq (A) {
    let maxSum = -1;
    let currSum = 0;
    for(let i =  0; i < A.length; i++) {
        currSum += A[i];
        maxSum =  Math.max(maxSum, currSum);
        currSum = Math.max(currSum,0);
    }
    return maxSum;
}

export {
    contigSeq,
    contigPosSeq
};
