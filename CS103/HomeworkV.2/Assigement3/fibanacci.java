public class fibanacci{
    public static void main(String[] args){
    assembly();   
    }
    public static void assembly(){
    devider();
    upArrow();
    downArrow();
    devider();
    downArrow();
    upArrow();
    devider();
    }
    public static void upArrow(){
    System.out.println("|    *    |");
    System.out.println("|   /*\\   |");
    System.out.println("|  //*\\\\  |");
    System.out.println("| ///*\\\\\\ |");
    }
    public static void downArrow(){
    System.out.println("| \\\\\\*/// |");
    System.out.println("|  \\\\*//  |");
    System.out.println("|   \\*/   |");
    System.out.println("|    *    |");
    }
    public static void devider(){
    System.out.println("+---------+");
    }
}