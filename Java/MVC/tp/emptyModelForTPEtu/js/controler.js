

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
    modelInteger.addObservers(new DesactiveButton(view));
    modelInteger.addObservers(new PrintObserver(view));
    modelInteger.addObservers(new Synchronized(modelInteger1, modelInteger2));
    modelActivation.addObservers(new Activation(view));
    //  action
    view.buttonPlus.addEventListener("click", modelInteger.plus);
    view.buttonMoins.addEventListener("click", modelInteger.moins);
    view.checkBox.addEventListener("change" ,() => {
      modelActivation.switchActivation()
    });
    view.text.addEventListener("change", (e) => {
      modelInteger.setValue(Number(e.target.value));
    });
  }
}
