import java.util.Stack;

public class StackDemo {

    public static void main(String args[]){

        Stack<Integer> s = new Stack<>();

        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        s.push(50);

        System.out.println(s);
        System.out.println("The Size of the Stack is : " + s.size());

        System.out.println("Element " + s.pop() + " Poped.");
        System.out.println("Element " + s.pop() + " Poped.");

        System.out.println("The Size of the Stack is : " + s.size());

        System.out.println("Stack Empty : " + s.isEmpty());

        System.out.println("Element " + s.pop() + " Poped.");
        System.out.println("Element " + s.pop() + " Poped.");
        System.out.println("Element " + s.pop() + " Poped.");

        System.out.println("The Size of the Stack is : " + s.size());

        System.out.println("Stack Empty : " + s.isEmpty());

        //check parenthasis

    }//end of main
    


}
