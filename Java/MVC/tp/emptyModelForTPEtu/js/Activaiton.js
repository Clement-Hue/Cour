class Activation extends Observer {
    constructor(view) {
        super();
        this.view = view;
    }

    update(observable, object) {
        if (observable.activation === true) {
            this.view.buttonPlus.disabled = false;
            this.view.buttonMoins.disabled = false;
        } else {
            this.view.buttonPlus.disabled = true;
            this.view.buttonMoins.disabled = true;
        }
    }
}