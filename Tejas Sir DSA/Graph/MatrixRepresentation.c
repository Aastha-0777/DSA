#include<stdio.h>

int graph[4][4];

int main(){

    int scr, desc, totalEdges;

    // for(int i = 0;i < 4; i++){
    //     for(int j = 0;j < 4; j++){
    //         printf("\nIs %d Connected with %d? : (0/1) ", i, j);
    //         scanf("%d", &graph[i][j]);
    //     }
    // }

    printf("How Many Edeges Do You Have? : ");
    scanf("%d", &totalEdges);

    for(int i = 1; i <= totalEdges; i++){
        printf("Enter Source and Destinatio : ");
        scanf("%d%d", &scr, &desc);
        graph[scr][desc] = 1;
        graph[desc][scr] = 1;
    }

    printf("\nMattrix : \n");
    for(int i = 0;i < 4; i++){
        for(int j = 0;j < 4; j++){
            printf(" %d ", graph[i][j]);
        }
        printf("\n");
    }

    int source;
    printf("Enter the Source to check it's Destinations : ");
    scanf("%d", &source);

    for(int i = 0;i < 4; i++){
        if(graph[source][i]){
            printf(" %d : %d ", i, source);
        }
    }

    return 0;

}