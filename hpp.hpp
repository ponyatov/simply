#ifndef _H_HPP
#define _H_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;

struct Sym {
	string tag,val;
	Sym(string,string); Sym(string);
	vector<Sym*> nest; void push(Sym*);
	virtual string head(); string pad(int);
	virtual string dump(int=0);
	virtual Sym* pfxadd();
	virtual Sym* pfxsub();
};

struct Int : Sym { Int(string); string head(); int val; };
struct Num : Sym { Num(string); string head(); float val; };

struct Str : Sym { Str(string); };

struct Op : Sym { Op(string); };

extern int yylex();
extern int yylineno;
extern char* yytext;
#define TOC(C,X) { yylval.o = new C(yytext); return X; }
extern int yyparse();
extern void yyerror(string);
#include "ypp.tab.hpp"

#endif // _H_HPP
