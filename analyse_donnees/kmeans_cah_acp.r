###############################################################################
# FONCTIONS GENERALES                                                         #
###############################################################################

# Charge un fichier dans une table R
# Param?tre :	le nom du fichier (cha?ne de caract?res)
# Sortie :	une table R (data.frame)
charger<-function(F) {T<-read.table(F,header=TRUE, row.names=1); return(T)}


# Centre et r?duit une table R
# Param?tre :	une table R
# Sortie : la table R centr?e r?duite
centreduire <- function(T) {
	N <- nrow(T) ; T1 <- scale(T);
	return(T1*sqrt(N/(N-1)))}


# Arrondit avec 3 d?cimales
# Param?tre :	objet ? arrondir (nombre simple ou tableau)
# Sortie :	objet arrondi
DEC3 <- function(T) {return(round(1000*T)/1000)}


###############################################################################
# FONCTIONS POUR LES k-MEANS                                                  #
###############################################################################

# Directement produit par des fonctions de R :
# on consid?re que "cnh" est un objet de type kmeans
#
# Classes : cnh$cluster
# Cardinaux des classes : cnh$size
# centres de gravit? des classes : cnh$center


# Affichage des classes d'un objet kmeans
# Param?tres :	partition (produite par kmeans),
#		
# Sortie : le vecteur des classes, affichage des classes
kclass <- function(P) {
	k <- length(P$size);
	N <- length(P$cluster);
	print("Composition des classes");
	C <- P$cluster;
	for (i in 1:k) print(C[C==i]);
	}

# Variance des variables (population)
# Param?tre : table des donn?es
# Sortie : tableau des variances
kvariance <- function(T) {
	nobs <- nrow(T);
	nvar <- ncol(T);
	TV <- vector(mode="numeric",nvar);
	names(TV) <- names(T);
	C <- cov(T);
	rap <- (nobs-1)/nobs;
	for (i in 1:nvar) TV[i] <- rap * C[i,i];
	return(TV)}

# Centre de gravit?
# Param?tre : table
# Sortie : coordonn?es du centre de gravit?
kcdg <- function(T) {
	nobs <- nrow(T);
	nvar <- ncol(T);
	CG <- vector(mode="numeric",nvar);
	names(CG) <- names(T);
	for (i in 1:nvar) CG[i] <- sum(T[,i])/nobs;
	return(CG)}


# Calcule le pourcentage d'inertie inter classes d'une partition
# (kmeans)
# Param?tres : table des donn?es
#              partition
#              
# Sortie : le pourcentage d'inertie inter classes
krap_inertie <- function(T,P) {
	nobs <- nrow(T);
	nvar <- ncol(T);
	cdgg <- cdg(T);
	cdgc <- P$centers;
	s <- 0;
	k <- length(P$size);
	for (ik in 1:k) {
		d2 <- sum((cdgc[ik,]-cdgg)^2);
		s <- s + P$size[ik]/nobs*d2;
	}
	it <- sum(variance(T));
        r <- 1000*s/it ; r <- round(r)/10;
        return(r)}

# R?alisation de plusieurs essais et s?lection du meilleur
# Param?tres : table des donn?es,
#              nombre de classes,
#              nombre d'essais
kNessais <- function(T,k,N) {
	res <- kmeans(T,k);
	qres <- rap_inertie(T,res);
	N1 <- N-1;
	for (i in 1:N1) {
		es <- kmeans(T,k);
		q <- rap_inertie(T,es);
		if (q > qres) {
			res <- es;
			qres <- q;
		}
	}
	return(res)}

# Contribution relative des variables ? ?loignement des classes
# Param?tres :	table des donn?es,
#		partition
# Sortie : les contributions relatives (isouvent not?es COR)
kctrcl <- function(T,P) {
	N <- nrow(T) ; M <- ncol(T);
	k <- length(P$size);
	cdgg <- cdg(T);
	cdgc <- P$center;
	ctr <- cdgc;
	for (i in 1:k) {
		s2 <- sum(cdgc[i,]^2);
		for (j in 1:M) ctr[i,j] <- cdgc[i,j]*abs(cdgc[i,j])/s2;
	};
	ctr <- round(1000*ctr);
	return(ctr/10)}


