/* 1 I Liste des tables créées par l’utilisateur MONDIAL */
select table_name from user_tables;


/* 2 I Nombre de tables crées par l’utilisateur MONDIAL ;*/

select count(table_name) from user_tables;

"""
COUNT(TABLE_NAME)
47 
"""

/* 3 I Liste des continents et de leur superficie, triés par superficie décroissante ;*/

select * from continent
order by area DESC;

"""
NAME	AREA
Asia 	44579000
America 	42075000
Africa 	30221000
Europe 	9938000
Australia/Oceania 	8600000 
"""

/* 4 I Nom et ville de fondation des cinq organisations mondiale contenant le plus de membress ;*/
select ISMEMBER.Organization, city ,count(*) as nb_membre from ISMEMBER 
join ORGANIZATION on ORGANIZATION.abbreviation = ISMEMBER.organization
group by ISMEMBER.Organization, city
order by nb_membre DESC 
FETCH NEXT 5 ROWS ONLY;

 """
 ORGANIZATION	CITY	NB_MEMBRE
UPU 	Bern 	227
IOC 	Lausanne 	202
UNESCO 	Paris 	202
Interpol 	Lyon 	201
FAO 	Roma 	194 
"""

/* 5 I Liste des villes dans lesquelles au moins deux organisations mondiales ont été fondées ; */

select city.name from city
group by city.name
having count(city.name) >= 2;


/* 6 I Quelles sont les langues parlées et les régimes politiques présents dans chaque continents ? */

select Continent, language.name, POLITICS.Government from Encompasses
join LANGUAGE on LANGUAGE.Country = Encompasses.Country
join POLITICS on POLITICS.Country = Encompasses.Country


/* 7 I Quelles sont les organisations crées entre 1900 et 1950 en Europe */
select name from organization
where established between to_date('1900','YYYY') and to_date('1950','YYYY');


/* 8 Quels sont les pays traverses par le Danube, */


/*9 liste des fleuves de France*/ 

select distinct river.name from river
join geo_sea on geo_sea.sea = river.sea
where country = 'F'


/*10 Liste des villes et éventuellement des organisations qui ont été fondées*/

select CITY.name as city, ORGANIZATION.name as organization from CITY
left join ORGANIZATION on CITY.name = ORGANIZATION.city

/*11 Liste des continents et de leur superficies, trié par continent décroissant et superficie croissante*/

select * from continent
order by name DESC, area ASC

"""
NAME	AREA
Europe 	9938000
Australia/Oceania 	8600000
Asia 	44579000
America 	42075000
Africa 	30221000 
"""

/*12 Liste des pays ayant une croissance démographique supérieur à 0 ou un PIB supérieur à 1000*/

select COUNTRY.name, GDP, population_growth from COUNTRY
join POPULATION on POPULATION.country = COUNTRY.code
join ECONOMY on ECONOMY.country = COUNTRY.code
where population_growth >0 or GDP > 1000

/*13 liste des organisations regroupant plus de 100 pays, avec la population totale de ceux-ci*/

select  Organization, Sum(Population) from ISMEMBER
join COUNTRY on COUNTRY.Code = ISMEMBER.Country
group by  Organization
having count(Country) > 100

/*14 I Liste des pays européens avec leur plus haute montagne.*/

/* 15 I Liste des pays dans lesquels toutes les religions sont pratiquées */

/*16 I Liste des affluents directs du Nil ainsi que les affluents de ses affluents */

/* 17 I Liste des pays frontaliers de la France, triés par population décroissante */

select Country2 from Borders
join POPULATION on POPULATION.Country = Borders.Country2
where Country1 = 'F'
order by population_growth DESC 


/* 18 I Longueur de la frontière française */

select sum(length) from Borders
where country1 = 'F'

/* 19 I Nombre de voisins de chaque pays d’Europe */

select  country1, count(country2) from Borders
group by country1

/* 20 I Liste des pays qui partagent une même montagne. */

select mountain from geo_mountain
group by mountain
having count(mountain) >=2

/* 21 I Liste des pays ayant une croissance démographique supérieure à 0 mais un PIB inférieur à 1000.*/

select COUNTRY.name, GDP, population_growth from COUNTRY
join POPULATION on POPULATION.country = COUNTRY.code
join ECONOMY on ECONOMY.country = COUNTRY.code
where population_growth >0 and GDP > 1000

/* 22 I Quels sont les pays frontaliers avec la France, */

select Country2 from Borders
join POPULATION on POPULATION.Country = Borders.Country2
where Country1 = 'F'

/* 23 I Liste des noms de villes partagés par au moins deux pays */

select Name from City
group by Name
having count(name) >=2

/* 24 I Liste des pays qui ne sont bordés par aucune mer,*/

select code from country
where code not in (select Country from Geo_Lake)

/* 25 I Quelles sont les langues parlées et les régimes politiques présents dans chaque continents ?*/
select Continent, language.name, POLITICS.Government from Encompasses
join LANGUAGE on LANGUAGE.Country = Encompasses.Country
join POLITICS on POLITICS.Country = Encompasses.Country

/*26 I Liste des fleuves de France (c’est-à-dire les rivières de France qui se jettent dans la mer) */

select distinct river.name from river
join geo_river on geo_river.river = river.name
where country = 'F' and sea is not null

/* 27 I Quels sont les pays qui ont acquis leur indépendance au XIXeme siècle */

select Country from politics
where independence between  to_date('1800','YYYY') and to_date('1900','YYYY');

/* 28 I Liste des organisations dont tous les pays membres sont européens*/

select Name from Organization
join Encompasses on Encompasses.country = Organization.country
where continent = 'Europe'

/*29 I Liste des pays à cheval sur plusieurs continents ; */

select country from encompasses
group by country
having count(country) >= 2

/*30 I Liste des pays du continent européen qui comptent moins de 10 habitants par km */

select country.name from country
join encompasses on encompasses.country = country.code
where population / area < 10 and continent = 'Europe'

/*31 I Dans quels pays partiellement francophone la langue française est-elle la plus parlée ? (les 3 premiers) */

select country.name from language
join country on country.code = language.country
where language.name = 'French' and language.percentage < 90
order by language.percentage DESC
FETCH NEXT 3 ROWS ONLY


/*32 I Liste des pays du continent européen qui comptent moins de 10 habitants par km */

select country.name from country
join encompasses on encompasses.country = country.code
where population / area < 10 and continent = 'Europe'

/*33 I Quelles sont les trois religions les plus pratiquées sur chaque continent ? */

/* 34 I Quels sont les trois pays les plus pauvres*/

select COUNTRY.name  from COUNTRY
join ECONOMY on ECONOMY.country = COUNTRY.code
order by GDP ASC
FETCH NEXT 3 ROWS ONLY


/* 35 I liste de tous les pays ayant une croissance démographique supérieure à 0 mais un PIB inférieur */

select COUNTRY.name, GDP, population_growth from COUNTRY
join POPULATION on POPULATION.country = COUNTRY.code
join ECONOMY on ECONOMY.country = COUNTRY.code
where population_growth >0 and GDP > population_growth
