
/**
 * Check if two strings are anagrams. runtime = O(n+n+n) = linear time
 * @param {String} str1 
 * @param {String} str2 
 * @return {Boolean} returns if anagram or not
 */
function anagram(str1, str2) {
    
    if (str1.length !== str2.length) {
        return false;
    }

    var obj = {}

    for (let i = 0; i < str1.length; i++) {
        if (!obj[str1.charAt(i)]) {
            obj[str1.charAt(i)] = 1;
        } else {
            obj[str1.charAt(i)]++;
        }
    }
    for (let i = 0; i < str2.length; i++) {
        let key = obj[str2.charAt(i)]
        if (!key && key <= 0) {
            return false;
        } else {
            obj[str2.charAt(i)]--;
        }
    }
    for (let i = 0; i < str1.length; i++) {
        if (obj[str1.charAt(i)] > 0) {
            return false;
        }
    }
    return true;
}

/**
 * Check if two strings are anagrams. runtime = O(nlogn(n) + nlogn(n)) = O(nlogn(n))
 * @param {String} str1 
 * @param {String} str2 
 * @return {Boolean} returns if anagram or not
 */
function anagramNlogN(str1, str2) {
    let sortedStr1 = str1.split('').sort().join('');
    let sortedStr2 = str2.split('').sort().join('');
    return sortedStr1 === sortedStr2;
}

export { anagram, anagramNlogN };