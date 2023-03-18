
class _Node<T>
{
    data: T;
    next: _Node<T> | null;

    constructor(data: T)
    {
        this.data = data;
        this.next = null;
    }
}

class Stack
{
    top: _Node<any> | null;
    length: number;

    constructor()
    {
        this.top = null;
        this.length = 0;
    }

    push(value: any) : void
    {
        let newNode = new _Node(value);
        newNode.next = this.top;
        this.top = newNode;
        this.length++;
    }

    isEmpty() : boolean
    {
        return this.length ? false : true;
    }

    size() : number
    {
        return this.length;
    }

    pop() : any
    {
        if (this.isEmpty())
        {
            console.log("cannot pop empty stack");
            return null;
        }
        else
        {
            let tmp = this.top!.data;
            this.top = this.top!.next ?? null;
            this.length--;
            return tmp;
        }
    }

    peek() : any
    {
        if (this.isEmpty())
        {
            console.log("No peek in empty stack");
            return null;
        }
        else
        {
            return this.top!.data;
        }
    }

    print() : void
    {
        process.stdout.write("[ ");
        let node = this.top;
        while(node){
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
console.log(`the stack peek: ${s.peek()}`)


