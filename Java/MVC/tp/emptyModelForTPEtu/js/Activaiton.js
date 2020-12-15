class Activation extends Observer {
    constructor(mediator) {
        super();
        this.mediator = mediator;
    }

    update(observable, object) {
        this.mediator.mediate(observable);
    }
}