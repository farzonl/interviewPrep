// {x: 10, l: {x: 5, l: {x:3}, r: {x: 8}}, r: {x: 20, l: {x:15}, r: {x: 25}}}
//  1 |          -- 10 --            | 1  10 = 10
//              /         \
//  1 |     -- 5 --     -- 20 --     | 2  10 > 5 but 10 < 20
//        /        \   /        \
//  1 |  3         8  15        25   | 3  10 > 3 & 10 > 8 & 20 > 15 but 20 < 25

// {x: 4, l: {x: 5, l: {x:6}, r: {x: 8}}, r: {x: 8, l: {x:10}, r: {x: 25}}}
//                 -- 4 --          | 1
//               /         \
//           -- 5 --     -- 8 --    | 2
//         /        \   /        \
//        6         8  10        25 | 4
// 1 + 2 + 4
function countLargerChildValues(T) {
    let count = 0;
    let treeTraverse = (T, parentValue) => {
        if (T === null || T === undefined) {
            return;
        }
        if (T.x >= parentValue) {
            count++;
        }
        treeTraverse(T.l, Math.max(T.x, parentValue));
        treeTraverse(T.r, Math.max(T.x, parentValue));
    };

    treeTraverse(T, T.x);
    return count;
}

function countFarthestRepeatOfSubstring(S) {
    let mapArr = {};
    for (let i = 0; i < S.length-1; i++) {
        let subStr = S.substring(i, i+2);

        if (mapArr[subStr] != undefined) {
            if (mapArr[subStr].length == 1) {
                mapArr[subStr].push(i);
            } else if (mapArr[subStr].length == 2 ) {
                mapArr[subStr][1] = i;
            }
        } else {
            mapArr[subStr] = [i];
        }
    }

    let maxDist = -1;
    // console.log(mapArr);
    for (let value in mapArr) {
        if (mapArr[value].length != 2) {
            continue;
        }
        let dist = mapArr[value][1] - mapArr[value][0];
        maxDist = Math.max(maxDist, dist);
    }
    return maxDist;
}

export {
    countLargerChildValues,
    countFarthestRepeatOfSubstring
};
