# 1
attach(db)
summary(db)

#1.2
table(Marque,Prix)
mosaicplot(Marque,Prix)
assocplot(table(Marque,Prix))
#chi2
chisq.test(Marque,Prix)

contingence = function(x,y ){
  N=length(y)
  matrice <- matrix(nrow = length(levels(x)), ncol =length(levels(y)))
  for (i in 1:length(levels(x))){
    for (j in 1:length(levels(y))){
      matrice[i,j] <- (table(x)[i] * table(y)[j]) / N
    }
  }
  return(matrice)
}

contingence(Marque,Prix)

# 1.4
khiDeux = function(x,y) {
  theorique <- contingence(x,y)
  reel <- table(x,y)
  somme <- 0
  for (i in 1:length(levels(x))){
    for (j in 1:length(levels(y))){
      somme <- somme + ((reel[i,j] - theorique[i,j])**2 ) / theorique[i,j]
    }
  }
  return(somme)
}

Cramer = function(x,y){
  N <- length(x)
  column <- length(levels(x))
  row <- length(levels(y))
  khi_deux = khiDeux(x,y)
  cramer<-(khi_deux/(N*(min(row,column)-1)))**0.5
  return(cramer) 
}

khiDeux(Marque,Prix)
khiDeux(Marque,Photo)
Cramer(Marque,Prix)
# p-value < 0,05: on accepte H0
chisq.test(Marque,Prix)
