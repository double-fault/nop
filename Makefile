all: ass.o
	g++ main.cpp -c -g -std=c++17 -O3 -fno-exceptions -fno-rtti -Wall -Werror -fno-omit-frame-pointer -isystem benchmark/include -Lbenchmark/build/src -lbenchmark -lpthread 
	g++ main.o ass.o -o a.out -g -std=c++17 -O3 -fno-exceptions -fno-rtti -Wall -Werror -fno-omit-frame-pointer -isystem benchmark/include -Lbenchmark/build/src -lbenchmark -lpthread 

ass.o: ass.S
	as ass.S -o ass.o

ass.S: gen_ass.cpp
	g++ gen_ass.cpp
	./a.out > ass.S

clean:
	rm *.o *.out
