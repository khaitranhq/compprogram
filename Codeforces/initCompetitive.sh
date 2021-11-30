#!/bin/bash

CODEFORCES_DIR=`pwd`
CONTEST_NAME="tmp"
PROBLEMS=(A B C D1 D2)

if [ -d "$CONTEST_NAME" ]; then
  echo "Direction existed"
  exit 1
fi

mkdir $CONTEST_NAME

cd $CONTEST_NAME

cp $CODEFORCES_DIR/../run_with_test.py .
for problemName in "${PROBLEMS[@]}" 
do 
  mkdir $problemName
  cd $problemName

  wget https://raw.githubusercontent.com/lioaslan/Competitive-Training/master/sample.cpp
  mv sample.cpp data.cpp

  touch data.inp

  cd ..
done 

echo "Create contest successfully"
