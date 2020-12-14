
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
    wrapper.appendChild(this.buttonPlus);
    wrapper.appendChild(this.buttonMoins);
    wrapper.appendChild(this.text);
    wrapper.appendChild(label);
    wrapper.appendChild(this.checkBox);
  }

  newButton(text) {
    const button = document.createElement("button");
    button.innerText = text;
    return button
  }
}
