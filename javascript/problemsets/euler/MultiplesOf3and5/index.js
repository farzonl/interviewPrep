
// https://projecteuler.net/problem=1
function m3Or5(n) {
    return sumMultiplesOfAandB(n, 3, 5);
}

function sumMultiplesOfAandB(n, a, b) {

    let aMultiples = getMultiples(n, a);
    let bMultiples = getMultiples(n, b);

    //r = a-b{dupes}
    let reduction = aMultiples.filter((number1) => {
        return !bMultiples.some(function (number2) {
            return number1 == number2;
        });
    })
    //m = r + b{nondupes}
    let merged = reduction.concat(...bMultiples);
    /*console.log(aMultiples);
    console.log(bMultiples);
    console.log(merged);*/
    return merged.reduce((total, num) => {
        return total + num;
    });
}

function getMultiples(n, m) {
    let returnArr = [];

    if (n == 0) {
        return returnArr;
    }
    let startN = n - 1;
    let mod = startN % m;
    
    /*console.log('n: ', n);
    console.log('startN: ', startN);
    console.log('mod: ', mod);
    console.log('m: ', m);*/
    
    if (mod != 0) {
        startN -= mod;
    }
    while (startN > 0) {
        returnArr.push(startN);
        startN -= m;
    }
    return returnArr
}
 
export { m3Or5 };