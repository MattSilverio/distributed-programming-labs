#include<stdio.h>
#include<mpi.h>

int main(int argc, char* argv[]){
	int rank, size, vector[4];
	
	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	
	if(rank == 0){
		// iniciando vetor, garantindo que o processo mestre esteja os iniciando
		
		for(int i = 0; i < 4; i++){
			vector[i] = i + 1;
		}
	}
	
	MPI_Bcast(vector, 4, MPI_INT, 0, MPI_COMM_WORLD);
	
	printf("Processo %d/%d recebeu valor %d\n", rank, size, vector[rank]);
	
	MPI_Finalize();

	return 0;
}
