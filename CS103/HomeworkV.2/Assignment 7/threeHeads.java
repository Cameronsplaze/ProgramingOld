//Cameron Showalter
//3-24-2015
//flips a coin until you flip 3 heads in a row
import java.util.*;
public class threeHeads{
    public static void main(String[] args){
        Random rand = new Random();
        int coin;
        boolean done = false;
        int count = 0;
        System.out.println("This program takes a coin and counts how many times it takes to flip three heads");
        while(done == false){
            coin = rand.nextInt(2)+1;
            if(coin == 1){
                System.out.print("H ");
                coin = rand.nextInt(2)+1;
                count++;
                if(coin==1){
                    System.out.print("H ");
                    coin = rand.nextInt(2)+1;
                    count++;
                    if(coin==1){
                        done = true;
                        System.out.print("H ");
                        count++;
                        System.out.print("\nIt took " + count + " times!!");
                    }
                    else{
                        System.out.print("T ");
                        count++;
                    }
                }
                else{
                    System.out.print("T ");
                    count++;
                }
      
            }
            else{
                System.out.print("T ");
                count++;
        }
    }
    }}