class PrintObserver extends Observer {
    constructor(view) {
        super();
        this.view = view;
    }

    update(observable, object){
        this.view.text.value = observable.z;
        this.view.slider.value = observable.z;
    }
}