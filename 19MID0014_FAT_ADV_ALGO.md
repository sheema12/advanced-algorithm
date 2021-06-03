```python
import random
print("---------------SHEEMA ZAINAB M I 19MID0014-------------------")
def rand_qs(arr, start, stop):
    if(start < stop):
        
        pivotindex = pivot(arr, start, stop)
        rand_qs(arr, start, pivotindex)
        rand_qs(arr, pivotindex + 1, stop)

def pivot(arr, start, stop):
    randpivot = random.randrange(start, stop)
    arr[start], arr[randpivot] = arr[randpivot], arr[start]
    return partition(arr, start, stop)

def partition(arr, start, stop):  ##ascending
    pivot = start  
    i = start - 1
    j = stop + 1
    while True:
        while True:
            i = i + 1
            if arr[i][2] >= arr[pivot][2]:
                break
        while True:
            j = j - 1
            if arr[j][2] <= arr[pivot][2]:
                break
        if i >= j:
            return j
        arr[i], arr[j] = arr[j], arr[i]


def display(array):
    print("Roll_no\t\t\tName   \t\t\tMarks")
    for i in range(len(array)):
        x, y, z = array[i][0], array[i][1], array[i][2]
        print(f"{x}\t\t\t{y}\t\t\t{z}")


array1 = [[1, 'Anand', 85], [3, 'Hari', 72], [5, 'Khanna', 100], [7, 'Santosh', 83], [9, 'Selvi', 80]]
array2 = [[2, 'Bose', 65], [4, 'Devi', 71], [ 6, 'Raji', 77], [8, 'Ruby', 94], [10, 'Uma', 82]]

print("Unsorted Table A : ")
display(array1)
rand_qs(array1, 0, len(array1) - 1)
print("------------------------------------------------------------------------")
print("Sorted Table A :")
display(array1)
print("------------------------------------------------------------------------")
print("Unsorted Table B :")
display(array2)
rand_qs(array2, 0, len(array2) - 1)
print("------------------------------------------------------------------------")
print("Sorted Table B :")
display(array2)
array3 = []
array3.extend(array1)
array3.extend(array2)
print("------------------------------------------------------------------------")
print("Unsorted Combined Table :")
display(array3)
rand_qs(array3, 0, len(array3) - 1)
print("------------------------------------------------------------------------")
print("Sorted Combined Table :")
display(array3)

```

    ---------------SHEEMA ZAINAB M I 19MID0014-------------------
    Unsorted Table A : 
    Roll_no			Name   			Marks
    1			Anand			85
    3			Hari			72
    5			Khanna			100
    7			Santosh			83
    9			Selvi			80
    ------------------------------------------------------------------------
    Sorted Table A :
    Roll_no			Name   			Marks
    3			Hari			72
    9			Selvi			80
    7			Santosh			83
    1			Anand			85
    5			Khanna			100
    ------------------------------------------------------------------------
    Unsorted Table B :
    Roll_no			Name   			Marks
    2			Bose			65
    4			Devi			71
    6			Raji			77
    8			Ruby			94
    10			Uma			82
    ------------------------------------------------------------------------
    Sorted Table B :
    Roll_no			Name   			Marks
    2			Bose			65
    4			Devi			71
    6			Raji			77
    10			Uma			82
    8			Ruby			94
    ------------------------------------------------------------------------
    Unsorted Combined Table :
    Roll_no			Name   			Marks
    3			Hari			72
    9			Selvi			80
    7			Santosh			83
    1			Anand			85
    5			Khanna			100
    2			Bose			65
    4			Devi			71
    6			Raji			77
    10			Uma			82
    8			Ruby			94
    ------------------------------------------------------------------------
    Sorted Combined Table :
    Roll_no			Name   			Marks
    2			Bose			65
    4			Devi			71
    3			Hari			72
    6			Raji			77
    9			Selvi			80
    10			Uma			82
    7			Santosh			83
    1			Anand			85
    8			Ruby			94
    5			Khanna			100
    


```python
from collections import deque
 
def BFS(a, b, c):
    m = {}
    Solvable = False
    path = []
     
    q = deque()
     
    # Initialing with initial state
    q.append((0, 0))
 
    while (len(q) > 0):
         
        # Current state
        u = q.popleft()
 
        if ((u[0], u[1]) in m):
            continue
 
        if ((u[0] > a or u[1] > b or
             u[0] < 0 or u[1] < 0)):
            continue
 
        path.append([u[0], u[1]])
 
        # Marking current state as visited
        m[(u[0], u[1])] = 1
 
        if (u[0] == target or u[1] == c):
            isSolvable = True
             
            if (u[0] == target):
                if (u[1] != 0):
                     
            
                    path.append([u[0], 0])
            else:
                if (u[0] != 0):
 
                    path.append([0, u[1]])
 
            sz = len(path)
            for i in range(sz):
                print("(", path[i][0], ",",
                           path[i][1], ")")
            break
            
        q.append([u[0], b]) # Filling Jug2
        q.append([a, u[1]]) # Filling Jug1
 
        for ap in range(max(a, b) + 1):
 
            c = u[0] + ap
            d = u[1] - ap
 
            # Check if this state is possible or not
            if (c == a or (d == 0 and d >= 0)):
                q.append([c, d])
 
            # Pour amount ap from Jug 1 to Jug2
            c = u[0] - ap
            d = u[1] + ap
 
            if ((c == 0 and c >= 0) or d == b):
                q.append([c,d])
         
        # Empty Jug2
        q.append([a, 0])
         
        # Empty Jug1
        q.append([0, b])

    if (not Solvable):
        
        print ("water is transferred")
 
# Driver code
if __name__ == '__main__':
    print("-------------------SHEEMA ZAINAB MI 19MID0014-----------------")
    Jug1=int(input("enter quantity in jug 1:"))
    Jug2=int(input("enter quantity in jug 2:"))
    target=int(input("enter how much water you want in Jug 1:"))
    
    print("Path from initial state "
          "to solution state ::")
    print("jug1 , jug2")
     
    BFS(Jug1, Jug2, c)
```

    -------------------SHEEMA ZAINAB MI 19MID0014-----------------
    enter quantity in jug 1:3
    enter quantity in jug 2:4
    enter how much water you want in Jug 1:2
    Path from initial state to solution state ::
    jug1 , jug2
    ( 0 , 0 )
    ( 0 , 4 )
    ( 3 , 0 )
    ( 3 , 4 )
    ( 3 , 1 )
    ( 0 , 3 )
    ( 3 , 3 )
    ( 2 , 4 )
    ( 2 , 0 )
    ( 0 , 2 )
    water is transferred
    


```python

```
