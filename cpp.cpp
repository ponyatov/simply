#include "hpp.hpp"
#define YYERR "\n\n"<<yylineno<<":"<<msg<<"["<<yytext<<"]\n\n"
void yyerror(string msg) { cout<<YYERR; cerr<<YYERR; exit(-1); }
int main() { return yyparse(); }

Sym::Sym(string T, string V) { tag=T; val=V; }
Sym::Sym(string V):Sym("sym",V){}
void Sym::push(Sym*o) { nest.push_back(o); }

string Sym::pad(int n) { string S; for (int i=0;i<n;i++) S+='\t'; return S; }
string Sym::head() { ostringstream os;
	os<<"<"<<tag<<":"<<val<<"> ^"<<this; return os.str(); }
string Sym::dump(int depth) { string S = "\n"+pad(depth)+head();
	for (auto it=nest.begin(),e=nest.end();it!=e;it++)
		S += (*it)->dump(depth+1);
	return S; }

Sym* Sym::pfxadd() { val="+"+val; return this; }
Sym* Sym::pfxsub() { val="-"+val; return this; }

Int::Int(string V):Sym("int",V){ val=atoi(V.c_str()); }
string Int::head() { ostringstream os;
	os<<"<"<<tag<<":"<<val<<"> ^"<<this; return os.str(); }

Num::Num(string V):Sym("num",V){ val=atof(V.c_str()); }
string Num::head() { ostringstream os;
	os<<"<"<<tag<<":"<<val<<"> ^"<<this; return os.str(); }

Str::Str(string V):Sym("str",V){}

Op::Op(string V):Sym("op",V){}

