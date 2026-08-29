# DSA 100 - Hard | Python solutions
from collections import Counter,defaultdict,deque
import heapq

def q71_trapping_rain_water(h):
 l,r=0,len(h)-1;lm=rm=ans=0
 while l<=r:
  if h[l]<=h[r]:lm=max(lm,h[l]);ans+=lm-h[l];l+=1
  else:rm=max(rm,h[r]);ans+=rm-h[r];r-=1
 return ans
def q72_first_missing_positive(a):
 n=len(a)
 for i,x in enumerate(a):a[i]=x if 1<=x<=n else n+1
 for x in a:
  v=abs(x)
  if v<=n and a[v-1]>0:a[v-1]=-a[v-1]
 return next((i+1 for i,x in enumerate(a) if x>0),n+1)
def q73_median_two_sorted(a,b):
 if len(a)>len(b):a,b=b,a
 m,n=len(a),len(b);lo,hi=0,m
 while lo<=hi:
  i=(lo+hi)//2;j=(m+n+1)//2-i
  al=a[i-1] if i else float('-inf');ar=a[i] if i<m else float('inf')
  bl=b[j-1] if j else float('-inf');br=b[j] if j<n else float('inf')
  if al<=br and bl<=ar:return max(al,bl) if (m+n)%2 else (max(al,bl)+min(ar,br))/2
  if al>br:hi=i-1
  else:lo=i+1
def q74_largest_rectangle(h):
 st=[];ans=0
 for i,x in enumerate(h+[0]):
  while st and h[st[-1]]>x:
   j=st.pop();left=st[-1] if st else -1;ans=max(ans,h[j]*(i-left-1))
  st.append(i)
 return ans
def q75_max_product(a):
 mx=mn=ans=a[0]
 for x in a[1:]:
  if x<0:mx,mn=mn,mx
  mx=max(x,mx*x);mn=min(x,mn*x);ans=max(ans,mx)
 return ans
def q76_count_inversions(a):
 def merge(a):
  if len(a)<2:return a,0
  m=len(a)//2;l,x=merge(a[:m]);r,y=merge(a[m:]);i=j=inv=0;res=[]
  while i<len(l) and j<len(r):
   if l[i]<=r[j]:res.append(l[i]);i+=1
   else:res.append(r[j]);j+=1;inv+=len(l)-i
  return res+l[i:]+r[j:],x+y+inv
 _,ans=merge(a);return ans
def q77_min_window(s,t):
 need=Counter(t);have=Counter();missing=len(t);l=st=0;best=float('inf')
 for r,c in enumerate(s):
  have[c]+=1
  if have[c]<=need[c]:missing-=1
  while missing==0:
   if r-l+1<best:best=r-l+1;st=l
   have[s[l]]-=1
   if have[s[l]]<need[s[l]]:missing+=1
   l+=1
 return '' if best==float('inf') else s[st:st+best]
def q78_word_break(s,words):
 d=set(words);p={0:None}
 for i in range(len(s)+1):
  if i not in p:continue
  for j in range(i+1,len(s)+1):
   if s[i:j] in d:p[j]=(i,s[i:j])
 if len(s) not in p:return []
 out=[];i=len(s)
 while i: i0,w=p[i];out.append(w);i=i0
 return out[::-1]
def q79_regex_match(s,p):
 from functools import lru_cache
 @lru_cache(None)
 def f(i,j):
  if j==len(p):return i==len(s)
  first=i<len(s) and (p[j]==s[i] or p[j]=='.')
  if j+1<len(p) and p[j+1]=='*':return f(i,j+2) or (first and f(i+1,j))
  return first and f(i+1,j+1)
 return f(0,0)
def q80_edit_distance(a,b):
 dp=list(range(len(b)+1))
 for i,x in enumerate(a,1):
  nd=[i]+[0]*len(b)
  for j,y in enumerate(b,1):nd[j]=min(dp[j]+1,nd[j-1]+1,dp[j-1]+(x!=y))
  dp=nd
 return dp[-1]
def q81_longest_pal_subseq(s):
 n=len(s);dp=[0]*n
 for i in range(n-1,-1,-1):
  prev=0;dp[i]=1
  for j in range(i+1,n):
   old=dp[j];dp[j]=prev+2 if s[i]==s[j] else max(dp[j],dp[j-1]);prev=old
 return dp[-1] if s else 0
