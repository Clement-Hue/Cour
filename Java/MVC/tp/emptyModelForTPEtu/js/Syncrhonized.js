class Synchronized extends Observer {
    constructor(modelInteger1, modelInteger2) {
        super();
        this.modelInteger1 = modelInteger1;
        this.modelInteger2 = modelInteger2;
    }

    update(observable, object){
        if (observable === this.modelInteger1) {
            this.modelInteger2.setValue( 10 - observable.z);
        } else if (observable === this.modelInteger2 ) {
            this.modelInteger1.setValue( 10 - observable.z);
        }
    }
}