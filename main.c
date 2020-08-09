/**
*   Example started from code snippet here:
*   https://www.geeksforgeeks.org/multithreading-c-2/
*   Thanks to Rahul Jain.
*
*
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 

typedef void (*threadFunction)(void *arg);
  
// Let us create a global variable to change it in threads 
int g = 0; 
  
void myThreadFun(void *vargp) 
{ 
    // Store the value argument passed to this thread 
    int *myid = (int *)vargp; 
  
    // Let us create a static variable to observe its changes 
    static int s = 0; 
  
    // Change static and global variables 
    ++s; ++g; 
  
    // Print the argument, static and global variables 
    printf("Thread ID: %d, Static: %d, Global: %d\n", *myid, ++s, ++g); 
    return;
} 

  
int main() 
{ 
    int i; 
    pthread_t tid; 
    threadFunction thread = &myThreadFun;

    // First test case
    //----------------

    // Create three threads 
    for (i = 0; i < 3; i++) 
        pthread_create(&tid, NULL, (void *)thread, (void *)&tid); 
  
    pthread_exit(NULL); 


    
    
    return 0; 
} 