class MediatorActivation extends Observer{
    constructor(view, checkbox, desactiveButton) {
        this.view = view;
        this.desactiveButton = desactiveButton;
        this.checkbox = checkbox;
    }

    update(observable, object) {
        this.checkbox.update(observable, object);
        if (this.modelActivation.activation === true) {
            this.desactiveButton.update(observable,object);
        }
    }

}