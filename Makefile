COMMAND=clang++-4.0 -std=c++1z

all: 1 2 3 4 5 6 7 8 9 10 11
	@echo "All done!"
1:
	$(COMMAND) 1/solution.cpp -o 1/a.out
2:
	$(COMMAND) 2/solution.cpp -o 2/a.out
3:
	$(COMMAND) 3/solution.cpp -o 3/a.out
4:
	$(COMMAND) 4/solution.cpp -o 4/a.out
5:
	$(COMMAND) 5/solution.cpp -o 5/a.out
6:
	$(COMMAND) 6/solution.cpp -o 6/a.out
7:
	$(COMMAND) 7/solution.cpp -o 7/a.out
8:
	$(COMMAND) 8/solution.cpp -o 8/a.out
9:
	$(COMMAND) 9/solution.cpp -o 9/a.out
10:
	$(COMMAND) 10/solution.cpp -o 10/a.out
11:
	$(COMMAND) 11/solution.cpp -o 11/a.out
12:
	$(COMMAND) 12/solution.cpp -o 12/a.out
13:
	$(COMMAND) 13/solution.cpp -o 13/a.out
14:
	$(COMMAND) 14/solution.cpp -o 14/a.out
15:
	$(COMMAND) 15/solution.cpp -o 15/a.out
16:
	$(COMMAND) 16/solution.cpp -o 16/a.out
17:
	$(COMMAND) 17/solution.cpp -o 17/a.out
18:
	$(COMMAND) 18/solution.cpp -o 18/a.out
19:
	$(COMMAND) 19/solution.cpp -o 19/a.out
20:
	$(COMMAND) 20/solution.cpp -o 20/a.out
21:
	$(COMMAND) 21/solution.cpp -o 21/a.out
22:
	$(COMMAND) 22/solution.cpp -o 22/a.out
23:
	$(COMMAND) 23/solution.cpp -o 23/a.out
24:
	$(COMMAND) 24/solution.cpp -o 24/a.out
25:
	$(COMMAND) 25/solution.cpp -o 25/a.out
clean:
	rm -rf */a.out
