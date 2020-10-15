import java.awt.Rectangle ;

class Pulsar extends Palet {
    int rect_larg = 10;
    int rect_long = 10;
    int rect_n = 2;

    Pulsar(int x, int y) { super(x, y); }

    @Override
    public void deplace() {
        if (sortie_x(this.x + this.vx)) {
            this.vx = -this.vx;
            this.rect_n = -this.rect_n;
        } else {
            this.x += this.vx;
            this.rect_larg += this.rect_n;
            this.rect_long += this.rect_n;
        }
        if (this.sortie_x(this.y + this.vy)) {
            this.vy = -this.vy;
        } else { y+= vy; }
    }

    @Override
    public Rectangle getRect() {
        return new Rectangle(this.x, this.y, this.rect_long, this.rect_larg);
    }
}