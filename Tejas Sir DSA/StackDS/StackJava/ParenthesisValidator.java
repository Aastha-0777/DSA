
import java.util.Scanner;
import java.util.Stack;

public class ParenthesisValidator {

    Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {

        ParenthesisValidator pv = new ParenthesisValidator();

        Stack<Character> s = new Stack<>();

        System.out.print("Enter a Parenthesis String for Validation : ");
        String paren = pv.sc.nextLine();

        for (int i = 0; i < paren.length(); i++) {

            if (paren.charAt(i) == '{' || paren.charAt(i) == '(' || paren.charAt(i) == '[') {

                s.push(paren.charAt(i));

            } else {

                char check = s.pop();
                
                if(check == '{' && paren.charAt(i) == '}'){

                    continue;

                }else if(check == '(' && paren.charAt(i) == ')'){

                    continue;

                }else if(check == '[' && paren.charAt(i) == ']'){

                    continue;

                }//end of if-else ladder
                

            }//end of if-else

        }//end of for

        if(s.isEmpty()){

            System.out.println("Valid");

        }else{

            System.out.println("InValid");

        }//end of if-else

    }

}
