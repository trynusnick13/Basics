import random


# output matrix args
def print_matrix(args, m):
    for i in range(m):
        for j in range(m):
            print(args[i][j], end=' ')

        print()


# randomize the values of a matrix
def filling_matrix(args, m):
    for i in range(m):
        for j in range(m):
            args[i][j] = int(random.randint(1,100))



n = int(input("Enter the size of a matrix: "))
a = []
for i in range(n):
    a.append([0]*n)


# print_matrix(a, n)
filling_matrix(a, n)
print_matrix(a, n)


# function of finding min value of the first triangle
min1 = 100
for i in range(0, int(n/2)+1):
    for j in range(i, n-i):
        # print(a[i][j], end=' ')
        if min1 > a[i][j]:
            min1 = a[i][j]


min2 = 100
for i in range(int(n/2), n):
    for j in range(n-i-1, i+1):
          # print(a[i][j], end=' ')
        if min2 > a[i][j]:
            min2 = a[i][j]


print("min1 = ", min1)
print("min2 = ", min2)

min = min1 if min1 < min2 else min2

print("min = ", min)