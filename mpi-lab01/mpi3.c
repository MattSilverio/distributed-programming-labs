#include <stdio.h>
#include <mpi.h>

#define MASTER 0
#define TAG 0


int main(){
	int rank, nprocs;
	
	// INICIANDO MPI
	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
	
	if(rank == MASTER){
		int valor =2;
		
		for (int i = 1; i<nprocs; i++){
			int valor_enviado = valor * i;
			MPI_Send(&valor_enviado,1, MPI_INT, i, TAG, MPI_COMM_WORLD);
		}
	}
	else {
		int valor_recebido;
		
		MPI_Recv(&valor_recebido, 1, MPI_INT, MASTER, TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("SLAVE (%d/%d) recebeu o valor %d\n", rank, nprocs, valor_recebido);
	}
	
	MPI_Finalize();
	
	
	return 0;
}
