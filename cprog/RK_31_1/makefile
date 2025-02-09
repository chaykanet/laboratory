CC := gcc
CFLAGS := -std=c99 -Werror -Wall -g

app.exe: main.o set.o set_io.o set_op.o set.h set_io.h set_op.h
	$(CC) -o $@ $^ -lm

main.o: main.c set.h set_io.h set_op.h
	$(CC) $(CFLAGS) -c $<

set.o: set.c set.h
	$(CC) $(CFLAGS) -c $<

set_io.o: set_io.c set.h set_io.h
	$(CC) $(CFLAGS) -c $<

set_op.o: set_op.c set.h set_op.h
	$(CC) $(CFLAGS) -c $<

.PHONY: clean

clean:
	$(RM) ./*.o ./*.exe