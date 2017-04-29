//Cameron Showalter
//3-24-2015
//Prints random number of "x" between 5 and 20 until it prints one above 15
import java.util.*;
public class randomX{
    public static void main(String[] args){
        Random rand = new Random();
        boolean done = false;
        System.out.println("This program prints \"X\" until it prints one above 15:");
        while(done == false){
            int randomInt = rand.nextInt(15)+5;
            for(int i = 0; i<randomInt; i++){
                System.out.print("X");
            }
            System.out.println();
            if(randomInt > 15){
                done = true;
            }
        }
    }
}