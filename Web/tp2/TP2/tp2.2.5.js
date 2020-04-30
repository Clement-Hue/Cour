function Album(albumJson){
    this.album = {...albumJson};
    this.getTitle = () => {
        return this.album.title;
    }
    this.getArtist = () => {
        return this.album.artist;
    }
    this.getYear = () => {
        return this.album.year;
    }
}


let fs = require('fs');
let albums = fs.readFileSync('albums.json')
albums = JSON.parse(albums);
albums = Object.entries(albums);
albums = albums.map(album => {
    album[1] = new Album(album[1]);
    return album;
})
albums = albums.map(album => {
    return {
        [album[0]]: album[1]
    }
})
let target = {};
Object.assign(target,...albums);
console.log("question 6",target);