#!/bin/bash

read -p "대회 명을 입력하세요: " contestName
read -p "문제 개수를 입력하세요: " problemCount

mkdir "${contestName}"
echo "${contestName} 디렉토리가 생성되었습니다."
i=1

while [ $i -le $problemCount ]
do
    #filename=$(printf "%c" $((i+96)))
    filename=$(printf "\\$(printf '%03o' $((i+96)))")
    cat template/template.cpp >> "${contestName}/${filename}.cpp"
    echo "파일 ${filename}.cpp 이 생성되었습니다."
    touch "${contestName}/${filename}.input.txt"
    echo "파일 ${filename}.input.txt 이 생성되었습니다."
    i=$((i+1))
    echo "현재 루프를 돌고 있는 중의 i 의 값은 ${filename} 입니다."
done
