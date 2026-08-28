# DSA 100 - Medium | Python solutions
from collections import Counter,deque,defaultdict
import heapq

def q31_longest_consecutive(a):
 s=set(a);best=0
 for x in s:
  if x-1 not in s:
   y=x
   while y in s:y+=1
   best=max(best,y-x)
 return best
def q32_product_except_self(a):
 r=[1]*len(a);p=1
 for i,x in enumerate(a):r[i]=p;p*=x
 p=1
 for i in range(len(a)-1,-1,-1):r[i]*=p;p*=a[i]
 return r
def q33_subarray_sum(a,k):
 d={0:1};s=ans=0
 for x in a:s+=x;ans+=d.get(s-k,0);d[s]=d.get(s,0)+1
 return ans
def q34_top_k_frequent(a,k):return [x for x,_ in Counter(a).most_common(k)]
def q35_rotate_array(a,k):
 if a:k%=len(a);a[:]=a[-k:]+a[:-k]
def q36_spiral_matrix(a):
 if not a:return []
 t,b,l,r=0,len(a)-1,0,len(a[0])-1;out=[]
 while t<=b and l<=r:
  out+=a[t][l:r+1];t+=1
  for i in range(t,b+1):out.append(a[i][r])
  r-=1
  if t<=b:out+=a[b][l:r+1][::-1];b-=1
  if l<=r:
   for i in range(b,t-1,-1):out.append(a[i][l])
   l+=1
 return out
def q37_merge_intervals(a):
 a.sort();r=[]
 for x,y in a:
  if not r or r[-1][1]<x:r.append([x,y])
  else:r[-1][1]=max(r[-1][1],y)
 return r
def q38_insert_interval(a,n):return q37_merge_intervals(a+[n])
def q39_longest_unique(s):
 d={};l=ans=0
 for i,c in enumerate(s):l=max(l,d.get(c,-1)+1);d[c]=i;ans=max(ans,i-l+1)
 return ans
def q40_character_replacement(s,k):
 c=Counter();l=mx=ans=0
 for r,x in enumerate(s):c[x]+=1;mx=max(mx,c[x])
 # re-run clean window
 c=Counter();l=mx=ans=0
 for r,x in enumerate(s):
  c[x]+=1;mx=max(mx,c[x])
  while r-l+1-mx>k:c[s[l]]-=1;l+=1
  ans=max(ans,r-l+1)
 return ans
def q41_permutation_in_string(p,s):
 if len(p)>len(s):return False
 need=Counter(p);win=Counter(s[:len(p)])
 if need==win:return True
 for i in range(len(p),len(s)):
  win[s[i]]+=1;win[s[i-len(p)]]-=1
  if win[s[i-len(p)]]==0:del win[s[i-len(p)]]
  if win==need:return True
 return False
def q42_min_window(s,t):
 need=Counter(t);have=Counter();need_count=len(t);l=st=0;best=float('inf')
 for r,c in enumerate(s):
  have[c]+=1
  if have[c]<=need[c]:need_count-=1
  while need_count==0:
   if r-l+1<best:best=r-l+1;st=l
   have[s[l]]-=1
   if have[s[l]]<need[s[l]]:need_count+=1
   l+=1
 return '' if best==float('inf') else s[st:st+best]
def q43_group_shifted(a):
 d=defaultdict(list)
 for s in a:
  k=tuple((ord(s[i])-ord(s[i-1]))%26 for i in range(1,len(s)))
  d[k].append(s)
 return list(d.values())
def q44_three_sum(a):
 a.sort();r=[]
 for i in range(len(a)-2):
  if i and a[i]==a[i-1]:continue
  l,j=i+1,len(a)-1
  while l<j:
   x=a[i]+a[l]+a[j]
   if x==0:
    r.append([a[i],a[l],a[j]]);lv,rv=a[l],a[j]
    while l<j and a[l]==lv:l+=1
    while l<j and a[j]==rv:j-=1
   elif x<0:l+=1
   else:j-=1
 return r
