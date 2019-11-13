all:
	gcc -mpreferred-stack-boundary=2 -march=i386 -o server ca647_server.c -lpthread
	gcc -o client ca647_client.c

clean:
	rm server
	rm client
