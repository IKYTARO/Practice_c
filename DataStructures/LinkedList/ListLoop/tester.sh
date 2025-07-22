#!/bin/bash

testing_exec=$1
for i in test/*.in;
do printf "Test %d: " $((counter++)); $testing_exec < $i;
done