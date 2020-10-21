class Cellule extends Liste {
    int val ;
    Liste next ;
    Cellule(int i, Liste suite){
        this.val = i ;
        this.next = suite ;
    }
    public int getVal() {
        return val;
    }

    @Override
    public Liste getNext() {
        return next;
    }

    @Override
    public boolean isEmpty() {
        return false;
    }
    public int longueur(){
        Liste cell = this;
        int lenght = 0;
        while (!(cell.isEmpty() )) {
            lenght++;
            cell = cell.getNext();
        }
        return lenght;
    }
    public boolean find(int n ){
        Cellule cell = this;
        while (!(cell.isEmpty() )) {
            if (cell.val == n) return true;
            cell =(Cellule) cell.next;
        }
        return false;
    }

    public int max () {
        Cellule cell = this;
        int max = 0;
        while (!(cell.isEmpty() )) {
            if (max < cell.val) max = cell.val;
            cell = (Cellule) cell.next;
        }
        return max;
    }
}
