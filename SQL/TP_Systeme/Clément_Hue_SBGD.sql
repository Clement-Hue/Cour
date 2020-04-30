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


/* 2 */
CREATE OR REPLACE PROCEDURE RENSNBMANDAT IS
BEGIN

    UPDATE HOMMEPOLEUROPE SET nbmandat=(select count(*) from Mandat where Mandat.NOHP = HOMMEPOLEUROPE.id)

END RENSNBMANDAT;

/*3*/
SELECT * FROM DBA_PROCEDURES WHERE OBJECT_NAME='RENSNBMANDAT' ;

/*4*/
CREATE OR REPLACE TRIGGER MAJNBMANDATS
AFTER INSERT ON MANDAT
FOR EACH ROW
DECLARE newnb INT;
BEGIN
    SELECT count(*)INTO newnb FROM MANDAT WHERE NOHP=:new.nohp;

    UPDATE HOMMEPOLITIQUE SET NBMANDATS = newnb WHERE ID=:new.nohp;
END;

/*5*/
SELECT * FROM DBA_TRIGGERS WHERE TRIGGER_NAME='MAJNBMANDATS';

/*IV Les vues */

/*1*/
CREATE VIEW HOMPOLEUROPE AS
    SELECT * FROM HOMMEPOLITIQUE
    INNER JOIN MANDAT ON HOMMEPOLITIQUE.ID = MANDAT.NOHP
    INNER JOIN ENCOMPASSES ON MANDAT.PAYS=ENCOMPASSES.COUNTRY
    WHERE ENCOMPASSES.CONTINENT="Europe" AND MANDAT.FIN> (SELECT SYSTIMESTAMP FROM dual);

/*2*/
SELECT * FROM DBA_VIEWS WHERE VIEW_NAME = 'HOMMEPOLEUROPE';

/*3*/
CREATE OR REPLACE TRIGGER del_vue
    INSTEAD OF DELETE ON HOMPOLEUROPE FOR EACH ROW
BEGIN
    DELETE FROM MANDAT WHERE MANDAT.NOHP=:old.id;

/*4*/
CREATE TABLE opecountry (id INT PRIMARY KEY, typeop VARCHAR(25),userop VARCHAR(25),dateop DATE);

CREATE OR REPLACE TRIGGER log_country AFTER INSERT OR UPDATE OR DELETE ON COUNTRY
    DECLARE typeop opecountry.typeop%type;
    userop opecountry.userop%type;
    idop opecountry.id%type;
    dateop opecountry.dateop%type;
BEGIN
    SELECT USERNAME INTO userop FROM USER_USERS;
    SELECT SYSTIMESTAMP INTO dateop FROM dual;
    CASE
        WHEN INSERTING THEN
            typeop:="INSERT";
        WHEN UPDATING THEN
            typeop:="UPDATE";
        WHEN DELETING THEN
            typeop:="DELETE";
    SELECT MAX(id)into idop FROM opecountry;
    idop:=idop+1;
    INSERT INTO opecountry VALUES(idop,typeop,userop,dateop);
    END




/* chap 3*/
/*1*/
create user michel identified by 1234;
/* 2 */
select * from USER_TAB_PRIVS_RECD
/* 3 */
create role Potion;
grant select on PotinsDePoliticiens  to Potion with grand option;

select * from ROLE_SYS_PRIVS;

