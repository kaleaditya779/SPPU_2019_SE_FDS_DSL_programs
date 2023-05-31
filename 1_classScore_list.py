
'''
Write a Python program to store marks scored in subject “Fundamental of Data Structure” by 
N students in the class. Write functions to compute following: 
    a) The average score of class 
    b) Highest score and lowest score of class 
    c) Count of students who were absent for the test 
    d) Display mark with highest frequency
'''

list1 = []
studentsAbsentG = 0
size = 0

def getMarks():
    size = int(input("Enter the number of students : "))
    for i in range(size):
        temp = int(input("Enter the marks : "))
        list1.append(temp)

def average():
    count = 0
    Sum = 0
    for i in list1:
        if(i == -1):
            continue
        Sum += i
        count += 1
    print("\naverage : ",Sum/count)
    print("\n")

def highestMarks():
    highM = 0
    for i in list1:
        if(i > highM):
            highM = i
    return highM

def lowestMarks():
    lowM = highestMarks()
    for i in list1:
        if(i == -1):
            continue
        if(i < lowM):
            lowM = i
    return lowM
    

def studentsAbsent():
    studentsAbsent = 0
    for i in list1:
        if(i == -1):
            studentsAbsent+=1
    return studentsAbsent

def lowMarkFreq():
    check = lowestMarks()
    count= 0
    for i in list1:
        if(i == check):
            count+=1
    return count

def HighMarkFreq():
    check = highestMarks()
    count= 0
    for i in list1:
        if(i == check):
            count+=1
    return count

def main():
    temp = 1
    while(temp):
        print("1.Enter marks of students \n2.Average marks\n3.Highest Marks\n4.Lowest marks\n5.absent students\n6.Mark with highest frequency\n7.Exit")
        choice = int(input("Choice : "))
        if(choice == 1):
            getMarks()
        elif(choice == 2):
            average()
        elif(choice == 3):
            print("\nHighest Marks : ",highestMarks())
            print("\n")
        elif(choice == 4):
            print("\nLowest Marks : ",lowestMarks())
            print("\n")
        elif(choice == 5):
            print("\n")
            print("Absent students : ",studentsAbsent())
            print("\n")
        elif(choice == 6):
            print("Lowest Marks Frequency : ",lowMarkFreq())
            print("Highest Marks Frequency : ",HighMarkFreq())
        elif(choice == 7):
            break

main()






