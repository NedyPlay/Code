%{
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#define YYSTYPE atributos

using namespace std;

//Variável Global
int var_qntd = 0;

//Estruturas
struct atributos
{
	string label;
	string traducao;
	string tipo;
};
typedef struct {
	string nomeVariavel;
	string tipoVariavel;
	//int memoria; Local onde foi salva na pilha
} TIPO_SIMBOLO;

vector<TIPO_SIMBOLO> tabelaSimbolos;

//Funções
int yylex(void);
void yyerror(string);
string genLabel(string tipo);
string genVar(string tipo, string nome);
string changeType(string tipo);
string declarAll(); 
//string verificaTipos($1.tipo, $3.tipo, operacao); isso aq vai ser mto bom [Thiago]

%}

%token TK_INT TK_FLOAT TK_BOOL TK_CHAR
%token TK_MAIN TK_ID TK_TIPO_INT TK_TIPO_FLOAT TK_TIPO_CHAR TK_TIPO_BOOL
%token TK_FIM TK_ERROR

%start S

%left '+' '-'
%left '*' '/'
%right '^'

%%

S 			: TK_TIPO_INT TK_MAIN '(' ')' BLOCO
			{
				cout << "/*Compilador FOCA*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main(void)\n{\n" << declarAll() << $5.traducao << "\treturn 0;\n}" << endl; 
			}
			;

BLOCO		: '{' COMANDOS '}'
			{
				$$.traducao = $2.traducao;
			}
			;

COMANDOS	: COMANDO COMANDOS
			{
				$$.traducao = $1.traducao + $2.traducao;
			}
			|
			{
				$$.traducao = "";
			}
			;
TIPO		: TK_TIPO_BOOL {$$.tipo = "bool";}		| TK_BOOL {$$.tipo = "bool";}
			| TK_TIPO_CHAR {$$.tipo = "char";} 		| TK_CHAR {$$.tipo = "char";} 	
			| TK_TIPO_FLOAT {$$.tipo = "float";} 	| TK_FLOAT {$$.tipo = "float";}
			| TK_TIPO_INT {$$.tipo = "int";} 		| TK_INT {$$.tipo = "int";}
			;
COMANDO 	: E ';'
			;

