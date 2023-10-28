#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 132
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 77
#define ALIAS_COUNT 0
#define TOKEN_COUNT 54
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 2
#define MAX_ALIAS_SEQUENCE_LENGTH 9
#define PRODUCTION_ID_COUNT 2

enum {
  sym_id = 1,
  anon_sym_SLASH_SLASH = 2,
  aux_sym_comment_token1 = 3,
  anon_sym_fun = 4,
  anon_sym_toaster = 5,
  anon_sym_extern = 6,
  anon_sym_LPAREN = 7,
  anon_sym_RPAREN = 8,
  anon_sym_COLON = 9,
  anon_sym_SEMI = 10,
  anon_sym_COMMA = 11,
  anon_sym_i64 = 12,
  anon_sym_i8 = 13,
  anon_sym_bool = 14,
  anon_sym_str = 15,
  anon_sym_LBRACK = 16,
  anon_sym_RBRACK = 17,
  anon_sym_unit = 18,
  anon_sym_LBRACE = 19,
  anon_sym_RBRACE = 20,
  anon_sym_let = 21,
  anon_sym_EQ = 22,
  anon_sym_return = 23,
  anon_sym_if = 24,
  anon_sym_else = 25,
  anon_sym_loop = 26,
  anon_sym_break = 27,
  anon_sym_STAR = 28,
  anon_sym_PLUS = 29,
  anon_sym_DASH = 30,
  anon_sym_LT_LT = 31,
  anon_sym_GT_GT = 32,
  anon_sym_GT_GT_GT = 33,
  anon_sym_LT = 34,
  anon_sym_LT_EQ = 35,
  anon_sym_GT = 36,
  anon_sym_GT_EQ = 37,
  anon_sym_EQ_EQ = 38,
  anon_sym_BANG_EQ = 39,
  anon_sym_AMP_AMP = 40,
  anon_sym_PIPE_PIPE = 41,
  anon_sym_AMP = 42,
  anon_sym_PIPE = 43,
  sym_unescaped = 44,
  sym_escape_seq = 45,
  anon_sym_DQUOTE = 46,
  anon_sym_SQUOTE = 47,
  aux_sym_char_token1 = 48,
  sym_integer = 49,
  anon_sym_true = 50,
  anon_sym_false = 51,
  anon_sym_BANG = 52,
  anon_sym_TILDE = 53,
  sym_prog = 54,
  sym_item = 55,
  sym_comment = 56,
  sym__fun = 57,
  sym_externdecl = 58,
  sym_func = 59,
  sym_arg = 60,
  sym_args = 61,
  sym_ty = 62,
  sym_block = 63,
  sym_stmt = 64,
  sym_bop = 65,
  sym_string = 66,
  sym_char = 67,
  sym__literal = 68,
  sym_uop = 69,
  sym_expr = 70,
  sym_fncall = 71,
  aux_sym_prog_repeat1 = 72,
  aux_sym_args_repeat1 = 73,
  aux_sym_block_repeat1 = 74,
  aux_sym_string_repeat1 = 75,
  aux_sym_fncall_repeat1 = 76,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_id] = "id",
  [anon_sym_SLASH_SLASH] = "comment_start",
  [aux_sym_comment_token1] = "comment_content",
  [anon_sym_fun] = "fun",
  [anon_sym_toaster] = "toaster",
  [anon_sym_extern] = "extern",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_COLON] = ":",
  [anon_sym_SEMI] = ";",
  [anon_sym_COMMA] = ",",
  [anon_sym_i64] = "i64",
  [anon_sym_i8] = "i8",
  [anon_sym_bool] = "bool",
  [anon_sym_str] = "str",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [anon_sym_unit] = "unit",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_let] = "let",
  [anon_sym_EQ] = "=",
  [anon_sym_return] = "return",
  [anon_sym_if] = "if",
  [anon_sym_else] = "else",
  [anon_sym_loop] = "loop",
  [anon_sym_break] = "break",
  [anon_sym_STAR] = "*",
  [anon_sym_PLUS] = "+",
  [anon_sym_DASH] = "-",
  [anon_sym_LT_LT] = "<<",
  [anon_sym_GT_GT] = ">>",
  [anon_sym_GT_GT_GT] = ">>>",
  [anon_sym_LT] = "<",
  [anon_sym_LT_EQ] = "<=",
  [anon_sym_GT] = ">",
  [anon_sym_GT_EQ] = ">=",
  [anon_sym_EQ_EQ] = "==",
  [anon_sym_BANG_EQ] = "!=",
  [anon_sym_AMP_AMP] = "&&",
  [anon_sym_PIPE_PIPE] = "||",
  [anon_sym_AMP] = "&",
  [anon_sym_PIPE] = "|",
  [sym_unescaped] = "unescaped",
  [sym_escape_seq] = "escape_seq",
  [anon_sym_DQUOTE] = "\"",
  [anon_sym_SQUOTE] = "'",
  [aux_sym_char_token1] = "char_token1",
  [sym_integer] = "integer",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [anon_sym_BANG] = "!",
  [anon_sym_TILDE] = "~",
  [sym_prog] = "prog",
  [sym_item] = "item",
  [sym_comment] = "comment",
  [sym__fun] = "_fun",
  [sym_externdecl] = "externdecl",
  [sym_func] = "func",
  [sym_arg] = "arg",
  [sym_args] = "args",
  [sym_ty] = "ty",
  [sym_block] = "block",
  [sym_stmt] = "stmt",
  [sym_bop] = "bop",
  [sym_string] = "string",
  [sym_char] = "char",
  [sym__literal] = "_literal",
  [sym_uop] = "uop",
  [sym_expr] = "expr",
  [sym_fncall] = "fncall",
  [aux_sym_prog_repeat1] = "prog_repeat1",
  [aux_sym_args_repeat1] = "args_repeat1",
  [aux_sym_block_repeat1] = "block_repeat1",
  [aux_sym_string_repeat1] = "string_repeat1",
  [aux_sym_fncall_repeat1] = "fncall_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_id] = sym_id,
  [anon_sym_SLASH_SLASH] = anon_sym_SLASH_SLASH,
  [aux_sym_comment_token1] = aux_sym_comment_token1,
  [anon_sym_fun] = anon_sym_fun,
  [anon_sym_toaster] = anon_sym_toaster,
  [anon_sym_extern] = anon_sym_extern,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_i64] = anon_sym_i64,
  [anon_sym_i8] = anon_sym_i8,
  [anon_sym_bool] = anon_sym_bool,
  [anon_sym_str] = anon_sym_str,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_unit] = anon_sym_unit,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_let] = anon_sym_let,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_return] = anon_sym_return,
  [anon_sym_if] = anon_sym_if,
  [anon_sym_else] = anon_sym_else,
  [anon_sym_loop] = anon_sym_loop,
  [anon_sym_break] = anon_sym_break,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_LT_LT] = anon_sym_LT_LT,
  [anon_sym_GT_GT] = anon_sym_GT_GT,
  [anon_sym_GT_GT_GT] = anon_sym_GT_GT_GT,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_LT_EQ] = anon_sym_LT_EQ,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_GT_EQ] = anon_sym_GT_EQ,
  [anon_sym_EQ_EQ] = anon_sym_EQ_EQ,
  [anon_sym_BANG_EQ] = anon_sym_BANG_EQ,
  [anon_sym_AMP_AMP] = anon_sym_AMP_AMP,
  [anon_sym_PIPE_PIPE] = anon_sym_PIPE_PIPE,
  [anon_sym_AMP] = anon_sym_AMP,
  [anon_sym_PIPE] = anon_sym_PIPE,
  [sym_unescaped] = sym_unescaped,
  [sym_escape_seq] = sym_escape_seq,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [aux_sym_char_token1] = aux_sym_char_token1,
  [sym_integer] = sym_integer,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [anon_sym_BANG] = anon_sym_BANG,
  [anon_sym_TILDE] = anon_sym_TILDE,
  [sym_prog] = sym_prog,
  [sym_item] = sym_item,
  [sym_comment] = sym_comment,
  [sym__fun] = sym__fun,
  [sym_externdecl] = sym_externdecl,
  [sym_func] = sym_func,
  [sym_arg] = sym_arg,
  [sym_args] = sym_args,
  [sym_ty] = sym_ty,
  [sym_block] = sym_block,
  [sym_stmt] = sym_stmt,
  [sym_bop] = sym_bop,
  [sym_string] = sym_string,
  [sym_char] = sym_char,
  [sym__literal] = sym__literal,
  [sym_uop] = sym_uop,
  [sym_expr] = sym_expr,
  [sym_fncall] = sym_fncall,
  [aux_sym_prog_repeat1] = aux_sym_prog_repeat1,
  [aux_sym_args_repeat1] = aux_sym_args_repeat1,
  [aux_sym_block_repeat1] = aux_sym_block_repeat1,
  [aux_sym_string_repeat1] = aux_sym_string_repeat1,
  [aux_sym_fncall_repeat1] = aux_sym_fncall_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_id] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_SLASH_SLASH] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_comment_token1] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_fun] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_toaster] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_extern] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_i64] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_i8] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_bool] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_str] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_unit] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_let] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_return] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_if] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_else] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_loop] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_break] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT_GT_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AMP_AMP] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AMP] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE] = {
    .visible = true,
    .named = false,
  },
  [sym_unescaped] = {
    .visible = true,
    .named = true,
  },
  [sym_escape_seq] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_char_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_integer] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_true] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_false] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_TILDE] = {
    .visible = true,
    .named = false,
  },
  [sym_prog] = {
    .visible = true,
    .named = true,
  },
  [sym_item] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym__fun] = {
    .visible = false,
    .named = true,
  },
  [sym_externdecl] = {
    .visible = true,
    .named = true,
  },
  [sym_func] = {
    .visible = true,
    .named = true,
  },
  [sym_arg] = {
    .visible = true,
    .named = true,
  },
  [sym_args] = {
    .visible = true,
    .named = true,
  },
  [sym_ty] = {
    .visible = true,
    .named = true,
  },
  [sym_block] = {
    .visible = true,
    .named = true,
  },
  [sym_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym_bop] = {
    .visible = true,
    .named = true,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [sym_char] = {
    .visible = true,
    .named = true,
  },
  [sym__literal] = {
    .visible = false,
    .named = true,
  },
  [sym_uop] = {
    .visible = true,
    .named = true,
  },
  [sym_expr] = {
    .visible = true,
    .named = true,
  },
  [sym_fncall] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_prog_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_args_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_block_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_fncall_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_content = 1,
  field_start = 2,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_content] = "content",
  [field_start] = "start",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_content, 1},
    {field_start, 0},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 40,
  [43] = 41,
  [44] = 44,
  [45] = 41,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 40,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 59,
  [63] = 63,
  [64] = 58,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 58,
  [79] = 59,
  [80] = 80,
  [81] = 81,
  [82] = 82,
  [83] = 83,
  [84] = 84,
  [85] = 85,
  [86] = 86,
  [87] = 87,
  [88] = 88,
  [89] = 89,
  [90] = 90,
  [91] = 91,
  [92] = 92,
  [93] = 93,
  [94] = 94,
  [95] = 95,
  [96] = 96,
  [97] = 97,
  [98] = 98,
  [99] = 99,
  [100] = 100,
  [101] = 101,
  [102] = 102,
  [103] = 103,
  [104] = 104,
  [105] = 105,
  [106] = 106,
  [107] = 107,
  [108] = 108,
  [109] = 109,
  [110] = 110,
  [111] = 111,
  [112] = 112,
  [113] = 113,
  [114] = 114,
  [115] = 115,
  [116] = 116,
  [117] = 117,
  [118] = 118,
  [119] = 119,
  [120] = 120,
  [121] = 121,
  [122] = 122,
  [123] = 123,
  [124] = 124,
  [125] = 125,
  [126] = 126,
  [127] = 127,
  [128] = 128,
  [129] = 129,
  [130] = 130,
  [131] = 131,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(56);
      if (lookahead == '!') ADVANCE(147);
      if (lookahead == '"') ADVANCE(138);
      if (lookahead == '&') ADVANCE(132);
      if (lookahead == '\'') ADVANCE(139);
      if (lookahead == '(') ADVANCE(90);
      if (lookahead == ')') ADVANCE(91);
      if (lookahead == '*') ADVANCE(118);
      if (lookahead == '+') ADVANCE(119);
      if (lookahead == ',') ADVANCE(94);
      if (lookahead == '-') ADVANCE(120);
      if (lookahead == '/') ADVANCE(6);
      if (lookahead == ':') ADVANCE(92);
      if (lookahead == ';') ADVANCE(93);
      if (lookahead == '<') ADVANCE(124);
      if (lookahead == '=') ADVANCE(107);
      if (lookahead == '>') ADVANCE(126);
      if (lookahead == '[') ADVANCE(99);
      if (lookahead == '\\') ADVANCE(52);
      if (lookahead == ']') ADVANCE(100);
      if (lookahead == 'b') ADVANCE(32);
      if (lookahead == 'e') ADVANCE(25);
      if (lookahead == 'f') ADVANCE(12);
      if (lookahead == 'i') ADVANCE(9);
      if (lookahead == 'l') ADVANCE(20);
      if (lookahead == 'r') ADVANCE(22);
      if (lookahead == 's') ADVANCE(44);
      if (lookahead == 't') ADVANCE(33);
      if (lookahead == 'u') ADVANCE(28);
      if (lookahead == '{') ADVANCE(102);
      if (lookahead == '|') ADVANCE(133);
      if (lookahead == '}') ADVANCE(103);
      if (lookahead == '~') ADVANCE(148);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(55)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(141);
      END_STATE();
    case 1:
      if (lookahead == '!') ADVANCE(10);
      if (lookahead == '&') ADVANCE(132);
      if (lookahead == '(') ADVANCE(90);
      if (lookahead == ')') ADVANCE(91);
      if (lookahead == '*') ADVANCE(118);
      if (lookahead == '+') ADVANCE(119);
      if (lookahead == ',') ADVANCE(94);
      if (lookahead == '-') ADVANCE(120);
      if (lookahead == '/') ADVANCE(6);
      if (lookahead == ';') ADVANCE(93);
      if (lookahead == '<') ADVANCE(124);
      if (lookahead == '=') ADVANCE(11);
      if (lookahead == '>') ADVANCE(126);
      if (lookahead == '[') ADVANCE(99);
      if (lookahead == ']') ADVANCE(100);
      if (lookahead == 'b') ADVANCE(73);
      if (lookahead == 'i') ADVANCE(65);
      if (lookahead == 'l') ADVANCE(59);
      if (lookahead == 'r') ADVANCE(64);
      if (lookahead == '{') ADVANCE(102);
      if (lookahead == '|') ADVANCE(133);
      if (lookahead == '}') ADVANCE(103);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 2:
      if (lookahead == '!') ADVANCE(146);
      if (lookahead == '"') ADVANCE(138);
      if (lookahead == '\'') ADVANCE(139);
      if (lookahead == '(') ADVANCE(90);
      if (lookahead == ')') ADVANCE(91);
      if (lookahead == '-') ADVANCE(120);
      if (lookahead == '/') ADVANCE(6);
      if (lookahead == ';') ADVANCE(93);
      if (lookahead == '=') ADVANCE(106);
      if (lookahead == '[') ADVANCE(99);
      if (lookahead == 'f') ADVANCE(58);
      if (lookahead == 't') ADVANCE(74);
      if (lookahead == '~') ADVANCE(148);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(141);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(138);
      if (lookahead == '/') ADVANCE(135);
      if (lookahead == '\\') ADVANCE(52);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(134);
      if (lookahead != 0) ADVANCE(136);
      END_STATE();
    case 4:
      if (lookahead == ')') ADVANCE(91);
      if (lookahead == '/') ADVANCE(6);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(4)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 5:
      if (lookahead == '/') ADVANCE(6);
      if (lookahead == 'b') ADVANCE(73);
      if (lookahead == 'e') ADVANCE(68);
      if (lookahead == 'i') ADVANCE(65);
      if (lookahead == 'l') ADVANCE(59);
      if (lookahead == 'r') ADVANCE(64);
      if (lookahead == '}') ADVANCE(103);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(5)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 6:
      if (lookahead == '/') ADVANCE(82);
      END_STATE();
    case 7:
      if (lookahead == '/') ADVANCE(140);
      if (lookahead == '\\') ADVANCE(52);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(140);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(140);
      END_STATE();
    case 8:
      if (lookahead == '4') ADVANCE(95);
      END_STATE();
    case 9:
      if (lookahead == '6') ADVANCE(8);
      if (lookahead == '8') ADVANCE(96);
      if (lookahead == 'f') ADVANCE(110);
      END_STATE();
    case 10:
      if (lookahead == '=') ADVANCE(129);
      END_STATE();
    case 11:
      if (lookahead == '=') ADVANCE(128);
      END_STATE();
    case 12:
      if (lookahead == 'a') ADVANCE(27);
      if (lookahead == 'u') ADVANCE(29);
      END_STATE();
    case 13:
      if (lookahead == 'a') ADVANCE(24);
      END_STATE();
    case 14:
      if (lookahead == 'a') ADVANCE(43);
      END_STATE();
    case 15:
      if (lookahead == 'e') ADVANCE(112);
      END_STATE();
    case 16:
      if (lookahead == 'e') ADVANCE(142);
      END_STATE();
    case 17:
      if (lookahead == 'e') ADVANCE(144);
      END_STATE();
    case 18:
      if (lookahead == 'e') ADVANCE(39);
      END_STATE();
    case 19:
      if (lookahead == 'e') ADVANCE(13);
      END_STATE();
    case 20:
      if (lookahead == 'e') ADVANCE(45);
      if (lookahead == 'o') ADVANCE(34);
      END_STATE();
    case 21:
      if (lookahead == 'e') ADVANCE(38);
      END_STATE();
    case 22:
      if (lookahead == 'e') ADVANCE(47);
      END_STATE();
    case 23:
      if (lookahead == 'i') ADVANCE(46);
      END_STATE();
    case 24:
      if (lookahead == 'k') ADVANCE(116);
      END_STATE();
    case 25:
      if (lookahead == 'l') ADVANCE(41);
      if (lookahead == 'x') ADVANCE(48);
      END_STATE();
    case 26:
      if (lookahead == 'l') ADVANCE(97);
      END_STATE();
    case 27:
      if (lookahead == 'l') ADVANCE(42);
      END_STATE();
    case 28:
      if (lookahead == 'n') ADVANCE(23);
      END_STATE();
    case 29:
      if (lookahead == 'n') ADVANCE(87);
      END_STATE();
    case 30:
      if (lookahead == 'n') ADVANCE(89);
      END_STATE();
    case 31:
      if (lookahead == 'n') ADVANCE(108);
      END_STATE();
    case 32:
      if (lookahead == 'o') ADVANCE(35);
      if (lookahead == 'r') ADVANCE(19);
      END_STATE();
    case 33:
      if (lookahead == 'o') ADVANCE(14);
      if (lookahead == 'r') ADVANCE(50);
      END_STATE();
    case 34:
      if (lookahead == 'o') ADVANCE(36);
      END_STATE();
    case 35:
      if (lookahead == 'o') ADVANCE(26);
      END_STATE();
    case 36:
      if (lookahead == 'p') ADVANCE(114);
      END_STATE();
    case 37:
      if (lookahead == 'r') ADVANCE(98);
      END_STATE();
    case 38:
      if (lookahead == 'r') ADVANCE(88);
      END_STATE();
    case 39:
      if (lookahead == 'r') ADVANCE(30);
      END_STATE();
    case 40:
      if (lookahead == 'r') ADVANCE(31);
      END_STATE();
    case 41:
      if (lookahead == 's') ADVANCE(15);
      END_STATE();
    case 42:
      if (lookahead == 's') ADVANCE(17);
      END_STATE();
    case 43:
      if (lookahead == 's') ADVANCE(49);
      END_STATE();
    case 44:
      if (lookahead == 't') ADVANCE(37);
      END_STATE();
    case 45:
      if (lookahead == 't') ADVANCE(104);
      END_STATE();
    case 46:
      if (lookahead == 't') ADVANCE(101);
      END_STATE();
    case 47:
      if (lookahead == 't') ADVANCE(51);
      END_STATE();
    case 48:
      if (lookahead == 't') ADVANCE(18);
      END_STATE();
    case 49:
      if (lookahead == 't') ADVANCE(21);
      END_STATE();
    case 50:
      if (lookahead == 'u') ADVANCE(16);
      END_STATE();
    case 51:
      if (lookahead == 'u') ADVANCE(40);
      END_STATE();
    case 52:
      if (lookahead == 'x') ADVANCE(54);
      if (lookahead == '"' ||
          lookahead == '\'' ||
          lookahead == '\\' ||
          lookahead == 'n' ||
          lookahead == 'r') ADVANCE(137);
      END_STATE();
    case 53:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(137);
      END_STATE();
    case 54:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(53);
      END_STATE();
    case 55:
      if (eof) ADVANCE(56);
      if (lookahead == '!') ADVANCE(147);
      if (lookahead == '"') ADVANCE(138);
      if (lookahead == '&') ADVANCE(132);
      if (lookahead == '\'') ADVANCE(139);
      if (lookahead == '(') ADVANCE(90);
      if (lookahead == ')') ADVANCE(91);
      if (lookahead == '*') ADVANCE(118);
      if (lookahead == '+') ADVANCE(119);
      if (lookahead == ',') ADVANCE(94);
      if (lookahead == '-') ADVANCE(120);
      if (lookahead == '/') ADVANCE(6);
      if (lookahead == ':') ADVANCE(92);
      if (lookahead == ';') ADVANCE(93);
      if (lookahead == '<') ADVANCE(124);
      if (lookahead == '=') ADVANCE(107);
      if (lookahead == '>') ADVANCE(126);
      if (lookahead == '[') ADVANCE(99);
      if (lookahead == ']') ADVANCE(100);
      if (lookahead == 'b') ADVANCE(32);
      if (lookahead == 'e') ADVANCE(25);
      if (lookahead == 'f') ADVANCE(12);
      if (lookahead == 'i') ADVANCE(9);
      if (lookahead == 'l') ADVANCE(20);
      if (lookahead == 'r') ADVANCE(22);
      if (lookahead == 's') ADVANCE(44);
      if (lookahead == 't') ADVANCE(33);
      if (lookahead == 'u') ADVANCE(28);
      if (lookahead == '{') ADVANCE(102);
      if (lookahead == '|') ADVANCE(133);
      if (lookahead == '}') ADVANCE(103);
      if (lookahead == '~') ADVANCE(148);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(55)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(141);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 'a') ADVANCE(66);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 'a') ADVANCE(67);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 'e') ADVANCE(77);
      if (lookahead == 'o') ADVANCE(70);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 'e') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 'e') ADVANCE(143);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 'e') ADVANCE(145);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 'e') ADVANCE(113);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 'e') ADVANCE(78);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 'f') ADVANCE(111);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 'k') ADVANCE(117);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 'l') ADVANCE(75);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 'l') ADVANCE(76);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 'n') ADVANCE(109);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 'o') ADVANCE(71);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 'p') ADVANCE(115);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 'r') ADVANCE(69);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 'r') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 'r') ADVANCE(80);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 's') ADVANCE(62);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 's') ADVANCE(63);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 't') ADVANCE(105);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 't') ADVANCE(79);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 'u') ADVANCE(72);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 'u') ADVANCE(61);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym_id);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(anon_sym_SLASH_SLASH);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(anon_sym_SLASH_SLASH);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(86);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '/') ADVANCE(85);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(84);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(86);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '/') ADVANCE(83);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(86);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(86);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_fun);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(anon_sym_toaster);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(anon_sym_extern);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(anon_sym_i64);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(anon_sym_i8);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(anon_sym_bool);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(anon_sym_str);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(anon_sym_unit);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(anon_sym_let);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(anon_sym_let);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '=') ADVANCE(128);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(anon_sym_return);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(anon_sym_return);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(anon_sym_if);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(anon_sym_if);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(anon_sym_else);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(anon_sym_else);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(anon_sym_loop);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(anon_sym_loop);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(anon_sym_break);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(anon_sym_break);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(anon_sym_LT_LT);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(anon_sym_GT_GT);
      if (lookahead == '>') ADVANCE(123);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(anon_sym_GT_GT_GT);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '<') ADVANCE(121);
      if (lookahead == '=') ADVANCE(125);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(127);
      if (lookahead == '>') ADVANCE(122);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(anon_sym_EQ_EQ);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(anon_sym_BANG_EQ);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(anon_sym_AMP_AMP);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(anon_sym_PIPE_PIPE);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(anon_sym_AMP);
      if (lookahead == '&') ADVANCE(130);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead == '|') ADVANCE(131);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(sym_unescaped);
      if (lookahead == '/') ADVANCE(135);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(136);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(sym_unescaped);
      if (lookahead == '/') ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(136);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(sym_unescaped);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(136);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(sym_escape_seq);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(aux_sym_char_token1);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(sym_integer);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(141);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(anon_sym_true);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(anon_sym_false);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(anon_sym_BANG);
      if (lookahead == '=') ADVANCE(129);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(anon_sym_TILDE);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 1},
  [3] = {.lex_state = 1},
  [4] = {.lex_state = 1},
  [5] = {.lex_state = 1},
  [6] = {.lex_state = 1},
  [7] = {.lex_state = 1},
  [8] = {.lex_state = 1},
  [9] = {.lex_state = 1},
  [10] = {.lex_state = 1},
  [11] = {.lex_state = 1},
  [12] = {.lex_state = 1},
  [13] = {.lex_state = 1},
  [14] = {.lex_state = 1},
  [15] = {.lex_state = 1},
  [16] = {.lex_state = 1},
  [17] = {.lex_state = 1},
  [18] = {.lex_state = 1},
  [19] = {.lex_state = 1},
  [20] = {.lex_state = 1},
  [21] = {.lex_state = 1},
  [22] = {.lex_state = 1},
  [23] = {.lex_state = 1},
  [24] = {.lex_state = 1},
  [25] = {.lex_state = 1},
  [26] = {.lex_state = 2},
  [27] = {.lex_state = 2},
  [28] = {.lex_state = 2},
  [29] = {.lex_state = 2},
  [30] = {.lex_state = 2},
  [31] = {.lex_state = 2},
  [32] = {.lex_state = 2},
  [33] = {.lex_state = 2},
  [34] = {.lex_state = 2},
  [35] = {.lex_state = 2},
  [36] = {.lex_state = 2},
  [37] = {.lex_state = 2},
  [38] = {.lex_state = 2},
  [39] = {.lex_state = 2},
  [40] = {.lex_state = 1},
  [41] = {.lex_state = 1},
  [42] = {.lex_state = 1},
  [43] = {.lex_state = 1},
  [44] = {.lex_state = 2},
  [45] = {.lex_state = 1},
  [46] = {.lex_state = 2},
  [47] = {.lex_state = 2},
  [48] = {.lex_state = 2},
  [49] = {.lex_state = 2},
  [50] = {.lex_state = 1},
  [51] = {.lex_state = 2},
  [52] = {.lex_state = 2},
  [53] = {.lex_state = 2},
  [54] = {.lex_state = 1},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 5},
  [58] = {.lex_state = 5},
  [59] = {.lex_state = 5},
  [60] = {.lex_state = 1},
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 1},
  [63] = {.lex_state = 1},
  [64] = {.lex_state = 1},
  [65] = {.lex_state = 1},
  [66] = {.lex_state = 1},
  [67] = {.lex_state = 1},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 0},
  [70] = {.lex_state = 1},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 0},
  [73] = {.lex_state = 0},
  [74] = {.lex_state = 0},
  [75] = {.lex_state = 0},
  [76] = {.lex_state = 0},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 0},
  [80] = {.lex_state = 3},
  [81] = {.lex_state = 0},
  [82] = {.lex_state = 0},
  [83] = {.lex_state = 0},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 0},
  [86] = {.lex_state = 3},
  [87] = {.lex_state = 4},
  [88] = {.lex_state = 0},
  [89] = {.lex_state = 3},
  [90] = {.lex_state = 4},
  [91] = {.lex_state = 0},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 0},
  [95] = {.lex_state = 2},
  [96] = {.lex_state = 0},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 0},
  [99] = {.lex_state = 3},
  [100] = {.lex_state = 0},
  [101] = {.lex_state = 0},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 0},
  [105] = {.lex_state = 0},
  [106] = {.lex_state = 0},
  [107] = {.lex_state = 0},
  [108] = {.lex_state = 0},
  [109] = {.lex_state = 7},
  [110] = {.lex_state = 4},
  [111] = {.lex_state = 0},
  [112] = {.lex_state = 0},
  [113] = {.lex_state = 4},
  [114] = {.lex_state = 0},
  [115] = {.lex_state = 4},
  [116] = {.lex_state = 0},
  [117] = {.lex_state = 0},
  [118] = {.lex_state = 0},
  [119] = {.lex_state = 0},
  [120] = {.lex_state = 0},
  [121] = {.lex_state = 4},
  [122] = {.lex_state = 84},
  [123] = {.lex_state = 0},
  [124] = {.lex_state = 0},
  [125] = {.lex_state = 4},
  [126] = {.lex_state = 0},
  [127] = {.lex_state = 0},
  [128] = {.lex_state = 0},
  [129] = {.lex_state = 2},
  [130] = {.lex_state = 2},
  [131] = {(TSStateId)(-1)},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [sym_comment] = STATE(0),
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_SLASH_SLASH] = ACTIONS(3),
    [anon_sym_fun] = ACTIONS(1),
    [anon_sym_toaster] = ACTIONS(1),
    [anon_sym_extern] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_i64] = ACTIONS(1),
    [anon_sym_i8] = ACTIONS(1),
    [anon_sym_bool] = ACTIONS(1),
    [anon_sym_str] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_unit] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_let] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_return] = ACTIONS(1),
    [anon_sym_if] = ACTIONS(1),
    [anon_sym_else] = ACTIONS(1),
    [anon_sym_loop] = ACTIONS(1),
    [anon_sym_break] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_LT_LT] = ACTIONS(1),
    [anon_sym_GT_GT] = ACTIONS(1),
    [anon_sym_GT_GT_GT] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_LT_EQ] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_GT_EQ] = ACTIONS(1),
    [anon_sym_EQ_EQ] = ACTIONS(1),
    [anon_sym_BANG_EQ] = ACTIONS(1),
    [anon_sym_AMP_AMP] = ACTIONS(1),
    [anon_sym_PIPE_PIPE] = ACTIONS(1),
    [anon_sym_AMP] = ACTIONS(1),
    [anon_sym_PIPE] = ACTIONS(1),
    [sym_escape_seq] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [sym_integer] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [anon_sym_BANG] = ACTIONS(1),
    [anon_sym_TILDE] = ACTIONS(1),
  },
  [1] = {
    [sym_prog] = STATE(118),
    [sym_item] = STATE(83),
    [sym_comment] = STATE(1),
    [sym__fun] = STATE(115),
    [sym_externdecl] = STATE(85),
    [sym_func] = STATE(85),
    [aux_sym_prog_repeat1] = STATE(56),
    [ts_builtin_sym_end] = ACTIONS(5),
    [anon_sym_SLASH_SLASH] = ACTIONS(3),
    [anon_sym_fun] = ACTIONS(7),
    [anon_sym_toaster] = ACTIONS(7),
    [anon_sym_extern] = ACTIONS(9),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(11), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_comment,
    ACTIONS(15), 5,
      anon_sym_GT_GT,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_AMP,
      anon_sym_PIPE,
    ACTIONS(13), 17,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LBRACE,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_LT_LT,
      anon_sym_GT_GT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
  [36] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    STATE(3), 1,
      sym_comment,
    STATE(32), 1,
      sym_bop,
    ACTIONS(19), 5,
      anon_sym_GT_GT,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_AMP,
      anon_sym_PIPE,
    ACTIONS(17), 17,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LBRACE,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_LT_LT,
      anon_sym_GT_GT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
  [72] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    STATE(4), 1,
      sym_comment,
    STATE(32), 1,
      sym_bop,
    ACTIONS(23), 5,
      anon_sym_GT_GT,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_AMP,
      anon_sym_PIPE,
    ACTIONS(21), 17,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LBRACE,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_LT_LT,
      anon_sym_GT_GT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
  [108] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    STATE(5), 1,
      sym_comment,
    ACTIONS(27), 5,
      anon_sym_GT_GT,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_AMP,
      anon_sym_PIPE,
    ACTIONS(25), 17,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LBRACE,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_LT_LT,
      anon_sym_GT_GT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
  [141] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    STATE(6), 1,
      sym_comment,
    ACTIONS(31), 5,
      anon_sym_GT_GT,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_AMP,
      anon_sym_PIPE,
    ACTIONS(29), 17,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LBRACE,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_LT_LT,
      anon_sym_GT_GT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
  [174] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    STATE(7), 1,
      sym_comment,
    ACTIONS(35), 5,
      anon_sym_GT_GT,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_AMP,
      anon_sym_PIPE,
    ACTIONS(33), 17,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LBRACE,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_LT_LT,
      anon_sym_GT_GT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
  [207] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    STATE(8), 1,
      sym_comment,
    ACTIONS(39), 5,
      anon_sym_GT_GT,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_AMP,
      anon_sym_PIPE,
    ACTIONS(37), 17,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LBRACE,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_LT_LT,
      anon_sym_GT_GT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
  [240] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    STATE(9), 1,
      sym_comment,
    ACTIONS(15), 5,
      anon_sym_GT_GT,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_AMP,
      anon_sym_PIPE,
    ACTIONS(13), 17,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LBRACE,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_LT_LT,
      anon_sym_GT_GT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
  [273] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    STATE(10), 1,
      sym_comment,
    ACTIONS(43), 5,
      anon_sym_GT_GT,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_AMP,
      anon_sym_PIPE,
    ACTIONS(41), 17,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LBRACE,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_LT_LT,
      anon_sym_GT_GT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
  [306] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    STATE(11), 1,
      sym_comment,
    ACTIONS(23), 5,
      anon_sym_GT_GT,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_AMP,
      anon_sym_PIPE,
    ACTIONS(21), 17,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LBRACE,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_LT_LT,
      anon_sym_GT_GT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
  [339] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    STATE(12), 1,
      sym_comment,
    ACTIONS(47), 5,
      anon_sym_GT_GT,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_AMP,
      anon_sym_PIPE,
    ACTIONS(45), 17,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LBRACE,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_LT_LT,
      anon_sym_GT_GT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
  [372] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    STATE(13), 1,
      sym_comment,
    ACTIONS(51), 5,
      anon_sym_GT_GT,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_AMP,
      anon_sym_PIPE,
    ACTIONS(49), 17,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LBRACE,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_LT_LT,
      anon_sym_GT_GT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
  [405] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    STATE(14), 1,
      sym_comment,
    ACTIONS(55), 5,
      anon_sym_GT_GT,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_AMP,
      anon_sym_PIPE,
    ACTIONS(53), 17,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LBRACE,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_LT_LT,
      anon_sym_GT_GT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
  [438] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    STATE(15), 1,
      sym_comment,
    ACTIONS(19), 5,
      anon_sym_GT_GT,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_AMP,
      anon_sym_PIPE,
    ACTIONS(17), 17,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LBRACE,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_LT_LT,
      anon_sym_GT_GT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
  [471] = 18,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(57), 1,
      anon_sym_RPAREN,
    ACTIONS(59), 1,
      anon_sym_COMMA,
    ACTIONS(61), 1,
      anon_sym_LBRACK,
    ACTIONS(63), 1,
      anon_sym_STAR,
    ACTIONS(69), 1,
      anon_sym_GT_GT,
    ACTIONS(77), 1,
      anon_sym_AMP_AMP,
    ACTIONS(79), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(81), 1,
      anon_sym_AMP,
    ACTIONS(83), 1,
      anon_sym_PIPE,
    STATE(16), 1,
      sym_comment,
    STATE(32), 1,
      sym_bop,
    STATE(101), 1,
      aux_sym_fncall_repeat1,
    ACTIONS(65), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(67), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT_GT,
    ACTIONS(71), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(73), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(75), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [531] = 16,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(61), 1,
      anon_sym_LBRACK,
    ACTIONS(63), 1,
      anon_sym_STAR,
    ACTIONS(69), 1,
      anon_sym_GT_GT,
    ACTIONS(77), 1,
      anon_sym_AMP_AMP,
    ACTIONS(79), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(81), 1,
      anon_sym_AMP,
    ACTIONS(83), 1,
      anon_sym_PIPE,
    STATE(17), 1,
      sym_comment,
    STATE(32), 1,
      sym_bop,
    ACTIONS(65), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(67), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT_GT,
    ACTIONS(71), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(73), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(75), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(85), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [586] = 17,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(61), 1,
      anon_sym_LBRACK,
    ACTIONS(63), 1,
      anon_sym_STAR,
    ACTIONS(69), 1,
      anon_sym_GT_GT,
    ACTIONS(77), 1,
      anon_sym_AMP_AMP,
    ACTIONS(79), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(81), 1,
      anon_sym_AMP,
    ACTIONS(83), 1,
      anon_sym_PIPE,
    ACTIONS(87), 1,
      anon_sym_LBRACE,
    STATE(18), 1,
      sym_comment,
    STATE(32), 1,
      sym_bop,
    STATE(57), 1,
      sym_block,
    ACTIONS(65), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(67), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT_GT,
    ACTIONS(71), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(73), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(75), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [643] = 16,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(61), 1,
      anon_sym_LBRACK,
    ACTIONS(63), 1,
      anon_sym_STAR,
    ACTIONS(69), 1,
      anon_sym_GT_GT,
    ACTIONS(77), 1,
      anon_sym_AMP_AMP,
    ACTIONS(79), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(81), 1,
      anon_sym_AMP,
    ACTIONS(83), 1,
      anon_sym_PIPE,
    ACTIONS(89), 1,
      anon_sym_SEMI,
    STATE(19), 1,
      sym_comment,
    STATE(32), 1,
      sym_bop,
    ACTIONS(65), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(67), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT_GT,
    ACTIONS(71), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(73), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(75), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [697] = 16,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(61), 1,
      anon_sym_LBRACK,
    ACTIONS(63), 1,
      anon_sym_STAR,
    ACTIONS(69), 1,
      anon_sym_GT_GT,
    ACTIONS(77), 1,
      anon_sym_AMP_AMP,
    ACTIONS(79), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(81), 1,
      anon_sym_AMP,
    ACTIONS(83), 1,
      anon_sym_PIPE,
    ACTIONS(91), 1,
      anon_sym_RPAREN,
    STATE(20), 1,
      sym_comment,
    STATE(32), 1,
      sym_bop,
    ACTIONS(65), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(67), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT_GT,
    ACTIONS(71), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(73), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(75), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [751] = 16,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(61), 1,
      anon_sym_LBRACK,
    ACTIONS(63), 1,
      anon_sym_STAR,
    ACTIONS(69), 1,
      anon_sym_GT_GT,
    ACTIONS(77), 1,
      anon_sym_AMP_AMP,
    ACTIONS(79), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(81), 1,
      anon_sym_AMP,
    ACTIONS(83), 1,
      anon_sym_PIPE,
    ACTIONS(93), 1,
      anon_sym_SEMI,
    STATE(21), 1,
      sym_comment,
    STATE(32), 1,
      sym_bop,
    ACTIONS(65), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(67), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT_GT,
    ACTIONS(71), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(73), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(75), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [805] = 16,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(61), 1,
      anon_sym_LBRACK,
    ACTIONS(63), 1,
      anon_sym_STAR,
    ACTIONS(69), 1,
      anon_sym_GT_GT,
    ACTIONS(77), 1,
      anon_sym_AMP_AMP,
    ACTIONS(79), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(81), 1,
      anon_sym_AMP,
    ACTIONS(83), 1,
      anon_sym_PIPE,
    ACTIONS(95), 1,
      anon_sym_RBRACK,
    STATE(22), 1,
      sym_comment,
    STATE(32), 1,
      sym_bop,
    ACTIONS(65), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(67), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT_GT,
    ACTIONS(71), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(73), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(75), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [859] = 16,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(61), 1,
      anon_sym_LBRACK,
    ACTIONS(63), 1,
      anon_sym_STAR,
    ACTIONS(69), 1,
      anon_sym_GT_GT,
    ACTIONS(77), 1,
      anon_sym_AMP_AMP,
    ACTIONS(79), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(81), 1,
      anon_sym_AMP,
    ACTIONS(83), 1,
      anon_sym_PIPE,
    ACTIONS(97), 1,
      anon_sym_SEMI,
    STATE(23), 1,
      sym_comment,
    STATE(32), 1,
      sym_bop,
    ACTIONS(65), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(67), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT_GT,
    ACTIONS(71), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(73), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(75), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [913] = 16,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(61), 1,
      anon_sym_LBRACK,
    ACTIONS(63), 1,
      anon_sym_STAR,
    ACTIONS(69), 1,
      anon_sym_GT_GT,
    ACTIONS(77), 1,
      anon_sym_AMP_AMP,
    ACTIONS(79), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(81), 1,
      anon_sym_AMP,
    ACTIONS(83), 1,
      anon_sym_PIPE,
    ACTIONS(99), 1,
      anon_sym_RBRACK,
    STATE(24), 1,
      sym_comment,
    STATE(32), 1,
      sym_bop,
    ACTIONS(65), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(67), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT_GT,
    ACTIONS(71), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(73), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(75), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [967] = 16,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(61), 1,
      anon_sym_LBRACK,
    ACTIONS(63), 1,
      anon_sym_STAR,
    ACTIONS(69), 1,
      anon_sym_GT_GT,
    ACTIONS(77), 1,
      anon_sym_AMP_AMP,
    ACTIONS(79), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(81), 1,
      anon_sym_AMP,
    ACTIONS(83), 1,
      anon_sym_PIPE,
    ACTIONS(101), 1,
      anon_sym_SEMI,
    STATE(25), 1,
      sym_comment,
    STATE(32), 1,
      sym_bop,
    ACTIONS(65), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(67), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT_GT,
    ACTIONS(71), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(73), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(75), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [1021] = 14,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(103), 1,
      sym_id,
    ACTIONS(105), 1,
      anon_sym_LPAREN,
    ACTIONS(107), 1,
      anon_sym_RPAREN,
    ACTIONS(111), 1,
      anon_sym_DQUOTE,
    ACTIONS(113), 1,
      anon_sym_SQUOTE,
    ACTIONS(115), 1,
      sym_integer,
    STATE(16), 1,
      sym_expr,
    STATE(26), 1,
      sym_comment,
    STATE(34), 1,
      sym_uop,
    ACTIONS(117), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(7), 2,
      sym_string,
      sym_char,
    STATE(9), 2,
      sym__literal,
      sym_fncall,
    ACTIONS(109), 3,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_TILDE,
  [1069] = 14,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(103), 1,
      sym_id,
    ACTIONS(105), 1,
      anon_sym_LPAREN,
    ACTIONS(111), 1,
      anon_sym_DQUOTE,
    ACTIONS(113), 1,
      anon_sym_SQUOTE,
    ACTIONS(115), 1,
      sym_integer,
    ACTIONS(119), 1,
      anon_sym_SEMI,
    STATE(23), 1,
      sym_expr,
    STATE(27), 1,
      sym_comment,
    STATE(34), 1,
      sym_uop,
    ACTIONS(117), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(7), 2,
      sym_string,
      sym_char,
    STATE(9), 2,
      sym__literal,
      sym_fncall,
    ACTIONS(109), 3,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_TILDE,
  [1117] = 14,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(103), 1,
      sym_id,
    ACTIONS(105), 1,
      anon_sym_LPAREN,
    ACTIONS(111), 1,
      anon_sym_DQUOTE,
    ACTIONS(113), 1,
      anon_sym_SQUOTE,
    ACTIONS(115), 1,
      sym_integer,
    ACTIONS(121), 1,
      anon_sym_RPAREN,
    STATE(20), 1,
      sym_expr,
    STATE(28), 1,
      sym_comment,
    STATE(34), 1,
      sym_uop,
    ACTIONS(117), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(7), 2,
      sym_string,
      sym_char,
    STATE(9), 2,
      sym__literal,
      sym_fncall,
    ACTIONS(109), 3,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_TILDE,
  [1165] = 13,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(103), 1,
      sym_id,
    ACTIONS(105), 1,
      anon_sym_LPAREN,
    ACTIONS(111), 1,
      anon_sym_DQUOTE,
    ACTIONS(113), 1,
      anon_sym_SQUOTE,
    ACTIONS(115), 1,
      sym_integer,
    STATE(25), 1,
      sym_expr,
    STATE(29), 1,
      sym_comment,
    STATE(34), 1,
      sym_uop,
    ACTIONS(117), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(7), 2,
      sym_string,
      sym_char,
    STATE(9), 2,
      sym__literal,
      sym_fncall,
    ACTIONS(109), 3,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_TILDE,
  [1210] = 13,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(103), 1,
      sym_id,
    ACTIONS(105), 1,
      anon_sym_LPAREN,
    ACTIONS(111), 1,
      anon_sym_DQUOTE,
    ACTIONS(113), 1,
      anon_sym_SQUOTE,
    ACTIONS(115), 1,
      sym_integer,
    STATE(19), 1,
      sym_expr,
    STATE(30), 1,
      sym_comment,
    STATE(34), 1,
      sym_uop,
    ACTIONS(117), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(7), 2,
      sym_string,
      sym_char,
    STATE(9), 2,
      sym__literal,
      sym_fncall,
    ACTIONS(109), 3,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_TILDE,
  [1255] = 13,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(103), 1,
      sym_id,
    ACTIONS(105), 1,
      anon_sym_LPAREN,
    ACTIONS(111), 1,
      anon_sym_DQUOTE,
    ACTIONS(113), 1,
      anon_sym_SQUOTE,
    ACTIONS(115), 1,
      sym_integer,
    STATE(24), 1,
      sym_expr,
    STATE(31), 1,
      sym_comment,
    STATE(34), 1,
      sym_uop,
    ACTIONS(117), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(7), 2,
      sym_string,
      sym_char,
    STATE(9), 2,
      sym__literal,
      sym_fncall,
    ACTIONS(109), 3,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_TILDE,
  [1300] = 13,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(103), 1,
      sym_id,
    ACTIONS(105), 1,
      anon_sym_LPAREN,
    ACTIONS(111), 1,
      anon_sym_DQUOTE,
    ACTIONS(113), 1,
      anon_sym_SQUOTE,
    ACTIONS(115), 1,
      sym_integer,
    STATE(4), 1,
      sym_expr,
    STATE(32), 1,
      sym_comment,
    STATE(34), 1,
      sym_uop,
    ACTIONS(117), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(7), 2,
      sym_string,
      sym_char,
    STATE(9), 2,
      sym__literal,
      sym_fncall,
    ACTIONS(109), 3,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_TILDE,
  [1345] = 13,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(103), 1,
      sym_id,
    ACTIONS(105), 1,
      anon_sym_LPAREN,
    ACTIONS(111), 1,
      anon_sym_DQUOTE,
    ACTIONS(113), 1,
      anon_sym_SQUOTE,
    ACTIONS(115), 1,
      sym_integer,
    STATE(17), 1,
      sym_expr,
    STATE(33), 1,
      sym_comment,
    STATE(34), 1,
      sym_uop,
    ACTIONS(117), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(7), 2,
      sym_string,
      sym_char,
    STATE(9), 2,
      sym__literal,
      sym_fncall,
    ACTIONS(109), 3,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_TILDE,
  [1390] = 12,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(103), 1,
      sym_id,
    ACTIONS(105), 1,
      anon_sym_LPAREN,
    ACTIONS(111), 1,
      anon_sym_DQUOTE,
    ACTIONS(113), 1,
      anon_sym_SQUOTE,
    ACTIONS(115), 1,
      sym_integer,
    STATE(3), 1,
      sym_expr,
    ACTIONS(117), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(7), 2,
      sym_string,
      sym_char,
    STATE(9), 2,
      sym__literal,
      sym_fncall,
    STATE(34), 2,
      sym_comment,
      sym_uop,
    ACTIONS(109), 3,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_TILDE,
  [1433] = 13,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(103), 1,
      sym_id,
    ACTIONS(105), 1,
      anon_sym_LPAREN,
    ACTIONS(111), 1,
      anon_sym_DQUOTE,
    ACTIONS(113), 1,
      anon_sym_SQUOTE,
    ACTIONS(115), 1,
      sym_integer,
    STATE(22), 1,
      sym_expr,
    STATE(34), 1,
      sym_uop,
    STATE(35), 1,
      sym_comment,
    ACTIONS(117), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(7), 2,
      sym_string,
      sym_char,
    STATE(9), 2,
      sym__literal,
      sym_fncall,
    ACTIONS(109), 3,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_TILDE,
  [1478] = 13,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(103), 1,
      sym_id,
    ACTIONS(105), 1,
      anon_sym_LPAREN,
    ACTIONS(111), 1,
      anon_sym_DQUOTE,
    ACTIONS(113), 1,
      anon_sym_SQUOTE,
    ACTIONS(115), 1,
      sym_integer,
    STATE(18), 1,
      sym_expr,
    STATE(34), 1,
      sym_uop,
    STATE(36), 1,
      sym_comment,
    ACTIONS(117), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(7), 2,
      sym_string,
      sym_char,
    STATE(9), 2,
      sym__literal,
      sym_fncall,
    ACTIONS(109), 3,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_TILDE,
  [1523] = 13,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(103), 1,
      sym_id,
    ACTIONS(105), 1,
      anon_sym_LPAREN,
    ACTIONS(111), 1,
      anon_sym_DQUOTE,
    ACTIONS(113), 1,
      anon_sym_SQUOTE,
    ACTIONS(115), 1,
      sym_integer,
    STATE(21), 1,
      sym_expr,
    STATE(34), 1,
      sym_uop,
    STATE(37), 1,
      sym_comment,
    ACTIONS(117), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(7), 2,
      sym_string,
      sym_char,
    STATE(9), 2,
      sym__literal,
      sym_fncall,
    ACTIONS(109), 3,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_TILDE,
  [1568] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    STATE(38), 1,
      sym_comment,
    ACTIONS(123), 3,
      sym_id,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(125), 7,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      sym_integer,
      anon_sym_BANG,
      anon_sym_TILDE,
  [1589] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    STATE(39), 1,
      sym_comment,
    ACTIONS(123), 3,
      sym_id,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(125), 7,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      sym_integer,
      anon_sym_BANG,
      anon_sym_TILDE,
  [1610] = 12,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(127), 1,
      sym_id,
    ACTIONS(129), 1,
      anon_sym_RBRACE,
    ACTIONS(131), 1,
      anon_sym_let,
    ACTIONS(133), 1,
      anon_sym_return,
    ACTIONS(135), 1,
      anon_sym_if,
    ACTIONS(137), 1,
      anon_sym_loop,
    ACTIONS(139), 1,
      anon_sym_break,
    STATE(40), 1,
      sym_comment,
    STATE(54), 1,
      aux_sym_block_repeat1,
    STATE(67), 1,
      sym_stmt,
    STATE(128), 1,
      sym_fncall,
  [1647] = 12,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(127), 1,
      sym_id,
    ACTIONS(131), 1,
      anon_sym_let,
    ACTIONS(133), 1,
      anon_sym_return,
    ACTIONS(135), 1,
      anon_sym_if,
    ACTIONS(137), 1,
      anon_sym_loop,
    ACTIONS(139), 1,
      anon_sym_break,
    ACTIONS(141), 1,
      anon_sym_RBRACE,
    STATE(40), 1,
      aux_sym_block_repeat1,
    STATE(41), 1,
      sym_comment,
    STATE(67), 1,
      sym_stmt,
    STATE(128), 1,
      sym_fncall,
  [1684] = 12,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(127), 1,
      sym_id,
    ACTIONS(131), 1,
      anon_sym_let,
    ACTIONS(133), 1,
      anon_sym_return,
    ACTIONS(135), 1,
      anon_sym_if,
    ACTIONS(137), 1,
      anon_sym_loop,
    ACTIONS(139), 1,
      anon_sym_break,
    ACTIONS(143), 1,
      anon_sym_RBRACE,
    STATE(42), 1,
      sym_comment,
    STATE(54), 1,
      aux_sym_block_repeat1,
    STATE(67), 1,
      sym_stmt,
    STATE(128), 1,
      sym_fncall,
  [1721] = 12,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(127), 1,
      sym_id,
    ACTIONS(131), 1,
      anon_sym_let,
    ACTIONS(133), 1,
      anon_sym_return,
    ACTIONS(135), 1,
      anon_sym_if,
    ACTIONS(137), 1,
      anon_sym_loop,
    ACTIONS(139), 1,
      anon_sym_break,
    ACTIONS(145), 1,
      anon_sym_RBRACE,
    STATE(42), 1,
      aux_sym_block_repeat1,
    STATE(43), 1,
      sym_comment,
    STATE(67), 1,
      sym_stmt,
    STATE(128), 1,
      sym_fncall,
  [1758] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    STATE(44), 1,
      sym_comment,
    ACTIONS(147), 3,
      sym_id,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(149), 7,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      sym_integer,
      anon_sym_BANG,
      anon_sym_TILDE,
  [1779] = 12,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(127), 1,
      sym_id,
    ACTIONS(131), 1,
      anon_sym_let,
    ACTIONS(133), 1,
      anon_sym_return,
    ACTIONS(135), 1,
      anon_sym_if,
    ACTIONS(137), 1,
      anon_sym_loop,
    ACTIONS(139), 1,
      anon_sym_break,
    ACTIONS(151), 1,
      anon_sym_RBRACE,
    STATE(45), 1,
      sym_comment,
    STATE(50), 1,
      aux_sym_block_repeat1,
    STATE(67), 1,
      sym_stmt,
    STATE(128), 1,
      sym_fncall,
  [1816] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    STATE(46), 1,
      sym_comment,
    ACTIONS(123), 3,
      sym_id,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(125), 7,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      sym_integer,
      anon_sym_BANG,
      anon_sym_TILDE,
  [1837] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    STATE(47), 1,
      sym_comment,
    ACTIONS(123), 3,
      sym_id,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(125), 7,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      sym_integer,
      anon_sym_BANG,
      anon_sym_TILDE,
  [1858] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    STATE(48), 1,
      sym_comment,
    ACTIONS(123), 3,
      sym_id,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(125), 7,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      sym_integer,
      anon_sym_BANG,
      anon_sym_TILDE,
  [1879] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    STATE(49), 1,
      sym_comment,
    ACTIONS(123), 3,
      sym_id,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(125), 7,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      sym_integer,
      anon_sym_BANG,
      anon_sym_TILDE,
  [1900] = 12,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(127), 1,
      sym_id,
    ACTIONS(131), 1,
      anon_sym_let,
    ACTIONS(133), 1,
      anon_sym_return,
    ACTIONS(135), 1,
      anon_sym_if,
    ACTIONS(137), 1,
      anon_sym_loop,
    ACTIONS(139), 1,
      anon_sym_break,
    ACTIONS(153), 1,
      anon_sym_RBRACE,
    STATE(50), 1,
      sym_comment,
    STATE(54), 1,
      aux_sym_block_repeat1,
    STATE(67), 1,
      sym_stmt,
    STATE(128), 1,
      sym_fncall,
  [1937] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    STATE(51), 1,
      sym_comment,
    ACTIONS(123), 3,
      sym_id,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(125), 7,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      sym_integer,
      anon_sym_BANG,
      anon_sym_TILDE,
  [1958] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    STATE(52), 1,
      sym_comment,
    ACTIONS(123), 3,
      sym_id,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(125), 7,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      sym_integer,
      anon_sym_BANG,
      anon_sym_TILDE,
  [1979] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    STATE(53), 1,
      sym_comment,
    ACTIONS(123), 3,
      sym_id,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(125), 7,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      sym_integer,
      anon_sym_BANG,
      anon_sym_TILDE,
  [2000] = 11,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(155), 1,
      sym_id,
    ACTIONS(158), 1,
      anon_sym_RBRACE,
    ACTIONS(160), 1,
      anon_sym_let,
    ACTIONS(163), 1,
      anon_sym_return,
    ACTIONS(166), 1,
      anon_sym_if,
    ACTIONS(169), 1,
      anon_sym_loop,
    ACTIONS(172), 1,
      anon_sym_break,
    STATE(67), 1,
      sym_stmt,
    STATE(128), 1,
      sym_fncall,
    STATE(54), 2,
      sym_comment,
      aux_sym_block_repeat1,
  [2035] = 8,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(175), 1,
      ts_builtin_sym_end,
    ACTIONS(180), 1,
      anon_sym_extern,
    STATE(83), 1,
      sym_item,
    STATE(115), 1,
      sym__fun,
    ACTIONS(177), 2,
      anon_sym_fun,
      anon_sym_toaster,
    STATE(55), 2,
      sym_comment,
      aux_sym_prog_repeat1,
    STATE(85), 2,
      sym_externdecl,
      sym_func,
  [2063] = 9,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(9), 1,
      anon_sym_extern,
    ACTIONS(183), 1,
      ts_builtin_sym_end,
    STATE(55), 1,
      aux_sym_prog_repeat1,
    STATE(56), 1,
      sym_comment,
    STATE(83), 1,
      sym_item,
    STATE(115), 1,
      sym__fun,
    ACTIONS(7), 2,
      anon_sym_fun,
      anon_sym_toaster,
    STATE(85), 2,
      sym_externdecl,
      sym_func,
  [2093] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(187), 1,
      anon_sym_RBRACE,
    ACTIONS(189), 1,
      anon_sym_else,
    STATE(57), 1,
      sym_comment,
    ACTIONS(185), 6,
      sym_id,
      anon_sym_let,
      anon_sym_return,
      anon_sym_if,
      anon_sym_loop,
      anon_sym_break,
  [2114] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(193), 1,
      anon_sym_RBRACE,
    STATE(58), 1,
      sym_comment,
    ACTIONS(191), 7,
      sym_id,
      anon_sym_let,
      anon_sym_return,
      anon_sym_if,
      anon_sym_else,
      anon_sym_loop,
      anon_sym_break,
  [2133] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(197), 1,
      anon_sym_RBRACE,
    STATE(59), 1,
      sym_comment,
    ACTIONS(195), 7,
      sym_id,
      anon_sym_let,
      anon_sym_return,
      anon_sym_if,
      anon_sym_else,
      anon_sym_loop,
      anon_sym_break,
  [2152] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(201), 1,
      anon_sym_RBRACE,
    STATE(60), 1,
      sym_comment,
    ACTIONS(199), 6,
      sym_id,
      anon_sym_let,
      anon_sym_return,
      anon_sym_if,
      anon_sym_loop,
      anon_sym_break,
  [2170] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(205), 1,
      anon_sym_LBRACK,
    STATE(61), 1,
      sym_comment,
    STATE(114), 1,
      sym_ty,
    ACTIONS(203), 5,
      anon_sym_i64,
      anon_sym_i8,
      anon_sym_bool,
      anon_sym_str,
      anon_sym_unit,
  [2190] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(197), 1,
      anon_sym_RBRACE,
    STATE(62), 1,
      sym_comment,
    ACTIONS(195), 6,
      sym_id,
      anon_sym_let,
      anon_sym_return,
      anon_sym_if,
      anon_sym_loop,
      anon_sym_break,
  [2208] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(209), 1,
      anon_sym_RBRACE,
    STATE(63), 1,
      sym_comment,
    ACTIONS(207), 6,
      sym_id,
      anon_sym_let,
      anon_sym_return,
      anon_sym_if,
      anon_sym_loop,
      anon_sym_break,
  [2226] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(193), 1,
      anon_sym_RBRACE,
    STATE(64), 1,
      sym_comment,
    ACTIONS(191), 6,
      sym_id,
      anon_sym_let,
      anon_sym_return,
      anon_sym_if,
      anon_sym_loop,
      anon_sym_break,
  [2244] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(213), 1,
      anon_sym_RBRACE,
    STATE(65), 1,
      sym_comment,
    ACTIONS(211), 6,
      sym_id,
      anon_sym_let,
      anon_sym_return,
      anon_sym_if,
      anon_sym_loop,
      anon_sym_break,
  [2262] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(217), 1,
      anon_sym_RBRACE,
    STATE(66), 1,
      sym_comment,
    ACTIONS(215), 6,
      sym_id,
      anon_sym_let,
      anon_sym_return,
      anon_sym_if,
      anon_sym_loop,
      anon_sym_break,
  [2280] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(221), 1,
      anon_sym_RBRACE,
    STATE(67), 1,
      sym_comment,
    ACTIONS(219), 6,
      sym_id,
      anon_sym_let,
      anon_sym_return,
      anon_sym_if,
      anon_sym_loop,
      anon_sym_break,
  [2298] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(205), 1,
      anon_sym_LBRACK,
    STATE(68), 1,
      sym_comment,
    STATE(117), 1,
      sym_ty,
    ACTIONS(203), 5,
      anon_sym_i64,
      anon_sym_i8,
      anon_sym_bool,
      anon_sym_str,
      anon_sym_unit,
  [2318] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(205), 1,
      anon_sym_LBRACK,
    STATE(69), 1,
      sym_comment,
    STATE(108), 1,
      sym_ty,
    ACTIONS(203), 5,
      anon_sym_i64,
      anon_sym_i8,
      anon_sym_bool,
      anon_sym_str,
      anon_sym_unit,
  [2338] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(187), 1,
      anon_sym_RBRACE,
    STATE(70), 1,
      sym_comment,
    ACTIONS(185), 6,
      sym_id,
      anon_sym_let,
      anon_sym_return,
      anon_sym_if,
      anon_sym_loop,
      anon_sym_break,
  [2356] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(205), 1,
      anon_sym_LBRACK,
    STATE(71), 1,
      sym_comment,
    STATE(106), 1,
      sym_ty,
    ACTIONS(203), 5,
      anon_sym_i64,
      anon_sym_i8,
      anon_sym_bool,
      anon_sym_str,
      anon_sym_unit,
  [2376] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(205), 1,
      anon_sym_LBRACK,
    STATE(72), 1,
      sym_comment,
    STATE(104), 1,
      sym_ty,
    ACTIONS(203), 5,
      anon_sym_i64,
      anon_sym_i8,
      anon_sym_bool,
      anon_sym_str,
      anon_sym_unit,
  [2396] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(205), 1,
      anon_sym_LBRACK,
    STATE(73), 1,
      sym_comment,
    STATE(124), 1,
      sym_ty,
    ACTIONS(203), 5,
      anon_sym_i64,
      anon_sym_i8,
      anon_sym_bool,
      anon_sym_str,
      anon_sym_unit,
  [2416] = 3,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    STATE(74), 1,
      sym_comment,
    ACTIONS(223), 5,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_LBRACE,
  [2430] = 3,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    STATE(75), 1,
      sym_comment,
    ACTIONS(225), 5,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_LBRACE,
  [2444] = 3,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    STATE(76), 1,
      sym_comment,
    ACTIONS(227), 4,
      ts_builtin_sym_end,
      anon_sym_fun,
      anon_sym_toaster,
      anon_sym_extern,
  [2457] = 3,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    STATE(77), 1,
      sym_comment,
    ACTIONS(229), 4,
      ts_builtin_sym_end,
      anon_sym_fun,
      anon_sym_toaster,
      anon_sym_extern,
  [2470] = 3,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    STATE(78), 1,
      sym_comment,
    ACTIONS(193), 4,
      ts_builtin_sym_end,
      anon_sym_fun,
      anon_sym_toaster,
      anon_sym_extern,
  [2483] = 3,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    STATE(79), 1,
      sym_comment,
    ACTIONS(197), 4,
      ts_builtin_sym_end,
      anon_sym_fun,
      anon_sym_toaster,
      anon_sym_extern,
  [2496] = 5,
    ACTIONS(231), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(235), 1,
      anon_sym_DQUOTE,
    STATE(80), 1,
      sym_comment,
    STATE(89), 1,
      aux_sym_string_repeat1,
    ACTIONS(233), 2,
      sym_unescaped,
      sym_escape_seq,
  [2513] = 3,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    STATE(81), 1,
      sym_comment,
    ACTIONS(237), 4,
      ts_builtin_sym_end,
      anon_sym_fun,
      anon_sym_toaster,
      anon_sym_extern,
  [2526] = 3,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    STATE(82), 1,
      sym_comment,
    ACTIONS(239), 4,
      ts_builtin_sym_end,
      anon_sym_fun,
      anon_sym_toaster,
      anon_sym_extern,
  [2539] = 3,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    STATE(83), 1,
      sym_comment,
    ACTIONS(241), 4,
      ts_builtin_sym_end,
      anon_sym_fun,
      anon_sym_toaster,
      anon_sym_extern,
  [2552] = 3,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    STATE(84), 1,
      sym_comment,
    ACTIONS(243), 4,
      ts_builtin_sym_end,
      anon_sym_fun,
      anon_sym_toaster,
      anon_sym_extern,
  [2565] = 3,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    STATE(85), 1,
      sym_comment,
    ACTIONS(245), 4,
      ts_builtin_sym_end,
      anon_sym_fun,
      anon_sym_toaster,
      anon_sym_extern,
  [2578] = 4,
    ACTIONS(231), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(250), 1,
      anon_sym_DQUOTE,
    ACTIONS(247), 2,
      sym_unescaped,
      sym_escape_seq,
    STATE(86), 2,
      sym_comment,
      aux_sym_string_repeat1,
  [2593] = 6,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(252), 1,
      sym_id,
    ACTIONS(254), 1,
      anon_sym_RPAREN,
    STATE(87), 1,
      sym_comment,
    STATE(93), 1,
      sym_arg,
    STATE(120), 1,
      sym_args,
  [2612] = 3,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    STATE(88), 1,
      sym_comment,
    ACTIONS(256), 4,
      ts_builtin_sym_end,
      anon_sym_fun,
      anon_sym_toaster,
      anon_sym_extern,
  [2625] = 5,
    ACTIONS(231), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(258), 1,
      anon_sym_DQUOTE,
    STATE(86), 1,
      aux_sym_string_repeat1,
    STATE(89), 1,
      sym_comment,
    ACTIONS(233), 2,
      sym_unescaped,
      sym_escape_seq,
  [2642] = 6,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(252), 1,
      sym_id,
    ACTIONS(260), 1,
      anon_sym_RPAREN,
    STATE(90), 1,
      sym_comment,
    STATE(93), 1,
      sym_arg,
    STATE(116), 1,
      sym_args,
  [2661] = 3,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    STATE(91), 1,
      sym_comment,
    ACTIONS(262), 4,
      ts_builtin_sym_end,
      anon_sym_fun,
      anon_sym_toaster,
      anon_sym_extern,
  [2674] = 3,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    STATE(92), 1,
      sym_comment,
    ACTIONS(264), 4,
      ts_builtin_sym_end,
      anon_sym_fun,
      anon_sym_toaster,
      anon_sym_extern,
  [2687] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(266), 1,
      anon_sym_RPAREN,
    ACTIONS(268), 1,
      anon_sym_COMMA,
    STATE(93), 1,
      sym_comment,
    STATE(102), 1,
      aux_sym_args_repeat1,
  [2703] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    STATE(94), 1,
      sym_comment,
    STATE(113), 1,
      sym__fun,
    ACTIONS(7), 2,
      anon_sym_fun,
      anon_sym_toaster,
  [2717] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(11), 1,
      anon_sym_LPAREN,
    ACTIONS(270), 1,
      anon_sym_LBRACK,
    ACTIONS(272), 1,
      anon_sym_EQ,
    STATE(95), 1,
      sym_comment,
  [2733] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(274), 1,
      anon_sym_COLON,
    ACTIONS(276), 1,
      anon_sym_LBRACE,
    STATE(76), 1,
      sym_block,
    STATE(96), 1,
      sym_comment,
  [2749] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(276), 1,
      anon_sym_LBRACE,
    ACTIONS(278), 1,
      anon_sym_COLON,
    STATE(84), 1,
      sym_block,
    STATE(97), 1,
      sym_comment,
  [2765] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(85), 1,
      anon_sym_RPAREN,
    ACTIONS(280), 1,
      anon_sym_COMMA,
    STATE(98), 2,
      sym_comment,
      aux_sym_fncall_repeat1,
  [2779] = 4,
    ACTIONS(231), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(285), 1,
      anon_sym_DQUOTE,
    STATE(99), 1,
      sym_comment,
    ACTIONS(283), 2,
      sym_unescaped,
      sym_escape_seq,
  [2793] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(287), 1,
      anon_sym_RPAREN,
    ACTIONS(289), 1,
      anon_sym_COMMA,
    STATE(100), 2,
      sym_comment,
      aux_sym_args_repeat1,
  [2807] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(59), 1,
      anon_sym_COMMA,
    ACTIONS(292), 1,
      anon_sym_RPAREN,
    STATE(98), 1,
      aux_sym_fncall_repeat1,
    STATE(101), 1,
      sym_comment,
  [2823] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(268), 1,
      anon_sym_COMMA,
    ACTIONS(294), 1,
      anon_sym_RPAREN,
    STATE(100), 1,
      aux_sym_args_repeat1,
    STATE(102), 1,
      sym_comment,
  [2839] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(296), 1,
      anon_sym_LBRACE,
    STATE(63), 1,
      sym_block,
    STATE(103), 1,
      sym_comment,
  [2852] = 3,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    STATE(104), 1,
      sym_comment,
    ACTIONS(298), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [2863] = 3,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    STATE(105), 1,
      sym_comment,
    ACTIONS(287), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [2874] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(276), 1,
      anon_sym_LBRACE,
    STATE(91), 1,
      sym_block,
    STATE(106), 1,
      sym_comment,
  [2887] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(300), 1,
      anon_sym_COLON,
    ACTIONS(302), 1,
      anon_sym_SEMI,
    STATE(107), 1,
      sym_comment,
  [2900] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(276), 1,
      anon_sym_LBRACE,
    STATE(92), 1,
      sym_block,
    STATE(108), 1,
      sym_comment,
  [2913] = 3,
    ACTIONS(231), 1,
      anon_sym_SLASH_SLASH,
    STATE(109), 1,
      sym_comment,
    ACTIONS(304), 2,
      sym_escape_seq,
      aux_sym_char_token1,
  [2924] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(252), 1,
      sym_id,
    STATE(105), 1,
      sym_arg,
    STATE(110), 1,
      sym_comment,
  [2937] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(306), 1,
      anon_sym_COLON,
    ACTIONS(308), 1,
      anon_sym_SEMI,
    STATE(111), 1,
      sym_comment,
  [2950] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(296), 1,
      anon_sym_LBRACE,
    STATE(66), 1,
      sym_block,
    STATE(112), 1,
      sym_comment,
  [2963] = 3,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(310), 1,
      sym_id,
    STATE(113), 1,
      sym_comment,
  [2973] = 3,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(312), 1,
      anon_sym_RBRACK,
    STATE(114), 1,
      sym_comment,
  [2983] = 3,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(314), 1,
      sym_id,
    STATE(115), 1,
      sym_comment,
  [2993] = 3,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(316), 1,
      anon_sym_RPAREN,
    STATE(116), 1,
      sym_comment,
  [3003] = 3,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(318), 1,
      anon_sym_SEMI,
    STATE(117), 1,
      sym_comment,
  [3013] = 3,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(320), 1,
      ts_builtin_sym_end,
    STATE(118), 1,
      sym_comment,
  [3023] = 3,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(322), 1,
      anon_sym_LPAREN,
    STATE(119), 1,
      sym_comment,
  [3033] = 3,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(324), 1,
      anon_sym_RPAREN,
    STATE(120), 1,
      sym_comment,
  [3043] = 3,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(326), 1,
      sym_id,
    STATE(121), 1,
      sym_comment,
  [3053] = 3,
    ACTIONS(231), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(328), 1,
      aux_sym_comment_token1,
    STATE(122), 1,
      sym_comment,
  [3063] = 3,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(330), 1,
      anon_sym_COLON,
    STATE(123), 1,
      sym_comment,
  [3073] = 3,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(332), 1,
      anon_sym_SEMI,
    STATE(124), 1,
      sym_comment,
  [3083] = 3,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(334), 1,
      sym_id,
    STATE(125), 1,
      sym_comment,
  [3093] = 3,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(336), 1,
      anon_sym_LPAREN,
    STATE(126), 1,
      sym_comment,
  [3103] = 3,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(338), 1,
      anon_sym_SQUOTE,
    STATE(127), 1,
      sym_comment,
  [3113] = 3,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(119), 1,
      anon_sym_SEMI,
    STATE(128), 1,
      sym_comment,
  [3123] = 3,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(340), 1,
      anon_sym_EQ,
    STATE(129), 1,
      sym_comment,
  [3133] = 3,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(342), 1,
      anon_sym_EQ,
    STATE(130), 1,
      sym_comment,
  [3143] = 1,
    ACTIONS(344), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 36,
  [SMALL_STATE(4)] = 72,
  [SMALL_STATE(5)] = 108,
  [SMALL_STATE(6)] = 141,
  [SMALL_STATE(7)] = 174,
  [SMALL_STATE(8)] = 207,
  [SMALL_STATE(9)] = 240,
  [SMALL_STATE(10)] = 273,
  [SMALL_STATE(11)] = 306,
  [SMALL_STATE(12)] = 339,
  [SMALL_STATE(13)] = 372,
  [SMALL_STATE(14)] = 405,
  [SMALL_STATE(15)] = 438,
  [SMALL_STATE(16)] = 471,
  [SMALL_STATE(17)] = 531,
  [SMALL_STATE(18)] = 586,
  [SMALL_STATE(19)] = 643,
  [SMALL_STATE(20)] = 697,
  [SMALL_STATE(21)] = 751,
  [SMALL_STATE(22)] = 805,
  [SMALL_STATE(23)] = 859,
  [SMALL_STATE(24)] = 913,
  [SMALL_STATE(25)] = 967,
  [SMALL_STATE(26)] = 1021,
  [SMALL_STATE(27)] = 1069,
  [SMALL_STATE(28)] = 1117,
  [SMALL_STATE(29)] = 1165,
  [SMALL_STATE(30)] = 1210,
  [SMALL_STATE(31)] = 1255,
  [SMALL_STATE(32)] = 1300,
  [SMALL_STATE(33)] = 1345,
  [SMALL_STATE(34)] = 1390,
  [SMALL_STATE(35)] = 1433,
  [SMALL_STATE(36)] = 1478,
  [SMALL_STATE(37)] = 1523,
  [SMALL_STATE(38)] = 1568,
  [SMALL_STATE(39)] = 1589,
  [SMALL_STATE(40)] = 1610,
  [SMALL_STATE(41)] = 1647,
  [SMALL_STATE(42)] = 1684,
  [SMALL_STATE(43)] = 1721,
  [SMALL_STATE(44)] = 1758,
  [SMALL_STATE(45)] = 1779,
  [SMALL_STATE(46)] = 1816,
  [SMALL_STATE(47)] = 1837,
  [SMALL_STATE(48)] = 1858,
  [SMALL_STATE(49)] = 1879,
  [SMALL_STATE(50)] = 1900,
  [SMALL_STATE(51)] = 1937,
  [SMALL_STATE(52)] = 1958,
  [SMALL_STATE(53)] = 1979,
  [SMALL_STATE(54)] = 2000,
  [SMALL_STATE(55)] = 2035,
  [SMALL_STATE(56)] = 2063,
  [SMALL_STATE(57)] = 2093,
  [SMALL_STATE(58)] = 2114,
  [SMALL_STATE(59)] = 2133,
  [SMALL_STATE(60)] = 2152,
  [SMALL_STATE(61)] = 2170,
  [SMALL_STATE(62)] = 2190,
  [SMALL_STATE(63)] = 2208,
  [SMALL_STATE(64)] = 2226,
  [SMALL_STATE(65)] = 2244,
  [SMALL_STATE(66)] = 2262,
  [SMALL_STATE(67)] = 2280,
  [SMALL_STATE(68)] = 2298,
  [SMALL_STATE(69)] = 2318,
  [SMALL_STATE(70)] = 2338,
  [SMALL_STATE(71)] = 2356,
  [SMALL_STATE(72)] = 2376,
  [SMALL_STATE(73)] = 2396,
  [SMALL_STATE(74)] = 2416,
  [SMALL_STATE(75)] = 2430,
  [SMALL_STATE(76)] = 2444,
  [SMALL_STATE(77)] = 2457,
  [SMALL_STATE(78)] = 2470,
  [SMALL_STATE(79)] = 2483,
  [SMALL_STATE(80)] = 2496,
  [SMALL_STATE(81)] = 2513,
  [SMALL_STATE(82)] = 2526,
  [SMALL_STATE(83)] = 2539,
  [SMALL_STATE(84)] = 2552,
  [SMALL_STATE(85)] = 2565,
  [SMALL_STATE(86)] = 2578,
  [SMALL_STATE(87)] = 2593,
  [SMALL_STATE(88)] = 2612,
  [SMALL_STATE(89)] = 2625,
  [SMALL_STATE(90)] = 2642,
  [SMALL_STATE(91)] = 2661,
  [SMALL_STATE(92)] = 2674,
  [SMALL_STATE(93)] = 2687,
  [SMALL_STATE(94)] = 2703,
  [SMALL_STATE(95)] = 2717,
  [SMALL_STATE(96)] = 2733,
  [SMALL_STATE(97)] = 2749,
  [SMALL_STATE(98)] = 2765,
  [SMALL_STATE(99)] = 2779,
  [SMALL_STATE(100)] = 2793,
  [SMALL_STATE(101)] = 2807,
  [SMALL_STATE(102)] = 2823,
  [SMALL_STATE(103)] = 2839,
  [SMALL_STATE(104)] = 2852,
  [SMALL_STATE(105)] = 2863,
  [SMALL_STATE(106)] = 2874,
  [SMALL_STATE(107)] = 2887,
  [SMALL_STATE(108)] = 2900,
  [SMALL_STATE(109)] = 2913,
  [SMALL_STATE(110)] = 2924,
  [SMALL_STATE(111)] = 2937,
  [SMALL_STATE(112)] = 2950,
  [SMALL_STATE(113)] = 2963,
  [SMALL_STATE(114)] = 2973,
  [SMALL_STATE(115)] = 2983,
  [SMALL_STATE(116)] = 2993,
  [SMALL_STATE(117)] = 3003,
  [SMALL_STATE(118)] = 3013,
  [SMALL_STATE(119)] = 3023,
  [SMALL_STATE(120)] = 3033,
  [SMALL_STATE(121)] = 3043,
  [SMALL_STATE(122)] = 3053,
  [SMALL_STATE(123)] = 3063,
  [SMALL_STATE(124)] = 3073,
  [SMALL_STATE(125)] = 3083,
  [SMALL_STATE(126)] = 3093,
  [SMALL_STATE(127)] = 3103,
  [SMALL_STATE(128)] = 3113,
  [SMALL_STATE(129)] = 3123,
  [SMALL_STATE(130)] = 3133,
  [SMALL_STATE(131)] = 3143,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prog, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expr, 1),
  [15] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expr, 1),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expr, 2),
  [19] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expr, 2),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expr, 3),
  [23] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expr, 3),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_char, 3),
  [27] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_char, 3),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 2),
  [31] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 2),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__literal, 1),
  [35] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__literal, 1),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fncall, 5),
  [39] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_fncall, 5),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 3),
  [43] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 3),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expr, 4),
  [47] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expr, 4),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fncall, 3),
  [51] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_fncall, 3),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fncall, 4),
  [55] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_fncall, 4),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [69] = {.entry = {.count = 1, .reusable = false}}, SHIFT(48),
  [71] = {.entry = {.count = 1, .reusable = false}}, SHIFT(39),
  [73] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [75] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [77] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [79] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [81] = {.entry = {.count = 1, .reusable = false}}, SHIFT(49),
  [83] = {.entry = {.count = 1, .reusable = false}}, SHIFT(38),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_fncall_repeat1, 2),
  [87] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [89] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [91] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [95] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [103] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [117] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [119] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [123] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bop, 1),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bop, 1),
  [127] = {.entry = {.count = 1, .reusable = false}}, SHIFT(95),
  [129] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [131] = {.entry = {.count = 1, .reusable = false}}, SHIFT(125),
  [133] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [135] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [137] = {.entry = {.count = 1, .reusable = false}}, SHIFT(103),
  [139] = {.entry = {.count = 1, .reusable = false}}, SHIFT(128),
  [141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [147] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_uop, 1),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uop, 1),
  [151] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [153] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [155] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(95),
  [158] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2),
  [160] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(125),
  [163] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(27),
  [166] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(36),
  [169] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(103),
  [172] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(128),
  [175] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_prog_repeat1, 2),
  [177] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_prog_repeat1, 2), SHIFT_REPEAT(121),
  [180] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_prog_repeat1, 2), SHIFT_REPEAT(94),
  [183] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prog, 1),
  [185] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_stmt, 3),
  [187] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stmt, 3),
  [189] = {.entry = {.count = 1, .reusable = false}}, SHIFT(112),
  [191] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 2),
  [193] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 2),
  [195] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 3),
  [197] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 3),
  [199] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_stmt, 4),
  [201] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stmt, 4),
  [203] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [205] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [207] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_stmt, 2),
  [209] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stmt, 2),
  [211] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_stmt, 7),
  [213] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stmt, 7),
  [215] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_stmt, 5),
  [217] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stmt, 5),
  [219] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 1),
  [221] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 1),
  [223] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ty, 3),
  [225] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ty, 1),
  [227] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func, 6),
  [229] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_externdecl, 7),
  [231] = {.entry = {.count = 1, .reusable = false}}, SHIFT(122),
  [233] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [235] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [237] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_externdecl, 8),
  [239] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_externdecl, 6),
  [241] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_prog_repeat1, 1),
  [243] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func, 5),
  [245] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_item, 1),
  [247] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_repeat1, 2), SHIFT_REPEAT(99),
  [250] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_repeat1, 2),
  [252] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [254] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [256] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_externdecl, 9),
  [258] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [260] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [262] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func, 7),
  [264] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func, 8),
  [266] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_args, 1),
  [268] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [270] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [272] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [274] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [276] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [278] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [280] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fncall_repeat1, 2), SHIFT_REPEAT(33),
  [283] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_string_repeat1, 1),
  [285] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_repeat1, 1),
  [287] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_args_repeat1, 2),
  [289] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_args_repeat1, 2), SHIFT_REPEAT(110),
  [292] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [294] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_args, 2),
  [296] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [298] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg, 3),
  [300] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [302] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [304] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [306] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [308] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [310] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [312] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [314] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [316] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [318] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [320] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [322] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [324] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [326] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__fun, 1),
  [328] = {.entry = {.count = 1, .reusable = false}}, SHIFT(131),
  [330] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [332] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [334] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [336] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [338] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [340] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [342] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [344] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 2, .production_id = 1),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_tost(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
