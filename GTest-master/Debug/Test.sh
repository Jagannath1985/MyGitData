#!/bin/bash
cd /home/jagannath/Nxp/GTest-master/Debug
make clean
make

GTEST_ARGS1=($1)
GTEST_ARGS2=($2)

echo ; echo $GTEST_ARGS1; echo ;
echo ; echo $GTEST_ARGS2; echo ;

if [[ $GTEST_ARGS1 != "-" ]] && [[ $GTEST_ARGS2 != "-" ]]
then    
./helloc --gtest_output="xml:Reports/testAll5.xml" 3
else
./helloc --gtest_output="xml:Reports/testAll5.xml" 2
fi



