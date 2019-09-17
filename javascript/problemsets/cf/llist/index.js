
function ListNode(x) {
    this.value = x;
    this.next = null;
}

function createListFromArr(arr) {
    if(arr.length == 0) {
        return null;
    }
    let l = new ListNode(arr[0]);
    let curr = l;
    for(let i = 1; i < arr.length; i++) {
        curr.next = new ListNode(arr[i]);
        curr = curr.next;
    }
    return l;
}

function creatArrFromList(list) {
    let curr = list;
    let arr = [];
    while(curr != null) {
        arr.push(curr.value);
        curr = curr.next;
    }
    return arr;
}

function removeKFromList(l, k) {
    if(l==null) {
        return l;
    }
    if(l.value == k) {
        l = l.next;
    }
    let curr = l;
    while(curr != null && curr.next != null) {
        if (curr.next.value == k) {
            curr.next = curr.next.next;
        } else {
            curr = curr.next
        }
    }
    if (curr != null && curr.value == k) {
        l = l.next;
    }
    
    return l;
}

function isListPalindrome(list) {
    if(list == null) {
        return true;
    }
    if(list.next == null) {
        return true;
    }
    let length = 0;
    let curr = list;
    while(curr != null) {
        curr = curr.next;
        length++;
    }
    let midpoint = Math.floor(length/2);
    if(length % 2 == 0) {
        midpoint--;
    }
    curr = list;
    let count = 0;
    let arr = []

    while(count < midpoint) {
        arr.unshift(curr.value);
        curr = curr.next;
        count++;
    }
    if(length % 2 == 0) {
        arr.unshift(curr.next.value);
    }
    curr = curr.next;
    count = 0;
    //console.log(arr);
    //console.log(`length is: ${length}`);
    //console.log(`midpoint is: ${midpoint}`);
    //console.log(`current node: ${curr.value}`);
    while(curr != null) {
        if(curr.value != arr[count]) {
            return false
        }
        curr = curr.next;
        count++;
    }
    return true;
}

export {  isListPalindrome, createListFromArr, 
          creatArrFromList, removeKFromList }