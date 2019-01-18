import java.util.*;

public class Bankers {
	
	public static void getneed(int np, int nr, int alloc[][], int max[][], int need[][]) {
		for(int i=0; i<np; i++) {
			for(int j=0; j<nr; j++) {
				need[i][j] = max[i][j]-alloc[i][j];
			}
		}
	}
	
	public static void showneed(int np, int nr,int need[][]) {
		System.out.println("Need matrix :");
		for(int i=0; i<np; i++) {
			for(int j=0; j<nr; j++) {
				System.out.print(need[i][j] + " ");
			}
			System.out.println();
		}
	}
	
	public static boolean check(int i, int nr, int need[][], int avail[]) {
		for(int j=0; j<nr; j++) {
			if(need[i][j] > avail[j]) {
				return false;
			}
		}
		return true;
	}
	
	
	public static boolean isSafe(int np, int nr, int alloc[][], int need[][], int avail[]) {
		int rp = np;
		boolean done[] = new boolean[np];
		System.out.println("Order of execution : ");
		
		while(rp > 0) {
			int c = 0;
			int irp = rp;
			int i = 0;
			while(c < np) {
				if(!done[i] && check(i, nr, need, avail)) {
					rp--;
					for(int j=0; j<nr; j++) {
						avail[j] += alloc[i][j];
					}
					done[i] = true;
					System.out.println("Proecss "+i+ " executed");
				}
				c++;
				i = (i+1)%np;
			}
			if(rp == irp) {
				return false;
			}
		}
		
		return true;
	}
	
	
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		
		System.out.print("Enter the no. of process : ");
		int np = in.nextInt();
		System.out.print("Enter the no. of resources : ");
		int nr = in.nextInt();
		
		int alloc[][] = new int[np][nr];
		int max[][] = new int[np][nr];
		int need[][] = new int[np][nr];
		int avail[] = new int[nr]; 
		
		
		System.out.println("Enter the allocation matrix : ");
		for(int i=0; i<np; i++) {
			for(int j=0; j<nr; j++) {
				alloc[i][j] = in.nextInt();
			}
		}
		
		System.out.println("Enter the max matrix : ");
		for(int i=0; i<np; i++) {
			for(int j=0; j<nr; j++) {
				max[i][j] = in.nextInt();
			}
		}
		
		System.out.println("Enter the availability array : ");
		for(int i=0; i<nr; i++) {
			avail[i] = in.nextInt();
		}
		
		getneed(np, nr, alloc, max, need);
		showneed(np, nr, need);
		
		int op;
		System.out.print("Enter the operation to be performed :  \n1:Check for safety of sytem\n2:Make request from a process\n");
		op = in.nextInt();
		
		switch(op) {
			case 1: {
				if(isSafe(np, nr, alloc, need, avail)) {
					System.out.println("System is in safe state\n");
				}
				else {
					System.out.println("System is in unsafe state\n");
				}
				break;
			}
			case 2 :{
				System.out.println("Enter the process id : ");
				int id = in.nextInt();
				
				int req[] = new int[nr];
				System.out.println("Enter the request array : ");
				for(int i=0; i<nr; i++) {
					req[i] = in.nextInt();
				}
				
				for(int i=0; i<nr; i++) {
					alloc[id][i] += req[i];
				}
				
				for(int i=0; i<nr; i++) {
					avail[i] -= req[i];
				}
				
				getneed(np, nr, alloc, max, need);
				showneed(np, nr, need);
				
				if(isSafe(np, nr, alloc, need, avail)) {
					System.out.println("System is in safe state\n");
				}
				else {
					System.out.println("System is in unsafe state\n");
				}
				break;			
			}
		}
		
	}

}
