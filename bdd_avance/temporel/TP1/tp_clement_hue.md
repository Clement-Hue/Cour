# TP Base de donnée temporelle - Clément Hue
## Exercice: [Valid Time]

### Question 1
le paramètre associé au temps de validité est  __validTime__

### Question 2
le paramètre associé au temps de transaction est hist avec pour valeur __view-wo-overwrite__ pour garder une trace de toute les modifications.

### Question 3
Une nouvelle colonne __VM_VALID__ a été ajouté

### Question 4
Suppression de 'office':
```sql
begin DBMS_WM.DisableVersioning('office'); end;
drop table office;
```
