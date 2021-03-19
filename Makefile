CC = gcc
CFLAGS = -Wall -O0 -g -o
LIBS = tl2/list.c st.h/st.h pl.c
TESTS = ./t1 ./t2 ./t3

tt1:
	$(CC) $(CFLAGS) t1 t1.c $(LIBS)

tt2:
	$(CC) $(CFLAGS) t2 t2.c $(LIBS)

tt3:
	$(CC) $(CFLAGS) t3 t3.c $(LIBS)

test: tt1 tt2 tt3
run:
	./t1
	./t2
	./t3

clear:
	rm $(TESTS)
