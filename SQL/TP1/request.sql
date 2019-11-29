/* 1 I Liste des tables créées par l’utilisateur MONDIAL */
select table_name from user_tables;

TABLE_NAME
AIRPORT
BORDERS
CITY
CITYLOCALNAME
CITYOTHERNAME
CITYPOPS
CITYXML
CONTINENT
COUNTRY
COUNTRYLOCALNAME
COUNTRYOTHERNAME
COUNTRYPOPS
DESERT
ECONOMY
ENCOMPASSES
ETHNICGROUP
GEO_DESERT
GEO_ESTUARY
GEO_ISLAND
GEO_LAKE
GEO_MOUNTAIN
GEO_RIVER
GEO_SEA
GEO_SOURCE
ISLAND
ISLANDIN
ISMEMBER
LAKE
LAKEONISLAND
LANGUAGE
LOCATED
LOCATEDON
MERGESWITH
MOUNTAIN
MOUNTAINONISLAND
ORGANIZATION
POLITICS
POPULATION
PROVINCE
PROVINCELOCALNAME
PROVINCEOTHERNAME
PROVPOPS
RELIGION
RIVER
RIVERONISLAND
RIVERTHROUGH
SEA 

/* 2 I Nombre de tables crées par l’utilisateur MONDIAL ;*/

select count(table_name) from user_tables

COUNT(TABLE_NAME)
47 

/* 3 I Liste des continents et de leur superficie, triés par superficie décroissante ;*/

select * from continent
order by area DESC;

NAME	AREA
Asia 	44579000
America 	42075000
Africa 	30221000
Europe 	9938000
Australia/Oceania 	8600000 

/* 4 I Nom et ville de fondation des cinq organisations mondiale contenant le plus de membress ;*/

/* 5 I Liste des villes dans lesquelles au moins deux organisations mondiales ont été fondées ; */

select city.name from city
join organization on organization.city = city.name
group by city.name
having count(city.name) >= 2

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

/* 6 I Quelles sont les langues parlées et les régimes politiques présents dans chaque continents ? */

/* 7 I Quelles sont les organisations crées entre 1900 et 1950 en Europe */
select name from organization
where established between to_date('1900','YYYY') and to_date('1950','YYYY')

NAME
Bank for International Settlements
Commonwealth
Council of Europe
Food and Agriculture Organization
Franc Zone
International Bank for Reconstruction and Development
International Chamber of Commerce
International Civil Aviation Organization
International Court of Justice
International Federation of Red Cross and Red Crescent Societies
International Labor Organization
International Maritime Organization
International Monetary Fund
International Organization for Standardization
League of Arab States
North Atlantic Treaty Organization
Secretariat of the Pacific Community
United Nations
United Nations Educational, Scientific, and Cultural Organization
United Nations High Commissioner for Refugees
United Nations Military Observer Group in India and Pakistan
United Nations Relief and Works Agency for Palestine Refugees in the Near East
United Nations Security Council
United Nations Truce Supervision Organization
World Federation of Trade Unions
World Health Organization
World Meteorological Organization 

/* 8 I Quels sont les pays traverses par le Danube, */
