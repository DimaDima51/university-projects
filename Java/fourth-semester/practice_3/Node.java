public class Node {
    char data;
    Node next;  // cледующий элемент

    public Node(char data) {
        this.data = data;
        this.next = null;
    }

    // Печать элемента
    public void printElement() {
        System.out.print(data);
    }
}
