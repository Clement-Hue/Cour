'use strict';

// import du module Express
const express = require('express');
const app = express();

const data = require('./data/db.json');

app.get('/genres', (request, response) => {
    response.setHeader('Content-Type', 'application/json');
    response.send(JSON.stringify(data.genres));
});

app.get('/genres/:genreId/artists', (request, response) => {
    const listeArtist = []
    data.artists.forEach(artist => {
        if (artist.genreId === request.params.genreId)
            listeArtist.push(artist);
    })
    response.json(listeArtist);
});


// export de notre application vers le serveur principal
module.exports = app;
