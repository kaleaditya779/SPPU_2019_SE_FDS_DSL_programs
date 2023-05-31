'''
Write a Python program to store first year percentage of students in array. 
Write function for sorting array of floating point numbers in ascending order using quick sort 
and display top five scores.
'''

def getMarks(list1 = []):
    size = int(input("Enter the number of students : "))
    for i in range(size):
        temp = int(input("Enter the marks : "))
        list1.append(temp)
    print("\nMarks")
    print(list1)

def partition(list1,start,end):
    pivot = list1[end]
    i = start - 1
    for j in range(start,end):
        if(list1[j] <= pivot):
            i += 1
            list1[i],list1[j] = list1[j],list1[i]
    list1[i+1],list1[end] = list1[end],list1[i+1]
    return i+1

def displayTop(list1):
    Top5 = int(input("\nDo you want top 5 scores ?(1/0)\n"))
    n = len(list1)
    if(Top5 == 1):
        if(n<5):
            for i in range(n-1,-1,-1):
                print(list1[i],end=" ")
        else:
            for i in range(5,0,-1):
                print(list1[i],end=" ")
    else:
        return

def quickSort(list1, start, end):
    if(start < end):
        pi = partition(list1,start,end)
        quickSort(list1,start,pi-1)
        quickSort(list1,pi+1,end)

def main():
    list1 = []
    getMarks(list1)
    quickSort(list1,0,len(list1)-1)
    print("Sorted : ",list1)
    displayTop(list1)

main()