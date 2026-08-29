# DSA 100 - Easy | Python solutions
from collections import Counter, deque

def q01_pair_with_target_sum(a,target):
    seen={}
    for i,x in enumerate(a):
        if target-x in seen:return [seen[target-x],i]
        seen[x]=i

def q02_remove_duplicates(a):
    k=0
    for x in a:
        if k==0 or x!=a[k-1]:a[k]=x;k+=1
    return k

def q03_move_zeroes(a):
    k=0
    for x in a:
        if x:a[k]=x;k+=1
    while k<len(a):a[k]=0;k+=1

def q04_max_profit(prices):
    mn=float('inf');ans=0
    for x in prices:mn=min(mn,x);ans=max(ans,x-mn)
    return ans

def q05_missing_number(a):
    x=len(a)
    for i,v in enumerate(a):x^=i^v
    return x

def q06_majority_element(a):
    cand=None;c=0
    for x in a:
        if c==0:cand=x
        c+=1 if x==cand else -1
    return cand

def q07_valid_anagram(s,t):return Counter(s)==Counter(t)
def q08_first_unique(s):
    c=Counter(s)
    return next((i for i,x in enumerate(s) if c[x]==1),-1)
def q09_reverse_words(s):return ' '.join(reversed(s.split()))
def q10_palindrome(s):
    t=''.join(c.lower() for c in s if c.isalnum());return t==t[::-1]
def q11_two_sum_sorted(a,target):
    i,j=0,len(a)-1
    while i<j:
        s=a[i]+a[j]
        if s==target:return [i,j]
        if s<target:i+=1
        else:j-=1
    return []
def q12_merge_sorted_arrays(a,b):
    i=j=0;r=[]
    while i<len(a) or j<len(b):
        if j==len(b) or (i<len(a) and a[i]<=b[j]):r.append(a[i]);i+=1
        else:r.append(b[j]);j+=1
    return r
def q13_binary_search(a,target):
    l,r=0,len(a)-1
    while l<=r:
        m=(l+r)//2
        if a[m]==target:return m
        if a[m]<target:l=m+1
        else:r=m-1
    return -1
def q14_search_insert(a,target):
    l,r=0,len(a)
    while l<r:
        m=(l+r)//2
        if a[m]<target:l=m+1
        else:r=m
    return l
def q15_sorted_squares(a):
    r=[0]*len(a);l,j,k=0,len(a)-1,len(a)-1
    while l<=j:
        x,y=a[l]*a[l],a[j]*a[j]
        if x>y:r[k]=x;l+=1
        else:r[k]=y;j-=1
        k-=1
    return r
class Q16ListNode:
    def __init__(self,val,next=None):self.val,self.next=val,next

def q16_reverse_list(h):
    p=None
    while h:n=h.next;h.next=p;p=h;h=n
    return p
def q17_middle_node(h):
    s=f=h
    while f and f.next:s=s.next;f=f.next.next
    return s
def q18_has_cycle(h):
    s=f=h
    while f and f.next:
        s=s.next;f=f.next.next
        if s is f:return True
    return False
def q19_merge_two_lists(a,b):
    d=Q16ListNode(0);t=d
    while a and b:
        if a.val<=b.val:t.next=a;a=a.next
        else:t.next=b;b=b.next
        t=t.next
    t.next=a or b;return d.next
def q20_valid_parentheses(s):
    st=[];mp={')':'(',']':'[','}':'{'}
    for c in s:
        if c in '([{':st.append(c)
        elif not st or st.pop()!=mp[c]:return False
    return not st
class Q21Stack:
    def __init__(self):self.q=deque()
    def push(self,x):self.q.append(x);self.q.rotate(1)
    def pop(self):return self.q.popleft()
    def top(self):return self.q[0]
    def empty(self):return not self.q
class Q22Queue:
    def __init__(self):self.i=[];self.o=[]
    def push(self,x):self.i.append(x)
    def _shift(self):
        if not self.o:self.o=self.i[::-1];self.i=[]
    def pop(self):self._shift();return self.o.pop()
    def peek(self):self._shift();return self.o[-1]
    def empty(self):return not self.i and not self.o
class Q23TreeNode:
    def __init__(self,val,left=None,right=None):self.val,self.left,self.right=val,left,right
def q23_max_depth(r):return 0 if not r else 1+max(q23_max_depth(r.left),q23_max_depth(r.right))
def q24_inorder(r):
    st=[];ans=[]
    while r or st:
        while r:st.append(r);r=r.left
        r=st.pop();ans.append(r.val);r=r.right
    return ans
def q25_level_order(r):
    if not r:return []
    q=deque([r]);ans=[]
    while q:
        level=[]
        for _ in range(len(q)):
            x=q.popleft();level.append(x.val)
            if x.left:q.append(x.left)
            if x.right:q.append(x.right)
        ans.append(level)
    return ans
def q26_search_bst(r,target):
    while r and r.val!=target:r=r.left if target<r.val else r.right
    return r
def q27_count_set_bits(x):
    c=0
    while x:x&=x-1;c+=1
    return c
def q28_power_of_two(n):return n>0 and n&(n-1)==0
def q29_gcd(a,b):
    while b:a,b=b,a%b
    return abs(a)
def q30_fibonacci(n):
    a,b=0,1
    for _ in range(n):a,b=b,a+b
    return a
