//Cameron Showalter
//2-10-2015
//CSF103
//prints a slashFigure
public class SlashFigure{
    public static final int COUNTER = 6;
    public static void main(String[] args){
        int line = 1;
        for(int j=1; j<COUNTER; j++){
            for(int i=0; i<line - 1; i++){
                System.out.print("\\\\");
            }
            for(int i=0; i<(4*COUNTER-2)-(line*4); i++){
                System.out.print("!");
            }
            for(int i=0; i<line - 1; i++){
                System.out.print("//");
            }
            
            
        line++;
        System.out.println();
        }
    }
}