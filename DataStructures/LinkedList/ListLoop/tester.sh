counter=1;
for i in test/*.in;
do printf "Test %d: " $((counter++)); ./is_loop < $i;
done