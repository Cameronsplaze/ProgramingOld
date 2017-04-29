// Cameron Showalter
// 2/17/2015
// prints a grid of numbers.... see bottom
import java.util.*;
public class printGrid{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        System.out.print("Height of rectangle: ");
        int height = in.nextInt();
        System.out.print("\nWidth of rectangle: ");
        int width = in.nextInt();
        gridLayout(width, height);
        in.close();
    }
    //actually creates the grid with information provided above
    public static void gridLayout(int width,int height){
        int startingValue = 1;
        for(int j=0; j<height; j++){
            for(int i=0; i<width; i++){
                System.out.print(startingValue + height * i + " ");
            }
        startingValue++;
        System.out.println();
        }
    }  
}

// width: 5, height: 4
// 1 5  9 13 17
// 2 6 10 14 18
// 3 7 11 15 19
// 4 8 12 16 20