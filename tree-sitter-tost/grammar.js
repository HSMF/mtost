module.exports = grammar({
  name: "tost",
  extras: ($) => [$.comment, /\s/],
  rules: {
    prog: ($) => repeat($.item),
    item: ($) => choice($.func, $.externdecl, $.import),
    import: ($) => seq("import", $.path, ";"),
    path: ($) => sep1($.id, "::"),
    id: (_) => /[a-zA-Z_]\w*/,
    // comment: (_) => seq("//", /[^\n]*/),
    comment: (_) =>
      seq(
        field("start", alias("//", "comment_start")),
        field("content", alias(/[^\r\n]*/, "comment_content"))
      ),
    _fun: (_) => choice("fun", "toaster"),
    externdecl: ($) =>
      seq(
        "extern",
        $._fun,
        $.id,
        "(",
        optional($.args),
        ")",
        optional(seq(":", $.ty)),
        ";"
      ),
    func: ($) =>
      seq(
        $._fun,
        $.id,
        "(",
        optional($.args),
        ")",
        optional(seq(":", $.ty)),
        $.block
      ),
    arg: ($) => seq($.id, ":", $.ty),
    args: ($) => sep1($.arg, ","),
    ty: ($) => choice("i64", "i8", "bool", "str", seq("[", $.ty, "]"), "unit"),
    block: ($) => seq("{", repeat($.stmt), "}"),
    stmt: ($) =>
      choice(
        seq("let", $.id, "=", $.expr, ";"),
        seq($.id, "=", $.expr, ";"),
        seq($.id, "[", $.expr, "]", "=", $.expr, ";"),
        seq($.fncall, ";"),
        seq("return", $.expr, ";"),
        seq("return", ";"),
        seq("if", $.expr, $.block),
        seq("if", $.expr, $.block, "else", $.block),
        seq("loop", $.block),
        seq("break", ";")
      ),
    bop: (_) =>
      choice(
        prec.left(100, "*"),
        prec.left(90, "+"),
        prec.left(90, "-"),
        prec.left(80, "<<"),
        prec.left(80, ">>"),
        prec.left(80, ">>>"),
        prec.left(70, "<"),
        prec.left(70, "<="),
        prec.left(70, ">"),
        prec.left(70, ">="),
        prec.left(60, "=="),
        prec.left(60, "!="),
        prec.left(50, "&&"),
        prec.left(40, "||"),
        prec.left(30, "&"),
        prec.left(20, "|")
      ),
    unescaped: (_) => token.immediate(prec(1, /[^"\\]+/)),
    escape_seq: (_) =>
      token.immediate(
        prec(1, seq("\\", choice(/x[a-fA-F0-9]{2}/, /[nr"'\\]/)))
      ),
    // token.immediate(
    //   seq("\\", "'", choice(/x[a-fA-F0-9]{2}/, /[0-7]{1,3}/, /[nr"\\]/))
    // ),
    string: ($) => seq('"', repeat(choice($.unescaped, $.escape_seq)), '"'),
    char: ($) =>
      seq("'", choice(token.immediate(prec(1, /[^'\\]/)), $.escape_seq), "'"),
    integer: (_) => /\d+/,
    _literal: ($) => choice($.integer, $.string, $.char, "true", "false"),

    uop: (_) => choice("-", "!", "~"),
    expr: ($) =>
      prec.left(
        choice(
          $.id,
          $._literal,
          seq($.expr, $.bop, $.expr),
          seq($.uop, $.expr),
          seq("(", $.expr, ")"),
          seq($.expr, "[", $.expr, "]"),
          $.fncall,
          seq("(", ")")
        )
      ),

    fncall: ($) => seq($.id, "(", optional(sep($.expr, ",")), ")"),
  },
});

/**
 *
 * @param {string} rule
 * */
function named(rule, $) {
  return alias(rule, $[rule]);
}

function sep1(rule, sep) {
  return seq(rule, repeat(seq(sep, rule)));
}

function sep(rule, separator) {
  return optional(sep1(rule, separator));
}
