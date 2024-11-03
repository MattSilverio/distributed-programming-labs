#include <stdio.h>
#include <mpi.h>

#define MASTER 0
#define SLAVE 1
#define TAG 0
#define TAMVET 5

int main (){
	int rank, nprocs;
	
	// INICIANDO MPI
	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
	
	////
	
	
	/// TRATA PROCESSO MASTER
	
	if (rank == MASTER){
		int v[TAMVET] = {1, 3, 5,7,9};
		float media_recebida;
		MPI_Send(v, TAMVET, MPI_INT, SLAVE, TAG, MPI_COMM_WORLD);
		MPI_Recv(&media_recebida, 1, MPI_FLOAT, SLAVE, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE );
		printf("A media dos elementos do vetor eh %f", media_recebida);
		
	}
	// TRATA PROCESSO SLAVE
	else{
		int vrec[5];
		MPI_Recv(vrec, TAMVET, MPI_INT, MASTER, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		
		int soma = 0;
		for(int i=0; i < TAMVET; i++)
			soma+= vrec[i];
		
		float media = (float) soma/TAMVET;
		
		MPI_Send(&media, 1, MPI_FLOAT, MASTER, TAG, MPI_COMM_WORLD);	
	}
	
	MPI_Finalize();
	
	return 0;	
}