def q45_max_area(a):
 l,j=0,len(a)-1;ans=0
 while l<j:
  ans=max(ans,min(a[l],a[j])*(j-l))
  if a[l]<a[j]:l+=1
  else:j-=1
 return ans
def q46_sort_colors(a):
 l=m=0;r=len(a)-1
 while m<=r:
  if a[m]==0:a[l],a[m]=a[m],a[l];l+=1;m+=1
  elif a[m]==1:m+=1
  else:a[m],a[r]=a[r],a[m];r-=1
def q47_kth_largest(a,k):return heapq.nlargest(k,a)[-1]
class Node:
 def __init__(self,val,next=None):self.val=val;self.next=next
def q48_remove_nth(h,n):
 d=Node(0,h);f=s=d
 for _ in range(n):f=f.next
 while f.next:f=f.next;s=s.next
 s.next=s.next.next;return d.next
def q49_add_two_numbers(a,b):
 d=Node(0);t=d;c=0
 while a or b or c:
  x=(a.val if a else 0)+(b.val if b else 0)+c;c,x=divmod(x,10);t.next=Node(x);t=t.next;a=a.next if a else None;b=b.next if b else None
 return d.next
def q50_reorder_list(h):
 if not h:return
 s=f=h
 while f.next and f.next.next:s=s.next;f=f.next.next
 b=s.next;s.next=None;p=None
 while b:n=b.next;b.next=p;p=b;b=n
 a=h;b=p
 while b:an=a.next;bn=b.next;a.next=b;b.next=an;a=an;b=bn
 return h
def q51_intersection(a,b):
 x,y=a,b
 while x is not y:x=x.next if x else b;y=y.next if y else a
 return x
class RNode:
 def __init__(self,val):self.val=val;self.next=None;self.random=None
def q52_copy_random(h):
 mp={};p=h
 while p:mp[p]=RNode(p.val);p=p.next
 p=h
 while p:mp[p].next=mp.get(p.next);mp[p].random=mp.get(p.random);p=p.next
 return mp.get(h)
def q53_daily_temperatures(a):
 r=[0]*len(a);st=[]
 for i,x in enumerate(a):
  while st and x>a[st[-1]]:j=st.pop();r[j]=i-j
  st.append(i)
 return r
def q54_eval_rpn(t):
 st=[]
 for x in t:
  if x in '+-*/':
   b=st.pop();a=st.pop();st.append({'+' :a+b,'-':a-b,'*':a*b,'/':int(a/b)}[x])
  else:st.append(int(x))
 return st[-1]
class Q55MinStack:
 def __init__(self):self.s=[]
 def push(self,x):self.s.append((x,min(x,self.s[-1][1] if self.s else x)))
 def pop(self):self.s.pop()
 def top(self):return self.s[-1][0]
 def getMin(self):return self.s[-1][1]
def q56_sliding_maximum(a,k):
 q=deque();r=[]
 for i,x in enumerate(a):
  while q and q[0]<=i-k:q.popleft()
  while q and a[q[-1]]<=x:q.pop()
  q.append(i)
  if i>=k-1:r.append(a[q[0]])
 return r
def q57_k_closest(p,k):return heapq.nsmallest(k,p,key=lambda x:x[0]*x[0]+x[1]*x[1])
def q58_task_scheduler(t,n):
 c=Counter(t);mx=max(c.values());cnt=sum(v==mx for v in c.values());return max(len(t),(mx-1)*(n+1)+cnt)
def q59_validate_bst(r):
 def f(x,l,r):return not x or l<x.val<r and f(x.left,l,x.val) and f(x.right,x.val,r)
 return f(r,float('-inf'),float('inf'))
def q60_lca_bst(r,p,q):
 while r:
  if p.val<r.val and q.val<r.val:r=r.left
  elif p.val>r.val and q.val>r.val:r=r.right
  else:return r
