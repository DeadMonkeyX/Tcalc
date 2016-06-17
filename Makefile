# Simple make file for my calc prgram

CC=c++
CFLAGS=-Wall
INSTALL=/usr/bin/install -m 755 -c
INSTALLPATH=/usr/local/bin/tcalc

all: tcalc

tcalc: main.cpp
	$(CC) $(CFLAGS)  main.cpp -o $@

install: tcalc
	$(INSTALL) tcalc $(INSTALLPATH)

deinstall:
	rm $(INSTALLPATH)

clean:
	rm tcalc
