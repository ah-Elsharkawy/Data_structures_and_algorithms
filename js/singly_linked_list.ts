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
            console.log(node.data);
            node = node.next;
        }
    }

    size(): number{
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