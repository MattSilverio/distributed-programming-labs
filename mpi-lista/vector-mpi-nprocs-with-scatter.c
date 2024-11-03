#include<stdio.h>
#include<mpi.h>

int main(int argc, char* argv[]){
	int rank, size, vector[4], received_data;
	
	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	
	if(rank == 0){
		// iniciando vetor, garantindo que o processo mestre esteja os iniciando
		
		for(int i = 0; i < 4; i++){
			vector[i] = i + 1;
		}
	}
	
	MPI_Scatter(vector, 1, MPI_INT, &received_data, 1, MPI_INT, 0, MPI_COMM_WORLD);
	
	// se printar com vector[rank] vai dar erro por conta que o metodo MPI_Scatter joga tudo para o received_data
	printf("Processo %d/%d recebeu valor %d\n", rank, size, received_data);
	
	MPI_Finalize();

	return 0;
}
