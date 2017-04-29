
public class Main
{
    public static void main(String[] args)
    {
        Nerf nStrike = new Nerf();
        nStrike.shoot();
        nStrike.getdartsInClip();
        System.out.println(nStrike.getdartsInClip());
        nStrike.shoot();
        System.out.println(nStrike.getdartsInClip());
        nStrike.reload(2);
        System.out.println(nStrike.getdartsInClip());
       
    }
}