# Contribution relative des classes ? inertie du nuage
# Param?tres :	table des donn?es,
#		partition
# Sortie : les contributions (souvent not?es CTR)
kctrng <- function(T1,P) {
        T <- centreduire(T1);
        N <- nrow(T) ; M <- ncol(T);
	k <- length(P$size);
	C <- P$cluster;
	ctr <- matrix(data=0,nrow=k,ncol=M);
	for (i in 1:N) {
		cli <- C[i];
		for (j in 1:M) ctr[cli,j] <- ctr[cli,j] + T[i,j];
	};
	for (i in 1:k)
		for (j in 1:M) ctr[i,j] <- ctr[i,j]^2/(N*P$size[i]);
	ctrframe <- as.data.frame(ctr);
	names(ctrframe) <- names(T1);
	return(round(1000*ctrframe)/1000)}


# Distance**2 des classes au centre du nuage
# Param?tres :	table des donn?es,
#		partition
# Sortie : les carr?s des distances (souvent not?s RHO2)
krho2 <- function(T,P) {
	k <- length(P$size);
        nobs <- nrow(T);
	nvar <- ncol(T);
	k <- length(P$size);
	cdgg <- cdg(T);
	cdgc <- P$center;
	r <- vector(mode="numeric",k);
	for (i in 1:k) r[i] <- sum((cdgc[i,]-cdgg)^2);
	return(r)}


###############################################################################
# FONCTIONS POUR LA CAH (WARD)                                                #
###############################################################################
	
# CAH - Ward, distance normalis?e entre individus.
# Param?tre :	table R
# Sortie : une hi?rarchie correspond ? la CAH Ward (distance normalis?e)
ward <- function(T) {
	N <- nrow(T);
	T1 <- scale(T);		# pour centrer r?duire uniquement
	T1 <- T1*sqrt(N/(N-1));	# pour centrer r?duire uniquement
	D <- dist(T1,method="euclidean");
	D <- D^2/(2*N); # mise en place de la distance entre classes
        R <- hclust(D,method="ward.D");
        return(R)}

# Directement produit par des fonctions de R :
# on consid?re que "cah" est un objet de type hi?rarchie
#
# Dessin du dendrogramme : plot(cah,hang=-1)
# Codage du dendrogramme : cah$merge
# Indices de niveau : cah$height
# Graphique des indices de niveau : plot(cah$height)

# Coupe un arbre hierarchique.
# Param?tres :	hi?rarchie (produite par hclust),
#		nombre de classes demand?es
# Sortie : le vecteur des classes, affichage des classes
couper <- function(H,k) {
	print("Composition des classes");
	C<-cutree(H,k);
	for (i in 1:k) print(C[C==i]);
	return(C)}

# Calcule le pourcentage d'inertie inter classes d'une partition
# issue d'une classification hi?rarchique
# Param?tres : hi?rarchie (produite par hclust, m?thode de Ward)
#              nombre de classes de la partition
# Sortie : le pourcentage d'inertie inter classes
rap_inertie <- function(H,k) {
            it <- sum(H$height) ; nh <- length(H$label)-1;
            s <- 0;
            j <- nh ; imax <- k-1;
            for (i in 1:imax) {
                 s <- s+H$height[j];
                 j <- j-1;
            };
            p <- 1000*s/it ; p <- round(p)/10;
            return(p)}


# Calcule les cdg  centr?s r?duits des classes.
# Param?tres :	table des donn?es,
#		hi?rarchie,
#		nombre de classes
# Sortie : les coordonn?es des centres de gravit? des classes
cdgcl <- function(T1,H,k) {
        T <- centreduire(T1);
        N <- nrow(T) ; M <- ncol(T);
	C <- cutree(H,k);
	cdg <- matrix(data=0,nrow=k,ncol=M);
	for (i in 1:N) {
		cli <- C[i];
		for (j in 1:M) cdg[cli,j] <- cdg[cli,j] + T[i,j];
	};
	for (i in 1:k)
		for (j in 1:M) cdg[i,j] <- cdg[i,j]/length(C[C==i]);
	cdgframe <- as.data.frame(cdg);
	names(cdgframe) <- names(T1);
	return(cdgframe)}

# Calcule les cdg des classes.
# Param?tres :	table des donn?es,
#		hi?rarchie,
#		nombre de classes
# Sortie : les coordonn?es des centres de gravit? des classes
cdgcl1 <- function(T,H,k) {
        N <- nrow(T) ; M <- ncol(T);
	C <- cutree(H,k);
	cdg <- matrix(data=0,nrow=k,ncol=M);
	for (i in 1:N) {
		cli <- C[i];
		for (j in 1:M) cdg[cli,j] <- cdg[cli,j] + T[i,j];
	};
	for (i in 1:k)
		for (j in 1:M) cdg[i,j] <- cdg[i,j]/length(C[C==i]);
	cdgframe <- as.data.frame(cdg);
	names(cdgframe) <- names(T);
	return(cdgframe)}