def q61_right_view(r):
 if not r:return []
 q=deque([r]);ans=[]
 while q:
  ans.append(q[-1].val)
  for _ in range(len(q)):
   x=q.popleft()
   if x.left:q.append(x.left)
   if x.right:q.append(x.right)
 return ans
def q62_build_tree(pre,ino):
 pos={v:i for i,v in enumerate(ino)};i=0
 def f(l,r):
  nonlocal i
  if l>r:return None
  x=Q23TreeNode(pre[i]);i+=1;m=pos[x.val];x.left=f(l,m-1);x.right=f(m+1,r);return x
 return f(0,len(ino)-1)
class Q23TreeNode:
 def __init__(self,val,left=None,right=None):self.val=val;self.left=left;self.right=right
def q63_diameter(r):
 ans=0
 def f(x):
  nonlocal ans
  if not x:return 0
  a,b=f(x.left),f(x.right);ans=max(ans,a+b);return 1+max(a,b)
 f(r);return ans
def q64_kth_smallest(r,k):
 st=[]
 while True:
  while r:st.append(r);r=r.left
  r=st.pop();k-=1
  if k==0:return r.val
  r=r.right
def q65_num_islands(g):
 n=len(g);m=len(g[0]) if n else 0;ans=0
 for i in range(n):
  for j in range(m):
   if g[i][j]=='1':
    ans+=1;q=deque([(i,j)]);g[i][j]='0'
    while q:
     x,y=q.popleft()
     for dx,dy in ((1,0),(-1,0),(0,1),(0,-1)):
      a,b=x+dx,y+dy
      if 0<=a<n and 0<=b<m and g[a][b]=='1':g[a][b]='0';q.append((a,b))
 return ans
class GNode:
 def __init__(self,val):self.val=val;self.neighbors=[]
def q66_clone_graph(node):
 if not node:return None
 mp={node:GNode(node.val)};q=deque([node])
 while q:
  x=q.popleft()
  for y in x.neighbors:
   if y not in mp:mp[y]=GNode(y.val);q.append(y)
   mp[x].neighbors.append(mp[y])
 return mp[node]
def q67_course_schedule(n,pre):
 g=[[] for _ in range(n)];d=[0]*n
 for a,b in pre:g[b].append(a);d[a]+=1
 q=deque(i for i in range(n) if d[i]==0);c=0
 while q:
  u=q.popleft();c+=1
  for v in g[u]:d[v]-=1;q.append(v) if d[v]==0 else None
 return c==n
def q68_shortest_path(n,e,s,t):
 g=[[] for _ in range(n)]
 for a,b in e:g[a].append(b);g[b].append(a)
 d=[-1]*n;d[s]=0;q=deque([s])
 while q:
  u=q.popleft()
  for v in g[u]:
   if d[v]<0:d[v]=d[u]+1;q.append(v)
 return d[t]
def q69_rotting_oranges(g):
 q=deque();fresh=0
 for i,row in enumerate(g):
  for j,x in enumerate(row):
   if x==2:q.append((i,j))
   elif x==1:fresh+=1
 t=0
 while q and fresh:
  for _ in range(len(q)):
   x,y=q.popleft()
   for dx,dy in ((1,0),(-1,0),(0,1),(0,-1)):
    a,b=x+dx,y+dy
    if 0<=a<len(g) and 0<=b<len(g[0]) and g[a][b]==1:g[a][b]=2;fresh-=1;q.append((a,b))
  t+=1
 return -1 if fresh else t
def q70_pacific_atlantic(h):
 n=len(h);m=len(h[0]) if n else 0
 def dfs(x,y,v):
  if (x,y) in v:return
  v.add((x,y))
  for dx,dy in ((1,0),(-1,0),(0,1),(0,-1)):
   a,b=x+dx,y+dy
   if 0<=a<n and 0<=b<m and h[a][b]>=h[x][y]:dfs(a,b,v)
 A=set();B=set()
 for i in range(n):dfs(i,0,A);dfs(i,m-1,B)
 for j in range(m):dfs(0,j,A);dfs(n-1,j,B)
 return [list(x) for x in sorted(A&B)]
