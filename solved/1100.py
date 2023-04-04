array = []

result = 0

for i in range(8):
    array.append(list(input()))

for i in range(8):
    for j in range(8):
        if (i % 2 == 0 and j % 2 == 0) and array[i][j] == "F":
            result += 1 
        elif (i % 2 != 0 and j % 2 != 0) and array[i][j] == "F":
            result += 1
            
print(result)