#include<stdio.h>
int queue[100];
int front=0,rear= 0;
void push(int b)
{
    queue[rear] = b;
    rear++;
}
void pop()
{
    queue[front]=0;
    front++;
}
int visited[4] ={0};            //visited array get initiated to 0
void main()
{
    int n,v;
    printf("Enter number of vertices in Graph:");
    scanf("%d",&n);
    int a[n][n];
    printf("Enter adjacency matrix for given Graph:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    
    push(1);        //1st element pushed in queue
    visited[0] = 1;       //in visited array its value is updated to 1
    printf("Breadth First Search ->\n");
    while(front!=rear)
    {
        int current = queue[front];
        pop();           //current element from queue is pop and print as it deque
        printf("%d ",current);
        for(int i=0;i<n;i++)        //searching for another nodes which are connected to current node
        {
            if(visited[i]!=1 && a[current-1][i]==1)     //current-1 as nodes start from 1
            {
                visited[i]= 1;       //as we found element which is not visietd yet then make it visited
                push(i+1);        //push that element in queue 
            }
        }
    }
}


/*
o/p:

Enter number of vertices in Graph:4
Enter adjacency matrix for given Graph:
0 1 1 1
1 0 0 1
1 0 0 1
1 1 1 0
Breadth First Search ->
1 2 3 4 

*/