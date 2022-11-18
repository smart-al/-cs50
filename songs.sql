-- A sql query that list all songs in the database

SELECT name FROM songs;

-- write a SQL query to list the names of all songs in increasing order of tempo

SELECT name FROM songs ORDER BY tempo;

-- write a SQL query to list the names of the top 5 longest songs, in descending order of length

SELECT name FROM songs
ORDER BY duration_ms
DESC LIMIT 5; 

-- write a SQL query that lists the names of any songs that have danceability, energy, and valence greater than 0.75.

SELECT name FROM songs
WHERE danceability > 0.75
AND energy > 0.75
AND valence > 0.75;

-- write a SQL query that returns the average energy of all the songs

SELECT avg(energy) FROM songs;

-- write a SQL query that lists the names of songs that are by Post Malone

SELECT name FROM songs WHERE artist_id = (SELECT id FROM artists WHERE name == 'Post Malone');


-- write a SQL query that returns the average energy of songs that are by Drake

SELECT avg(energy) FROM Songs WHERE artist_id = (SELECT id FROM artists WHERE name == 'Drake');

-- write a SQL query that lists the names of the songs that feature other artists

SELECT name FROM songs WHERE name LIKE '%feat.%';
