'use strict';

// Pas besoin d'évenement window.onload puisqu'on utilise l'attribut defer
// lorsque l'on charge notre script

const baseUrl =  'http://localhost:3000';

async function loadGenres() {
    const response = await fetch(`${baseUrl}/genres`);
    if (!response.ok)
        throw new Error ('error response');
    const genres = await response.json();
    const select = document.querySelector('select');
    genres.forEach(element => {
        const option = document.createElement('option');
        option.value = element.id;
        option.text = element.name;
        select.add(option);
    });
    loadArtists(select, genres).catch(error => console.log(error));
    select.addEventListener('change', (e) => {
        loadArtists(e.target, genres).catch(error => {
            console.log('Error' + error);
        });
    });
}



async function loadArtists( genreSelected, genres ){
    const description = genres.find(genre => genre.id === genreSelected.value).description;
    document.querySelector('#main h2').textContent = `Top ${genreSelected.value} artists`;
    document.querySelector('#description ').textContent = description;
    const response = await fetch(`${baseUrl}/genres/${genreSelected.value}/artists`);
    if (!response.ok)
        throw new Error ('error response');
    const artists = await response.json();
    const list = document.querySelector('#main ul');
    list.innerHTML = '';
    for (const artist of artists){
        const name = document.createElement('h3');
        const li = document.createElement('li');
        const link = document.createElement('a');
        const image = document.createElement('img');
        link.setAttribute('id', artist.id);
        image.setAttribute('src', artist.photo);
        name.textContent = artist.name;
        li.appendChild(link).appendChild(name);
        list.appendChild(li).appendChild(image);
    }
    list.addEventListener('click', (e) => {
        if (e.target.nodeName !== 'H3')
            return;
        artistSelected(e.target).catch(error => {
            console.log('Error' + error);
        });
    });
}


async function artistSelected(event) {
    const response = await fetch(`${baseUrl}/artists/${event.parentElement.id}/albums`);
    if (!response.ok)
        throw new Error ('error response');
    const albums = await response.json();
    const popup = document.getElementById('albums');
    popup.style.visibility = 'visible';
    popup.style.opacity = 1;
    popup.style.transitionDuration = '0.5s';
    popup.style.left = `${(document.body.clientWidth - popup.clientWidth) / 2}px`;
    popup.style.top = `${(document.body.clientHeight - popup.clientHeight) / 2}px`;
    document.querySelector('#albums form button').addEventListener('click', (e) => {
        e.preventDefault();
        popup.style.visibility = 'hidden';
        popup.style.opacity = 0;
    });
    const table = document.querySelector('#albums tbody');
    table.innerHTML = '';
    for (const album of albums){
        const row = document.createElement('tr');
        const title = document.createElement('td');
        const cover = document.createElement('img');
        const year = document.createElement('td');
        const label = document.createElement('td');
        title.textContent = album.title;
        label.textContent = album.label;
        year.textContent = album.year;
        cover.setAttribute('src', album.cover);
        table.appendChild(row);
        row.appendChild(cover);
        row.appendChild(title);
        row.appendChild(year);
        row.appendChild(label);
    }
}


loadGenres().catch(error => {
    console.log('Error' + error);
});