# simple make file
# September 2004
SOURCES=clipQuad.c 
PRODUCT=$(HOME)/bin/clipQuad



CC=gcc
CFLAGS=-lm -O2 -I$(NR)/include

all: $(PRODUCT)

$(PRODUCT) : $(SOURCES)
	$(CC) $(CFLAGS) -o $(PRODUCT) $(SOURCES)
