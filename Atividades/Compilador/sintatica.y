%{
#include <iostream>
#include <string>
#include <sstream>

#define YYSTYPE atributos

using namespace std;

//Variável Global
int var_qntd = 0;

//Estruturas
struct atributos
{
	string label;
	string traducao;
};

//Funções - P
int yylex(void);
void yyerror(string);
string genLabel();

%}

%token TK_NUM
%token TK_MAIN TK_ID TK_TIPO_INT
//%token TK_FIM TK_ERROR

%start S

%left '+'

%%

S 			: TK_TIPO_INT TK_MAIN '(' ')' BLOCO
			{
				cout << "/*Compilador FOCA*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main(void)\n{\n" << $5.traducao << "\treturn 0;\n}" << endl; 
			}
			;

BLOCO		: '{' COMANDOS '}'
			{
				$$.traducao = $2.traducao;
			}
			;

COMANDOS	: COMANDO COMANDOS
			|
			;

COMANDO 	: E ';'
			;

E			: E '+' E
			{
				$$.label = genLabel();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " + " + $3.label + ";\n";
			}
			| E '-' E
			{
				$$.label = genLabel();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " - " + $3.label + ";\n";
			}
			| E '*' E
			{
				$$.label = genLabel();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " * " + $3.label + ";\n";
			}
			| E '/' E
			{
				$$.label = genLabel();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " / " + $3.label + ";\n";
			}
			| TK_NUM
			{
				$$.label = genLabel();
				$$.traducao = "\t" +$$.label + " = " + $1.traducao + ";\n";
			}
			| TK_ID
			{
				$$.label = genLabel();
				$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
			}
			| TK_ID '=' TK_NUM
			{
				$$.label = genLabel();
				$$.traducao = $1.traducao + $3.traducao + "\tint " + $$.label; + " = " + $1.label = ";\n";
			} 
			;

%%

#include "lex.yy.c"

//Funções
string genLabel ()
{
	var_qntd++;
	return "t" + std::to_string(var_qntd);
}
int yyparse();

int main( int argc, char* argv[] )
{
	yyparse();

	return 0;
}

void yyerror( string MSG )
{
	cout << MSG << endl;
	exit (0);
}				
