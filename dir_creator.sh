#!/bin/bash

# Exit on error
set -e

#read -p "대회 명을 입력하세요: " contestName
read -p "대회 명을 입력하세요: " contestName && contestName=${contestName// /_}
read -p "문제 개수를 입력하세요: " problemCount

# Create main directory
if ! mkdir "${contestName}" 2>/dev/null; then
    echo "Error: Directory ${contestName} already exists or cannot be created"
    exit 1
fi
echo "${contestName} 디렉토리가 생성되었습니다."

# Create .vscode directory
#mkdir "${contestName}/.vscode"
#echo ".vscode 디렉토리가 생성되었습니다."

# Create c_cpp_properties.json
#cat > "${contestName}/.vscode/c_cpp_properties.json" << 'EOL'
#{
#    "configurations": [
#        {
#            "name": "Mac",
#            "includePath": [
#                "${workspaceFolder}/**"
#            ],
#            "defines": [],
#            "macFrameworkPath": [
#                "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/System/Library/Frameworks"
#            ],
#            "compilerPath": "/usr/bin/g++",
#            "cStandard": "c17",
#            "cppStandard": "c++17",
#            "intelliSenseMode": "macos-clang-arm64"
#        }
#    ],
#    "version": 4
#}
#EOL
#echo "c_cpp_properties.json 파일이 생성되었습니다."

# Create tasks.json
#cat > "${contestName}/.vscode/tasks.json" << 'EOL'
#{
#    "version": "2.0.0",
#    "tasks": [
#        {
#            "type": "shell",
#            "label": "C/C++: g++ build active file",
#            "command": "/usr/bin/g++",
#            "args": [
#                "-std=c++17",
#                "-stdlib=libc++",
#                "-g",
#                "${file}",
#                "-o",
#                "${fileDirname}/${fileBasenameNoExtension}.out",
#                "&&",
#                "${fileDirname}/${fileBasenameNoExtension}.out"
#            ],
#            "options": {
#                "cwd": "${workspaceFolder}"
#            },
#            "problemMatcher": [
#                "$gcc"
#            ],
#            "group": {
#                "kind": "build",
#                "isDefault": true
#            }
#        },
#        {
#            "label": "exec",
#            "type": "shell",
#            "command": "${fileDirname}/${fileBasenameNoExtension}.out",
#            "group": {
#                "kind": "build",
#                "isDefault": true
#            }
#        }
#    ]
#}
#EOL
#echo "tasks.json 파일이 생성되었습니다."

i=1

while [ $i -le $problemCount ]
do
    filename=$(printf "\\$(printf '%03o' $((i+96)))")
    cat template/template.cpp | sed "s#freopen(\"input.txt\", \"r\", stdin);#freopen(\"${contestName}/${filename}.input.txt\", \"r\", stdin);#" >> "${contestName}/${filename}.cpp"
    echo "파일 ${filename}.cpp 이 생성되었습니다."
    touch "${contestName}/${filename}.input.txt"
    echo "파일 ${filename}.input.txt 이 생성되었습니다."
    i=$((i+1))
done
