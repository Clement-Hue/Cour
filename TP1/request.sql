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

"""
NAME
Georgetown
Abidjan
London
Colombo
Moskva
Genève
Bruxelles
Jeddah
New York
Washington
Den Haag
Wien
Paris
Jakarta
Roma 
"""

/* 6 I Quelles sont les langues parlées et les régimes politiques présents dans chaque continents ? */

select Continent, language.name, POLITICS.Government from Encompasses
join LANGUAGE on LANGUAGE.Country = Encompasses.Country
join POLITICS on POLITICS.Country = Encompasses.Country


/* 7 I Quelles sont les organisations crées entre 1900 et 1950 en Europe */
select name from organization
where established between to_date('1900','YYYY') and to_date('1950','YYYY');


/* 8 I Quels sont les pays traverses par le Danube, */


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

select  Organization from ISMEMBER
join COUNTRY on COUNTRY.Code = ISMEMBER.Country
group by  Organization
having count(Country) > 100
