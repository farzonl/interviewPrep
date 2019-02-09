
class SinglyLinkedList {

    constructor() {
        this.head = null;
        this.count = 0;
    }

    addToFront(value) {
        let newNode = new Node(value);
        if (this.head == null) {
            this.head = newNode;
        } else {
            newNode.next = this.head;
            this.head = newNode;
        }
        this.count++;
    }

    /**
     * @return {Array} 
     */
    toArray() {
        let curr = this.head;
        let returnArr = [];
        let currCount = 0;
        while(curr != null) {
            returnArr.push(curr.data);
            curr = curr.next;
            if (currCount > this.count) {
                throw new Error("List is corupted");
            }
            currCount++;
        }
        return returnArr;
    }

    getNodeAt(index) {
        let curr = this.head;
        let currIndex = 0;
        while (curr != null) {
            if (currIndex === index) {
                return curr;
            }
            curr = curr.next;
            currIndex++;
        }

        return curr;
    }

    //2.5
    detectCycle() {
        let slowPtr = this.head;
        let fastPtr = this.head.next;
        while (slowPtr != null && fastPtr != null) {
            if (slowPtr === fastPtr) {
                return true;
            }
            slowPtr = slowPtr.next;
            fastPtr = fastPtr.next.next;
        }
        return false;
    }

    detectCycleKeyTable() {
        let seenNodes = {};
        let curr = this.head;
        while (curr != null) {
            if (seenNodes[curr.uniqueId]) {
                return true;
            }
            seenNodes[curr.uniqueId] = true;
            curr = curr.next;
        }
        return false;
    }
}

class Node {

    constructor(data) {
        this.data = data;
        this.next = null;
        this.uniqueId = guid();
    }
}

function guid() {
    function s4() {
      return Math.floor((1 + Math.random()) * 0x10000)
        .toString(16)
        .substring(1);
    }
    return s4() + s4() + '-' + s4() + '-' + s4() + '-' + s4() + '-' + s4() + s4() + s4();
  }

export { SinglyLinkedList };
