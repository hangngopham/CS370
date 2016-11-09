

delim   [ \t\n]   
ws      {delim}+

%%

if      {return(IF);}
cond    {return(COND);}
else    {return(ELSE);}
stmt    {return(STMT);}
{ws}    {/* no action and no return */} 
.       {/* no action and no return */}

%%
