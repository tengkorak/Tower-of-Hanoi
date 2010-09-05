#include <stdio.h>

int j = 1;

void dohanoi(int N, char from, char to, char using)
{
  if (N > 0) {
   dohanoi(N-1, from, using, to);
   printf ("Step %d: Move Disk %d From %c To %c\n", j++, N, from, to);
   dohanoi(N-1, using, to, from);
  }
}

int main (int argc, char **argv)
{
  long int N;

  if (argc != 2) {
    fprintf(stderr, "usage: %s N\n", argv[0]);
    return (1);
  }

  N = strtol(argv[1], (char **)NULL, 10);

  dohanoi(N, 'A', 'C', 'B');

  return(0);
}
