class Stack {
    private Node top;  // вершина стека

    public Stack() {  // конструктор
        top = null;
    }

    public boolean isEmpty() {  // проверка на пустоту
        return (top == null);
    }

    public void push(char c) {
        Node newNode = new Node(c);  // новый элемент
        newNode.next = top;  // следующий элемент - текущая вершина
        top = newNode;  // вершина теперь новый элемент
    }

    public char pop() {
        if (isEmpty()) return '\n';  // если стек пустой, возвращаем null
        Node temp = top;  // сохраняем ссылку на старую вершину
        top = top.next;  // новая вершина - следующий элемент
        temp.next = null;
        return temp.data;  // возвращаем старую вершину
    }

    public void display() {
        Node current = top;  // начинаем с вершины
        while (current != null) {  // пока не дойдем до конца
            current.printElement();  // печать элемента
            current = current.next;  // переход по ссылке
        }
    }
}