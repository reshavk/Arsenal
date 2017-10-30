import java.net.*;
import java.io.*;
import java.util.*;

class SerMulti {
	static int port;
	static HashSet<PrintWriter> writers = new HashSet<PrintWriter>();
	ServerSocket serverSocket;
	
	public SerMulti() {
		try {
			serverSocket = new ServerSocket(port);
			System.out.println("Server up and runnning...");
		}
		catch(Exception e) {
			
		}
	}
	
	public void connect() {
		try {
			while(true) {
				new Handler(serverSocket.accept()).start();
			}
		}
		catch(Exception e) {
			System.out.println(e);
			System.exit(0);
		}		
	}
	
	private static class Handler extends Thread {
		Socket socket = null;
		BufferedReader in;
		PrintWriter out;
		
		public Handler(Socket s) {
			this.socket = s;
			System.out.println("Client connected to server.");
		}
		
		public void run() {
			try {
				out = new PrintWriter(socket.getOutputStream(), true);
				writers.add(out);
				in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
				
				readThread();
			}
			catch(Exception e) {
				System.out.print(e);
				System.exit(0);
			}
						
		}
		
		public synchronized void readThread() {
			Thread read = new Thread() {
				public void run() {
					String data;
					try {
						while( (data = in.readLine()) != null) {	
							System.out.println(data);
							for(PrintWriter w : writers) {
								w.println(data);
							}
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
		
	}
	
	public static void main(String args[]) {
		port = 8000;
		SerMulti server = new SerMulti();
		server.connect();
	}
	
}

