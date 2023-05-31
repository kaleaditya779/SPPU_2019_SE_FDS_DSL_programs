'''
Write a Python program to store second year percentage of students in array. Write function for 
sorting array of floating point numbers in ascending order using 
    a) Insertion sort 
    b) Shell Sort and display top five scores
'''



a = []

def getL():
    n = int(input("Enter size : "))
    for i in range(n):
        t = int(input("Enter : "))
        a.append(t)

def insertion_sort():
    for i in range(1,len(a)):
        key = a[i]
        j = i-1
        while j>=0 and key<a[j]:
            a[j+1] =  a[j]
            j-=1
        a[j+1] = key
    for i in range(len(a)):
        print(a[i])

def shell_sort(A,n):
   gap = n // 2
   while gap > 0:
      for i in range(gap,n):
         temp = A[i]
         j = i
         while j >= gap and A[j - gap] > temp:
            A[j] = A[j - gap]
            j =j-gap
         A[j] = temp
      gap= gap// 2


getL()
shell_sort(a,len(a))
for i in range(len(a)):
    print(a[i])