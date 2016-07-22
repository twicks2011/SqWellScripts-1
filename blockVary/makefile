# simple make file
# September 2004
SOURCES=blockVary.c 
PRODUCT=$(HOME)/bin/blockVary



CC=gcc
CFLAGS=-lm -O2 -I$(NR)/include

all: $(PRODUCT)

$(PRODUCT) : $(SOURCES)
	$(CC) $(CFLAGS) -o $(PRODUCT) $(SOURCES)
