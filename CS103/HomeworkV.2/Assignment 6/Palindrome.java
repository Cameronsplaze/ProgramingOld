import java.util.*;
public class Palindrome{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        System.out.print("Enter a word: ");
        String phrase = in.next();
        if(backwardsWord(phrase) == true){
            System.out.print("It's also the same word read front to back.");
        }
        else{
            System.out.print("It's not the same word read front to back.");
        }
        in.close();
    }

    public static boolean backwardsWord(String phrase){
        int lengthPH = phrase.length();
        String newPhrase = "";
        for(int i = 0; i < lengthPH; i++){
            newPhrase = newPhrase + phrase.charAt(lengthPH-i-1);
            
        }
        if(newPhrase.equalsIgnoreCase(phrase)){
            return true;
        }
        else{
            return false;
        }
    }
}