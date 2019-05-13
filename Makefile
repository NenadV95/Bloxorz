
CC  	= gcc
CCLIBS	= -lGL -lGLU -lglut -lm
CCFLAGS	= -Wall
PROGRAM	= main
OBJ 	= main.o	\
		init.o	\
		callbacks.o	\
		draw_cuboid.o	\
		moves.o		\
		start_reset.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(PROGRAM): $(OBJ)
	$(CC) -o $@ $^ $(CCLIBS) $(CCFLAGS)


.PHONY: clean

clean:
	rm -f src/*.swp *~ *.swp src/*~ *.o
