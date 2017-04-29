public class displacement{
    public static void main(String[]args){
        int countDown = 6;
        for(int j=6; j>=0; j--){
            for(int i = countDown; i > 0; i--){
                System.out.print("*");
            }
            countDown = (countDown - 7) * -1;
            for(int k = 0; k<countDown; k++){
                System.out.print(" ");
            }
            countDown = (countDown * -1) + 7;
            for(int i = countDown; i > 0; i--){
                System.out.print("//");
            }
            countDown = (countDown - 7) * -1;
            for(int k = 0; k<countDown; k++){
                System.out.print("\\\\");
            }
            countDown = (countDown * -1) + 7;
            countDown = (countDown - 7) * -1;
            for(int k = 0; k<countDown; k++){
                System.out.print(" ");
            }
            countDown = (countDown * -1) + 7;
            for(int i = countDown; i > 0; i--){
                System.out.print("*");
            }  
            countDown --;
            System.out.println();
        }               
    }
}

