import java.util.*;
import java.io.*;

public class pass2 {
	
	static ArrayList<SYM> sym;
	static ArrayList<LIT> lit;
	
	public static void main(String args[])throws Exception {
		sym = new ArrayList<SYM>();
		lit = new ArrayList<LIT>();
		
		Scanner symfile = new Scanner(new FileInputStream("sym.txt"));
		Scanner litfile = new Scanner(new FileInputStream("lit.txt"));
		Scanner intcode = new Scanner(new FileInputStream("intcode.txt"));
		BufferedWriter output = new BufferedWriter(new FileWriter("output.txt"));
		
		while(symfile.hasNext()) {
			sym.add(new SYM(symfile.next(), symfile.nextInt()));
		}
		
		while(litfile.hasNext()) {
			lit.add(new LIT(litfile.next(), litfile.nextInt()));
		}
		symfile.close();
		litfile.close();
		
		while(intcode.hasNext()) {
			String line = intcode.nextLine();
			String words[] = line.split("( |\t)+");
			output.write(words[0] + "\t+\t" );
			
			for(int i=1; i<words.length; i++) {
				switch(words[i].charAt(0)) {
					case 'I': {
						output.write(words[i].substring(3) + "\t");
						break;
					}
					case 'C': {
						output.write(words[i].substring(3) + "\t");
						break;
					}
					case 'R': {
						output.write(words[i].substring(3) + "\t");
						break;
					}
					case 'S': {
						int pos = Integer.parseInt(words[i].substring(2)) -1;
						output.write(sym.get(pos).addr + "\t");
						break;
					}
					case 'L': {
						int pos = Integer.parseInt(words[i].substring(2)) -1;
						output.write(lit.get(pos).addr + "\t");
						break;
					}
					case 'D' : {
						if(words[i].charAt(3) == '1') {
							i++;
							break;
						}
						else {
							int pos = Integer.parseInt(words[i+1].substring(2))-1;
							output.write(sym.get(pos).addr + "\t");
							output.write(words[i+2].substring(2));
							break;
						}
					}
				}
			}
			output.write("\n");
		}
		intcode.close();
		output.close();
	}

}
