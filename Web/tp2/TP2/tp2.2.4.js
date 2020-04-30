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

let newAlbum = new Album({
    title: 'Fresh Cream',
    artist: 'Cream',
    year: 1966,
})

console.log(newAlbum);
console.log(newAlbum.getTitle())
console.log(newAlbum.getArtist())
console.log(newAlbum.getYear())