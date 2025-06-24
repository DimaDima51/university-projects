import java.util.Scanner;

// Узел
class Node {
    int data; // значение узла
    Node next; // следующий узел

    public Node(int data) {
        this.data = data;
        this.next = null; // по умолчанию нет следующего узла
    }
}

// Очередь
class Queue {
    private Node head; // голова
    private Node tail; // хвост

    // Изначально очередь пуста
    public Queue() {
        this.head = null;
        this.tail = null;
    }

    // Добавить элемент в хвост очереди
    public void addNode(int data) {
        Node newNode = new Node(data); // создаём новый узел

        // Если очередь пуста, то новый узел и хвост и голова
        if (this.tail == null) {
            this.head = newNode;
            this.tail = newNode;
            return;
        }

        // "Прицепляем" новый узел к текущему хвосту
        this.tail.next = newNode;
        // Обновляем tail на новый узел
        this.tail = newNode;
    }

    // Удалить элемент из головы очереди
    public int delNode() {
        int data = this.head.data; // сохраняем значение из головы
        Node node1 = this.head.next; // временный узел
        
        this.head = null; // обнуление удаляемого узла

        this.head = node1; // сдвигаем голову на следующий узел
        node1 = null; // обнуление временного узла

        // Если после удаления очередь стала пустой, обнуляем tail
        if (this.head == null) {
            this.tail = null;
        }
        
        return data;
    }

    // Посмотреть значение в голове, не удаляя его
    public int peek() {
        return this.head.data;
    }

    // Проверить, пуста ли очередь
    public boolean isEmpty() {
        return this.head == null;
    }

    // Вывести все элементы очереди от головы к хвосту
    public void display() {
        Node current = this.head;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next; // переходим к следующему узлу
        }
        System.out.println();
    }
}

public class Program {
    public static void main(String[] args) {
        Queue q1 = new Queue();
        Queue q2 = new Queue();
        Queue q1copy = new Queue();
        Queue q2copy = new Queue();

        Scanner scanner = new Scanner(System.in);

        // Ввод первой очереди
        System.out.print("Введите количество элементов для первой очереди: ");
        int count1 = scanner.nextInt();
        for (int i = 0; i < count1; i++) {
            System.out.printf("%d: ", i + 1);
            int number = scanner.nextInt();
            q1.addNode(number);
            q1copy.addNode(number);
        }

        // Ввод второй очереди
        System.out.print("Введите количество элементов для второй очереди: ");
        int count2 = scanner.nextInt();
        for (int i = 0; i < count2; i++) {
            System.out.printf("%d: ", i + 1);
            int number = scanner.nextInt();
            q2.addNode(number);
            q2copy.addNode(number);
        }

        scanner.close();

        System.out.print("Список q1: "); q1.display();
        System.out.print("Список q2: "); q2.display();

        Queue q3 = mergeQueueWithoutDuplicates(q1copy, q2copy);
        Queue q4 = mergeQueueWithDuplicates(q1, q2);

        // Вывод результатов
        System.out.print("Без дубликатов: "); q3.display();
        System.out.print("С дубликатами: "); q4.display();
    }

    // Слияние двух очередей с сохранением дубликатов
    public static Queue mergeQueueWithDuplicates(Queue q1, Queue q2) {
        Queue result = new Queue(); // результирующая очередь

        // Пока обе очереди не пусты, сравниваем головы
        while (!q1.isEmpty() && !q2.isEmpty()) {
            if (q1.peek() < q2.peek()) {
                result.addNode(q1.delNode()); // меньшее из q1
            } else if (q1.peek() > q2.peek()) {
                result.addNode(q2.delNode()); // меньшее из q2
            } else {
                // если равны, добавляем оба
                result.addNode(q1.delNode());      
                result.addNode(q2.delNode());      
            }
        }

        // добираем остатки из q1
        while (!q1.isEmpty()) {
            result.addNode(q1.delNode());
        }
        // добираем остатки из q2
        while (!q2.isEmpty()) {
            result.addNode(q2.delNode());
        }

        return result;
    }

    // Слияние двух очередей без дубликатов
    public static Queue mergeQueueWithoutDuplicates(Queue q1, Queue q2) {
        Queue result = new Queue();
        Integer lastAdded = null; // для отслеживания последнего добавленного

        // Основной цикл сравнения голов
        while (!q1.isEmpty() && !q2.isEmpty()) {
            int val;
            if (q1.peek() < q2.peek()) {
                val = q1.delNode();
            } else if (q1.peek() > q2.peek()) {
                val = q2.delNode();
            } else {
                val = q1.delNode();
                q2.delNode(); // одинаковый элемент пропускаем во второй очереди
            }

            // Добавляем в результат только новый (отличный от lastAdded)
            if (lastAdded == null || lastAdded != val) {
                result.addNode(val);
                lastAdded = val;
            }
        }

        // Остатки q1
        while (!q1.isEmpty()) {
            int val = q1.delNode();
            if (lastAdded == null || lastAdded != val) {
                result.addNode(val);
                lastAdded = val;
            }
        }
        // Остатки q2
        while (!q2.isEmpty()) {
            int val = q2.delNode();
            if (lastAdded == null || lastAdded != val) {
                result.addNode(val);
                lastAdded = val;
            }
        }

        return result;
    }
}
