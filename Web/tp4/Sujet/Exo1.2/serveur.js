// Clément Hue
'use strict';

const http = require('http');
http.createServer((request,response) => {
    const html = `
    <!DOCTYPE html>
    <head>
        <title> Bonjour </title> 
        <meta charset="UTF-8"/> 
     </head>
     <body>
         Analyse de votre requête: <br>\
         Vous accédez à l\'url: ${request.url.split('?')[0]} <br>
         La chaine de requête est: ${request.url.split('?')[1]} 
    </body>`
    if (request.method === 'GET')
        response.writeHead(200,{
            'Content-Type':'text/html',
            'Content-Length': Buffer.byteLength(html),
        })
    else
        response.statusCode = 405;
    response.write(html);
    response.end();
}).listen(8080);