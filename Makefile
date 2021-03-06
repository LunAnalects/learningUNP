#It's not for building this library, just a makefile for some tests

#
LIB = util/server_process.c util/utility.c signal/unp_signal.c

OCLI = client.c
OSER = server.c
SRCDIR = ./server_client/
CLI = $(SRCDIR)$(OCLI)
SER = $(SRCDIR)$(OSER)
CLIOBJ =  $(CLI:%.c=.o)
SEROBJ =  $(SER:%.c=.o)
SRC = $CLI $SER
EXE = $(SRC:%.c=%)

OUTDIR = ./bin/
CLIEXE = $(CLI:%.c=%)

CC = gcc
CFLAGS = -Wall -std=c99 -I .
CXXFLAGS = $(CFLAGS)
DUMPFLAGS = -Wall -std=c99 -I. 

#----------------------------------------------
no:$(EXE)
	$(CC) $(CFLAGS) -o $(OUTDIR)$@ $(SRC)


client:$(CLI)
	$(CC) $(CFLAGS) -o $(OUTDIR)$(CLIEXE) $(CLI) $(LIB)


server:$(SER)
	$(CC) $(CFLAGS) -o $(OUTDIR)$@ $(SER) $(LIB)


depend:
	makedepend $(CXLAGS) -Y $(LIB) $(SRC);


clean:

archive:

CFL =
OLEVEL =  
coredump:
	$(CC) 
# DO NOT DELETE

util/server_process.o: util/server_process.h
util/utility.o: util/utility.h
signal/unp_signal.o: signal/unp_signal.h
