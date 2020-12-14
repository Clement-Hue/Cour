

// implementation class

class ModelInteger extends Observable {
    constructor() {
        super();
        this.plus = this.plus.bind(this)
        this.moins = this.moins.bind(this)
        this.z = 0;
    }

    setValue(value) {
        if (value < 0 || value > 10) 
            return;
        this.z = value;
        this.setChanged();
    }

    plus() {
        this.setValue(this.z + 1);
    }

    moins() {
        this.setValue(this.z- 1);
    }
}