E			: E '+' E
			{
				if($1.tipo == $3.tipo)
				{
					$$.label = genLabel($$.tipo);
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " + " + $3.label + ";\n";
				}
				else if ($1.tipo == "float" && $3.tipo == "int")
				{
					$3.label = "(float)" + $3.label;
					$2.label = genLabel("float");
					$3.traducao = $3.traducao + "\t" + $2.label + " = " + $3.label + ";\n";
					$$.label = genLabel("float");
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $2.label + " + " + $1.label + ";\n";
				}
				else if ($1.tipo == "int" && $3.tipo == "float")
				{
					$1.label = "(float)" + $1.label;
					$2.label = genLabel("float");
					$3.traducao = $3.traducao + "\t" + $2.label + " = " + $1.label + ";\n";
					$$.label = genLabel("float");
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $2.label + " + " + $3.label + ";\n";
				}

				/*if($1.tipo == $3.tipo)
				{
					$$.label = genLabel($$.tipo);
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " + " + $3.label + ";\n";
				}
				else
				{
					//$$.traducao = $1.traducao + $3.traducao + verificaTipos($1.tipo, $3.tipo, operacao);
				}*/
			
			}
			| E '-' E
			{
				if($1.tipo == $3.tipo)
				{
					$$.label = genLabel($$.tipo);
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " - " + $3.label + ";\n";
				}
				else if ($1.tipo == "float" && $3.tipo == "int")
				{
					$3.label = "(float)" + $3.label;
					$2.label = genLabel("float");
					$3.traducao = $3.traducao + "\t" + $2.label + " = " + $3.label + ";\n";
					$$.label = genLabel("float");
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $2.label + " - " + $1.label + ";\n";
				}
				else if ($1.tipo == "int" && $3.tipo == "float")
				{
					$1.label = "(float)" + $1.label;
					$2.label = genLabel("float");
					$3.traducao = $3.traducao + "\t" + $2.label + " = " + $1.label + ";\n";
					$$.label = genLabel("float");
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $2.label + " - " + $3.label + ";\n";
				}
			}
			| E '*' E
			{
				if($1.tipo == $3.tipo)
				{
					$$.label = genLabel($$.tipo);
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " * " + $3.label + ";\n";
				}
				else if ($1.tipo == "float" && $3.tipo == "int")
				{
					$3.label = "(float)" + $3.label;
					$2.label = genLabel("float");
					$3.traducao = $3.traducao + "\t" + $2.label + " = " + $3.label + ";\n";
					$$.label = genLabel("float");
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $2.label + " * " + $1.label + ";\n";
				}
				else if ($1.tipo == "int" && $3.tipo == "float")
				{
					$1.label = "(float)" + $1.label;
					$2.label = genLabel("float");
					$3.traducao = $3.traducao + "\t" + $2.label + " = " + $1.label + ";\n";
					$$.label = genLabel("float");
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $2.label + " * " + $3.label + ";\n";
				}
			}
			| E '/' E
			{	
				if($1.tipo == $3.tipo)
				{
					$$.label = genLabel($$.tipo);
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " / " + $3.label + ";\n";
				}
				else if ($1.tipo == "float" && $3.tipo == "int")
				{
					$3.label = "(float)" + $3.label;
					$2.label = genLabel("float");
					$3.traducao = $3.traducao + "\t" + $2.label + " = " + $3.label + ";\n";
					$$.label = genLabel("float");
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $2.label + " / " + $1.label + ";\n";
				}
				else if ($1.tipo == "int" && $3.tipo == "float")
				{
					$1.label = "(float)" + $1.label;
					$2.label = genLabel("float");
					$3.traducao = $3.traducao + "\t" + $2.label + " = " + $1.label + ";\n";
					$$.label = genLabel("float");
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $2.label + " / " + $3.label + ";\n";
				}
			}
			| E '^' E
			{
				if($1.tipo == $3.tipo)
				{
					$$.label = genLabel($$.tipo);
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = pow(" + $1.label + ", " + $3.label + ");\n";
				}
				else if ($1.tipo == "float" && $3.tipo == "int")
				{
					$3.label = "(float)" + $3.label;
					$2.label = genLabel("float");
					$3.traducao = $3.traducao + "\t" + $2.label + " = " + $3.label + ";\n";
					$$.label = genLabel("float");
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = pow(" + $2.label + ", " + $1.label + ");\n";
				}
				else if ($1.tipo == "int" && $3.tipo == "float")
				{
					$1.label = "(float)" + $1.label;
					$2.label = genLabel("float");
					$3.traducao = $3.traducao + "\t" + $2.label + " = " + $1.label + ";\n";
					$$.label = genLabel("float");
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = pow(" + $2.label + ", " + $3.label + ");\n";
				}
			}
			| E '>' E
			{
				if($1.tipo == $3.tipo)
				{
					$$.label = genLabel($$.tipo);
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " > " + $3.label + ";\n";
				}
				else if ($1.tipo == "float" && $3.tipo == "int")
				{
					$3.label = "(float)" + $3.label;
					$2.label = genLabel("float");
					$3.traducao = $3.traducao + "\t" + $2.label + " = " + $3.label + ";\n";
					$$.label = genLabel("float");
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " > " + $2.label + ";\n";
				}
				else if ($1.tipo == "int" && $3.tipo == "float")
				{
					$1.label = "(float)" + $1.label;
					$2.label = genLabel("float");
					$3.traducao = $3.traducao + "\t" + $2.label + " = " + $1.label + ";\n";
					$$.label = genLabel("float");
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $2.label + " > " + $3.label + ";\n";
				}
			}
			| E '<' E
			{
				if($1.tipo == $3.tipo)
				{
					$$.label = genLabel($$.tipo);
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $3.label + " < " + $1.label + ";\n";
				}
				else if ($1.tipo == "float" && $3.tipo == "int")
				{
					$3.label = "(float)" + $3.label;
					$2.label = genLabel("float");
					$3.traducao = $3.traducao + "\t" + $2.label + " = " + $3.label + ";\n";
					$$.label = genLabel("float");
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $2.label + " < " + $1.label + ";\n";
				}
				else if ($1.tipo == "int" && $3.tipo == "float")
				{
					$1.label = "(float)" + $1.label;
					$2.label = genLabel("float");
					$3.traducao = $3.traducao + "\t" + $2.label + " = " + $1.label + ";\n";
					$$.label = genLabel("float");
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $3.label + " < " + $2.label + ";\n";
				}
			}
			| TIPO TK_ID '=' E
			{
				if($1.tipo != $4.tipo){
					
				}
				bool encontrei = false;
				TIPO_SIMBOLO variavel;
				for(int i = 0; i < tabelaSimbolos.size(); i++){
					if(tabelaSimbolos[i].nomeVariavel == $1.label){
						variavel = tabelaSimbolos[i];
						encontrei = true;
						var_qntd--;
					}
				}
				
				$$.tipo = genVar($$.tipo, $2.label);
				$$.traducao = $4.traducao + "\t" + $$.tipo + "\n" + "\t" + $3.label + " = " + $4.label + ";\n";
			}
			| TIPO TK_ID
			{
				genVar($$.tipo, $2.label);
			}
			| '-'TIPO
			{
				$$.label = genLabel($$.tipo);
				$$.traducao = "\t" + $$.label + " = " + '-' + $2.traducao + ";\n";
			}
			| TIPO
			{
				$$.label = genLabel($$.tipo);
				if($$.tipo == "int")
				{
					$$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n";
				}
				else{
					$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
				}
				
			}
			| TK_ID '=' E
			{
				if($1.tipo != $3.tipo){
					
				}
				bool encontrei = false;
				TIPO_SIMBOLO variavel;
				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{
					if(tabelaSimbolos[i].nomeVariavel == $1.label)
					{
						variavel = tabelaSimbolos[i];
						encontrei = true;
					}
				}
				if(!encontrei){
					yyerror($$.label + " >>> Variavel nao declarada");
				}
				$1.label = variavel.nomeVariavel;
				$$.traducao = $1.traducao + $3.traducao +  "\t" + $1.label + " = " + $3.label + ";\n";
			}
			| TK_ID ':' '=' E //Go Like
			{
				genVar($4.tipo, $2.label);
				$$.traducao = $4.traducao + "\t" + $2.label + " = " + $4.tipo + ";\n";
			}
			| TK_ID
			{
				bool encontrei = false;
				TIPO_SIMBOLO variavel;
				for(int i = 0; i < tabelaSimbolos.size(); i++){
					if(tabelaSimbolos[i].nomeVariavel == $1.label){
						variavel = tabelaSimbolos[i];
						encontrei = true;
					}
				}
				if(!encontrei){
					yyerror($$.label + " >>> Variavel nao declarada");
					var_qntd--;
				}
				genVar($$.tipo, $1.label);
				$$.traducao = "";
			}
			;

