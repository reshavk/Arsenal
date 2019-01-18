import java.util.*;
public class Priority {
	
	public static void simulatePriority(int n, int p[], int bt[], int at[], int pri[]) {
		
		int rp = n;
		int cbt[] = bt.clone();
		int tat[] = new int[n];
		int wt[] = new int[n];
		
		int t=0;
		while(rp > 0) {
			int maxp = Integer.MIN_VALUE, pid = 0;
			boolean found = false;
			for(int i=0; i<n;i++) {
				if(at[i] <= t && bt[i] > 0 && pri[i] > maxp) {
					maxp = pri[i];
					pid = i;
					found = true;
				}
			}
			if(found) {
				rp--;
				t += bt[pid];
				tat[pid] = t - at[pid];
				wt[pid] = tat[pid] - bt[pid];
				bt[pid] = 0;
			}
			else{
				t++;
			}
		}
		
		System.out.println("After non-pre-emptive priority scheduling : ");
		System.out.println("Process id\tArrival Time\tBurst time\tWaiting time\tTurn around time\n");
		for(int i=0; i<n; i++) {
			System.out.println(p[i]+"\t\t"+at[i]+"\t\t"+cbt[i]+"\t\t"+wt[i]+"\t\t"+tat[i]+"");
		}
	}
	
	
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		
		System.out.println("Enter the number of process : ");
		int n = in.nextInt();
		
		int p[] = new int[n];
		int pri[] = new int[n];
		int bt[] = new int[n];
		int at[] = new int[n];
		
		System.out.println("Enter the burst time of processes : ");
		for(int i=0; i<n; i++) {
			p[i] = i;
			bt[i] = in.nextInt();
		}
		
		System.out.println("Enter the arrivall time of processes : ");
		for(int i=0; i<n; i++) {
			at[i] = in.nextInt();
		}
		
		System.out.println("Enter the priority of processes : ");
		for(int i=0; i<n; i++) {
			pri[i] = in.nextInt();
		}
		
		simulatePriority(n, p, bt, at, pri);
		in.close();
		
	}

}
