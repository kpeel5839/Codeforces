#!/bin/bash

read -p "대회 명을 입력하세요: " contestName
read -p "문제 개수를 입력하세요: " problemCount

mkdir "${contestName}"
echo "${contestName} 디렉토리가 생성되었습니다."
i=1

while [ $i -le $problemCount ]
do
    filename=$(printf "\\$(printf '%03o' $((i+96)))")
    cat template/template.cpp | sed "s/freopen(\"input.txt\", \"r\", stdin);/freopen(\"${filename}.input.txt\", \"r\", stdin);/" >> "${contestName}/${filename}.cpp"
    echo "파일 ${filename}.cpp 이 생성되었습니다."
    touch "${contestName}/${filename}.input.txt"
    echo "파일 ${filename}.input.txt 이 생성되었습니다."
    i=$((i+1))
done
