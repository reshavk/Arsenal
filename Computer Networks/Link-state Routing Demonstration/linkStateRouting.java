import java.util.*;

class linkStateRouting {


	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		System.out.print("Enter the no. of routers : ");
		int n = in.nextInt();
	
		int[][] adj = new int[n][n];
		System.out.print("Enter the number of links between routers : ");
		int e = in.nextInt();
	
		System.out.print("Enter the interconnection information about the router : \nRouter1\tRouter2\tDistance\n");
		int a, b, d;
		for(int i=0; i<e; i++) {
			a = in.nextInt();
			b = in.nextInt();
			d = in.nextInt();
			adj[a][b] = d;
			adj[b][a] = d;
		}
	
		System.out.println("Flooding information for each router");
		System.out.println("===============================================\n");
		for(int i=0; i<n; i++) {
			System.out.println("Flooding for router " + i + " : ");
			System.out.println("--------------------------------------------------");
			for(int j=0; j<n; j++) {
				System.out.print("Distance from router " + j + " : ");
				if(adj[i][j]  == 0 && i != j) {
					System.out.println("inf");
					adj[i][j] = 1000;
				}
				else{
					System.out.println(adj[i][j]);
				}
			}
		}
		
		int[] dist = new int[n];
		int[] parent = new int[n];
		boolean[] visited = new boolean[n];
		
		int inf = 1000;
		System.out.println("Link State Routing table for routers");
		System.out.println("===========================================");
		for(int i=0; i<n; i++) {
			
			for(int j=0; j<n; j++) {
				dist[j] = inf;
				visited[j] = false;
				parent[j] = -1;
			}
			
			dist[i] = 0;
			int dis = 0, src = i;
			for(int j=0; j<n; j++) {
				int mdis = inf;
				for(int k=0; k<n; k++) {
					if(dist[k] < mdis && !visited[k]) {
						mdis = dist[k];
						src = k;
					}
				}
				visited[src] = true;
				for(int k=0; k<n; k++) {
					if(dist[k] > mdis + adj[src][k] && parent[k] == -1) {
						parent[k] = src;
					}
					dist[k] = Math.min(dist[k], mdis + adj[src][k]);
					
				}
				
			}
			
			System.out.println("Linkstate routing information for router " + i );
			System.out.println("-----------------------------------------------");
			for(int j=0; j<n; j++) {
				System.out.println("Distance from router " + j + " : " + dist[j]+ "\tNext router : " + parent[j]); 
			}
			
			
		}
		
		
		
		
	} 	
}
