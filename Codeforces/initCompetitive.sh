#!/bin/bash

CONTEST_NAME="CFR/CFR739"
PROBLEMS=(A B C D E F G)

if [ -d "$CONTEST_NAME" ]; then
  echo "Direction existed"
  exit 1
fi

mkdir $CONTEST_NAME

cd $CONTEST_NAME
for problemName in "${PROBLEMS[@]}" do 
  mkdir $problemName 
  cd $problemName 

  wget https://raw.githubusercontent.com/lioaslan/Competitive-Training/master/sample.cpp
  mv sample.cpp data.cpp

  touch data.inp
  touch data.out

  cd ..
done 

echo "Create contest successfully"
