//  Cameron Showalter
//  3/4/2015
//  V1.0
//  Java 103
//  Homework 4.3
//  tells you how many words are in a sentance in a very complex way. (Will simplify later)
public class wordCounter{
    public static void main(String[] args){
        String str1 = "I am a string";
        String str2 = "         ";
        String str3 = "Here   is a   nice   String!   ";
        wordCount(str1);
        wordCount(str2);
        wordCount(str3);
    }
    //Counts the words of a string. 0 = space, 1 = notSpace
    public static void wordCount(String myWord){
        int numberChars = myWord.length();
        String newWord = "";
        for(int i = 0; i<numberChars; i++){
            char letter = myWord.charAt(i);
            if(letter == ' '){
                newWord = newWord + "0";
            }
            else{
                newWord = newWord + "1";
            }
        }
        newWord = newWord + "0";
        int count = 0;
        for(int i = 1; i<numberChars + 1; i++){// " +1 because i added a space @ end of string
            if(newWord.charAt(i)=='0'){
                if(newWord.charAt(i - 1)=='1'){
                    count++;
                }
            }
        }
    System.out.print(count);
    //test
    System.out.print("\n" + newWord);
    }
}