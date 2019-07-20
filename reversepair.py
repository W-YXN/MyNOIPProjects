def InversionNum(lst):
    if len(lst) == 1:
        return lst,0
    else:
        n = len(lst) // 2
        lst1,count1 = InversionNum(lst[0:n])
        lst2,count2 = InversionNum(lst[n:len(lst)])
        lst,count = Count(lst1,lst2,0)
        return lst,count1+count2+count
 
def Count(lst1,lst2,count): 
    i = 0
    j = 0
    res = []
    while i < len(lst1) and j < len(lst2):
        if lst1[i] <= lst2[j]:
            res.append(lst1[i])
            i += 1
        else:
            res.append(lst2[j])
            count += len(lst1)-i 
            j += 1
    res += lst1[i:]
    res += lst2[j:]
    return res,count
 
n = input()
n = int(n)
list1 = []
list1 = input().split()
list2 = []
i = 0
while i < n:
    m = int(list1[i])
    list2.append(m)
    i += 1 

anslst,ansnum = InversionNum(list2)

print ansnum