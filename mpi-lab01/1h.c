#include <stdio.h>
#include <mpi.h>
#include <sys/types.h>
#include <unistd.h>

int main (int argc, char *argv[]){
	int rank, nprocs;
	
	MPI_Init(NULL,NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
		printf("numero processo: %d nrank: %d Ola mundo!\n",
			 &nprocs, &rank);
	MPI_Finalize();

	return 0;
}
