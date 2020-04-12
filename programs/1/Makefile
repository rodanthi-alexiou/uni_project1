# paths
LIB = ../../lib
INCLUDE = ../../include

# compiler
CC = gcc

# Compile options. Το -I<dir> λέει στον compiler να αναζητήσει εκεί include files
CFLAGS = -Wall -Werror -g -I$(INCLUDE)
LDFLAGS = -lm

# Αρχεία .o
OBJS = original.o  

# Το εκτελέσιμο πρόγραμμα
EXEC = original

# Ορίσματα για make run
ARGS = < ../../misc/words/words-10


$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) $(LDFLAGS)

# Για να φτιάξουμε το k08.a, τρέχουμε το make στο lib directory.

clean:
	rm -f $(OBJS) $(EXEC)

run: $(EXEC)
	./$(EXEC) $(ARGS)
