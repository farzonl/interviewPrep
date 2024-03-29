
/**
 *
 * @param {Number} a
 * @param {Number} b
 * @return {Number} returns the multiplication of a and b.
 */
function rMultiply(a, b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    if (a == 1) {
        return b;
    }
    return b + rMultiply(a - 1, b);
}

export { rMultiply };
