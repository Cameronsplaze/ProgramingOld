/*
 * Author: Cameron Showalter - Jim Sewell
 * Date compleated: 11/6/2014
 * Guess a number between the bounds you set. 
 * Virson 3.2
 */

import java.util.Scanner;
public class Main
{
  public static void main(String[] args)
  {
   Scanner in = new Scanner(System.in);
   boolean becauseICan = false;
   int randomGuess;
   int numberPicked;
   int numberGuess;
     
   String banana = "yes";
   System.out.print("What do you want the max number to be?: ");
   numberPicked = in.nextInt();
   System.out.println("Great, now pick a number between 1 and " + numberPicked);
   Game obj1 = new Game(numberPicked);
    while(banana.equalsIgnoreCase("yes"))
   {
     while(becauseICan == false)
     {
       randomGuess = in.nextInt();
       becauseICan = obj1.guess(randomGuess);
     }
     System.out.print("You Win! It only took you " + obj1.numberOfGuess); 
     System.out.println(" tries! Do you want to play again? (yes/no): ");
     banana = in.next();
     becauseICan = false;
     if(banana.equalsIgnoreCase("yes"))
     {
        obj1.reset(numberPicked);
     }
   }
  }
}
