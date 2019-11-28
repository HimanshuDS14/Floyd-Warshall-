#include<stdio.h>
#define INF 99999

struct Graph
{
    int V;
    int E;
    int *adj;
};

void floydWarshall(struct Graph*G)

{
    int i,j,k;
    //create temp matrix
    int temp[G->V][G->V];

    //copy original matrix into temp matrix
    for(i=0;i<G->V;i++)
    {
        for(j=0;j<G->V;j++)
        {
            temp[i][j] = *(G->adj+i * G->V+j);
        }
    }

    //find minimum distance between two vertex
    for(k=0;k<G->V;k++)
    {
        for(i=0;i<G->V;i++)
        {
            for(j=0;j<G->V;j++)
            {
                if(temp[i][k] + temp[k][j] < temp[i][j])
                {
                    temp[i][j] = temp[i][k] + temp[k][j];
                }
            }
        }
    }

    for(i=0;i<G->V;i++)
    {
        for(j=0;j<G->V;j++)
        {
            *(G->adj+i * (G->V)+j) = temp[i][j];
        }
    }



}

void printSolution(struct Graph *G)
{
    for(int i=0;i<G->V;i++)
    {
        for(int j=0;j<G->V;j++)
        {
            if(*(G->adj+i * G->V+j)==INF)
                {
                    printf("%7s" , "INF");
                }
            else
            {
                printf("%7d" ,*(G->adj+i * G->V+j));

            }

        }
        printf("\n");
    }
}

int main()
{

    struct Graph *G;
    int matrix[4][4] = {{0,5,INF,10},
                        {INF,0,3,INF},
                        {INF,INF,0,1},
                        {INF,INF,INF,0}};
    G  = (struct Graph *)malloc(sizeof(struct Graph));
    G->V = 4;
    G->E = 4;
    G->adj = malloc((G->V)*(G->V) * sizeof(int));

    for(int i=0;i<G->V;i++)
    {
        for(int j=0;j<G->V;j++)
        {
            *(G->adj+i * G->V+j) = matrix[i][j];
        }
    }

    printf("Original Distance : \n");
    printSolution(G);
    floydWarshall(G);
    printf("After applying floyd warshall. minimum distance between two vertex is :  \n");
    printSolution(G);

}
