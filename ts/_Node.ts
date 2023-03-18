export class _Node<T>
{
    data: T;
    next: _Node<T> | null;

    constructor(data: T)
    {
        this.data = data;
        this.next = null;
    }
}