class Cellule extends Liste {
    int val ;
    Liste next ;
    Cellule(int i, Liste suite){
        this.val = i ;
        this.next = suite ;
    }
    public int longueur(){
        Cellule cell = this;
        int lenght = 0;
        while (cell != null) {
            lenght++;
            cell = (Cellule) cell.next;
        }
        return lenght;
    }
    public boolean find(int n ){
        Cellule cell = this;
        while (cell != null) {
            if (cell.val == n) return true;
            cell =(Cellule) cell.next;
        }
        return false;
    }

    public int max () {
        Cellule cell = this;
        int max = 0;
        while (cell!=null){
            if (max < cell.val) max = cell.val;
            cell = (Cellule) cell.next;
        }
        return max;
    }
}
