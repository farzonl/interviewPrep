export function RobHouse(arr) {
    let sumArr = [];
    sumArr.length = arr.length;
    sumArr[0] = arr[0];
    sumArr[1] = Math.max(arr[0],arr[1]);
    for(let i = 2; i < arr.length; i++) {
        sumArr[i] = Math.max(sumArr[i-1], sumArr[i-2] + arr[i])
    }
    return sumArr[sumArr.length-1];
}