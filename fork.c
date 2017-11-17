#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


int child() {
  unsigned int therand = rand() % 15 + 5;
  printf("I, the child, have a pid of %d\n", getpid());
  sleep(therand);
  printf("I, the child with a pid of %d, have awoken and finished!\n", getpid());
  return(therand);
}

int main() {

  int status;
  srand(time(NULL));
  printf("=======pre-fork=======\n");
  int f = fork();

  if (f) {
    f = fork();
    int child_pid = wait(&status);
    printf("The finished child:\npid: %d\t time asleep: %d\n", child_pid, WEXITSTATUS(status));
    printf("I, the parent, am done\n");
  }
  else {
    child();
  }

  return 0;
}
