#include <iostream>
#include <limits.h>
using namespace std;

#define Max_nodes 6  //maximum nodes = 6
#define Infinity 9999  // defining the value of infinity to 9999

int dijkstra_algo(int graph[Max_nodes][Max_nodes],int num_of_nodes,int source_node){
    int cost[Max_nodes][Max_nodes],time_taken[Max_nodes], pred[Max_nodes];
    bool visited[Max_nodes];
    int count, min_time, next_node;

    for(int i=0; i < num_of_nodes; i++){
        for(int j = 0; j < num_of_nodes; j++){
            if (graph[i][j] == 0){
                cost[i][j] = Infinity;
            }else{
                cost[i][j] = graph[i][j];
            }
        }
    }

    for(int i = 0; i < num_of_nodes; i++){
        time_taken[i] = cost[source_node][i];
        pred[i] = source_node;
        visited[i] = false;
    }

    time_taken[source_node] = 0;
    visited[source_node] = true;
    count =1;

    while(count < num_of_nodes-1){
        min_time = Infinity;

        for(int i=0; i < num_of_nodes; i++){
            if (time_taken[i] < min_time && !visited[i]){
                min_time  = time_taken[i];
                next_node = i;
            }
        }

        visited[next_node] = true;
        for(int i=0; i < num_of_nodes; i++){
            if(!visited[i] && (min_time + cost[next_node][i] < time_taken[i])){
                time_taken[i] = min_time + cost[next_node][i];
                pred[i] = next_node;
            }
        }
        count++;
    }
    float avg_time = 0;
    for (int i=0; i < num_of_nodes; i++){
        if (i != source_node){
            cout << "Time taken from node " << source_node<< " to " << i << " node = " << time_taken[i] << endl;
            avg_time += time_taken[i];
            cout << "Path " << i;

            int j = i;
            do{
                j = pred[j];
                cout << "<-" << j;
            }while(j != source_node);
            cout << endl;
        }
    }
    cout << "Average time taken:" << avg_time/5 << endl;
}

int main(){
    int graph[Max_nodes][Max_nodes] = { {0,10,0,0,15,5},
                                        {10,0,10,30,0,0},
                                        {0,10,0,12,5,0},
                                        {0,30,12,0,0,20},
                                        {15,0,5,0,0,0},
                                        {5,0,0,20,0,0}};
    for (int i=0; i<6 ; i++){
        cout << "start node " << i << endl;
        dijkstra_algo(graph,6,i);   //no of nodes is 6 and the source node is i
        cout << endl;
    }
    return 0;
}