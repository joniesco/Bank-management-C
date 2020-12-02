CC=gcc
FLAG=-Wall
AR=ar
fPIC=-fPIC

all: myBankd myBanks mains maind
	
myBankd: myBankd.so
myBanks: myBanks.a
mains: main.o myBanks.a
	$(CC) $(FLAG) -g -o mains main.o myBanks.a
maind: main.o myBankd.so
	$(CC) $(FLAG) -g -o maind main.o ./myBankd.so
myBanks.a: myBank.c 
	$(AR) rcs -o myBanks.a myBank.o
myBankd.so: myBank.o
	$(CC) -shared myBank.o  -o myBankd.so
myBank.o:myBank.c myBank.h
	$(CC) $(FLAG) $(fPIC) -g -c  myBank.c
main.o:myBank.h main.c
	$(CC) $(FLAG) -g -c main.c
.PHONY: myBanks myBankd clean all
clean:
	rm -f *.o *.a *.so mains maind
	

