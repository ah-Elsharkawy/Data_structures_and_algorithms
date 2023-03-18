"use strict";
var __createBinding = (this && this.__createBinding) || (Object.create ? (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    var desc = Object.getOwnPropertyDescriptor(m, k);
    if (!desc || ("get" in desc ? !m.__esModule : desc.writable || desc.configurable)) {
      desc = { enumerable: true, get: function() { return m[k]; } };
    }
    Object.defineProperty(o, k2, desc);
}) : (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    o[k2] = m[k];
}));
var __setModuleDefault = (this && this.__setModuleDefault) || (Object.create ? (function(o, v) {
    Object.defineProperty(o, "default", { enumerable: true, value: v });
}) : function(o, v) {
    o["default"] = v;
});
var __importStar = (this && this.__importStar) || function (mod) {
    if (mod && mod.__esModule) return mod;
    var result = {};
    if (mod != null) for (var k in mod) if (k !== "default" && Object.prototype.hasOwnProperty.call(mod, k)) __createBinding(result, mod, k);
    __setModuleDefault(result, mod);
    return result;
};
Object.defineProperty(exports, "__esModule", { value: true });
const readlineSync = __importStar(require("readline-sync"));
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
            process.stdout.write(`${node.data}${node.next ? ' ' : '\n'}`);
            node = node.next;
        }
    }
    // remove the node at that index
    removeByIndex(index) {
        var _a, _b, _c, _d;
        if (index < 0 || index >= this.length) {
            console.log("Out of range, enter a valid index\n");
            return;
        }
        if (index === 0) {
            this.head = (_b = (_a = this.head) === null || _a === void 0 ? void 0 : _a.next) !== null && _b !== void 0 ? _b : null;
        }
        else {
            let curr = this.head;
            for (let i = 0; i < index - 1; i++) {
                curr = curr.next;
            }
            curr.next = (_d = (_c = curr.next) === null || _c === void 0 ? void 0 : _c.next) !== null && _d !== void 0 ? _d : null;
        }
        this.length--;
    }
    // removes all the nodes having that value 
    removeByValue(value) {
        var _a, _b;
        if (this.length === 0) {
            console.log("the list is empty");
            return;
        }
        let pre = null;
        let curr = this.head;
        while (curr != null) {
            if (curr.data === value) {
                if (pre === null) {
                    this.head = (_b = (_a = this.head) === null || _a === void 0 ? void 0 : _a.next) !== null && _b !== void 0 ? _b : null;
                    curr = this.head;
                }
                else {
                    pre.next = curr.next;
                    curr = curr.next;
                }
                this.length--;
            }
            else {
                pre = curr;
                curr = curr.next;
            }
        }
    }
    findValue(value) {
        let tmp = this.head;
        let i = 0;
        while (tmp != null) {
            if (tmp.data === value) {
                return i;
            }
            else {
                i++;
                tmp = tmp.next;
            }
        }
        return -1;
    }
    size() {
        return this.length;
    }
    reverse() {
        var _a;
        if (this.length == 0 || this.length == 1)
            return;
        let pre = null;
        let curr = this.head;
        let next = (_a = curr === null || curr === void 0 ? void 0 : curr.next) !== null && _a !== void 0 ? _a : null;
        while (curr != null) {
            next = curr.next;
            curr.next = pre;
            pre = curr;
            curr = next;
        }
        this.head = pre;
    }
}
let list = new linked_list();
const n = readlineSync.questionInt('Enter a number: ');
list.add(1);
list.add(2);
list.add(3);
list.add(4);
list.add(1);
list.add(1);
list.add(2);
list.add(3);
list.add(4);
list.add(1);
list.add(1);
list.add(1);
list.add(1);
console.log("the size of the linked list is ", list.size());
list.print();
console.log(`the element ${n} is found at index ${list.findValue(n)}`);
console.log(`the list after reversing is ${list.reverse()}`);
list.print();
