"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const _Node_1 = require("./_Node");
class Stack {
    constructor() {
        this.top = null;
        this.length = 0;
    }
    push(value) {
        let newNode = new _Node_1._Node(value);
        newNode.next = this.top;
        this.top = newNode;
        this.length++;
    }
    isEmpty() {
        return this.length ? false : true;
    }
    size() {
        return this.length;
    }
    pop() {
        var _a;
        if (this.isEmpty()) {
            console.log("cannot pop empty stack");
            return null;
        }
        else {
            let tmp = this.top.data;
            this.top = (_a = this.top.next) !== null && _a !== void 0 ? _a : null;
            this.length--;
            return tmp;
        }
    }
    peek() {
        if (this.isEmpty()) {
            console.log("No peek in empty stack");
            return null;
        }
        else {
            return this.top.data;
        }
    }
    print() {
        process.stdout.write("[ ");
        let node = this.top;
        while (node) {
            process.stdout.write(`${node.data}${node.next ? ', ' : ' '}`);
            node = node.next;
        }
        process.stdout.write("]\n");
    }
}
let s = new Stack();
s.push(1);
s.push(2);
s.push(3);
s.push("as");
console.log(`the stack size: ${s.size()}`);
s.print();
console.log(`the stack popped: ${s.pop()}, and the size is: ${s.size()}`);
console.log(`the stack peek: ${s.peek()}`);
