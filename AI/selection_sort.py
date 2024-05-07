def selection_sort(a):
    for i in range(len(a)-1):
        min_index = i
        for j in range(i+1, len(a)):
            if a[min_index] > a[j]:
                min_index = j
        a[i], a[min_index] = a[min_index], a[i]

a = []

n = int(input("Enter the number of elements: "))
print("Enter the elements: ")
for k in range(n):
    element = int(input())
    a.append(element)

print("Unsorted Array:", a)

selection_sort(a)

print("Sorted Array:", a)
