import java.util.Random;
/**
 * Write a description of class Dice here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Dice
{
  private int diceSides;
  private int numberOfDice;
    public Dice(int x, int y)
   {
    diceSides = x;
    numberOfDice = y;
    
    
    
   
   }
   public int getRoll()
   {
     Random randomGenerator = new Random();
     int resoult = 0;
   
     
     for(int i=0;i< numberOfDice; i++)
     {
     int randomInt = randomGenerator.nextInt(diceSides)+1;
     resoult += randomInt;
     
    }
   return resoult;
  }
}