class Node:
 def __init__(self,val,next=None):self.val=val;self.next=next
def q82_merge_k_lists(lists):
 h=[];uid=0
 for x in lists:
  if x:heapq.heappush(h,(x.val,uid,x));uid+=1
 d=Node(0);t=d
 while h:
  _,_,x=heapq.heappop(h);t.next=x;t=x
  if x.next:heapq.heappush(h,(x.next.val,uid,x.next));uid+=1
 return d.next
def q83_reverse_k_group(h,k):
 d=Node(0,h);g=d
 while True:
  p=g
  for _ in range(k):p=p.next if p else None
  if not p:break
  cur=g.next;prev=p.next
  for _ in range(k):n=cur.next;cur.next=prev;prev=cur;cur=n
  old=g.next;g.next=prev;g=old
 return d.next
class q84_LRUCache:
 def __init__(self,capacity):self.c=capacity;self.d={};self.order=[]
 def get(self,key):
  if key not in self.d:return -1
  self.order.remove(key);self.order.append(key);return self.d[key]
 def put(self,key,value):
  if key in self.d:self.order.remove(key)
  self.d[key]=value;self.order.append(key)
  if len(self.d)>self.c:x=self.order.pop(0);del self.d[x]
class q85_MedianFinder:
 def __init__(self):self.lo=[];self.hi=[]
 def addNum(self,x):
  heapq.heappush(self.lo,-x);heapq.heappush(self.hi,-heapq.heappop(self.lo))
  if len(self.hi)>len(self.lo):heapq.heappush(self.lo,-heapq.heappop(self.hi))
 def findMedian(self):
  return -self.lo[0] if len(self.lo)>len(self.hi) else (-self.lo[0]+self.hi[0])/2
class TNode:
 def __init__(self,val,left=None,right=None):self.val=val;self.left=left;self.right=right
def q86_serialize(r):
 out=[]
 def f(x):
  if not x:out.append('#');return
  out.append(str(x.val));f(x.left);f(x.right)
 f(r);return ','.join(out)
def q86_deserialize(s):
 it=iter(s.split(','))
 def f():
  x=next(it)
  if x=='#':return None
  r=TNode(int(x));r.left=f();r.right=f();return r
 return f()
def q87_max_path_sum(r):
 ans=[float('-inf')]
 def f(x):
  if not x:return 0
  a=max(0,f(x.left));b=max(0,f(x.right));ans[0]=max(ans[0],x.val+a+b);return x.val+max(a,b)
 f(r);return ans[0]
def q88_recover_bst(r):
 st=[];prev=first=second=None;x=r
 while st or x:
  while x:st.append(x);x=x.left
  x=st.pop()
  if prev and prev.val>x.val:
   if first is None:first=prev
   second=x
  prev=x;x=x.right
 first.val,second.val=second.val,first.val
class q89_Trie:
 def __init__(self):self.root={}
 def insert(self,w):
  p=self.root
  for c in w:p=p.setdefault(c,{})
  p['#']=True
 def search(self,w):
  p=self.root
  for c in w:
   if c not in p:return False
   p=p[c]
  return '#' in p
 def startsWith(self,w):
  p=self.root
  for c in w:
   if c not in p:return False
   p=p[c]
  return True
def q90_word_search_ii(board,words):
 root={}
 for w in words:
  p=root
  for c in w:p=p.setdefault(c,{})
  p['#']=w
 out=set();n=len(board);m=len(board[0])
 def dfs(i,j,p):
  c=board[i][j]
  if c=='#' or c not in p:return
  q=p[c]
  if '#' in q:out.add(q['#'])
  board[i][j]='#'
  for di,dj in ((1,0),(-1,0),(0,1),(0,-1)):
   x,y=i+di,j+dj
   if 0<=x<n and 0<=y<m:dfs(x,y,q)
  board[i][j]=c
 for i in range(n):
  for j in range(m):dfs(i,j,root)
 return list(out)
