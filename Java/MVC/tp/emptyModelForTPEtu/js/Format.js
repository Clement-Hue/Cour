class Format {
    constructor(date) {
        this.date = date;
    }

    format() {
        return `${this.date.getDate()} ${this.date.getMonth()-1} ${this.date.getFullYear()}`;
    }
}