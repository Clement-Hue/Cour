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
let listArtist = []
 albums.forEach(elem =>  listArtist.push(elem))

function Artist(){ }

Artist.prototype.list = [...listArtist ]
Artist.prototype.withName = function(name) {
    return Artist.prototype.list.find(elem => Object.keys(elem) == name) 
}
let newArtist = new Artist()
console.log(newArtist.withName("Fresh_Cream"))