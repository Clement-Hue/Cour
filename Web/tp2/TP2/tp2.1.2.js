'use strict';
var t = [0, 3, 2, 5];
console.log('Plus petite valeur ' +
    t[findMinIndex(t, 0, t.length)]);
console.log('Plus petite valeur parmi les trois dernières ' +
    t[findMinIndex(t, 1, t.length)]);
sortTable(t);
console.log(t);

/**
 * return the index of the minimal value in the array 't' from index
 * 'from' to index 'to' (excluded)
 */
function findMinIndex(t, from, to) {
    var j = from;
    for (let i = from + 1; i < to; i += 1) {
        if (t[j] > t[i]) {
            j = i;
        }
    }
    return j;
}

/**
 * sort the table 't'.
 */
function sortTable(t) {
    var j, s;
    for (let i = 0; i < t.length - 1; i += 1) {
        // Find the index of the minimal value in the unsorted part of
        // the array
        j = findMinIndex(t, i, t.length);
        // Swap the ith minimal value
        s = t[j];
        t[j] = t[i];
        t[i] = s;
    }
}


/* 1.2.1
La variable i n'était pas définis, c'est pour cela que la fonction ne marchait pas.
1.2.2
On aurait pu trouver l'erreur plus facielement en utilisant use strict */