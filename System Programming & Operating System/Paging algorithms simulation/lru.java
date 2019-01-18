import java.util.*;

public class lru {
	
	public static void simulateLRU(int n, int capacity, int page[]) {
		HashSet<Integer> buffer = new HashSet<Integer>(capacity);
		HashMap<Integer,Integer> m = new HashMap<Integer, Integer>();
		
		int hit = 0, miss = 0;
		for(int i=0; i<n; i++) {
			System.out.println("Before page request : ");
			for(int r : buffer) {
				System.out.println(" --- ");
				System.out.println("| " + r + " |");
			}
			System.out.println(" --- ");
			
			if(buffer.contains(page[i])) {
				hit++;
				m.replace(page[i], i);
			}
			else {
				miss++;
				if(buffer.size() < capacity) {
					buffer.add(page[i]);
					m.put(page[i], i);
				}
				else {
					int min = Integer.MAX_VALUE, val = 0;
					for(int r : buffer) {
						if(m.get(r) < min) {
							min = m.get(r);
							val = r;
						}
					}
					buffer.remove(val);
					buffer.add(page[i]);
					m.put(page[i], i);
				}
			}
			
			System.out.println("After page request : ");
			for(int r : buffer) {
				System.out.println(" --- ");
				System.out.println("| " + r + " |");
			}
			System.out.println(" --- ");
			
			System.out.println("Total hits : "+hit);
			System.out.println("Total miss : "+miss);
			System.out.println("----------------------------------------");
		}
		
	}
	
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		
		System.out.print("Enter the no. of pages : ");
		int n = in.nextInt();
		
		int page[] = new int[n];
		System.out.println("Enter the page ids : ");
		for(int i=0 ;i<n; i++) {
			page[i] = in.nextInt();
		}
		
		System.out.println("Enter the maximum buffer capacity : ");
		int capacity = in.nextInt();
		
		simulateLRU(n,capacity, page);
		in.close();
	}

}
