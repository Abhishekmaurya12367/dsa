#Q1. There are N processes in the CPU. Each process requires some number of
resources. Store the number of resources required by each process in the form of
Max Heap (2 marks). Implement the user driven program to perform the
following operations:
(a) Print the process id with maximum resources. (1 mark)
(b) Increase the number of resources for a given process. (2 marks)
(c) Remove the process having maximum resources. (1.5 marks)
(d) Insert a new process along with its required number of resources into the
heap. (1.5 marks)
(e) Sort the processes in terms of their number of resources in ascending order
using the constructed heap. (2 marks)
Input = [1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17]
/*************  ✨ Codeium Command 🌟  *************/
#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

typedef struct {
    int process_id;
    int resources;
} Process;

typedef struct {
write i c
/******  849c1445-050a-44d8-b5db-04211361928f  *******/