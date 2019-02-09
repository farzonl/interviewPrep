
function square(n) {
    return n ** 2;
}

function sum(a, b) {
    return a + b;
}

function sumSquares(n) {
    return [...Array(n + 1).keys()].map(square).reduce(sum);
}

function squareOfSums(n) {
    return square( [...Array(n + 1).keys()].reduce(sum) );
}

function sumSquareDiff(n) {
    return squareOfSums(n) -sumSquares(n);
}

export { sumSquares, squareOfSums, sumSquareDiff };
