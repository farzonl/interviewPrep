function composeRanges(nums) {
    let tempArr = [nums[0]];
    let rangeArr = [];
    let i = 1;
    for (i = 1; i < nums.length; i++) {
        if ( nums[i-1] == nums[i]-1) {
            tempArr.push(nums[i]);
        } else {
            rangeArr.push(tempArr.slice());
            tempArr = [nums[i]];
        }
    }

    if (i == nums.length) {
        rangeArr.push(tempArr.slice());
    }

    let rangeArrStr = [];
    for (i = 0; i <rangeArr.length; i++) {
        let curr = rangeArr[i];
        let str = '';
        if (curr.length == 1) {
            str =`${curr[0]}`;
        } else {
            str = `${curr[0]}->${curr[curr.length-1]}`;
        }
        rangeArrStr.push(str);
    }
    return rangeArrStr;
}

export { composeRanges };
