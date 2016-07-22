# simple make file
# September 2004
SOURCES=blockVary.c 
PRODUCT=$(HOME)/bin/blockVary



CC=gcc
CFLAGS=-lm -O2 -I$(NR)/include


#use icc on certain servers
HN:=$(hostname)
ifeq ($(filter $HN,$(lagavulin) $(login01) $(login02)  $(frontend1)),)
	CC=icc
endif

all: $(PRODUCT)

$(PRODUCT) : $(SOURCES)
	$(CC) $(CFLAGS) -o $(PRODUCT) $(SOURCES)