def q91_dijkstra(n,edges,src):
 g=[[] for _ in range(n)]
 for u,v,w in edges:g[u].append((v,w))
 d=[float('inf')]*n;d[src]=0;h=[(0,src)]
 while h:
  du,u=heapq.heappop(h)
  if du!=d[u]:continue
  for v,w in g[u]:
   if du+w<d[v]:d[v]=du+w;heapq.heappush(h,(d[v],v))
 return d
def q92_network_delay(n,times,k):
 d=q91_dijkstra(n,[(u-1,v-1,w) for u,v,w in times],k-1);x=max(d);return -1 if x==float('inf') else x
def q93_mst(n,edges):
 p=list(range(n));
 def f(x):
  while p[x]!=x:p[x]=p[p[x]];x=p[x]
  return x
 ans=0
 for u,v,w in sorted(edges,key=lambda e:e[2]):
  a,b=f(u),f(v)
  if a!=b:p[a]=b;ans+=w
 return ans
def q94_critical_connections(n,edges):
 g=[[] for _ in range(n)];
 for i,(u,v) in enumerate(edges):g[u].append((v,i));g[v].append((u,i))
 tin=[-1]*n;low=[0]*n;ans=[];time=0
 def dfs(u,pe):
  nonlocal time;tin[u]=low[u]=time;time+=1
  for v,eid in g[u]:
   if eid==pe:continue
   if tin[v]>=0:low[u]=min(low[u],tin[v])
   else:
    dfs(v,eid);low[u]=min(low[u],low[v])
    if low[v]>tin[u]:ans.append([u,v])
 dfs(0,-1);return ans
def q95_scc(n,edges):
 g=[[] for _ in range(n)];rg=[[] for _ in range(n)]
 for u,v in edges:g[u].append(v);rg[v].append(u)
 vis=[0]*n;order=[]
 def f(u):
  vis[u]=1
  for v in g[u]:
   if not vis[v]:f(v)
  order.append(u)
 for i in range(n):
  if not vis[i]:f(i)
 comp=[-1]*n;cid=0
 def r(u):
  comp[u]=cid
  for v in rg[u]:
   if comp[v]<0:r(v)
 for u in reversed(order):
  if comp[u]<0:r(u);cid+=1
 return comp
def q96_alien_dictionary(words):
 chars=set(''.join(words));g={c:set() for c in chars};d={c:0 for c in chars}
 for a,b in zip(words,words[1:]):
  k=0
  while k<len(a) and k<len(b) and a[k]==b[k]:k+=1
  if k==len(b)<len(a):return ''
  if k<len(a) and k<len(b) and b[k] not in g[a[k]]:g[a[k]].add(b[k]);d[b[k]]+=1
 q=deque(c for c in chars if d[c]==0);out=''
 while q:
  c=q.popleft();out+=c
  for v in g[c]:d[v]-=1;q.append(v) if d[v]==0 else None
 return out if len(out)==len(chars) else ''
def q97_partition_equal(a):
 s=sum(a)
 if s%2:return False
 t=s//2;dp={0}
 for x in a:dp|={v+x for v in list(dp) if v+x<=t}
 return t in dp
def q98_palindrome_partition_min_cuts(s):
 n=len(s);pal=[[False]*n for _ in range(n)];cut=list(range(n))
 for r in range(n):
  for l in range(r+1):
   if s[l]==s[r] and (r-l<2 or pal[l+1][r-1]):
    pal[l][r]=True;cut[r]=0 if l==0 else min(cut[r],cut[l-1]+1)
 return cut[-1] if n else 0
def q99_n_queens(n):
 ans=[]
 def dfs(r,cols,d1,d2):
  if r==n:ans.append(1);return
  for c in range(n):
   if c not in cols and r+c not in d1 and r-c not in d2:dfs(r+1,cols|{c},d1|{r+c},d2|{r-c})
 dfs(0,set(),set(),set());return len(ans)
def q100_burst_balloons(a):
 a=[1]+a+[1];n=len(a);dp=[[0]*n for _ in range(n)]
 for length in range(2,n):
  for l in range(n-length):
   r=l+length
   dp[l][r]=max((dp[l][k]+a[l]*a[k]*a[r]+dp[k][r] for k in range(l+1,r)),default=0)
 return dp[0][-1]
