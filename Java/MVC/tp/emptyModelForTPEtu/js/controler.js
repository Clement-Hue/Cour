

class Controler {

  constructor(modelInteger1 , modelInteger2){
      this.modelInteger1 = modelInteger1;
      this.modelInteger2 = modelInteger2;
      this.modelActivation1 = new ModelActivation();
      this.modelActivation2 = new ModelActivation();
      this.frame(this.modelInteger1, this.modelActivation1);
      this.frame( this.modelInteger2, this.modelActivation2);
  }



  frame(modelInteger, modelActivation) {
    const view = new View();
    // update
    const mediator = new MediatorActivation(view,modelInteger,modelActivation);
    modelInteger.addObservers(new DesactiveButton(mediator));
    modelActivation.addObservers(new Activation(mediator));
    modelInteger.addObservers(new PrintObserver(view));
    modelInteger.addObservers(new Synchronized(modelInteger1, modelInteger2));
    //  action
    view.buttonPlus.addEventListener("click", modelInteger.plus);
    view.select.addEventListener("change", (e) => {
      if (e.target.value === "1") {
        modelInteger.moins();
      } else if (e.target.value === "2") {
        modelInteger.plus();
      }
    });
    view.buttonMoins.addEventListener("click", modelInteger.moins);
    view.checkBox.addEventListener("change" ,() => {
      modelActivation.switchActivation()
    });
    view.slider.addEventListener("change",(e) => {
      modelInteger.setValue(e.target.value)
    });
    view.text.addEventListener("change", (e) => {
      modelInteger.setValue(Number(e.target.value));
    });
  }
}
