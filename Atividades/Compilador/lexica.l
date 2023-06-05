%{
#include <string>

%}

ESPACO [ \t]
DIGITO [0-9]
LETRA [A-Za-z_]
DELIM {ESPACO}+

INT ({DIGITO}+|"-"{DIGITO}+)
FLOAT {INT}+("."{INT}+)?
CHAR \'({LETRA}|{INT})\'
BOOL \'(true|false)\'
ID {LETRA}({LETRA}|{INT})*


%%

"\n"		{}

{DELIM} 	{}

"main"		{return TK_MAIN;}

"int"		{return TK_TIPO_INT;}

"float"		{return TK_TIPO_FLOAT;}

"bool"		{return TK_TIPO_BOOL;}

"char"		{return TK_TIPO_CHAR;}

[(){}[\];,:]	{ return *yytext; }

[+\-*/=^<>]	{ return *yytext; }


{INT}		{ yylval.traducao = yytext; return TK_INT; }
{ID}		{ yylval.label = yytext; return TK_ID; }
{FLOAT}     { yylval.label = yytext; return TK_FLOAT; }
{CHAR}      { yylval.label = yytext; return TK_CHAR; }
{BOOL}      { yylval.label = yytext; return TK_BOOL; }

.			{ *yytext; }

%%
