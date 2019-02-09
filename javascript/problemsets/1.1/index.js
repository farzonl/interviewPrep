
/**
 * function that will return true or false if a string is unique.
 * the runtime is O(n)
 * @param {String} str we will check for uniqueness
 * @return {Boolean} true or false depending on uniqueness
 */
function isUnque(str) {
    let obj = {};
    for (let i = 0; i < str.length; i++) {
        if (!obj[str.charAt(i)]) {
            obj[str.charAt(i)] = true;
        } else {
            return false;
        }
    }
    return true;
}


function isUnqueOn2(str) {
    for (let i = 0; i < str.length; i++) {
        for (let j = 0; j < str.length; j++) {
            if (i === j) {
                continue;
            }
            if (str.charAt(i) === str.charAt(j)) {
                return false;
            }
        }
    }
    return true;
}

function isUnqueNLogN(str) {
    let arrSorted = str.split('').sort();
    for (let i = 0; i < arrSorted.length; i++) {
        if (arrSorted[i] === arrSorted[i + 1]) {
            return false;
        }
    }
    return true;
}

// TODO bit vector solution

export { isUnque, isUnqueOn2, isUnqueNLogN };
