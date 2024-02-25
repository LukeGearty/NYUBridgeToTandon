#list_one = [0, 6, 14, 19, 22, -1, 9, 14, 22, -3]
#list_one = [1, 4, 5, 6, 7, 8, 19, 22, 33, -1, -8, 22, 94, -978, 44, 93]
#list_one = [1, 2, 3, 4, 5]

#list_one = [-1,-2, -3, -4, -5, 10, 11, 12, 13, 14]
#list_one = [1,2,3,4,5, 7, 25, 8, -12, -16, - 1, -2, -3, -4, -5, -6, -7]
list_one = [1, 3, 4, -4, -1, -3]
n = len(list_one)
p = 0

i = 0
j = n-1

i_count = 0
j_count = 0
swap_count = 0
num_of_times_done = 0
while (i < j):
    while (i < j and list_one[i] < p):
        i += 1
        i_count += 1
    while (i < j and list_one[j] >= p):
        j -= 1 
        j_count+= 1
    
    if (i < j):
        temp = list_one[i]
        list_one[i] = list_one[j]
        list_one[j] = temp
        swap_count += 1
    num_of_times_done += 1

print(swap_count)
print(i_count, j_count)
print(list_one)
print(num_of_times_done)
     
    
