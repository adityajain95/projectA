#!/bin/bash
read -r arg1 arg2 arg3 < /tmp/arguments.in
g++-10 -std=c++14 $arg1 -o $arg3/$arg2
$arg3/$arg2
echo "[FINISHED]"
read
exit