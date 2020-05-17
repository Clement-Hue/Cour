// Clément Hue
'use strict';

const http = require('http');
http.createServer((request, response) => {
    response.writeHead(200);
    response.write('Bonjour tout le monde');
    response.end();
}).listen(8080);