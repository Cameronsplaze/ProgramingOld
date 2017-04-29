import java.util.*;
public class myGrades{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        System.out.print("What precent did you get in the class?: ");
        int percent = in.nextInt();
        if(percent > 0){
            if(percent < 100){
                System.out.print("Your GPA is: " + percentToGPA(percent));
            }
            else{
                System.out.print("Grade is way too high!!");
            }
        }
        else{
            System.out.print("Grade is too low!!");
        }
        in.close();
    }
    public static double percentToGPA(int percent){
        if(percent < 60){
            return 0.0;
        }
        else if(percent > 95){
            return 4.0;
        }
        else if(percent < 62){//already excluded all values below 60 with the if statement abbove
            return 0.7;
        }
        else{
            double Gpa = (percent - 55)/10.0;
            return Gpa;
        }
    }
}