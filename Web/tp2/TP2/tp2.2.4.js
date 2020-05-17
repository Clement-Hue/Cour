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

let newAlbum = new Album({
    title: 'Fresh Cream',
    artist: 'Cream',
    year: 1966,
});

console.log(newAlbum);
console.log(newAlbum.getTitle());
console.log(newAlbum.getArtist());
console.log(newAlbum.getYear());