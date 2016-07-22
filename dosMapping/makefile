# simple make file
# September 2004
SOURCES=dosMapping.c
PRODUCT=$(HOME)/bin/dosMapping



CC=gcc
CFLAGS=-lm -O2 -I$(NR)/include

#use icc on certain servers
HN:=$(hostname)
ifeq ($(HN),lagavulin)
	CC=icc
endif
ifeq ($(HN),login01)
	CC=icc
endif
ifeq ($(HN),login02)
	CC=icc
endif
ifeq ($(HN),frontend1)
	CC=icc
endif

all: $(PRODUCT)

$(PRODUCT) : $(SOURCES)
	$(CC) $(CFLAGS) -o $(PRODUCT) $(SOURCES)
