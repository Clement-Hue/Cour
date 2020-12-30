
class View {
  constructor() {
    wrapper = document.getElementById("wrapper");
    const date = document.createElement("div");
    const today = new Format(new Date());
    date.innerHTML = today.format();
    this.buttonPlus = this.newButton($.i18n("plus"));
    this.buttonMoins = this.newButton($.i18n("moins"));
    this.text = document.createElement("input")
    this.checkBox = document.createElement("INPUT")
    this.checkBox.setAttribute("type","checkbox")
    this.checkBox.setAttribute("id","activate")
    const label = document.createElement("label")
    label.htmlFor = "activate"
    label.textContent = "Activation"
    this.select = this.selectMenu();
    const {slider, container} = this.createSlider();
    this.slider = slider;
    wrapper.appendChild(date);
    wrapper.appendChild(this.buttonPlus);
    wrapper.appendChild(this.buttonMoins);
    wrapper.appendChild(this.text);
    wrapper.appendChild(label);
    wrapper.appendChild(this.checkBox);
    wrapper.appendChild(this.select);
    wrapper.appendChild(container);
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
      moins.text = $.i18n("moins");
      plus.value = "2";
      plus.text = $.i18n("plus");
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
    return {container, slider};
  }
}

