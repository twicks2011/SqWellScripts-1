# simple make file
# September 2004
SOURCES=dosMapping.c
PRODUCT=$(HOME)/bin/dosMapping



CC=gcc
CFLAGS=-lm -O2 -I$(NR)/include

all: $(PRODUCT)

$(PRODUCT) : $(SOURCES)
	$(CC) $(CFLAGS) -o $(PRODUCT) $(SOURCES)
