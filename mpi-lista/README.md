Exercícios
1. Elaborar um programa MPI que consiga criar 4 processos em hosts disFntos do
cluster e imprimir a mensagem “Olá, mundo!\n” em cada um deles.
2. Elaborar um programa MPI com quatro processos, onde cada um deles imprime uma
das posições de um vetor de 4 posições. Obs.: GaranFr que apenas um dos
processos seja responsável por inicializar o vetor.
3. Faça uma pesquisa sobre comunicação em grupo no MPI e tente reescrever o
programa da questão 2 usando a função MPI_ScaVer.
4. Elaborar um programa MPI com dois processos, que imprimem, proporcionalmente,
um vetor fixo (do Fpo int) de 8 posições
5. Elaborar um programa MPI para que n processos consigam imprimir o vetor de
tamanho fixo (do Fpo int) de 8 posições. Considere que apenas um dos processos
deve inicializar o vetor.
6. Elaborar uma programa MPI para que n processos possam imprimir,
proporcionalmente, um vetor dinâmico (de tamanho aleatório), inicializado pelo
MASTER
7. Elaborar uma nova versão do programa anterior, usando a função MPI_Bcast()
8. Elaborar um programa MPI com 3 processos, para manipular um vetor de 8 posições
de valores inteiros. O processo Master inicializa o vetor com valores inteiros; em
seguida, distribui proporcionamente os elementos do vetor para cada um dos dois
Slaves; finalmente, calcula a média dos valores recebidos de cada slave. Os Slaves,
por sua vez, recebem os valores do master, calculam a média dos valores recebidos e
os devolvem para o Master.
9. Crie uma versão extra do código da questão anterior que permita trabalhar com um
número aleatório de processos, mantendo a distribuição mais proporcional possível
de elementos entre os escravos. Considere ainda que o vetor é de tamanho
aleatório, mantendo as funcionalidades descritas anteriormente.
10.Faça uma pesquisa sobre comunicação coleFva e refaça os exercícios 4 e 5 usando
funções MPI_ScaVer e MPI_Gather.
