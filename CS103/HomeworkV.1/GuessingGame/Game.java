import java.util.Random;
public class Game
{ 
   public int randomInt = 0;
   public int numberOfGuess = 0;
  public Game(int maxNumber)
  {
     Random randomGenerator = new Random();
     randomInt = randomGenerator.nextInt(maxNumber + 1); //because randomInt can pick 0
  }
     public boolean guess(int guess)
   {
     numberOfGuess ++;
      if(guess != randomInt)
     {
       if(guess > randomInt)
       {
          System.out.println("the number is \"too damn high\"!");
          return false;
       }
       else
       {
          System.out.println("too low!");
          return false;
        }
     }
      else
     {
       System.out.println("About time you guessed it!");
       return true;
     }
   }
  public void reset(int maxNumber)
  {
    Random randomGenerator2 = new Random();
     randomInt = randomGenerator2.nextInt(maxNumber + 1); //because randomInt can pick 0
     System.out.println("Same max number but different random. What's your Guess?");
     numberOfGuess = 0;
  }
}  
     

 


