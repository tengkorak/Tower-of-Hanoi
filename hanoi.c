/*
 * The Towers Of Hanoi
 * C
 * Copyright (C) 1998 Amit Singh. All Rights Reserved.
 *
 * Tested with, ah well ... :)
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define FROM	1
#define TO	3
#define USING	2

void
dohanoi(int N, int from, int to, int using)
{
  if (N > 0) {
    dohanoi(N-1, from, using, to);
    printf ("move %d --> %d\n", from, to);
    dohanoi(N-1, using, to, from);
  }
}

int
main (int argc, char **argv)
{
  long int N;

  if (argc != 2) {
    fprintf(stderr, "usage: %s N\n", argv[0]);
    exit(1);
  }

  N = strtol(argv[1], (char **)NULL, 10);

  /* a bit of error checking, LONG_XXX should be there in limits.h */
  if (N == LONG_MIN || N == LONG_MAX || N <= 0) {
    fprintf(stderr, "illegal value for number of disks\n");
    exit(2);
  }

  dohanoi(N, FROM, TO, USING);

  exit(0);
}



   1.
      #include<stdio.h>
   2.
      #include<conio.h>
   3.
      #include<math.h>
   4.
      void hanoi(int x, char from,char to,char aux)
   5.
      {
   6.
       
   7.
      if(x==1)
   8.
      {
   9.
      printf("Move Disk From %c to %c\n",from,to);
  10.
      }
  11.
      else
  12.
      {
  13.
      hanoi(x-1,from,aux,to);
  14.
      printf("Move Disk From %c to %c\n",from,to);
  15.
      hanoi(x-1,aux,to,from);
  16.
      }
  17.
       
  18.
      }
  19.
      void main()
  20.
      {
  21.
      int disk;
  22.
      int moves;
  23.
      clrscr();
  24.
      printf("Enter the number of disks you want to play with:");
  25.
      scanf("%d",&disk);
  26.
      moves=pow(2,disk)-1;
  27.
      printf("\nThe No of moves required is=%d \n",moves);
  28.
      hanoi(disk,'A','C','B');
  29.
      getch();
  30.
      }


#include<stdio.h>
#include<conio.h>
#include<math.h>
void hanoi(int x, char from,char to,char aux)
{

if(x==1)
{
printf("Move Disk From %c to %c\n",from,to);
}
else
{
hanoi(x-1,from,aux,to);
printf("Move Disk From %c to %c\n",from,to);
hanoi(x-1,aux,to,from);
}

}
void main()
{
int disk;
int moves;
clrscr();
printf("Enter the number of disks you want to play with:");
scanf("%d",&disk);
moves=pow(2,disk)-1;
printf("\nThe No of moves required is=%d \n",moves);
hanoi(disk,'A','C','B');
getch();
} 

/* hanoi.c: solves the tower of hanoi problem. (Programming exercise.) */
/* By Terry R. McConnell (12/2/97) */
/* Compile: cc -o hanoi hanoi.c */

/* This program does no error checking. But then, if it's right, 
it's right ... right ? */


/* The original towers of hanoi problem seems to have been originally posed
by one M. Claus in 1883. There is a popular legend that goes along with
it that has been often repeated and paraphrased. It goes something like this:
In the great temple at Benares there are 3 golden spikes. On one of them,
God placed 64 disks increasing in size from bottom to top, at the beginning
of time. Since then, and to this day, the priest on duty constantly transfers
disks, one at a time, in such a way that no larger disk is ever put on top
of a smaller one. When the disks have been transferred entirely to another
spike the Universe will come to an end in a large thunderclap.

This paraphrases the original legend due to DeParville, La Nature, Paris 1884,
Part I, 285-286. For this and further information see: Mathematical 
Recreations & Essays, W.W. Rouse Ball, MacMillan, NewYork, 11th Ed. 1967,
303-305.
*
*
*/

#include<stdio.h>
#include<stdlib.h>

#define N 4    /* This is the number of "disks" on tower A initially. */
	       /* Taken to be 64 in the legend. The number of moves 
                  required, in general, is 2^N - 1. For N = 64, this is
                  18,446,744,073,709,551,615 */

int A[N], B[N], C[N];  /* These are the three towers. For example if the
state of A is 0,1,3,4, that means that there are three discs on A of sizes
1, 3, and 4. (Think of right as being the "down" direction.) */

void Hanoi(int,int*,int*,int*);

/* Print the current configuration of A, B, and C to the screen */

void
PrintAll(void)
{
	int i;

	printf("A: ");
	for(i=0;i<N;i++)printf(" %d ",A[i]);
	printf("\n");

	printf("B: ");
	for(i=0;i<N;i++)printf(" %d ",B[i]);
	printf("\n");

	printf("C: ");
	for(i=0;i<N;i++)printf(" %d ",C[i]);
	printf("\n");
	printf("------------------------------------------\n");
	return;
}
	
/* Move the leftmost nonzero element of source to dest, leave behind 0. */
/* Returns the value moved (not used.) */

int Move(int *source, int *dest)
{
	int i=0,j=0;

	while((*(source + i)==0)&&(i<N))i++;
	while((*(dest + j)==0)&&(j<N))j++;


	*(dest+j-1) = *(source+i);
	*(source + i) = 0;
	PrintAll();       /* Print configuration after each move. */
	return *(dest+j-1);
}


/* Moves first n nonzero numbers from source to dest using the rules of Hanoi.
   Calls itself recursively.
*/

void
Hanoi(int n,int *source, int *dest, int *spare)
{
	int i;
	if(n==1){
		Move(source,dest);
		return;
	}

	Hanoi(n-1,source,spare,dest);
	Move(source,dest);
	Hanoi(n-1,spare,dest,source);	
	return;
}


int
main()
{
	int i;

	/* initialize the towers */
	for(i=0;i<N;i++)A[i]=i+1;
	for(i=0;i<N;i++)B[i]=0;
	for(i=0;i<N;i++)C[i]=0;
		
	printf("Solution of Tower of Hanoi Problem with %d Disks\n\n",N);

	/* Print the starting state */
	printf("Starting state:\n");
	PrintAll();
	printf("\n\nSubsequent states:\n\n");

	/* Do it! Use A = Source, B = Destination, C = Spare */
	Hanoi(N,A,B,C);
	return 0;
}

#include "stdio.h"

void towers(int,char,char,char);

void towers(int n,char frompeg,char topeg,char auxpeg)
	{ /* If only 1 disk, make the move and return */
	  if(n==1)
	    { printf("\nMove disk 1 from peg %c to peg %c",frompeg,topeg);
	      return;
	    }
	  /* Move top n-1 disks from A to B, using C as auxiliary */
	  towers(n-1,frompeg,auxpeg,topeg);
	  /* Move remaining disks from A to C */
	  printf("\nMove disk %d from peg %c to peg %c",n,frompeg,topeg);
	  /* Move n-1 disks from B to C using A as auxiliary */
	  towers(n-1,auxpeg,topeg,frompeg);
	}
main()
	{ int n;
	  printf("Enter the number of disks : ");
	  scanf("%d",&n);
	  printf("The Tower of Hanoi involves the moves :\n\n");
	  towers(n,'A','C','B');
	  return 0;
	}