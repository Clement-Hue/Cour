public class Palet implements MovingObject{
    int x;
    int y;
    int vx;
    int vy;
    public int getX() { return x;};
    public int getY() { return y;};
    boolean sortie_x (int px) { return px < 0 || px > 320; };
    boolean sortie_y  (int py) { return py < 0 || py > 200; };
    public void deplace() {
        if ( sortie_x(x + vx)) {
            vx = -vx;
        } else {
            x = x + vx;
        }
        if ( sortie_y(y + vy)) {
            vy = -vy;
        }  else {
            y = y + vy;
        }
    }
    Palet(){
        this.x = 20;
        this.y = 50 ;
        this.vx = 10;
        this.vy = 10;
    }
    Palet(int x, int y){
        this.x = x;
        this.y = y ;
        this.vx = 10;
        this.vy = 0;
    }
}