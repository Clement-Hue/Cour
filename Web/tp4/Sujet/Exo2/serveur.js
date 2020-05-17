'use strict';

const express = require('express');
const api = require('./api/api');

const app =  new express();

app.use(express.static('public'));
app.use('/api', api);

app.listen(8080);

