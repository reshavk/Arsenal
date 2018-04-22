import java.util.*;

public class operation {
	
	public native int add(int a, int b);
	public native int sub(int a, int b);
	public native int mult(int a, int b);
	public native int div(int a, int b);
	
	public static void main(String args[]) {
		System.loadLibrary("operation");
		operation obj = new operation();
		Scanner in = new Scanner(System.in);
		
		boolean flag = true;
		while(flag) {
			System.out.println("Choose opeartion :\n1:Add\n2:Sub\n3:Multiply\n4:Div\n");
			int o = in.nextInt();
			System.out.print("Enter operand 1 : ");
			int a = in.nextInt();
			System.out.print("Enter operand 2 : ");
			int b = in.nextInt();
			switch(o) {
				case 1 : {
					System.out.println("Result of addition : "+obj.add(a, b));
					break;
				}
				case 2 : {
					System.out.println("Result of subtraction : "+obj.sub(a, b));
					break;
				}
				case 3 : {
					System.out.println("Result of multiplication : "+obj.mult(a, b));
					break;
				}
				case 4 : {
					System.out.println("Result of division : "+obj.div(a, b));
					break;
				}
				default : {
					System.out.println("Invalid Choice");
				}
			}
			
			System.out.println("Continue(y/n) : ");
			String c;
			c = in.next();
			if(c.equals("n") || c.equals("N")) {
				flag = false;
			}	
		}
		in.close();
	}
}
