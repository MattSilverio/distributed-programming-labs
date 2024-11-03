#include <stdio.h>
#include <mpi.h>

int main(int argc, char * argv[]) {
	int rank, size, vector[8], recv_data[4];
	
	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	
	if(rank == 0){
		for(int i = 0; i < 8; i++){
			vector[i] = i + 1;
		}
	}
	
	MPI_Scatter(vector, 4, MPI_INT, &recv_data, 4, MPI_INT, 0, MPI_COMM_WORLD);
	
	printf("Processo %d recebeu o vetor: [", rank);
	
	for(int i = 0; i < 4; i++){
		printf("%d ", recv_data[i]);
		if(i < 3) printf(",");
	}
	
	printf("];\n"); 
	
	MPI_Finalize();
	
	return 0;
}
