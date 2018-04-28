import java.util.*;
public class sjf {
	
	public static void simulateSJF(int n, int p[], int arr[], int bt[]) {
		int rp = n;
		int cbt[] = bt.clone();
		
		int wt[] = new int[n];
		int tat[] = new int[n];
		
		int t = 0;
		System.out.println("Time\tProcess id\tArrival Time\tBurst Time left");
		while(rp > 0) {
			int mbt = Integer.MAX_VALUE;
			int sj = 0;
			boolean found = false;
			for(int i=0; i<n; i++) {
				if(arr[i] <= t && bt[i] > 0 && bt[i] < mbt) {
					mbt = bt[i];
					sj = i;
					found = true;
				}
			}
			if(found) {
				System.out.println(t + "\t\t"+ sj + "\t\t" + arr[sj] + "\t\t" + bt[sj]);
				bt[sj]--;
				if(bt[sj] == 0) {
					rp--;
					tat[sj] = (t+1)-arr[sj];
					wt[sj] = tat[sj] - cbt[sj];
				}
			}
			t++;
		}
		
		System.out.println("Process id\tArrival time\tBurst time\tWaiting Time\tTurn");
		for(int i=0; i<n; i++) {
			System.out.println(p[i]+"\t\t"+arr[i]+"\t\t"+cbt[i]+"\t\t"+wt[i]+"\t\t"+tat[i]);
		}
	}
	
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		
		System.out.print("Enter the no. of process : ");
		int n = in.nextInt();
		
		int p[] = new int[n];
		int arr[] = new int[n];
		int burst[] = new int[n];
		
		System.out.println("Enter arrival time of each process :  ");
		for(int i=0; i<n; i++) {
			p[i] = i;
			arr[i] = in.nextInt();
		}
		
		System.out.println("Enter burst time of each process :  ");
		for(int i=0; i<n; i++) {
			burst[i] = in.nextInt();
		}
		
		simulateSJF(n, p, arr, burst);
		in.close();
	}

}
