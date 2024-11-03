#include <stdio.h>
#include <mpi.h>
#include <sys/types.h>
#include <unistd.h>

#define 	MASTER 0
#define 	SLAVE 1
#define 	TAG 0



int main (int argc, char *argv[]){
	int rank, nprocs;
	
	MPI_Init(NULL,NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
	
	if(rank == MASTER) {
		int i=8, recebido;
		// MPI_Send(BUFFER_ENVIO, QTD, TIPO, TAG, DESTINO, MPI_COMM_WORLD);
		MPI_Send(&i, 1, MPI_INT, SLAVE, TAG, MPI_COMM_WORLD);
		MPI_Recv(&recebido, 1 , MPI_INT, SLAVE, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("Valor recebido do Slave -> %d\n", recebido);
		
	} else {
		int rec, resposta;
		// MPI_Recv(BUFFER_RECEBE, QTD, TIPO , ORIGEMM, TAG, MPI_COMM_WORLD, STATUS);
		MPI_Recv(&rec, 1, MPI_INT, MASTER, TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("SLAVE (%d/%d)  recebeu o valor %d\n", rank, nprocs, rec);
		resposta = rec *2;
		MPI_Send(&resposta, 1, MPI_INT, MASTER, TAG, MPI_COMM_WORLD);
	}

	MPI_Finalize();

	return 0;
}
