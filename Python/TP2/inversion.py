res = []
while True:
    nombre = input("saisir nombre")
    if len(nombre) == 0:
        break
    nombre = int(nombre)
    res.append(nombre)
print(res)
for i in range(0,len(res)//2):
    res[len(res)-1-i], res[i] = res[i],res[len(res)-1-i]
print(res)
    

    

