dict = {}
temp = head
while temp:
if temp in dict:
return True
else:
dict[temp] = temp
temp = temp.next
return False