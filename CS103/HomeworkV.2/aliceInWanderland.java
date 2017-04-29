//Cameron Showalter
//AliceInWanderLand
//3-31-2015
//replaces words in Alice in WanderLand
import java.io.*;
import java.util.*;

public class aliceInWanderland{
    public static void main(String[] args) throws FileNotFoundException{
        Scanner input = new Scanner(new File("Alice.txt"));
        PrintStream outprint = new PrintStream(new File("Alice1.txt"));
        Scanner in = new Scanner(System.in);
        System.out.print("What name do you want to replace with \"Alice\"?: ");
        String name = in.next();
        String next = "";
     

        while(input.hasNextLine()){
            next = input.next();
            if(next.equalsIgnoreCase("alice")){
                outprint.printf(name);
                outprint.printf(" ");
            }
            else if(next.equalsIgnoreCase("alice's")){
                outprint.printf(name + "\'s");
                outprint.printf(" ");
            }
            else{
                outprint.print(next);
                outprint.printf(" ");
            }
        }
    }    
}