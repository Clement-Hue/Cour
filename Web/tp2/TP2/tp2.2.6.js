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
albums = Object.entries(albums)
                .map(album => {
                    album[1] = new Album(album[1]);
                    return album;
                })
                .map(album => {
                    return {
                        [album[0]]: album[1],
                    };
                });

function Artist(name){
    this.name = name;
}

// je comprends pas ce qu'il faut faire