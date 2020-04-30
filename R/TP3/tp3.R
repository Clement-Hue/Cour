# 1.1 1
db = read.table("spotify.data")
attach(db)
summary(BPM)
summary(danceability)
boxplot(BPM)
boxplot(danceability)

# 1.1 3
shapire.test(liveness) # ne suit pas une loi normal car p-value < 0.05
shapire.test(danceability) # suit une loi normal car p-value > 0.05
apply(db,2,sd) # calcul l'écart type de toute les colonnes (2 indique les colonnes)

# 1.2 1
cor(db) # la valence est plus lié à la danceability que l'énergie
pairs(db)

(mean((danceability - mean(danceability))*(acousticness - mean(acousticness))))/sqrt((mean((danceability - mean(danceability))**2)) * (mean((acousticness - mean(acousticness))**2)));

# 1.2.5
# les variables sont liés si la corrélation est proche de 1
 corelation <- function(data_frame ){
   corelation <- cor(data_frame)
   for (i in 1:ncol(data_frame)) {
     for(j in i:ncol(data_frame)){
       if (abs(corelation[i,j]) > 0.2){
         print(corelation[i,j])
         print(colnames(db[i]))
         print(colnames(db[j]))
       }
     }
   }
 }

# 2
x <- rnorm(60)
y <- -3.14*x + 7.04
z <- -exp(x)
t <- x**2
plot(x,t)
cor(x,t)
cor(x,y, method="spearman")
cor(x,y, method="kendall")
# on peut avoir en pearson si c'est linéaire
# les autres ont peu avoir confiance si c'est monotonne