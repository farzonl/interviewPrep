
function longestIncSubsecTable(arr) {
    let table = Array(arr.length).fill().map(() => []);

    for (let i = 0; i < arr.length; i++) {
        let curr = arr[i];
        table[i][0] = curr;
        for (let j = i; j < arr.length; j++) {
            if (arr[j] > curr) {
                curr = arr[j];
                table[i].push(arr[j]);
            }
        }
    }
    return table;
}

function longestIncSubsec(arr) {
    let table = longestIncSubsecTable(arr);
    let longestLen = 0;
    let longestLenIndex = 0;
    for (let i = 0; i < table.length; i++) {
        if (longestLen < table[i].length) {
            longestLen = table[i].length;
            longestLenIndex = i;
        }
    }
    return table[longestLenIndex];
}

export { longestIncSubsec };
