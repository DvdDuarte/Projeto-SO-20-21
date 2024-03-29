all: server client

server: bin/aurrasd

client: bin/aurras

bin/aurrasd: obj/aurrasd.o
	gcc -g obj/aurrasd.o -o bin/aurrasd
obj/aurrasd.o: src/aurrasd.c
	gcc -Wall -g -c src/aurrasd.c obj/aurrasd.o
bin/aurras: obj/aurras.o
	gcc -g obj/aurras.o -o bin/aurras
obj/aurras.o: src/aurras.c
	gcc -Wall -g -c src/aurras.c obj/aurras.o
clean:
	rm obj/* tmp/* bin/{aurras,aurrasd}
test:
	bin/aurras
	bin/aurras status
	bin/aurras transform samples/sample-1.m4a output.m4a alto eco rapido
