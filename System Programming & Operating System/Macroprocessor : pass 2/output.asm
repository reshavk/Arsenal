START 200
MOVER AREG,A
MOVEM BREG,B

MOVER DATA3 DATA1 
ADD DATA3 DATA2 
MOVEM DATA3 DATA1 
ADD AREG,B

MOVER DATA3 DATA1 
SUB DATA3 DATA2 
MOVEM DATA3 DATA1 
MOVER BREG,='1'

MOVER DATA1 DATA3 
ADD DATA1 DATA2 
MOVEM DATA1 DATA3 
MOVEM BREG,A
SUB AREG,A
DATA1 DC '5'
DATA2 DC '10'
DATA3 DC '5'
END
