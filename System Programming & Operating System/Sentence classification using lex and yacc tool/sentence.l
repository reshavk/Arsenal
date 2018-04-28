%%
[^\n]+([aA][nN][dD]|[oO][rR]|[bB][uU][tT])+[^\n]+		{return COMP;}
.+		{return SIMP;}
\n		{return 0;}
%%
