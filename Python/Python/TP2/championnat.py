def championnat(N):
    if N%2 == 0:
        Ni = N
    else:
        Ni = N + 1
    Nb_jour = Ni - 1
    Nb_match = Ni //2
    for J in range(1,Nb_jour+1):
        print("jour n*",J)
        for M in range(1,Nb_jour+1):
            print("match n*",M)
            if M == 1 and N%2 != 0:
                print("pas de match")
                continue
            elif M==1 and N%2 ==0:
                print("équipe qui reçoit : n*",Ni)
            elif M>1:
                print("équipe qui reçoit : n*",  ((J+M-2)%(Ni - 1)) +1 )
            print("équie en déplacement : n*",((J-M+Ni-1)%(Ni-1)) + 1)
        
                  

N = int(input("entrer le nombre d'équipe"))
championnat(N)
