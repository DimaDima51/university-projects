public class stackdemo {
    public static void main(String[] args) {
        Inverter inv = new Inverter();

        inv.invert("hello");
    }
}

class Inverter {
    
    Inverter() {}

    public void invert(String s) {
        Stack stack = new Stack();

        for(int i = 0; i < s.length(); i++) {
            stack.push(s.charAt(i));
        }

        stack.display();
    }
}