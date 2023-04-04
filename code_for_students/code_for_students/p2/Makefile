#****************************************************
# Variables
#****************************************************


CC=gcc
RPCGEN=rpcgen
CFLAGS= -I. -Wall -ggdb
LDFLAGS= -pthread
client = client
server= server
INICIALIZADOR= initializer_sislog

todo : $(client) $(server) $(INICIALIZADOR)

#**************************************************
# Client and server generation
#**************************************************

$(client) : # TODO
	# TODO
	|
	|

$(INICIALIZADOR) : # TODO
	# TODO
	|
	|

$(server) : # TODO
	# TODO
	|
	|

sislog_svc.o : sislog_svc.c sislog.h
	$(CC) $(CFLAGS) -c sislog_svc.c 

servicies.o: servicies.c sislog.h util.h
	$(CC) $(CFLAGS) -c servicies.c

sislog_clnt.o : sislog_clnt.c sislog.h
	$(CC) $(CFLAGS) -c sislog_clnt.c

sislog_xdr.o : sislog_xdr.c sislog.h
	$(CC) $(CFLAGS) -c sislog_xdr.c

client.o : client.c sislog.h util.h 
	$(CC) $(CFLAGS) -c client.c

initializer_sislog.o : initializer_sislog.c util.c util.h sislog.h
	$(CC) $(CFLAGS) -c initializer_sislog.c 

util.o : util.c util.h
	$(CC) $(CFLAGS) -c util.c

sislog.h: sislog.x
	# TODO
	|
	|

#**************************************************
# Utilities
#**************************************************

clean : 
	rm -f *.o	

cleanall: clean
	rm -f sislog_*
	rm -f sislog.h
	rm -f client server initializer_sislog
