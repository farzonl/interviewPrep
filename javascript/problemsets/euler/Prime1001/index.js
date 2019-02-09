
function* sievesGen() {
    let sieveList = [];
    let lastIndex = 2;
    while (true) {
        while (sieveList[lastIndex]) {
            // Composite case
            // lastIndex is composite
            let factor = sieveList[lastIndex];
            let nextComposite = lastIndex + factor;
            while (sieveList[nextComposite]) {
 nextComposite += factor;
}
            sieveList[nextComposite] = factor;
            lastIndex++;
        }
        // Prime case
        sieveList[2 * lastIndex] = lastIndex;
        let temp = lastIndex;
        lastIndex++;
        yield temp;
    }
}

function getNthPrime(n) {
    let i = 1;
    let prime;
    let gen = sievesGen();
    while (i <= n) {
        prime = gen.next().value;
        // console.log(`i: ${i} = prime: ${prime}`)
        i++;
    }
    return prime;
}

export { getNthPrime };
