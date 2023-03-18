import { _Node } from "./_Node";


class Queue
{
    first: _Node<any> | null;
    last: _Node<any> | null;
    length: number;

    constructor()
    {
        this.first = null;
        this.last = null;
        this.length = 0;
    }

    enqueue(value: any) : void
    {
        let newNode = new _Node(value);
        if(this.first == null)
        {
            this.first = newNode;
            this.last = newNode;
        }
        else
        {
            this.last!.next = newNode;
            this.last = newNode;
        }
        this.length++;
    }

    dequeue() : void
    {
        if(this.isEmpty())
        {
            console.log("the queue is empty");
            return;
        }
        console.log(`dequeued: ${this.first!.data}`);
        this.first = this.first?.next ?? null;
    }

    isEmpty() : boolean
    {
        return this.length ? false : true;
    }

    size() : number
    {
        return this.length;
    }

    peek() : any
    {
        if (this.isEmpty())
        {
            console.log("No peek, the Queue is empty");
            return null;
        }
        else
        {
            return this.first!.data;
        }
    }

    print() : void
    {
        process.stdout.write("[ ");
        let node = this.first;
        while(node){
            process.stdout.write(`${node.data}${node.next ? ', ' : ' '}`);
            node = node.next;
        }
        process.stdout.write("]\n");
    }
}


let q = new Queue();

q.enqueue(1);
q.enqueue(2);
q.enqueue(3);
q.enqueue(1);
q.enqueue(2);
q.enqueue(3);

console.log("the Queue:");
q.print();
console.log(`the queue size is: ${q.size()}`);

q.dequeue();
q.dequeue();

console.log("the Queue after using dequeue:");
q.print();
console.log(`the queue size is: ${q.size()}`);
console.log(`the queue peek: ${q.peek()}`)