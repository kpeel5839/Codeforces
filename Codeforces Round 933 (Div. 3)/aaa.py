# 파일명
filename = "output.txt"

# 그래프의 정점 수
vertices = 200000

# 그래프의 간선 수
edges = 199999

# 파일에 출력
with open(filename, 'w') as f:
    f.write(str(edges) + "\n")
    f.write(str(vertices) + " " + str(edges) + "\n")
    
    # 간선 정보 생성 및 파일에 쓰기
    for i in range(2, vertices + 1):
        f.write("1 " + str(i) + " " + str(i - 1) + "\n")

print("파일이 성공적으로 생성되었습니다.")