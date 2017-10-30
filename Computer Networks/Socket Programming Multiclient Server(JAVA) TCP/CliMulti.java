import java.net.*;
import java.io.*;

class CliMulti {
	Socket socket;
	BufferedReader in, stdin;
	PrintWriter out;
	static String name;
	static int port;
	static String hostname;
	
	public void connect() {
		try {
			socket = new Socket(hostname, port);
			System.out.println("Connected to server.");
			in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			stdin = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(socket.getOutputStream(), true);
			
			System.out.print("Enter your screen name : ");
			name = stdin.readLine();
			out.println(name + " joined chat ! ");
		}
		catch(Exception e) {
			System.out.println(e);
			System.exit(0);
		}
	}
	
	public void readThread() {
		Thread read = new Thread() {
			public void run() {
				try {
					while(true) {
						System.out.println(in.readLine());
					}
				}
				catch(Exception e) {
					System.out.println(e);
					System.exit(0);
				}
			}
		};
		read.start();
	}
	
	public void writeThread() {
		Thread write = new Thread() {
			public void run() {
				try {
					while(true) {
						String msg = stdin.readLine();
						msg = name + " : " + msg;
						out.println(msg);
					}
				}
				catch(Exception e) {
					
				}
			}
		};
		write.start();
	}
	
	
	public static void main(String args[]) {
		hostname = "localhost";
		port = 8000;
		
		CliMulti client = new CliMulti();
		client.connect();
		
		client.writeThread();
		client.readThread();
	}
	
}
