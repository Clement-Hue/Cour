
class View {
  constructor() {
    wrapper = document.getElementById("wrapper");
    this.buttonPlus = this.newButton("Plus");
    this.buttonMoins = this.newButton("Moins");
    this.text = document.createElement("input")
    this.checkBox = document.createElement("INPUT")
    this.checkBox.setAttribute("type","checkbox")
    this.checkBox.setAttribute("id","activate")
    const label = document.createElement("label")
    label.htmlFor = "activate"
    label.textContent = "Activation"
    this.select = this.selectMenu();
    this.slider = this.createSlider();
    wrapper.appendChild(this.buttonPlus);
    wrapper.appendChild(this.buttonMoins);
    wrapper.appendChild(this.text);
    wrapper.appendChild(label);
    wrapper.appendChild(this.checkBox);
    wrapper.appendChild(this.select);
    wrapper.appendChild(this.slider);
  }

  newButton(text) {
    const button = document.createElement("button");
    button.innerText = text;
    return button
  }
    selectMenu() {
      const plus = document.createElement("option");
      const moins = document.createElement("option");
      moins.value = "1";
      moins.text = "Moins";
      plus.value = "2";
      plus.text = "Plus";
      const select = document.createElement("SELECT");
      select.add(plus);
      select.add(moins);
      return select;
  }


  createSlider() {
    const container = document.createElement("div");
    const slider = document.createElement('input');
    slider.id = "volume";
    slider.type = 'range';
    slider.min = 0;
    slider.max = 10;
    slider.step = 1;
    slider.classList.add("slider")
    container.classList.add("slidecontainer");
    container.appendChild(slider)
    return container;
  }
}

