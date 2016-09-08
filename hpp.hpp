#ifndef _H_HPP
#define _H_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;

struct Sym {
	string tag,val;
	Sym(string,string); Sym(string);
	virtual string head(); string pad(int);
	virtual string dump(int=0);
};

struct Num : Sym { Num(string); };

struct Op : Sym { Op(string); };

extern int yylex();
extern int yylineno;
extern char* yytext;
#define TOC(C,X) { yylval.o = new C(yytext); return X; }
extern int yyparse();
extern void yyerror(string);
#include "ypp.tab.hpp"

#endif // _H_HPP
