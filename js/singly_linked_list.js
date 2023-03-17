"use strict";
class _Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}
class linked_list {
    constructor() {
        this.length = 0;
        this.head = null;
    }
    add(data) {
        let node = new _Node(data);
        node.next = this.head;
        this.head = node;
        this.length++;
    }
    print() {
        let node = this.head;
        while (node) {
            console.log(node.data);
            node = node.next;
        }
    }
    size() {
        return this.length;
    }
}
let list = new linked_list();
list.add(4);
list.add(5);
list.add(6);
list.add(7);
console.log("the size of the linked list is ", list.size());
list.print();
