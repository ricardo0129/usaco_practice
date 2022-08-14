#!/bin/bash

echo "$1"
cp ../../template.cpp "./$1.cppt"
sed 's/test/'$1"/g" $1.cppt > $1.cpp
rm $1.cppt
