# simple make file
# September 2004
SOURCES=masterCollate.c 
PRODUCT=$(HOME)/bin/masterCollate



CC=gcc
CFLAGS=-lm -O2 -I$(NR)/include

all: $(PRODUCT)

$(PRODUCT) : $(SOURCES)
	$(CC) $(CFLAGS) -o $(PRODUCT) $(SOURCES)
