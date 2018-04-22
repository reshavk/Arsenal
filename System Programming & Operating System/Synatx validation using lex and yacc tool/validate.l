%%
[ \t]		;
=		{return ASSIGN;}
[0-9]+		{return IC;}
["][^\n]["]		{return SC;}
static|public|protected|private		{return KEYWORD;}
int|float|long|double|String|void		{return TYPE;}
[_a-zA-Z][a-zA-Z0-9_]*		{return ID;}
,|;		{return yytext[0];}
\n		{return 0;}
.		{return 0;}
%%
