# mtost - the mediocre tost compiler

## Try it out

1. Get Ocaml, dune, menhir, ocamllex

1. there is no real standard library yet, so to write actual programs, `std.c` exists. You need to
   build that first:

```
gcc -c std.c
```

3. build the compiler

```
dune build
```

3. compile your first tost program

```
./_build/default/mtost.exe main.tost
```

4. run it!

```
./target/main
```

## further

for todos see [TODO.md](./TODO.md)


