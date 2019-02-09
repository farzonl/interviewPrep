// greatest common denominator
function gcd(a, b) {
    if (b == 0 || a == 0) {
        return 0;
    }
    if (b == a) {
        return a;
    }
    if (a > b) {
        return gcd(a - b, b);
    }
    return gcd(a, b-a);
}

//least common multiple
function lcm(a, b) {
    return a * b / gcd(a, b);
}

function lcm2(a, b) {
    return lcm2Helper(a, b, a, b);
}

function lcm2Helper(a, b, aCurr, bCurr) {
    if (bCurr == 0 || aCurr == 0) {
        return 0;
    }
    if (aCurr == bCurr) {
        return aCurr;
    }
    if (aCurr > bCurr) {
        return lcm2Helper(a, b, aCurr, bCurr + b);
    }
    return lcm2Helper(a, b, aCurr + a, bCurr);
}

function* multipleGenerator(a) {
    let i = a;
    yield i;
    while(true) {
      i += a;
      yield i;
    }
  }
  
function lcm3(a, b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    let genA = multipleGenerator(a);
    let genB = multipleGenerator(b);

    let genAVal = genA.next().value;
    let genBVal = genB.next().value;
    while (true) {
        if (genAVal == genBVal) {
            return genAVal;
        }
        if (genAVal > genBVal) {
            genBVal = genB.next().value;
        } else {
            genAVal = genA.next().value;
        }
    }
    
}

function lcm4(a, b) {
    let aCurr = a;
    let bCurr = b;
    while (true) {
        if (bCurr == 0 || aCurr == 0) {
            return 0;
        }
        if (aCurr == bCurr) {
            return aCurr;
        }
        if (aCurr > bCurr) {
            bCurr += b;
        } else {
            aCurr += a;
        }
    }
}



//https://projecteuler.net/problem=5
function SmallestMultiple(num) {
    let arr = [...Array(num+1).keys()];
    arr.shift();

    /*let curr = 1;
    for (let i = 1; i <= 20; i++) {
        //console.log(`i:${i}`,curr);
        curr = lcm3(curr, i);
    }*/

    return arr.reduce(lcm4);
}

export { gcd, lcm, lcm2, lcm3, lcm4, SmallestMultiple };