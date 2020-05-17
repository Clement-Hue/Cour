// Clément Hue
'use strict';
function Album(albumJson){
    this.album = Object.assign(albumJson);
}
Album.prototype.getArtist = function () {
    return this.album.artist;
};
Album.prototype.getYear = function () {
    return this.album.year;
};
Album.prototype.getTitle = function () {
    return this.album.title;
};




let fs = require('fs');
let albums = fs.readFileSync('albums.json');
albums = JSON.parse(albums);
albums = Object.entries(albums);
albums = albums.map(album => {
    album[1] = new Album(album[1]);
    return album;
});
albums = albums.map(album => {
    return {
        [album[0]]: album[1],
    };
});
let target = {};
Object.assign(target, ...albums);
console.log('question 6', target);