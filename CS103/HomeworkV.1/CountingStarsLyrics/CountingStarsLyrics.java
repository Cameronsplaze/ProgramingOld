
/**
 * Prints lyrics for song Counting Stars by OneRepublic
 * 
 * @author Cameron Showalter 
 * @version v1.0
 */
public class CountingStarsLyrics{
    public static void main(String[] args){// Runs the "printlyrics" method 
        printlyrics();
    }
    public static void printlyrics(){ //The correct order to print the lyrics for the song
        chorus();
        System.out.println("");
        verseOne();
        System.out.println("");
        verseTwo();
        System.out.println("");
        chorus();
        System.out.println("");
        System.out.println("Oh, oh, oh.");
        System.out.println("");
        bridge();
        bridge();
        bridge();
        bridge();
        System.out.println("Everything that kills me makes me feel alive");
        System.out.println("");
        chorus();
        System.out.println("");
        outro();
        outro();
        outro();
        outro();
    }
    public static void chorus(){// prints the chorus
        System.out.println("Lately I been, I been losing sleep");
        System.out.println("Dreaming about the things that we could be");
        System.out.println("But baby, I been, I been prayin' hard");
        System.out.println("Said no more counting dollars");
        System.out.println("We'll be counting stars");         
        System.out.println("Yeah, We'll be counting stars");
    }
    public static void verseOne(){// prints verseOne
        System.out.println("I see this life");
        System.out.println("Like a swinging vine");
        System.out.println("Swing my heart across the line");
        System.out.println("In my face is flashing signs");    
        System.out.println("Seek it out and ye shall find");
        System.out.println("");
        System.out.println("Old, but I'm not that old");
        System.out.println("Young, but I', not that bold");
        System.out.println("And I don't think the world is sold");
        System.out.println("I'm just doing what we're told");
        System.out.println("");
        System.out.println("And i feel something so wrong");
        System.out.println("By doing the right thing");
        System.out.println("I couldn't lie, couldn't lie, ouldn't lie");
        System.out.println("Everything that drowns me makes me wanna fly");   
    }
    public static void verseTwo(){// prints verseTwo
        System.out.println("I feel the love");
        System.out.println("And I feel it burn");
        System.out.println("Down this river every turn");
        System.out.println("Hope is our four letter word");
        System.out.println("Make that money");
        System.out.println("Watch it burn");
        System.out.println("");
        System.out.println("Old, but I'm not that old");
        System.out.println("Young, but I'm not that bold");
        System.out.println("And I don't think the world is sold");
        System.out.println("I'm just doing what we're told");
        System.out.println("");
        System.out.println("And I feel something so wrong");
        System.out.println("By doing the right thing");
        System.out.println("I couldn't lie, couldn't lie, couldn't lie");
        System.out.println("Everything that drowns me makes me wanna fly");
        }
    public static void bridge(){ //prints the bridge
        System.out.println("Take that money");
        System.out.println("Watch it burn");
        System.out.println("Sink in the river");
        System.out.println("The lessons I learned");
    }
    public static void outro(){//prints the outro
        System.out.println("Take that money");
        System.out.println("Watch it burn");
        System.out.println("Sink in the river");
        System.out.println("The lessons I learned");
    }
}

