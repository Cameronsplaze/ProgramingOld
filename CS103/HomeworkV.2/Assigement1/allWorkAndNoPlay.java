// Cameron Showater   Java103   1/27/2015
// Homework P.54  1.13  (typo on assigmenet saying its 1.16 but the same question in the book is on #13)
//print a statement 1000 times!!!
public class allWorkAndNoPlay{
    public static void main(String[] args){
        branchOne();
        branchOne();
        branchOne();
        branchOne();
        branchOne();
        branchOne();
        branchOne();
        branchOne();
        branchOne();
        branchOne();
    }
    // reduse the lines needed
    public static void branchOne(){

        branchTwo();
        branchTwo();
        branchTwo();
        branchTwo();
        branchTwo();
        branchTwo();
        branchTwo();
        branchTwo();
        branchTwo();
        branchTwo();
        branchTwo();
        branchTwo();
        branchTwo();
        branchTwo();
        branchTwo();
        branchTwo();
        branchTwo();
        branchTwo();
        branchTwo();
        branchTwo();
    }
    //prints the statement 5 times each time it's called
    public static void branchTwo(){
        System.out.println("All work and no play makes Jack a dull boy.");
        System.out.println("All work and no play makes Jack a dull boy.");
        System.out.println("All work and no play makes Jack a dull boy.");
        System.out.println("All work and no play makes Jack a dull boy.");
        System.out.println("All work and no play makes Jack a dull boy.");
    }
}