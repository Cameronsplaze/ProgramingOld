import java.util.Scanner;
/**
 * MadLips assigmement.
 * 
 * @author Cameron Showalter
 * @version 1.0
 */
public class Main
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);

        System.out.print("Do you want to play a game? (yes/no): ");
         // Sees if what they entered is == to yes
        String Yea = "";
        Yea = in.next();
        
        if(Yea.equals("yes"))
        {
       
            // just to make the code more compacted and not repeditive
            String noun = "Please enter a Noun: "; 
        String nameOfMan = "Name of a Man in the Room: ";
        String adjetive = "Please enter a Adjetive: ";
        String pluralNoun = "Please enter a Plural Noun: ";
        String geoLocation = "Please enter a name of a Geographical Location: ";
        String nameOfGirl = "Name of a Girl in the Room: ";
        String number = "Please enter a Number: ";
        
        String str1, str2, str3, str4, str5, str6, str7, str8; // a friend tought me this trick <-----
        String str9, str10, str11, str12, str13, str14, str15, str16;
        System.out.println("Rules: ");
        System.out.println("1. Don't repeat any of the questions please!");
        System.out.println("2. All replys have to only be one word, ex: (MonkeyArms)"); //<--- i dont know how to fix this bug
        System.out.print(nameOfMan);
        str1 = in.next();
       
        System.out.print(adjetive);
        str2 = in.next();
        
        System.out.print(nameOfGirl);
        str3 = in.next();
        
        System.out.print(noun);
        str4 = in.next();
        
        System.out.print(noun);
        str5 = in.next();
        
        System.out.print(noun);
        str6 = in.next();
        
        System.out.print(pluralNoun);
        str7 = in.next();
        
        System.out.print(noun);
        str8 = in.next();
        
        System.out.print(adjetive);
        str9 = in.next();
        
        System.out.print(number);
        str10 = in.next();
        
        System.out.print(noun);
        str11 = in.next();
        
        System.out.print(geoLocation);
        str12 = in.next();
        
        System.out.print(adjetive);
        str13 = in.next();
        
        System.out.print(adjetive);
        str14 = in.next();
        
        System.out.print(noun);
        str15 = in.next();
        
        System.out.print(nameOfMan);
        str16 = in.next();
        
        System.out.print("Dear "); // the actuall madlib paragraph starts here
        System.out.print(str1);
        System.out.println(",");
        
        System.out.print("I am in love with your ");
        System.out.print(str2);
        System.out.println(" daughter,");
        
        System.out.print(str3);
        System.out.println(" and I would like to ask her ");
        
        System.out.print(str4);
        System.out.println(" in marrige. She is my idea of a perfect ");
        
        System.out.print(str5);
        System.out.print(". She is the only ");
        System.out.print(str6);
        System.out.println(" I have ever");
        
        System.out.print("loved and I want her to be the mother of my ");
        System.out.print(str7);
        System.out.println(".");
        
        System.out.print("At present, I am employed as an assistant ");
        System.out.print(str8);
        System.out.println(" and I");
        
        System.out.print("make a ");
        System.out.print(str9);
        System.out.print(" salary of ");
        System.out.print(str10);
        System.out.println(" dollars a week.");
        
        System.out.print("I have a split-level ");
        System.out.print(str11);
        System.out.print(" picked out in ");
        System.out.println(str12);
        
        System.out.println("that we can live in. If you give your permission I promise to make");
        
        System.out.print("her ");
        System.out.print(str13);
        System.out.print(" and to be a ");
        System.out.print(str14);
        System.out.print(" ");
        System.out.println(str15);
        
        System.out.print("signed: ");
        System.out.println(str16);
        }
        else
        {
            System.out.println("That was not a yes!!");
        }
        
    
    }
}
