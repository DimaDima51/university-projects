class Queue {
    private Node first;
    private Node last;

    public Queue() {  // конструктор
        first = last = null;
    }

    public boolean isEmpty() {  // проверка на пустоту
        return (first == null);
    }

    public void push(char c) {
        Node newNode = new Node(c);  // новый элемент
        if (last == null) {  // если очередь пуста
            first = last = newNode;  // новый элемент становится и началом, и концом
        } else {
            last.next = newNode;  // связываем конец очереди с новым элементом
            last = newNode;  // новый элемент теперь в конце
        }
    }

    public Node pop() {
        if (first == null) {
            System.out.print("Очередь пустая!");
            return null;
        }
        Node temp = first;  // сохраняем ссылку на начало очереди
        first = first.next;  // новый первый элемент
        if (first == null) {  // если очередь опустела
            last = null;  // очередь пуста
        }
        temp.next = null;
        return temp;  // возвращаем старый первый элемент
    }

    public void display() {  // печать содержимого очереди
        Node current = first;  // начинаем с начала очереди
        while (current != null) {  // пока не дойдем до конца
            current.printElement();
            current = current.next;  // переход по ссылке
        }
    }
}