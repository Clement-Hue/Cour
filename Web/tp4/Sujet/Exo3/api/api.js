'use strict';

// import du module Express
const express = require('express');
const app = express();
const HttpProxyAgent = require( 'http-proxy-agent' );
const fetch = require('node-fetch');
const DOMParser = require('xmldom').DOMParser;
const xpath = require('xpath');

// a passer en paramètre de vos appels à fetch pour que node puisse utiliser le proxy
let options = {
    // l'adresse du cache varie selon la connexion
    // filaire : 'http://cache.ha.univ-nantes.fr:3128'
    // eduroam : 'http://cache.etu.univ-nantes.fr:3128'
    // univ-nantes : 'http://cache.wifi.univ-nantes.fr:3128'
    agent: new HttpProxyAgent( 'http://cache.ha.univ-nantes.fr:3128' ),
};

app.get('/genres', async (req, res, next) => {
    let data = await fetch('http://ws.audioscrobbler.com/2.0/?method=tag.getTopTags&api_key=2c08f218f45c6f367a0f4d2b350bbffc');
    data = await data.text();
    data = new DOMParser().parseFromString(data);
    //console.log(data);
    const genres = xpath.select('//tag/name/text()', data);
    let promises =  genres.map( genre => {
        return  fetch(`http://ws.audioscrobbler.com/2.0/?method=tag.getinfo&tag=${genre.data}&api_key=2c08f218f45c6f367a0f4d2b350bbffc`);
    })
    let descriptions = await Promise.all(promises);
    promises = descriptions.map(async data => {
        data = await data.text();
        data = new DOMParser().parseFromString(data);
        return xpath.select('//summary/text()', data).map(description => {
             return description.data;
         });
    }) 
    descriptions = await Promise.all(promises);
})

// export de notre application vers le serveur principal
module.exports = app;
