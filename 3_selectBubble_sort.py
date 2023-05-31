'''
Write a Python program to store first year percentage of students in array. Write function for 
sorting array of floating point numbers in ascending order using 
    a) Selection Sort 
    b) Bubble sort and display top five scores
'''


def getMarks(list1):
    size = int(input("Enter the number of students : "))
    for i in range(size):
        temp = int(input("Enter the marks : "))
        list1.append(temp)
    print("\nMarks")
    print(list1)

def display(list1):
    n = len(list1)
    for i in list1:
        print(i,end=" ")
    Top5 = int(input("\nDo you want top 5 scores ?(1/0)\n"))
    if(Top5 == 1):
        for i in range(n-1,-1,-1):
            print(list1[i],end=" ")
    else:
        return

def selection_sort(list1):
    n = len(list1)
    for i in range(n):
        min_index = i;
        for j in range(i+1,n):
            if(list1[j] < list1[min_index]):
                min_index = j
        list1[i],list1[min_index] = list1[min_index],list1[i]

def bubble_sort(list1):
    n = len(list1)
    for i in range(n):
        for j in range(n-1):
            if(list1[j] > list1[j+1]):
                list1[j],list1[j+1] = list1[j+1],list1[j] 

def main():
    temp = 1
    while(temp):
        print("\n1.Selection Sort \n2.Bubble Sort\n3.Exit\n")
        choice = int(input("Choice : "))
        if(choice == 1):
            list_s = []
            getMarks(list_s)
            selection_sort(list_s);
            display(list_s)
        elif(choice == 2):
            list_b = []
            getMarks(list_b)
            bubble_sort(list_b);
            display(list_b)
        elif(choice == 3):
            temp = 0
            print("Thank you !!")

main()