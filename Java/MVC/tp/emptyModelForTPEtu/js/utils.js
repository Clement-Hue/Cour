// utils classes


class  Observable {
  observer = new Array();
  state = false;

  addObservers(observer){
    this.observer.push(observer);
    observer.update(this)
  }

  notifyObservers(object = null){
    this.observer.forEach(obs => {
      obs.update(this, object);
    });
  }

  clearObservers(){
    this.observer = new Array();
  }

  setChanged(){
    this.state = !this.state;
    if (this.state) {
      this.notifyObservers();
      this.state = false;
    }
  }

  removeObserver(observer){
    this.observer.splice(this.observer.indexOf(observer), 1);
  }
}

class Observer {
  update(observable, object){};
}
