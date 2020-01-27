#!/bin/bash

## -------------------------------- PATHS ----------------------------------- ##

test()
{
	echo "NEW:"
	../asm champs/${1}.s
	hexdump -C champs/${1}.cor > myret
	../asm_zaz champs/${1}.s
	hexdump -C champs/${1}.cor > zazret
	echo "Champion: ${1} | diff with zaz is:" >> script.out;
	diff myret zazret >> script.out;
}

echo "ASM TEST FOR VALID CHAMPIONS"
touch script.out
echo "\n--- RESULTS ---" >> script.out
#test Car
#test ex
#test Gagnant
#test jumper
#test maxidef
#test mortel
#test slider2
#test test
#test toto
#test Octobre_Rouge_V4.2
for f in champs/*.s
do
	test `echo $f | rev | cut -c 3- | rev | cut -d '/' -f 2`
done
cat -e script.out
rm champs/*.cor zazret myret script.out
