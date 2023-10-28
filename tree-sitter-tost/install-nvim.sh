#!/bin/sh

set -e

base="$(pwd)"
neovim_config_dir="$XDG_CONFIG_HOME/nvim"
tree-sitter generate
cd src
gcc -o tost.so -shared parser.c -Os -fPIC
cd "$base"
mkdir -p "$neovim_config_dir/queries/tost"
mkdir -p "$neovim_config_dir/parser"
cp "$base/src/tost.so" "$neovim_config_dir/parser/tost.so"
echo "copied files:" "$neovim_config_dir/parser/tost.so"
cp "$base/queries/"* "$neovim_config_dir/queries/tost"
echo "copied files:"  "$neovim_config_dir/queries/tost"/*

echo "[NOTE]: make sure to set the file type to tost in .tost files"
