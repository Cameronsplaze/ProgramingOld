// Cameron Showalter   103 Java   1/27/2015
// Homework p.54  1.11
public class rockets{
    public static void main(String[] args){
        rocketStream();
    }
    //Puts all the other methods together and adds spacing
    public static void rocketStream(){
    starLines();
    starCross();
    System.out.println();
    starLines();
    starCross();
    starLines();
    System.out.println();
    System.out.println("  *");
    System.out.println("  *");
    System.out.println("  *");
    starLines();
    starCross();
    }
    //prints two lines of five stars
    public static void starLines(){
        System.out.println("*****\n*****");
    }
    //prints stars that resemble an "x"or cross
    public static void starCross(){
        System.out.println(" * * \n  * \n * *");
    }    
}
    