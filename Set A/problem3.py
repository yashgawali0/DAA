#3rd problem
def findNum(n):
    num=1
    cnt=0
    while True:
        temp=num
        while temp%5==0:
            cnt+=1
            temp//=5
        
        if cnt>=n:
            return num
        num+=1
        
n=4
print(findNum(n))