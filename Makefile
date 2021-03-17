CC = gcc
CFLAGS = -Wall -O0 -g -o
LIBS = tl2/list.c st.h/st.h pl.c

t1:
	
all:
	gcc -Wall -O0 -g -o pl pl.c tl2/list.c st.h/st.h
