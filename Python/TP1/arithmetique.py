def est_divisible_par(n,k):
    if n%k == 0:
        return True
    else:
        return False

def est_paire(entier):
    if est_divisible_par(entier,2):
        return True
    else:
        return False

def est_compris_dans(a,b,c):
    if b <= a <= c:
        return True
    else:
        return False



print("divisiblité de 5 par 3: ", est_divisible_par(5,3))
print("divisibilité de 6 par 2: ",est_divisible_par(6,2))
print("divisibilité de 9 par 3: ",est_divisible_par(9,3))
print("2 est-il paire ?",est_paire(2))
print("4 est-il paire ?",est_paire(4))
print("3 est-il paire ?",est_paire(3))
print("7 est-il paire ?",est_paire(7))
print("5 est il compris entre 2 et 10:",est_compris_dans(5,2,10))
