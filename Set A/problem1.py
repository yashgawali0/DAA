#1st problem
class GFG:
    def firstzeroindex(arr,n):
        i=0
        while (i<n):
            if(arr[i]==0):
                return i
            i+=1
        return -1
    def main(args):
        arr=[1,1,1,1,1,0,0,0,0,0,0]
        n=len(arr)
        x=GFG.firstzeroindex(arr,n)
        if(x==-1):
            print("Count of zero is 0.")
        else:
            print("Count of zero is: ",end=' ')
            print(n-x)
            
if _name=="main_":
    GFG.main([])