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
albums = Object.entries(albums)
            .map(album => {
                album[1] = new Album(album[1]);
                return album;
            })
            .map(album => {
                return {
                    [album[0]]: album[1]
                }
            })
let listAlbums = {}
Object.assign(listAlbums,...albums);
console.log(albums)
let listArtist = []
 albums.forEach(elem =>  listArtist.push(Object.keys(elem)[0]))

function Artist(nom){
    this.nom = nom;
}
Artist.prototype.withName = function() {

}

Artist.prototype.list = [...listArtist ]