# simple make file
# September 2004
SOURCES=multiAverage.c 
PRODUCT=$(HOME)/bin/multiAverage_sqW




CFLAGS=-lm -O2 -I$(NR)/include




all: $(PRODUCT)

$(PRODUCT) : $(SOURCES)
	$(CC) $(CFLAGS) -o $(PRODUCT) $(SOURCES)
