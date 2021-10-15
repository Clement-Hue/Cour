# TP Base de donnée spatial Clément Hue

## Pour commencer

### Question 1
```sql
SELECT ST_IsSimple(ST_GeomFromText('POLYGON((1 2, 3 4, 5 6, 1 2))'));
```
Renvoie False
```sql
SELECT ST_IsSimple(ST_GeomFromText('POLYGON((1 2, 3 4, 3 2, 1 2))'));
```
Renvoie True. 
La fonction isSimple renvoie True si le polygonne n’a pas d’intersection.
```sql
SELECT ST_IsValid(ST_GeomFromText('LINESTRING(0 0, 1 1)'));
```
Renvoie True
```sql
SELECT ST_IsValid(ST_GeomFromText('POLYGON((0 0, 1 1, 2 1, 5 4, 0 0))')) ;
```
Renvoie False. La fonction isValid renvoie True si l’objet géométrique est bien formé en 2D

## OpenStreetMap

### Question 2
 Les attributs communs sont gid, osm_id , code, fclass sauf pour la table quartiers.

### Question 3
```sql
SELECT count(*)  from buildings where  ST_IsValid(geom)
```
Renvoie 79425 buildings valide
```sql
SELECT count(*)  from roads where  ST_IsValid(geom)
```
Renvoie 25875 routes valides

### Question 4
```sql
delete from roads where «table-name»is NULL;
```

Pour toute les tablesil reste 1923 buildings, 11720 roads, 4067 pois, 11 quartiers, 365 railways, 11720 roads, 131 waterways

### Question 5
```sql
select name, geom from buildings where type = 'university';
```
### Question 6

```sql
select count(*) from roads where name = 'Route de Saint-Joseph';
```
Il y’a 97 portions de la route de siant joseph.

## Selection spatial

### Question 1

- Cross détermine si les objets géométrique ont quelques points en commun.
- Intersect détermine si les objets géométrique ont occupe une même partie de l’espace
- Overlap est comme intersect mais partiellement. (un objet ne contient pas l’autre entièrement).

```sql
SELECT *FROM railways, quartierswhere quartiers.nom = 'Ile de Nantes'and ST_Crosses(railways.geom, quartiers.geom);
```
### Question 2

```sql
select ST_Relate((select geom  from buildingswhere name = 'Château des Ducs de Bretagne'), (
select geom from buildings where name = 'Tour des Espagnols') )
```
Renvoie FF2F1121

### Question 3
Version avec __st_touches__
```sql
select b1.name, b2.name from buildings b1, buildings b2
where ST_TOUCHES(b1.geom, b2.geom);
```
_Durée_: 551ms

Version avec __st_relate__
```sql
select b1.name, b2.name from buildings b1, buildings b2
where ST_RELATE(b1.geom, b2.geom, 'F***T****');

```
_Durée_: 15 927ms

### Question 4

Retourne les tronçons de rue du Centre ville
```sql
select r.name, r.geom from roads r where st_intersection( (
    select geom from quartiers q where q.nom = 'Centre Ville'
    ), r.geom) is not Null and r.fclass = 'trunk';
```
