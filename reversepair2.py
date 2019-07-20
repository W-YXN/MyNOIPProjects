def InversePairs(data):
        count = 0
        copy = []
        for i in data:
            copy.append(i)
        copy.sort()
        for i in range(len(copy)):
            count += data.index(copy[i])
            data.remove(copy[i])
        return count

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
ans = int(InversePairs(list2))
print(ans)