
# All the stuff
all:	predictors

# executable 
predictors:	driver.o perceptron.o
	g++ -g -Wall -std=c++11 driver.o perceptron.o -o predictors

# driver obj
driver.o:	driver.cpp
	g++ -g -Wall -std=c++11 -c driver.cpp

# perceptron
perceptron.o:	perceptron.cpp
	g++ -g -Wall -std=c++11 -c perceptron.cpp

# trash the exe and objs
clean:
	rm -f *.o predictors


#tests --make sure you comment this out before turning in the assignment
test:	predictors
	./predictors traces/short_trace1.txt output/short1_extra.txt
	./predictors traces/short_trace2.txt output/short2_extra.txt
	./predictors traces/short_trace3.txt output/short3_extra.txt
	./predictors traces/long_trace1.txt output/long1_extra.txt
	./predictors traces/long_trace2.txt output/long2_extra.txt
	./predictors traces/long_trace3.txt output/long3_extra.txt
#	./predictors traces/longestTrace.txt output/longest_extra.txt	
	
# debug
gdb:	predictors
	gdb ./predictors

# valgrind
valg:	predictors
	valgrind ./predictors traces/short_trace1.txt output/short1_extra.txt

