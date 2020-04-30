# 1
plot(db)

Price.1970.log <- log(Price.1970)
Price.1980.log <- log(Price.1980)

plot(Price.1970.log,Price.1980.log)
regression <- lm(Price.1980.log ~ Price.1970.log)
summary(regression)
# la droite ax+b, a = 0.95465 et b = 1.13231
# R² Multiple R-squared <- 0.9496
regression$coefficients # récuépére les coefficients a et b
regression$residuals # les résidues
regression$fitted.values # y chapeau (valeur prédite)
abline(regression$coefficients[1], regression$coefficients[2]) # trace la droite de régression
# linéaire sur le nuage de poitn
plot(regression$fitted,regression$residuals)
shapiro.test(regression$residuals) #la p-value est de 0.5348, donc H0 est valide: les résidus
# suivent une loi normal
qqnorm(regression$residuals)
qqline(regression$residuals)
# les résidus sont linéaire par conséquent il y'a normalité ???



