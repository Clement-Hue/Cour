res = []
for i in range(3):
	word = input("entrer mot")
	test = ""
	for i in range(len(word)-1,-1,-1):
		test+=  word[i]
	if word == test:
		res.append(test)
print(res)

