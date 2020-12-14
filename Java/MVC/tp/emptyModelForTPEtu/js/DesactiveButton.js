class DesactiveButton extends Observer{
    constructor(view) {
        super();
        this.view = view;
    }


  update(observable, object) {
    // this.mediator.mediate(observable)
    if (observable.z === 0) {
      this.view.buttonMoins.disabled= true;
    } else {
      this.view.buttonMoins.disabled= false;
    }
    if (observable.z === 10) {
      this.view.buttonPlus.disabled= true;
    } else {
      this.view.buttonPlus.disabled= false;
    }
  }
}