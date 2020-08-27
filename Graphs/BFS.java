import java.io.*;
import java.util.*;
class BFS
{
    private int V;   
    private LinkedList<Integer> adj[]; //Adjacency Lists 

    BFS(int v) 
    { 
        V = v; 
        adj = new LinkedList<Integer>[v]; 
        for (int i=0; i<v; ++i) 
            adj[i] = new LinkedList<Integer>(); 
    } 
  
    // Function to add an edge into the graph 
    void addEdge(int v,int w) 
    { 
        adj[v].add(w); 
    } 
    void bfs(int s)
    {
        boolean visited[]=new boolean[V];
        LinkedList<Integer> queue=new LinkedList<Integer>();
        visited[s]=true;
        queue.add(s);
        while(queue.size()!=0)
        {
            s=queue.poll();
            System.out.println(s+" ");
            Iterator<Integer> i=adj[s].listIterator();
            while(i.hasNext())
            {
                int n=i.next();
                if(!visited[n])
                {
                    visited[n]=true;
                    queue.add(n);
                }
            }
        }
    }
    public static void main(String args[])
    {
        BFS g=new BFS(7);
        g.addEdge(0,1);
        g.addEdge(0,2);
        g.addEdge(1,3);
        g.addEdge(1,4);
        g.addEdge(2,5);
        g.addEdge(2,6);
        System.out.println("Breadth First Search");
        g.bfs(0);
    }
}