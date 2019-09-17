
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
    let curr = list;
    let arr = [];
    while(curr != null) {
        arr.push(curr.value);
        curr = curr.next;
    }
    curr = list;
    while(curr != null) {
        let arrCurr = arr.pop();
        if(curr.value != arrCurr) {
            return false
        }
        curr = curr.next;
    }
    return true;
}

export {  isListPalindrome, createListFromArr, 
          creatArrFromList, removeKFromList }