def hanoi(n,D,A,I):
	if n<=0:
		return
	hanoi(n-1,D,I,A)
	print("disque",n,"part de",D,"à",A)
	hanoi(n-1,I,A,D)

hanoi(10,1,3,2)
