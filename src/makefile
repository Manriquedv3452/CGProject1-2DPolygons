OBJECTS=proyect1.o
OUTPUT=project1
FNAME=main.c
FLEXNAME=flex.l
FLEXOUTPUT=lex.yy.c

CFLAGS=-I/usr/local/Mesa-18.1.5/include
#LDLIBS=-lX11 -lglut -lMesaGLU -lMesaGL -lm -lXext -lXmu
#LDLIBS=-lX11-lglut -lGLU -lGL -lm -lXext -lXmu
LDLIBS = -lGL -lGLU -lglut -lm -lfl
LDFLAGS=-L/usr/local/Mesa-18.1.5/lib -L/usr/include/X11/Xlib.h
#cc $(CFLAGS) $(LDFLAGS) $(LDLIBS) -o $(OUTPUT) $(OBJECTS)

$(OUTPUT): $(OBJECTS)
	flex $(FLEXNAME)
	cc $(FNAME) $(FLEXOUTPUT) $(LDLIBS) -o $(OUTPUT)

$(OBJECTS): structs.h

clean:
	rm -f *.o
	rm -f $(OUTPUT)
