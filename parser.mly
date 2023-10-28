%{
open Ast;;
%}

%token EOF
%token <Range.t * string> IDENT
%token <Range.t> TRUE
%token <Range.t> FALSE

(* keywords *)
%token <Range.t> FUN
%token <Range.t> LET
%token <Range.t> RETURN
%token <Range.t> BREAK
%token <Range.t> LOOP
%token <Range.t> IF
%token <Range.t> ELSE
%token <Range.t> EXTERN
%token <Range.t> IMPORT

(* punctuation *)
%token <Range.t> LPAREN
%token <Range.t> RPAREN
%token <Range.t> LBRACE
%token <Range.t> RBRACE
%token <Range.t> LBRACK
%token <Range.t> RBRACK
%token <Range.t> STAR
%token <Range.t> COLON
%token <Range.t> COMMA
%token <Range.t> SEMICOLON
%token <Range.t> EQL
%token <Range.t> DOUBLECOLON

%token <Range.t> T_i64
%token <Range.t> T_i8
%token <Range.t> T_bool
%token <Range.t> T_str
%token <Range.t> T_UNIT

%token <Range.t * int64> INT
%token <Range.t * int> CHAR
%token <Range.t * string> STRING

%token <Range.t> ADD
%token <Range.t> SUB
%token <Range.t> SHIFTL
%token <Range.t> SHIFTR
%token <Range.t> SHIFTRA
%token <Range.t> LT
%token <Range.t> LE
%token <Range.t> GT
%token <Range.t> GE
%token <Range.t> EQ
%token <Range.t> NEQ
%token <Range.t> LAND
%token <Range.t> LOR
%token <Range.t> BAND
%token <Range.t> BOR
%token <Range.t> LNOT
%token <Range.t> BNOT

%start toplevel

%type <Ast.item list> toplevel
%type <Ast.typ> typ
%type <Ast.statement> statement

%left ADD SUB
%left STAR
%left SHIFTL SHIFTR SHIFTRA
%left LT LE GT GE
%left EQ NEQ
%left LAND
%left LOR
%left BAND
%left BOR
%nonassoc UMINUS

%%

toplevel:
  | b = EOF { [] }
  | f = func rest = toplevel { f :: rest }
  | f = extern_decl rest = toplevel { f :: rest }
  | import = import rest = toplevel { import :: rest }

extern_decl:
  | EXTERN FUN name = IDENT LPAREN args=args RPAREN SEMICOLON { ExternDecl(snd name, args, UnitTyp) }
  | EXTERN FUN name = IDENT LPAREN args=args RPAREN COLON ty=typ SEMICOLON { ExternDecl(snd name, args, ty) }

func:
  | FUN name = IDENT LPAREN args=args RPAREN body=block  { FuncDecl(snd name, args, body, UnitTyp) }
  | FUN name = IDENT LPAREN args=args RPAREN COLON ty=typ body=block  { FuncDecl(snd name, args, body, ty) }

import:
  | IMPORT p=path SEMICOLON { Import p }

path:
  | {[]}
  | ident=IDENT {[snd ident]}
  | ident=IDENT DOUBLECOLON rest=path {snd ident::rest}

args:
  | {[]}
  | arg=arg {[arg]}
  | arg = arg COMMA args=args {arg::args}

arg:
  | ident=IDENT COLON typ=typ {(snd ident, typ)}

typ:
  | T_i64 { I64 }
  | T_i8 { I8 }
  | T_bool { Bool }
  | T_str { Str }
  | T_UNIT { UnitTyp }
  | typ=typ STAR  { Ptr (typ) }
  | LBRACK typ=typ RBRACK { Arr (typ) }


block:
  | LBRACE block=_inblock RBRACE { block }
_inblock:
  | {[]}
  | statement=statement rest=_inblock {statement::rest}

statement:
  | LET name=IDENT EQL value=expr SEMICOLON { Let (snd name, value) }
  | name=IDENT EQL value=expr SEMICOLON { Assign (Ident(snd name), value) }
  | name=IDENT LBRACK idx=expr RBRACK EQL value=expr SEMICOLON { Assign (ArrIndex(snd name, idx), value) }
  | name=IDENT LPAREN args=_exprlist RPAREN SEMICOLON { Funccall (snd name, args ) }
  | RETURN x=expr SEMICOLON { Return x }
  | RETURN SEMICOLON { Return Unit }
  | LOOP b=block { Loop b }
  | BREAK SEMICOLON { Break }
  | IF cond=expr block=block { If (cond, block, []) }
  | IF cond=expr block=block ELSE otherwise=block { If (cond, block, otherwise) }


_exprlist:
  | {[]}
  | expr=expr { [expr] }
  | x=expr COMMA rest=_exprlist { x::rest }

expr:
  | LPAREN RPAREN { Unit }
  | LPAREN e=expr RPAREN {e}
  | arr=expr LBRACK e=expr RBRACK { Index (arr, e) }
  | x=IDENT { Var (snd x) }
  | lit=INT { Int (snd lit) }
  | lit=CHAR { Char (snd lit) }
  | lit=STRING { String (snd lit) }
  | lit=TRUE { Boolean (true) }
  | lit=FALSE { Boolean (false) }
  | name=IDENT LPAREN args=_exprlist RPAREN { Fn (snd name, args ) }
  | e1=expr STAR e2=expr {Bop (Mult, e1, e2)}
  | e1=expr ADD e2=expr {Bop (Add, e1, e2)}
  | e1=expr SUB e2=expr {Bop (Sub, e1, e2)}
  | e1=expr SHIFTL e2=expr {Bop (Shl, e1, e2)}
  | e1=expr SHIFTR e2=expr {Bop (Shr, e1, e2)}
  | e1=expr SHIFTRA e2=expr {Bop (Shrr, e1, e2)}
  | e1=expr LT e2=expr {Bop (Lt, e1, e2)}
  | e1=expr LE e2=expr {Bop (Le, e1, e2)}
  | e1=expr GT e2=expr {Bop (Gt, e1, e2)}
  | e1=expr GE e2=expr {Bop (Ge, e1, e2)}
  | e1=expr EQ e2=expr {Bop (Eq, e1, e2)}
  | e1=expr NEQ e2=expr {Bop (Neq, e1, e2)}
  | e1=expr LAND e2=expr {Bop (Land, e1, e2)}
  | e1=expr LOR e2=expr {Bop (Lor, e1, e2)}
  | e1=expr BAND e2=expr {Bop (Band, e1, e2)}
  | e1=expr BOR e2=expr {Bop (Bor, e1, e2)}
  | SUB e=expr %prec UMINUS { Uop (Minus, e)}
  | LNOT e=expr %prec UMINUS { Uop (Lnot, e)}
  | BNOT e=expr %prec UMINUS { Uop (Bnot, e)}

