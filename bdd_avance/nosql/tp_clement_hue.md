# TP NoSQL - Clément Hue

1. Ami de Gabriel:
```sql
select h1.name from Highschooler h1
join Friend f1 on f1.ID1 = h1.ID
join Highschooler h2 on h2.ID = f1.ID2
where h2.name = 'Gabriel';
```
```cypher
match (:Highschooler{name:'Gabriel'}) - [:IS_FRIEND_OF] - (p) return p
```

