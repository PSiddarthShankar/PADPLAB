#include <stdio.h>
#include <mpi.h>
int main (int nargs, char** args)
{
int size, my_rank,i;
MPI_Init (&nargs, &args);
MPI_Comm_size (MPI_COMM_WORLD, &size);
MPI_Comm_rank (MPI_COMM_WORLD, &my_rank);
for (i=0; i<size; i++) {
MPI_Barrier (MPI_COMM_WORLD);
if (i==my_rank) {
printf("Hello world, I’ve rank %d out of %d procs.\n",
my_rank, size);
fflush (stdout);
}
}
MPI_Finalize ();
return 0;
}
