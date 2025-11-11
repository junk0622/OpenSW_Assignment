#!/bin/bash

factorial() {
local num=$1
result=1

for i in $(seq 1 $num)
do
result=$((result * i))
done
echo "Factorial of $1 is $result"
}
read -p "Enter a number: " NUM

factorial $NUM
