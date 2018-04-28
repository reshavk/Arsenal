import java.util.ArrayList;

class MNT {
	int mntp, mdtp;
	String mname;
	ArrayList<ALA> ala;
	
	MNT(int mntp, String mname, int mdtp, ArrayList<ALA> ala) {
		this.mntp = mntp;
		this.mname = mname;
		this.mdtp = mdtp;
		this.ala = new ArrayList<ALA>();
		for(int i=0; i<ala.size(); i++) {
			this.ala.add(ala.get(i));
		}
	}
}

class MDT {
	int mdtp;
	String md;
	
	MDT(int mdtp, String md) {
		this.mdtp = mdtp;
		this.md = md;
	}
}

class ALA {
	String argname, argval;
	
	ALA(String argname, String argval) {
		this.argname = argname;
		this.argval = argval;
	}
}