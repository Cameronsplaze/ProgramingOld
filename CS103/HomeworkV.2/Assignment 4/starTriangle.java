//Cameron Showalter
//2-10-2015
//CSF103
//Creates an increasing triangle of stars
public class starTriangle{
    public static void main(String[] args){
        int maxStars = 5;
        int starStorage = 0;
        for(int i=0; i< maxStars; i++){
            starStorage++;
            for(int j=0; j<starStorage; j++){
                System.out.print("*");
            }
            System.out.println();
        }        
    }
}