showC: readFile
	cat progC.txt

readFile: exec
	./a.out < progfactV2.txt 

exec: yacc 
	gcc y.tab.c -ll

lex:
	flex tp3.l

yacc: lex
	yacc -d tp3.y