# Contribution relative des variables ? ?loignement des classes
# Param?tres :	table des donn?es,
#		hi?rarchie,
#		nombre de classes
# Sortie : les contributions relatives (isouvent not?es COR)
ctrcl <- function(T,H,k) {
	N <- nrow(T) ; M <- ncol(T);
	cdg <- cdgcl(T,H,k);
	ctr <- cdg;
	for (i in 1:k) {
		s2 <- sum(cdg[i,]^2);
		for (j in 1:M) ctr[i,j] <- cdg[i,j]*abs(cdg[i,j])/s2;
	};
	ctr <- round(1000*ctr);
	return(ctr/10)}


# Contribution relative des classes ? inertie du nuage
# Param?tres :	table des donn?es,
#		hi?rarchie,
#		nombre de classes
# Sortie : les contributions (souvent not?es CTR)
ctrng <- function(T1,H,k) {
        T <- centreduire(T1);
        N <- nrow(T) ; M <- ncol(T);
	C <- cutree(H,k);
	ctr <- matrix(data=0,nrow=k,ncol=M);
	for (i in 1:N) {
		cli <- C[i];
		for (j in 1:M) ctr[cli,j] <- ctr[cli,j] + T[i,j];
	};
	for (i in 1:k)
		for (j in 1:M) ctr[i,j] <- ctr[i,j]^2/(N*length(C[C==i]));
	ctrframe <- as.data.frame(ctr);
	names(ctrframe) <- names(T1);
	return(round(1000*ctrframe)/10)}


# Distance**2 des classes au centre du nuage
# Param?tres :	table des donn?es,
#		hi?rarchie,
#		nombre de classes
# Sortie : les carr?s des distances (souvent not?s RHO2)
rho2 <- function(T1,H,k) {
        T <- centreduire(T1);
        N <- nrow(T) ; M <- ncol(T);
	C <- cutree(H,k);
	cdg <- matrix(data=0,nrow=k,ncol=M);
	for (i in 1:N) {
		cli <- C[i];
		for (j in 1:M) cdg[cli,j] <- cdg[cli,j] + T[i,j];
	};
	for (i in 1:k)
		for (j in 1:M) cdg[i,j] <- cdg[i,j]/length(C[C==i]);
	r <- vector(mode="numeric",k);
	for (i in 1:k) r[i] <- sum(cdg[i,]^2);
	return(r)}


# Pouvoir discriminant des variables
# Param?tres :	table des donn?es,
#		hi?rarchie,
#		nombre de classes
# Sortie : les carr?s des distances (souvent not?s RHO2)
pdis <- function(T1,H,k) {
        T <- centreduire(T1);
        N <- nrow(T) ; M <- ncol(T);
	C <- cutree(H,k);
	ctr <- matrix(data=0,nrow=k,ncol=M);
	for (i in 1:N) {
		cli <- C[i];
		for (j in 1:M) ctr[cli,j] <- ctr[cli,j] + T[i,j];
	};
	r <- vector(mode="numeric",M);
	for (i in 1:k)
		for (j in 1:M) ctr[i,j] <- ctr[i,j]^2/(N*length(C[C==i]));
	for (i in 1:M) r[i] <- sum(ctr[,i]) ;
	return(round(1000*r)/10)}




# Contribution des variables ? la s?paration de classes
# Param?tre : les coordonn?es du dip?le (cdg[i,]-cdg[j,])
# Sortie : les contributions des variables ? la s?paration (souvent not?es COD)
codij <- function(dipij) {
	M <- length(dipij);
	cod <- dipij;
	s2 <- sum(dipij^2);
	for (i in 1:M) cod[i] <- dipij[i]^2/s2;
	return(cod)}


# Inertie intra d'une classe
# Param?tres :	table des donn?es,
#		hi?rarchie,
#		nombre de classess
#		num?ro de la classe
iintra <- function(T1,H,k,num) {
	x <- cutree(cah,k);
	cdk=length(x[x==num]);
        return(cdk*sum(cdgcl(T1,H,k)[num,]^2)/nrow(T1))}

		
###############################################################################
# FONCTIONS POUR L'ACP                                                        #
###############################################################################

# ACP norm?e
# Param?tre :	Table R des donn?es
# Sortie :	un objet de type ACP
ACPN<-function(T) {
	resacp <- princomp(T, cor = TRUE, scores = TRUE);
	return(resacp)}

# Fonctions pr?sentes dans R pour interpr?ter une ACP :
# soient "acp" un objet de type acp et T la table des donn?es
#
# coefficients de corr?lation entre les variables cor(T)
# Inertie des axes, axe i : acpn$sdev^2 , acpn$sdev[i]^2
# Nouvelles coordonn?es des individus : acpn$scores
# De l'individu i sur CP j : acpn$scores[i,j]
# Graphique des inerties (valeurs propres) : plot(acp)
# Plan principal : biplot(acp)
# Plan i x j : biplot(acp,c(c1=i, c2=j))


