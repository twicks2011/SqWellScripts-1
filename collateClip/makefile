# simple make file
# September 2004
SOURCES=collateClip.c 
PRODUCT=$(HOME)/bin/collateClip




CFLAGS=-lm -O2 -I$(NR)/include


all: $(PRODUCT)

$(PRODUCT) : $(SOURCES)
	$(CC) $(CFLAGS) -o $(PRODUCT) $(SOURCES)
