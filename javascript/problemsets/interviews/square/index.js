
/**
 * 
 * @param {Number} n
 * @return {Array<Number>} 
 */
function sieves(n) {
    let arr = new Array(n+1);
    for (let i = 2; i <= n; i++) {
        if (arr[i] === undefined) {
            for (let j = i; j <= n; j += i) {
                if (j == i) {
                    arr[j] =  [j, true ];
                } else {
                    arr[j] = [j, false ];
                }
            }
        }    
    }

    let primes = arr.filter(isPrime => isPrime[1]).map(arr => arr[0]);
    /*let composites = arr.filter(isPrime => !isPrime[1]).map(arr => arr[0]);
    for(let i = 0; i < primes.length; i++) {
        console.log('primes: ', primes[i]);
    }
    
    for(let i = 0; i < composites.length; i++) {
        console.log('composites: ', composites[i]);
    }*/

    return primes;
}


export { sieves };
