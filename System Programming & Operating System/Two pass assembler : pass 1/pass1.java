import java.util.*;
import java.io.*;

public class pass1 {
	static ArrayList<MOT> mot;
	static ArrayList<POT> pot;
	static ArrayList<SYM> sym;
	static ArrayList<LIT> lit;
	
	public static int inpot(String s) {
		for(int i=0; i<pot.size(); i++) {
			if(pot.get(i).inst.equals(s))
				return i;
		}
		return -1;
	}
	
	public static int inmot(String s) {
		for(int i=0; i<mot.size(); i++) {
			if(mot.get(i).inst.equals(s))
				return i;
		}
		return -1;
	}
	
	public static int insym(String s) {
		for(int i=0; i<sym.size(); i++) {
			if(sym.get(i).sym.equals(s))
				return i;
		}
		return -1;
	}
	
	public static int inlit(String s, int i) {
		for(; i<lit.size(); i++) {
			if(lit.get(i).lit.equals(s))
				return i;
		}
		return -1;
	}
	
	public static void main(String args[])throws Exception {
		mot = new ArrayList<MOT>();
		pot = new ArrayList<POT>();
		sym = new ArrayList<SYM>();
		lit = new ArrayList<LIT>();
		
		Scanner input = new Scanner(new FileInputStream("input.asm"));
		Scanner motfile = new Scanner(new FileInputStream("mot.txt"));
		Scanner potfile = new Scanner(new FileInputStream("pot.txt"));
		BufferedWriter intcode = new BufferedWriter(new FileWriter("intcode.asm"));
		
		while(motfile.hasNext()) {
			mot.add(new MOT(motfile.next(), motfile.nextInt(), motfile.nextInt()));
		}
		
		while(potfile.hasNext()) {
			pot.add(new POT(potfile.next(), potfile.nextInt()));
		}
		motfile.close();
		potfile.close();
		
		int loc = 0, pool = 0;
		int pos;
		while(input.hasNext()) {
			int p = 0;
			String line = input.nextLine();
			line.trim();
			String words[] = line.split("( |\t)+");
			if(words.length == 3) {
				pos = insym(words[p]);
				if(pos == -1) {
					sym.add(new SYM(words[p], loc));
				}
				else {
					sym.get(pos).addr = loc;
				}
				p++;
			}
			pos = inpot(words[p]);
			if(pos == -1) {
				pos = inmot(words[p]);
				if( (pos+1) == 7 ) {
					String arg[] = words[p+1].split(",");
					intcode.write(loc + "\t" + "IS," + (pos+1) + "\t");
					if(arg[0].equals("LT")) {
						intcode.write("CC,1" + "\t");
					}
					else if(arg[0].equals("LE")) {
						intcode.write("CC,2" + "\t");
					}
					else if(arg[0].equals("GT")) {
						intcode.write("CC,3" + "\t");
					}
					else if(arg[0].equals("GE")) {
						intcode.write("CC,4" + "\t");
					}
					
					pos = insym(arg[1]);
					if(pos == -1) {
						sym.add(new SYM(arg[1], -1));
						intcode.write("S," + sym.size());
					}
					else {
						intcode.write("S,"+(pos+1));
					}
				}
				else {
					intcode.write(loc + "\t" + "IS," + (pos+1) + "\t");
					String arg[] = words[p+1].split(",");
					for(int i=0; i<arg.length; i++) {
						if(arg[i].equals("AREG")) {
							intcode.write("RG,1\t");
						}
						else if(arg[i].equals("BREG")) {
							intcode.write("RG,2\t");
						}
						else if(arg[i].equals("CREG")) {
							intcode.write("RG,3\t");
						}
						else if(arg[i].equals("DREG")) {
							intcode.write("RG,4\t");
						}
						else {
							if(arg[i].charAt(0) == '=') {
								pos = inlit(arg[i], pool);
								if(pos == -1) {
									lit.add(new LIT(arg[i], -1));
									intcode.write("L,"+lit.size() + "\t");
								}
								else {
									intcode.write("L,"+(pos+1) + "\t");
								}
							}
							else {
								pos = insym(arg[i]);
								if(pos == -1) {
									sym.add(new SYM(arg[i], -1));
									intcode.write("S,"+sym.size() + "\t");
								}
								else {
									intcode.write("S," +(pos+1) + "\t");
								}
							}
						}
					}
				}
				intcode.write("\n");
				loc++;
			}
			else {
				switch(pos+1) {
					case 1 : {
						if(words.length == 2) {
							loc = Integer.parseInt(words[1]);
						}
						else {
							loc = 0;
						}
						break;
					}
					case 2 :
					case 3 : {
						for(int i=pool; i<lit.size(); i++) {
							lit.get(i).addr = loc++;
						}
						pool = lit.size();
						break;
					}
					case 4 : {
						intcode.write(loc + "\t" + "DL,1" + "\t");
						pos = insym(words[p-1]);
						intcode.write("S,"+(pos+1) + "\n");
						sym.get(pos).addr = loc;
						loc += Integer.parseInt(words[p+1]);
						
						break;
					}
					case 5 : {
						System.out.println(words[p]);
						intcode.write(loc + "\t" + "DL,2" + "\t");
						pos = insym(words[p-1]);
						intcode.write("S,"+(pos+1) + "\t");
						intcode.write(words[p+1].charAt(1) + "\n");
						sym.get(pos).addr = loc;
						loc++;
						break;
					}
				}
			}
		}
		intcode.close();
		input.close();
		
		System.out.println("Symbol Table");
		for(int i=0; i<sym.size(); i++) {
			System.out.println(sym.get(i).sym + "\t" + sym.get(i).addr);
		}
		System.out.println();
		System.out.println("Literal Table");
		for(int i=0; i<lit.size(); i++) {
			System.out.println(lit.get(i).lit + "\t" + lit.get(i).addr);
		}

	}

}
