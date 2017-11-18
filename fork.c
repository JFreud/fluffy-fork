#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>


int child() {
  srand(time(NULL) + getpid());
  unsigned int time_asleep = rand() % 15 + 5;
  printf("I, the child, have a pid of %d and will sleep for %d seconds!\n", getpid(), time_asleep);
  sleep(time_asleep);
  printf("I, the child with a pid of %d, have awoken and finished!\n", getpid());
  exit(time_asleep);
}

int main() {

  int status;

  printf("=======pre-fork=======\n");
  int f = fork();
  int f2;

  if (f) {f2 = fork();}
  else {f2 = 1;}


  if (!f || !f2) {
    child();
  }

  int child_pid = wait(&status);
  printf("The finished child:\npid: %d\t time asleep: %d\n", child_pid, WEXITSTATUS(status));
  printf("I, the parent, am done\n");

  return 0;
}
