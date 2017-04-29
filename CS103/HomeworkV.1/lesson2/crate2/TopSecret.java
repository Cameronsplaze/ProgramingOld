// BlueJ project: lesson2/crate2

public class TopSecret
{
    public static void main(String[] args)
    {
        /* Name of Line- First leter= Area of it (S- screen, M- Moniter, K- Keyboard, B- main body, P- Mouse pad, etc)
         *             Second letter= Direction (NW- North west, C- Center, etc)
         *            Third "letter"= number, how many other are there to avoid duplicets. 
         */              
        
        // Define the line
        Line MN1 = new Line(200, 20, 400, 50);
        Line MNW1 = new Line(200, 20, 210, 8);
        Line MN2 = new Line(210, 8, 410, 38);
        Line MNE1 = new Line(400, 50, 410, 38);
        Line MW1 = new Line(200, 20, 200, 150);
        Line ME1 = new Line(400, 50, 400, 190);
        Line MS1 = new Line(200, 150, 400, 180);
        Line MSE1 = new Line(400, 180, 410, 166);
        Line ME2 = new Line(410, 166, 410, 38);
        Line SN1 = new Line(210, 30, 390, 60);
        Line SE1 = new Line(390, 60, 390, 170);
        Line SS1 = new Line(390, 170, 210, 140);
        Line SW1 = new Line(210, 140, 210, 30);
        Line BW1 = new Line(200, 150, 120, 260);
        Line BE1 = new Line(400, 180, 320, 290);
        Line BS1 = new Line(120, 260, 320, 290);
        Line BSW1 = new Line(120, 260, 120, 270);
        Line BSE1 = new Line(320, 300, 320, 290);
        Line BS2 = new Line(120, 270, 320, 300);
        Line BE2 = new Line(400, 190, 320, 300);
        Line KN1 = new Line(205, 160, 380, 190);
        Line KE1 = new Line(380, 190, 340, 240);
        Line KS1 = new Line(165, 210, 340, 240);
        Line KW1 = new Line(165, 210, 205, 160);
        Line PS1 = new Line(200, 267, 240, 273);
        Line PW1 = new Line(200, 267, 216, 245);
        Line PC1 = new Line(204, 261.5, 244, 267.5);
        Line PE1 = new Line(240, 273, 256, 251);
        Line PS2 = new Line(224, 264.5, 220, 270);
        Line PN1 = new Line(256, 251, 216, 245);
        // Draw the lines
        MN1.draw();
        MNW1.draw();
        MN2.draw();
        MNE1.draw();
        MW1.draw();
        ME1.draw();
        MS1.draw();
        MSE1.draw();
        ME2.draw();
        SN1.draw();
        SE1.draw();
        SS1.draw();
        SW1.draw();
        BW1.draw();
        BE1.draw();
        BS1.draw();
        BSW1.draw();
        BSE1.draw();
        BS2.draw();
        BE2.draw();
        KN1.draw();
        KE1.draw();
        KS1.draw();
        KW1.draw();
        PS1.draw();
        PW1.draw();
        PC1.draw();
        PE1.draw();
        PS2.draw();
        PN1.draw();
    }
}
