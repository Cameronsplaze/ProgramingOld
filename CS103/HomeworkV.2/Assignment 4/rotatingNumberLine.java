//Cameron Showalter
//2-10-2015
//CSF103
//prints the line of numbers with a bar above all "0"
//gives a warning about local j not being used... ignore it. i added it to keep the for loop happy.(line 18)
public class rotatingNumberLine{
    public static final int REPEAT = 6;
    public static void main(String[] args){
        int counter = 1;
        for(int i=0; i<REPEAT; i++){
            for(int j=1; j<10; j++){
                System.out.print(" ");
            }
        System.out.print("|");
        }
        System.out.println();
        for(int i=0; i<REPEAT; i++){
            for(int j = 0;counter<10; counter++){ //used j because it needs a variable. Didn't use it anyware else
                System.out.print(counter);
            }
        counter=0;
        }
    System.out.print("0"); //prints last "0"
    }
}