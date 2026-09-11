package listtopicjava;

import java.util.LinkedList;

public class listdemo {
    
    public static void main(String[] args) {
        
        LinkedList<Integer> list = new LinkedList<>();

        list.addLast(10);
        list.addLast(20);
        list.addLast(30);
        list.addLast(10);
        list.addLast(50);

        System.out.println(list);

        System.out.println("***********************");

        for(Integer data : list){

            System.out.println(data);

        }

    }

}
