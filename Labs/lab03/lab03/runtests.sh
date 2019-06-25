#!/bin/sh
num=1
while test $num -lt 6
do
    ./autotest $num
    num=$(($num + 1))
done