#Tableau des inerties et des pourcentages cumul?s
# Param?tre : r?sultat ACP
# Sortie : tableau des inerties, pourcentages et pourcentages cumul?s
VP <- function(resacp) {
	N <- length(resacp$sdev);
	tab <- matrix(nrow=N,ncol=3);
	s <- sum(resacp$sdev^2);
	s1 <- 0;
	for (i in 1:N) {
		tab[i,1] <- round(100000*resacp$sdev[i]^2)/100000;
		tab[i,2] <- round(100000*resacp$sdev[i]^2/s)/1000;
		s1 <- s1+resacp$sdev[i]^2;
		tab[i,3] <- round(100000*s1/s)/1000;
	};
	return(tab)}


# Corr?lations entre les axes et les variables initiales
# Param?tres :	table R des donn?es
#		r?sultat ACP (produit par princomp)
# Sortie :	la matrice des corr?lations
AXEVAR <- function(T,resacp) {return(cor(T,resacp$scores))}


# Corr?lations entre les k premiers axes et les variables initiales
# Param?tres :	table R des donn?es
#		r?sultat ACP (produit par princomp)
#		nombre axes
# Sortie :	la matrice des corr?lations
AXEVARk <- function(T,resacp,k) {
	return(cor(T,subset(as.data.frame(resacp$scores),select=1:k)))}


# Contribution de la ligne i ? l'inertie de l'axe j
# Param?tres :	r?sultat ACP
#		num?ro ligne
#		num?ro axe
# Sortie :	pourcentage de la contribution
CTRij <- function(resacp,i,j) {
	x <- resacp$scores[i,j]^2/(resacp$n.obs * resacp$sdev[j]^2);
        x <- round(1000*x);
	return(x/10)}


# Tableau des contribution des lignes aux axes
# Param?tres :	r?sultat ACP
#		nombre axes
# Sortie :	tableau des pourcentages des contributions
CTR <- function(resacp, nbax) {
      	matrice <- matrix(nrow=resacp$n.obs,ncol=nbax);
        row.names(matrice) <- row.names(resacp$scores);
        for (j in 1:nbax) 
		for (i in 1:resacp$n.obs) matrice[i,j] <- CTRij(resacp,i,j);
     
       return(matrice)}

# Fonction utilitaire
SOMME2 <- function(resacp) {
	N <- resacp$n.obs ; M <- ncol(resacp$scores);
	s2 <- vector (mode = "numeric", N);
	for (i in 1:N)
		for (j in 1:M) s2[i] <- s2[i] + resacp$scores[i,j]^2;
	return(s2)}


# Cosinus ** 2 des angles de projection
# Param?tres :	r?sultat ACP
#		nombre axes
# Sortie :	tableau des cos2 des angles de projection
COS2TETA <- function(resacp, nbax) {
	N <- resacp$n.obs ; 
	c2teta <- matrix(nrow=N,ncol=nbax);
	row.names(c2teta) <- row.names(resacp$scores);
	s2 <- SOMME2(resacp);
	for (i in 1:N)
		for (j in 1:nbax) c2teta[i,j] <- resacp$scores[i,j]^2 / s2[i];
	return(round(1000*c2teta)/1000)}


# Raccourci pour faire afficher un plan de projection
# Param?tres :	r?sultat ACP
#		premier axe choisi
#		deuxi?me axe choisi	
PLAN <- function(resacp,i,j) {biplot(resacp,c(c1=i,c2=j))}


###############################################################################
# Projections d'une partition (obtenue ici avec hclust) sur un plan factoriel #
# (ici : projection sur le plan principal)                                    #
###############################################################################

# Param?tres : r?sultat de l'acp (renvoy? par princomp),
#              r?sultat de la cah (renvoy? par hclust),
#              nombre de classes de la cah

# Sortie : les ?l?ments des classes projet?s sur le plan principal
#          une couleur par classes

CAHsurACP<-function(acp,cah,k){
    n<-acp$obs
    classe<-cutree(cah,k)
    couleur<-vector("numeric",n)
    # pour avoir la liste des couleurs, on peut raper sous R : colors()
    liste_coul<-c("blue","red", "green", "grey", "orange", "turquoise", "yellow")
    for(i in 1:n){
        couleur[i]<-liste_coul[classe[i]]
    }
    plot (acp$scores[,1],acp$scores[,2], col=couleur)
}

	
	
