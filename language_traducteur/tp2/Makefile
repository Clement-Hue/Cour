FLEX = tp1.lex
exec : cFile
		gcc lex.yy.c -ll

cFile: 
		lex ${FLEX}

clean: 
	rm a.out lex.yy.c
