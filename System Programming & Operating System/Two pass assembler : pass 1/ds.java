class MOT {
	String inst;
	int length, addr;
	
	MOT(String inst, int length, int addr) {
		this.inst = inst;
		this.length = length;
		this.addr = addr;
	}
}

class POT {
	String inst;
	int addr;
	
	POT(String inst, int addr) {
		this.inst = inst;
		this.addr = addr;
	}
}

class SYM {
	String sym;
	int addr;
	
	SYM(String sym, int addr) {
		this.sym = sym;
		this.addr = addr;
	}
}

class LIT {
	String lit;
	int addr;
	
	LIT(String lit, int addr) {
		this.lit = lit;
		this.addr = addr;
	}
}