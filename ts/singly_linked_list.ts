import * as readlineSync from 'readline-sync';
class _Node<T>
{
    data: T;
    next: _Node<T> | null;

    constructor(data: T){
        this.data = data;
        this.next = null;
    }
}


class linked_list
{
    length: number;
    head: _Node<any> | null;

    constructor(){
        this.length = 0;
        this.head = null;
    }

    add(data: any): void{
        let node = new _Node(data);
        node.next = this.head;
        this.head = node;
        this.length++;
    }

    print(): void{
        let node = this.head;
        while(node){
            process.stdout.write(`${node.data}${node.next ? ' ' : '\n'}`);
            node = node.next;
        }
    }

    // remove the node at that index
    removeByIndex(index:number): void{
        if(index < 0 || index >= this.length){
            console.log("Out of range, enter a valid index\n");
            return;
        }

        if (index === 0)
        {
            this.head = this.head?.next ?? null;
        }
        else 
        {
            let curr = this.head;
            for(let i = 0; i < index - 1; i++)
            {
                curr = curr!.next;
            }
            curr!.next = curr!.next?.next ?? null;

        }
        this.length--;
    }

    // removes all the nodes having that value 
    removeByValue(value: any): void
    {
        if(this.length === 0)
        {
            console.log("the list is empty");
            return;
        }

        let pre = null;
        let curr = this.head;
        while(curr != null)
        {
            if(curr.data === value)
            {
                if(pre === null)
                {
                    this.head = this.head?.next ?? null;
                    curr = this.head;
                }
                else
                {
                    pre.next = curr.next;
                    curr = curr.next;
                }
                this.length--;
            }
            else
            {
                pre = curr;
                curr = curr.next;
            }
        }
    }

    findValue(value: any): number
    {
        let tmp = this.head;
        let i = 0;
        while(tmp != null)
        {
            if(tmp.data === value)
            {
                return i;
            }
            else
            {
                i++;
                tmp = tmp.next;
            }
        }
        return -1;
    }
    size(): number{
        return this.length;
    }

    reverse(): void
    {   if(this.length == 0 || this.length == 1)
        return;
        let pre = null;
        let curr = this.head;
        let next = curr?.next ?? null;

        while(curr != null)
        {
            next = curr.next;
            curr.next = pre;
            pre = curr;
            curr = next;
        }
        this.head = pre;
    }
}

let list = new linked_list();
const n: number = readlineSync.questionInt('Enter a number: ');
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
console.log(`the element ${n} is found at index ${list.findValue(n)}`)
console.log(`the list after reversing is ${list.reverse()}`);
list.print();