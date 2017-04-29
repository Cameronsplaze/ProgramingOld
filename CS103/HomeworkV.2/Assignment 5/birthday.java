// Cameron Showalter
// 2/17/2015
// Prints your birthday!!
import java.util.*;
public class birthday{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        System.out.print("The Day of the month you were born(Numbers): ");
        int day = in.nextInt();
        System.out.print("\nThe Month you were born(Words): ");
        String month = in.next();
        System.out.print("\nThe Year you were born(Numbers): ");
        int year = in.nextInt();
        tellThemThereOld(day, month, year);
        in.close();
    }
    //puts all the information together
    public static void tellThemThereOld(int day, String month, int year){
        System.out.println("You were born on " + month + " " + day + ", " + year + ". Your really old!!");
    }
}