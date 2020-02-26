
function ListNode(x) {
    this.value = x;
    this.next = null;
}

function createListFromArr(arr) {
    if (arr.length == 0) {
        return null;
    }
    let l = new ListNode(arr[0]);
    let curr = l;
    for (let i = 1; i < arr.length; i++) {
        curr.next = new ListNode(arr[i]);
        curr = curr.next;
    }
    return l;
}

function creatArrFromList(list) {
    let curr = list;
    let arr = [];
    while (curr != null) {
        arr.push(curr.value);
        curr = curr.next;
    }
    return arr;
}

function removeKFromList(l, k) {
    if (l==null) {
        return l;
    }
    if (l.value == k) {
        l = l.next;
    }
    let curr = l;
    while (curr != null && curr.next != null) {
        if (curr.next.value == k) {
            curr.next = curr.next.next;
        } else {
            curr = curr.next;
        }
    }
    if (curr != null && curr.value == k) {
        l = l.next;
    }

    return l;
}

function isListPalindrome(list) {
    if (list == null) {
        return true;
    }
    if (list.next == null) {
        return true;
    }
    let curr = list;
    let arr = [];
    while (curr != null) {
        arr.push(curr.value);
        curr = curr.next;
    }
    curr = list;
    while (curr != null) {
        let arrCurr = arr.pop();
        if (curr.value != arrCurr) {
            return false;
        }
        curr = curr.next;
    }
    return true;
}

function getPlaceValue(n) {
    let intN = Math.ceil(n);
    return 10**(intN.toString().length-1);
}

function createListFromArrReverse(arr) {
    if (arr.length == 0) {
        return null;
    }
    let l = new ListNode(arr[arr.length-1]);
    let curr = l;
    for (let i = arr.length-2; i >= 0; i--) {
        curr.next = new ListNode(arr[i]);
        curr = curr.next;
    }
    return l;
}

function addTwoHugeNumbers(a, b) {
    let curr = a;
    let arrA = [];
    while (curr != null) {
        arrA.unshift(curr.value);
        curr = curr.next;
    }

    curr = b;
    let arrB = [];
    while (curr != null) {
        arrB.unshift(curr.value);
        curr = curr.next;
    }
    let len = Math.min(arrA.length, arrB.length);
    let finalArr = [];
    finalArr.length = Math.max(arrA.length, arrB.length);
    finalArr.fill(0);
    let i = 0;
    for (; i < len; i++) {
        let maxPlaceValue = Math.max(getPlaceValue(arrA[i]),
                                     getPlaceValue(arrB[i]));
        let nextPlaceValue = maxPlaceValue*10;
        let addAB = finalArr[i] + arrA[i] + arrB[i];
        if (addAB >= nextPlaceValue) {
            finalArr[i] = addAB - nextPlaceValue;
            finalArr[i+1] += 1;
        } else {
            finalArr[i] = addAB;
        }
    }
    let largestArr = arrA.length > arrB.length ? arrA : arrB;
    for (;i < finalArr.length; i++) {
        finalArr[i] = largestArr[i];
    }

    return createListFromArrReverse(finalArr);
}


export { isListPalindrome, createListFromArr,
          creatArrFromList, removeKFromList,
          addTwoHugeNumbers };
