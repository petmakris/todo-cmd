CC 	= gcc
CFLAGS 	= -Wall -g3 -c -fPIC
LFLAGS 	=
LIBS 	= 
INCS 	= 

# SOURCES = src/menu.c src/list.c src/todo-getsize.c src/todo.c 
OBJECTS = src/menu.o src/list.o src/todo.o
OBJECTS_TS = src/todo-getsize.o

all: todo todo-getsize

todo: $(OBJECTS) 
	$(CC) $(LFLAGS) $(OBJECTS) -o todo

todo-getsize: $(OBJECTS_TS)
	$(CC) $(LFLAGS) $(OBJECTS_TS) -o todo-getsize

.c.o:
	$(CC) $(CFLAGS) $(INCS) $<  -o $@


clean:
	$(RM) $(OBJECTS) $(OBJECTS_TS) todo todo-getsize


install: 
	install -m 0755 todo todo-getsize /usr/local/bin
	install -m 0644 bashrc ~/.console-todo.config
	
uninstall:
	rm -f /usr/local/bin/todo /usr/local/bin/todo-getsize
	rm -f ~/console-todo.config

.PHONY: depend clean install uninstall


