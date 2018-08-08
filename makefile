CC 	= gcc
CFLAGS 	= -Wall -g3 -c -fPIC
LFLAGS 	=
LIBS 	= 
INCS 	= 

OBJECTS = src/list.o src/todo.o
OBJECTS_TS = src/todos-size.o

all: todo todo-getsize

todo: $(OBJECTS) 
	$(CC) $(LFLAGS) $(OBJECTS) -o todo

todo-getsize: $(OBJECTS_TS)
	$(CC) $(LFLAGS) $(OBJECTS_TS) -o todos-size

.c.o:
	$(CC) $(CFLAGS) $(INCS) $<  -o $@

clean:
	$(RM) $(OBJECTS) $(OBJECTS_TS) todo todos-size


install: all 
	install -m 0755 todo todos-size /usr/local/bin
	
uninstall:
	rm -f /usr/local/bin/todo /usr/local/bin/todos-size

.PHONY: depend clean install uninstall


