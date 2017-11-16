#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


int child() {
  unsigned int therand = rand() % 15 + 5;
  sleep(therand);
  printf("I, the child, have finished!\n");
  return(therand);
}

int main() {

  int * status;
  srand(time(NULL));
  printf("=======pre-fork=======\n");
  int f = fork();
  int f2 = fork();

  if (f == 0) {
    if (f2 == 0) {
      child();
    }
    else {
      int child_pid = wait(&status);
      printf("The finished child:\npid: %d\t time asleep: %d\n", child_pid, WEXITSTATUS(status));
    }
    child();
  }
  else {
    int child_pid = wait(&status);
    printf("The finished child:\npid: %d\t time asleep: %d\n", child_pid, WEXITSTATUS(status));
  }

  

  printf("The parent is done!\n");
  return 0;
}
