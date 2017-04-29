// Cameron Showalter
// 2/17/2015
// Swiches someones "full name" with there "propper name"
import java.util.*;
public class reverseName{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        System.out.println("When you type your name, seperate it by a period, not a space. (Cameron.Showalter)");
        System.out.println("What is your name?: ");
        String name = in.next();
        System.out.println(flipName(name));
        in.close();
    }
   // flips the name, makes it more propper
    public static String flipName(String name){
        int space = name.indexOf("."); //I tried swiching the "." with a " " and it didn't see the space.
        String firstName = name.substring(0,space);
        String lastName = name.substring(space+1, name.length());
        String fullName = lastName + ", " + firstName;
        return fullName;
    }
}