class MediatorActivation {
    constructor(view, modelInteger, modelActivation) {
        this.view = view;
        this.modelActivation = modelActivation;
        this.modelInteger= modelInteger;
    }

    mediate(observable) {
        if (observable === this.modelInteger && this.modelActivation.activation) {
            this.desactivateButton(observable);
        } else if (observable === this.modelActivation) {
            this.activation(observable);
        }
    }


    activation(observable) {
        if (observable.activation === true) {
            this.view.buttonPlus.disabled = false;
            this.view.buttonMoins.disabled = false;
        } else {
            this.view.buttonPlus.disabled = true;
            this.view.buttonMoins.disabled = true;
        }
    }

    desactivateButton(observable) {
        if (observable.z === 0) {
            this.view.buttonMoins.disabled = true;
        } else {
            this.view.buttonMoins.disabled = false;
        }
        if (observable.z === 10) {
            this.view.buttonPlus.disabled = true;
        } else {
            this.view.buttonPlus.disabled = false;
        }
    }
}