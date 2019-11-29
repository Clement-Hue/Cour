def facto(n):
    if n == 0:
        return 1
    return n*facto(n-1)

n = int(input("entrer une valeur de n"))
print(facto(n))
