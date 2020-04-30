CC = gcc
CFLAGS = -W -Wall -g
EXEC =  analyse 
 
SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)
 
 
$(EXEC) : $(OBJS) 
	$(CC) $(CFLAGS)  -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	@rm -f *.a *.o core

cleaner : clean
	@rm $(EXEC)

