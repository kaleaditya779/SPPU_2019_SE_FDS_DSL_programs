'''
Write a Python program to compute following computation on matrix: 
    a) Addition of two matrices 
    B) Subtraction of two matrices 
    c) Multiplication of two matrices 
    d) Transpose of a matrix
'''


def getMat(r,c):
    matrix = []
    for i in range(r):
        a = []
        for j in range(c):
            temp = int(input("Enter the matrix element : "))
            a.append(temp)
        matrix.append(a)
    return matrix

def Display(matrix,r,c):
    for i in range(r):
        for j in range(c):
            print(matrix[i][j],end=" ")
        print(" ")

def additionM(mat1,mat2,r,c):
    if(r == c):
        result = [[0 for i in range(r)]for i in range(c)]
        for i in range(r):
            for j in range(c):
                result[i][j] = mat1[i][j] + mat2[i][j]
        return result
    else:
        print("Rows are not equal to columns.\n")

def subtractionM(mat1,mat2,r,c):
    if(r == c):
        result = [[0 for i in range(r)]for i in range(c)]
        for i in range(r):
            for j in range(c):
                result[i][j] = mat1[i][j] - mat2[i][j]
        return result
    else:
        print("Rows are not equal to columns.\n")

def multiplicationM(mat1,mat2,r1,c1,r2,c2):
    if(c1 == r2):
        result = [[0 for i in range(r1)]for i in range(c2)]
        for i in range(r1):
            for j in range(c2):
                for k in range(c1):
                    result[i][j] += mat1[i][k] * mat2[k][j]
        return result
    else:
        print("Not satisfy the Multiplication condition !!")
            
def transposeM(mat,r1,c1):
    result = [[0 for i in range(r1)]for i in range(c1)]
    for i in range(r1):
        for j in range(c1):
            result[j][i] = mat[i][j]
    return result

def main():
    temp = 1
    while(temp):
        print("1.Addition of Matrices \n2.Subtraction of Matrices\n3.Multiplication of Matrices\n4.Transpose of matrix\n5.Exit")
        choice = int(input("Choice : "))
        if(choice == 1):
            r1 = int(input("Enter the number of rows : "))
            c1 = int(input("Enter the number of columns : "))
            mat1 = getMat(r1,c1)
            Display(mat1,r1,c1)
            mat2 = getMat(r1,c1)
            Display(mat2,r1,c1)
            res = additionM(mat1,mat2,r1,c1)
            print("Addition\n")
            print(Display(res,r1,c1))
        elif(choice == 2):
            r1 = int(input("Enter the number of rows : "))
            c1 = int(input("Enter the number of columns : "))
            mat1 = getMat(r1,c1)
            Display(mat1,r1,c1)
            mat2 = getMat(r1,c1)
            Display(mat2,r1,c1)
            res = subtractionM(mat1,mat2,r1,c1)
            print("Subtraction\n")
            print(Display(res,r1,c1))
        elif(choice == 3):
            r1 = int(input("Enter the number of rows : "))
            c1 = int(input("Enter the number of columns : "))
            mat1 = getMat(r1,c1)
            Display(mat1,r1,c1)
            r2 = int(input("Enter the number of rows : "))
            c2 = int(input("Enter the number of columns : "))
            mat2 = getMat(r1,c1)
            Display(mat2,r1,c1)
            res = multiplicationM(mat1,mat2,r1,c1,r2,c2)
            print("Multiplication\n")
            print(Display(res,r1,c2))
        elif(choice == 4):
            r = int(input("Enter the number of rows : "))
            c = int(input("Enter the number of columns : "))
            mat1 = getMat(r,c)
            Display(mat1,r,c)
            res = transposeM(mat1,r,c)
            print("Transpose\n")
            print(Display(res,c,r))
        elif(choice == 5):
            temp = 0

main()