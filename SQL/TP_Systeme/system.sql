/*1 contrainte d'ingérité */
/*1*/
create or replace trigger age_75
before insert on hommePolitique for each row
declare age number(5);
begin 
age := trunc((SYSDATE - :new.datenaissance) / (365));
if age > 75 then
RAISE_Application_error(-20005, 'homme trop vieux');
end if;
end;
/

/*2, obligé de mettre 9 car il y'a déja des personnes ayant plus de 3 mandats, donc ça marche pas*/

alter table hommePolitique
add constraint mandat_Max check (nbmandats <=9); 


/*3*/
create sequence nouveau_HommePolitique;
create or replace trigger inc_HommePolitique
before insert on hommePolitique for each row;
begin 
    select nouveau_HommePolitique.nextval into :new.id From dual;
end if;
end;
/


/*2 les attributs calculés*/

/*1*/
alter table hommePolitique 
add column nbMandatsexercés  ;

/*2 à finir*/

create or replace procedure nb_mandat
compteur number := 0;
begin 
loop 
 select count(*) from mandat where 

exit when
end loop;
end;
/