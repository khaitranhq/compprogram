#!/bin/bash

PROBLEM_NAME="CFR479/F"

if [ -d "$PROBLEM_NAME" ]; then
  echo "Direction existed"
  exit 1
fi

mkdir -p $PROBLEM_NAME

cd $PROBLEM_NAME
wget https://raw.githubusercontent.com/lioaslan/Competitive-Training/master/sample.cpp
mv sample.cpp data.cpp

touch data.inp

echo "Create problem successfully"
