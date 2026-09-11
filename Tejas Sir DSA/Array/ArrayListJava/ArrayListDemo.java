
import java.util.ArrayList;
import java.util.Scanner;

public class ArrayListDemo {

    Scanner sc = new Scanner(System.in);
    public static void main(String args[]) {

        ArrayListDemo a = new ArrayListDemo();

        ArrayList<Integer> list = new ArrayList<>();

        int num;

        for (int i = 1; i < 6; i++) {

            System.out.print("Enter a Number : ");
            num = a.sc.nextInt();
            list.add(num);

        }//end of for

        System.out.println(list);

    }//end of main

}
