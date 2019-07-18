

'''三数(最左，最右，中间)取中值，将中值与最左值交换位置，返回中值'''
def midian(t, left, right):
    mid=int((left + right)/ 2)
    l, r, m=t[left], t[right], t[mid]
    pivot=m
    if (((m <= l) & (l <= r)) | ((r <= l) & (l <= m))):  #中值为最左值
        pivot=l
    if  ((m >= l & m <= r) | (m <=l & m >=r)):  # 中值为中间值
        pivot = m
        t[mid], t[left]=t[left], t[mid]  # 将中值放在最左边
    if (((m >= r) & (r >= l)) | ((r <= l) & (r >= m))): # 中值为最右值
        pivot = r
        t[right], t[left]=t[left], t[right]  # 同理，将中值放在最左边
    return pivot

def quicksort(t, left, right):
    if left + 2 <= right:  # 列表元素个数大于3个，采用基准元采取三数取中值法
        i, j=left + 1, right
        pivot=midian(t, left, right)
        for k in range (right-left):
            while(t[i] < pivot):  # 左边扫描，因为基准元是中值，所以不会越界(越界指：i > right)
                i=i + 1
            while(t[j] > pivot): # 右边扫描，同理，j也不会出现j < left
                j=j - 1
            if(i < j):
                t[i], t[j]=t[j], t[i]
            else:
                break
        t[j], t[left]=t[left], t[j] #将基准元放回正确的位置，使得在基准元左边的数比基准元小(或等于)，基准元右边的数比基准元大(或等于)

        # 递归调用，对序列在基准元的左边(比基准元小)和基准元的右边(比基准元大)的部分再递归调用快速排序
        if left <= (right - 1):
            quicksort(t, left, j - 1)
        if (j + 1) <= right:
            quicksort(t, j + 1, right)
    elif (right - left)== 1:  # 列表元素为2个，直接比较
        if (t[left] > t[right]):
            t[left], t[right]=t[right], t[left]
        else:
            return
    else:  # 列表元素只有1个直接返回
        return

def quicksort1(t):
    quicksort(t, 0, len(t)-1)

t=[1, 5, 6, 8, 3, 2, 9, 7, 4, 1]
print("未排序时的序列为：",t)
quicksort1(t)
print("排序后的序列为：",t)


