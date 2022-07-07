w,h,x,y=map(int,input().split())
area = w*h
ans1 = area/2
ans2 = 0
if (x==w/2 and y==h/2):
	ans2 = 1
else:
	ans2 = 0

print(ans1,ans2)