%%

#include "lex.yy.c"

//Funções
string genLabel (string tipo)
{
	var_qntd++;
	string temp = "temp" + std::to_string(var_qntd);
	TIPO_SIMBOLO valor;
	valor.nomeVariavel = temp;
	valor.tipoVariavel = tipo;
	tabelaSimbolos.push_back(valor);
	return "temp" + std::to_string(var_qntd);
}

string genVar (string tipo, string nome)
{
	TIPO_SIMBOLO valor;
	valor.nomeVariavel = nome;
	valor.tipoVariavel = tipo;

	for(int i = 0; i < tabelaSimbolos.size(); i++)
	{
		if(tabelaSimbolos[i].nomeVariavel == valor.nomeVariavel && tabelaSimbolos[i].tipoVariavel == valor.tipoVariavel) 
		{
			if(tabelaSimbolos[i].tipoVariavel == valor.tipoVariavel){
				yyerror(valor.nomeVariavel + " >>> Variavel ja declarada");
			}
			var_qntd--;
		}
		
	}

	tabelaSimbolos.push_back(valor);
	return "";
}
string declarAll() {
	int i;
	for (i = 0; i < tabelaSimbolos.size(); i++){
		cout << "\t" + tabelaSimbolos[i].tipoVariavel + " " + tabelaSimbolos[i].nomeVariavel + ";\n";
	}
	return "";
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
