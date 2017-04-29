import java.util.Scanner;
import java.util.ArrayList;
/**
 * Take any number of dice with any number of sides, and tell you what it rolls after x number of times
 * 
 * @author Cameron Showater 
 * @version V 1.8
 */
public class main
{
    public static void main(String [] args)
    {
      Scanner in = new Scanner(System.in);
      int sides;
      int dice;
      int rolls;
      int resoult;
      
      int[] name = new int[10000];  //max size to array is 10,000. can be changed
      
      System.out.println("How many dice would you like to roll? " );
      dice = in.nextInt();
      System.out.println("How many sides do each dice have? ");
      sides = in.nextInt();
      System.out.println("How many times do you want to roll each dice?");
      rolls = in.nextInt();
      Dice squareThingy = new Dice(sides, dice);
      
      for(int i=0; i<rolls ; i++)
      {
        resoult = squareThingy.getRoll();
        name[resoult]=name[resoult]+1;
        
      }
      
      for(int i=dice; i<=dice*sides; i++)
      {
        
          System.out.println(i+ ": " +name[i]); //prints only the array values that are needed.
      }
      
    }
    
}
