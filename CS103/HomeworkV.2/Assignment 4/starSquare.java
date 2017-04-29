//Cameron Showalter
//2-10-2015
//CSF103
//Creates a rectangle of stars
public class starSquare{
    public static void main(String[] args){
        int starWidth = 5;
        int starLength = 4;
        //row-length
        for(int i=0; i<starLength; i++){
            //column-width
            for (int j=0; j<starWidth; j++){
                System.out.print("*");
            }
            System.out.println();
        }      
    }
}