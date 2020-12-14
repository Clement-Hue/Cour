class ModelActivation extends Observable{
    activation = false;

    switchActivation() {
        this.activation = !this.activation;
        this.setChanged()
    }

}