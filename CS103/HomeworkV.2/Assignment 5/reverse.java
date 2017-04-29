// Cameron Showalter
// 2/17/2015
// takes any string you enter and reverses each char.   Cameron = noremaC
import java.util.*;
public class reverse{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        System.out.println("Enter a String: ");
        String coolString = in.nextLine();
        reverseIt(coolString);
        in.close();
    }    
 //   reverses the string that was entered above
    public static void reverseIt(String s){
        String reversedString = "";
        for(int i=s.length(); i>0; i--) {
            reversedString += s.charAt(i-1);
        }   
    System.out.print(reversedString);
    }
}