
/**
 * NerfGun that can shoot, reload, and tell you how many shots are left.
 * 
 * @author Brandon Abbott Cameron Showalter 
 * @version 1.2
 * @date 10/02/2014
 */
public class Nerf 
{
    // instance variables - replace the example below with your own
    public int dartsInClip;

    
    /**
     * Constructor for objects of class Nerf
     */
    public Nerf()
    {
        // initialinewse instance variables
        dartsInClip = 6;
        
        
        
    }
    
    /**
     * adds darts to clip or reloads the clip
     * @param Darts number of shots in the clip.
     */
    public void reload (int darts) 
    {
        dartsInClip = dartsInClip + darts;
        System.out.print("Reloading: ");
        System.out.println(darts);
        System.out.print("Number of shots: ");
    }
    
    /**
     * shoots how ever many darts that assgin it to shoot
     */
    public void shoot()
     {
        dartsInClip = dartsInClip - 1;
        System.out.print("Bang ");
     }
    
    /**
     * returns the amount of darts in clip
     */
    public int getdartsInClip()
    {
       return dartsInClip;
    }    
    
    
}
