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
	string nomeTemp;
	//int memoria; Local onde foi salva na pilha
} TIPO_SIMBOLO;

string functions[20];
vector<TIPO_SIMBOLO> tabelaSimbolos;

//Funções
int yylex(void);
void yyerror(string);
string genLabel(string tipo);
TIPO_SIMBOLO genVar(string tipo, string nome);
string declarAll(); 
TIPO_SIMBOLO typeVerify(string tipo1, string tipo2);
//string verificaTipos($1.tipo, $3.tipo, operacao); isso aq vai ser mto bom [Thiago]

%}

%token TK_INT TK_FLOAT TK_BOOL TK_CHAR TK_STRING
%token TK_MAIN TK_ID TK_TIPO_INT TK_TIPO_FLOAT TK_TIPO_CHAR TK_TIPO_BOOL TK_TIPO_STRING
%token TK_FIM TK_ERROR

%start S

%left '+' '-'
%left '*' '/'
%right '^'

%%

S 			: TK_TIPO_INT TK_MAIN '(' ')' BLOCO
			{
				cout << "/*Compilador Silk*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main(void)\n{\n" << declarAll() << $5.traducao << "\treturn 0;\n}" << endl; 
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
			| TK_TIPO_STRING {$$.tipo = "string";} 		| TK_STRING {$$.tipo = "string";}
			;
COMANDO 	: E ';'
			;

E			: E '+' E
			{
				if(($1.tipo != "int" &&  $1.tipo != "float") || ($3.tipo != "int" &&  $3.tipo != "float"))
				{
					
				}
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
			
			}
			| E '-' E
			{
				if(($1.tipo != "int" &&  $1.tipo != "float") || ($3.tipo != "int" &&  $3.tipo != "float"))
				{
					yyerror($1.tipo + " " + $3.tipo);
				}
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
				if(($1.tipo != "int" &&  $1.tipo != "float") || ($3.tipo != "int" &&  $3.tipo != "float"))
				{
					yyerror($1.tipo + " " + $3.tipo);
				}
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
				if(($1.tipo != "int" &&  $1.tipo != "float") || ($3.tipo != "int" &&  $3.tipo != "float"))
				{
					yyerror($1.tipo + " " + $3.tipo);
				}
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
				if(($1.tipo != "int" &&  $1.tipo != "float") || ($3.tipo != "int" &&  $3.tipo != "float"))
				{
					yyerror($1.tipo + " " + $3.tipo);
				}
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
				TIPO_SIMBOLO variavel;
				int find = 0;
				if($2.tipo != $4.tipo)
				{
					cout << "\taoba\n";
					//variavel = typeVerify($1.tipo, $4.tipo);
				}

				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{
					if(tabelaSimbolos[i].nomeVariavel == $2.label){
						variavel = tabelaSimbolos[i];
						find = 1;
					}
					if(tabelaSimbolos[i].nomeVariavel == $4.label)
					{
						TIPO_SIMBOLO variavel2 = tabelaSimbolos[i];
						$4.label = variavel2.nomeTemp;
						$4.tipo = variavel2.tipoVariavel;
					}
				}

				if(!find)
				{
					variavel = genVar($$.tipo, $2.label);
					$2.label = variavel.nomeTemp;
					$2.tipo = variavel.tipoVariavel;
				}
				
				
				$$.traducao = $4.traducao + "\t" + $2.label + " = " + $4.label + ";\n";
			}
			| TIPO TK_ID
			{
				TIPO_SIMBOLO variavel = genVar($$.tipo, $2.label);
				$$.label = $2.label;
			}
			| '-'TK_INT
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
				bool encontrei = false;
				TIPO_SIMBOLO variavel;
				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{
					if(tabelaSimbolos[i].nomeVariavel == $1.label)
					{
						variavel = tabelaSimbolos[i];
						encontrei = true;
					}
					if(tabelaSimbolos[i].nomeVariavel == $3.label)
					{
						TIPO_SIMBOLO variavel2 = tabelaSimbolos[i];
						$3.label = variavel2.nomeTemp;
						$3.tipo = variavel2.tipoVariavel;
					}
				}
				if(!encontrei){
					yyerror($$.label + " >>> Variavel nao declarada");
				}
				if($1.tipo != $3.tipo){
					
				}
				$1.label = variavel.nomeTemp;
				$$.traducao = $1.traducao + $3.traducao +  "\t" + variavel.nomeTemp + " = " + $3.label + ";\n";
			}
			| TK_ID ':' '=' E //Go Like
			{
				int encontrei = 1;
				TIPO_SIMBOLO variavel;
				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{
					if(tabelaSimbolos[i].nomeVariavel == $4.label)
					{
						TIPO_SIMBOLO variavel2 = tabelaSimbolos[i];
						$4.label = variavel2.nomeTemp;
						$4.tipo = variavel2.tipoVariavel;
						continue;
					}
					if(tabelaSimbolos[i].nomeVariavel == $1.label)
					{
						variavel = tabelaSimbolos[i];
						encontrei = 0;
					}
				}
				if(encontrei)
				{
					variavel = genVar($4.tipo, $2.label);
				}
				$$.traducao = $4.traducao + "\t" + variavel.nomeTemp + " = " + $4.label + ";\n";
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
					
				}
				variavel = genVar($$.tipo, $1.label);
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
	valor.nomeTemp = temp;
	tabelaSimbolos.push_back(valor);
	return temp;
}

TIPO_SIMBOLO genVar (string tipo, string nome)
{
	TIPO_SIMBOLO valor;
	valor.nomeVariavel = nome;
	valor.tipoVariavel = tipo;

	for(int i = 0; i < tabelaSimbolos.size(); i++)
	{
		if(tabelaSimbolos[i].nomeVariavel == valor.nomeVariavel) 
		{
			return valor;
		}
		
	}
	var_qntd++;
	valor.nomeTemp = "temp" + std::to_string(var_qntd);
	tabelaSimbolos.push_back(valor);
	cout << "\t/*Variavel declarada:\n\tNome: " + valor.nomeVariavel + "\n\tTipo: " + valor.tipoVariavel + "\n\tTemporaria: " + valor.nomeTemp + "\n\t*/\n";
	return valor;
}

string declarAll()
{
	int i;
	for (i = 0; i < tabelaSimbolos.size(); i++){
		cout << "\t" + tabelaSimbolos[i].tipoVariavel + " " + tabelaSimbolos[i].nomeTemp + ";\n";
	}
	return "";
}

TIPO_SIMBOLO typeVerify(string tipo1, string tipo2)
{
	TIPO_SIMBOLO variavel;
	return variavel;
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
