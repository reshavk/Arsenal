import java.util.*;

public class Optimal {
	
	public static int findDistant(int i, int pageid, int page[]) {
		for(; i<page.length; i++) {
			if(page[i] == pageid) {
				return i;
			}
		}
		return -1;
	}
	
	public static void simulateOptimal(int n, int capacity, int page[]) {
		HashSet<Integer> buffer = new HashSet<Integer>(capacity);
		
		int hit = 0, miss = 0;
		for(int i=0; i<n; i++) {
			System.out.println("Before page request : ");
			for(int r : buffer) {
				System.out.println(" --- ");
				System.out.println("| "+r+" |");
			}
			System.out.println(" --- ");
			
			if(buffer.contains(page[i])) {
				hit++;
			}
			else {
				miss++;
				if(buffer.size() < capacity) {
					buffer.add(page[i]);
				}
				else {
					int maxd = Integer.MIN_VALUE, val = 0, d;
					for(int r : buffer) {
						d = findDistant(i, r, page);
						if(d == -1) {
							val = r;
							break;
						}
						else if(d > maxd) {
							maxd = d;
							val = r;
						}
					}
					buffer.remove(val);
					buffer.add(page[i]);
				}
			}
			
			System.out.println("After page request : ");
			for(int r : buffer) {
				System.out.println(" --- ");
				System.out.println("| "+r+" |");
			}
			System.out.println(" --- ");
			
			System.out.println("Total hits : "+ hit);
			System.out.println("Total miss : "+ miss);
			System.out.println("--------------------------------------");
		}
		
	}
	
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		
		System.out.print("Enter the no. of pages : ");
		int n = in.nextInt();
		
		int page[] = new int[n];
		System.out.println("Enter the page ids : ");
		for(int i=0; i<n; i++) {
			page[i] = in.nextInt();
		}
		
		System.out.println("Enter the maximum buffer capacity : ");
		int capacity = in.nextInt();
		
		simulateOptimal(n, capacity, page);
	}

}
