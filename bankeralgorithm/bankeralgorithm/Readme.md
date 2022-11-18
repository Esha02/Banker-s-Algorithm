# Banking Algorithm
This program is made in cpp language. 
It is a simple banking algorithm which is used to check 
whether the system is safe or not for given process and resources.
It is a simple program which is made for beginners to understand the basic concepts of cpp language.

## Advantages of Banking Algorithm
* Banker’s algorithm Avoids deadlock, and it is less restrictive than deadlock prevention.

## Disadvantages of Banking Algorithm
* Banker’s algorithm is not always safe. It is possible that the system is in a safe state, but the banker’s algorithm will not detect it.
* It only works with a fixed number of resources and processes.

## How to run the program
1. Download the cpp file.
2. Open the cpp file in any cpp compiler.
3. Run the program.

## Input
Input file is given in the input.txt file.
It contains the allocated resources to each process.
then it contains the maximum resources required by each process.
Then it contains the available resources.
(Considering number of processes as 5 and number of resources as 3)

## Output
Output will be shown in the console. showing that whether the system is safe or not.

**Remember:** With Change of input file we have to change array size, number of process, and number of resources in cpp file
## Examples
Input: (P = 5, R = 3)
```
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
3 3 2
```
Output:
```
System is in safe state
Safe sequence is: P1 -> P3 -> P4 -> P0 -> P2
```

Input: (P = 2, R = 3)
```
1 2 3
4 5 6
2 3 4
5 6 7
5 6 7
```
Output:
```
System is not in safe state
```



