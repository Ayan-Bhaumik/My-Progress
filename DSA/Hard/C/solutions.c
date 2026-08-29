/* DSA 100 - Hard | C solutions. Signatures are contest-style; malloc'd returns should be freed by caller. */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
typedef struct ListNode{int val;struct ListNode*next;}ListNode;typedef struct TreeNode{int val;struct TreeNode*left,*right;}TreeNode;
int q71_trap(int*h,int n){int l=0,r=n-1,lm=0,rm=0,a=0;while(l<=r){if(h[l]<=h[r]){lm=lm>h[l]?lm:h[l];a+=lm-h[l++];}else{rm=rm>h[r]?rm:h[r];a+=rm-h[r--];}}return a;}
int q72_first_missing_positive(int*a,int n){for(int i=0;i<n;i++)if(a[i]<1||a[i]>n)a[i]=n+1;for(int i=0;i<n;i++){int v=abs(a[i]);if(v<=n&&a[v-1]>0)a[v-1]=-a[v-1];}for(int i=0;i<n;i++)if(a[i]>0)return i+1;return n+1;}
double q73_median_two_sorted(int*A,int m,int*B,int n){if(m>n)return q73_median_two_sorted(B,n,A,m);int lo=0,hi=m,total=m+n;while(lo<=hi){int i=(lo+hi)/2,j=(total+1)/2-i;int al=i?A[i-1]:INT_MIN,ar=i<m?A[i]:INT_MAX,bl=j?B[j-1]:INT_MIN,br=j<n?B[j]:INT_MAX;if(al<=br&&bl<=ar)return total%2?(al>bl?al:bl):((double)(al>bl?al:bl)+(ar<br?ar:br))/2;if(al>br)hi=i-1;else lo=i+1;}return 0;}
int q74_largest_rectangle(int*h,int n){int*st=malloc((n+1)*sizeof(int));int top=0,ans=0;for(int i=0;i<=n;i++){int x=i==n?0:h[i];while(top&&h[st[top-1]]>x){int p=st[--top],left=top?st[top-1]:-1;int area=h[p]*(i-left-1);if(area>ans)ans=area;}st[top++]=i;}free(st);return ans;}
int q75_max_product(int*a,int n){int mx=a[0],mn=a[0],ans=a[0];for(int i=1;i<n;i++){if(a[i]<0){int t=mx;mx=mn;mn=t;}mx=mx*a[i]>a[i]?mx*a[i]:a[i];mn=mn*a[i]<a[i]?mn*a[i]:a[i];if(mx>ans)ans=mx;}return ans;}
long long q76_count_inversions(int*a,int n){int*tmp=malloc(n*sizeof(int));long long ans=0;void merge(int l,int r){if(r-l<2)return;int m=(l+r)/2;merge(l,m);merge(m,r);int i=l,j=m,k=l;while(i<m||j<r){if(j==r||(i<m&&a[i]<=a[j]))tmp[k++]=a[i++];else tmp[k++]=a[j++],ans+=m-i;}for(i=l;i<r;i++)a[i]=tmp[i];}merge(0,n);free(tmp);return ans;}
/* Q77 */
char*q77_min_window(const char*s,const char*t){int need[128]={0},have[128]={0};for(int i=0;t[i];i++)need[(unsigned char)t[i]]++;int missing=strlen(t),l=0,st=0,best=INT_MAX;for(int r=0;s[r];r++){unsigned char c=s[r];have[c]++;if(have[c]<=need[c])missing--;while(!missing){if(r-l+1<best)best=r-l+1,st=l;unsigned char d=s[l++];if(--have[d]<need[d])missing++;}}char*out=malloc((best==INT_MAX?0:best)+1);if(best==INT_MAX){out[0]=0;return out;}memcpy(out,s+st,best);out[best]=0;return out;}
/* Q78: word-break reconstruction; words[] has count w. Returns malloc'd array of chosen word pointers. */
char**q78_word_break(const char*s,const char**words,int w,int*outn){int n=strlen(s);int*pre=malloc((n+1)*sizeof(int));for(int i=0;i<=n;i++)pre[i]=-1;pre[0]=0;for(int i=0;i<n;i++)if(pre[i]>=0)for(int z=0;z<w;z++){int len=strlen(words[z]);if(i+len<=n&&pre[i+len]<0&&!strncmp(s+i,words[z],len))pre[i+len]=z+1;}if(pre[n]<0){*outn=0;free(pre);return NULL;}char**r=malloc((n+1)*sizeof(char*));int c=0,pos=n;while(pos){int z=pre[pos]-1,len=strlen(words[z]);r[c++]=(char*)words[z];pos-=len;}for(int i=0;i<c/2;i++){char*t=r[i];r[i]=r[c-1-i];r[c-1-i]=t;}*outn=c;free(pre);return r;}
/* Q79 */
bool q79_regex_match(const char*s,const char*p){
 int n=strlen(s),m=strlen(p); char*dp=calloc((n+1)*(m+1),1);
 #define D(i,j) dp[(i)*(m+1)+(j)]
 D(0,0)=1;
 for(int j=2;j<=m;j++) if(p[j-1]=='*') D(0,j)=D(0,j-2);
 for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {
  if(p[j-1]=='*') D(i,j)=D(i,j-2)||((p[j-2]=='.'||p[j-2]==s[i-1])&&D(i-1,j));
  else D(i,j)=(p[j-1]=='.'||p[j-1]==s[i-1])&&D(i-1,j-1);
 }
 bool ans=D(n,m); free(dp); return ans;
}
int q80_edit_distance(const char*a,const char*b){int n=strlen(b);int*dp=malloc((n+1)*sizeof(int));for(int j=0;j<=n;j++)dp[j]=j;for(int i=1;a[i-1];i++){int prev=dp[0];dp[0]=i;for(int j=1;j<=n;j++){int old=dp[j],v=prev+(a[i-1]!=b[j-1]);int x=dp[j]+1,y=dp[j-1]+1;if(x<v)v=x;if(y<v)v=y;dp[j]=v;prev=old;}}int ans=dp[n];free(dp);return ans;}
int q81_longest_pal_subseq(const char*s){int n=strlen(s);int*dp=calloc(n,sizeof(int));for(int i=n-1;i>=0;i--){int prev=0;dp[i]=1;for(int j=i+1;j<n;j++){int old=dp[j];dp[j]=s[i]==s[j]?prev+2:(dp[j]>dp[j-1]?dp[j]:dp[j-1]);prev=old;}}int ans=n?dp[n-1]:0;free(dp);return ans;}
ListNode*q82_merge_k_lists(ListNode**a,int k){ListNode d={0},*t=&d;while(1){int bi=-1;for(int i=0;i<k;i++)if(a[i]&&(bi<0||a[i]->val<a[bi]->val))bi=i;if(bi<0)break;t->next=a[bi];t=t->next;a[bi]=a[bi]->next;}return d.next;}
ListNode*q83_reverse_k_group(ListNode*h,int k){ListNode*d=malloc(sizeof(ListNode));d->next=h;ListNode*g=d;while(1){ListNode*p=g;for(int i=0;i<k&&p;i++)p=p->next;if(!p)break;ListNode*cur=g->next,*prev=p->next;for(int i=0;i<k;i++){ListNode*n=cur->next;cur->next=prev;prev=cur;cur=n;}ListNode*old=g->next;g->next=prev;g=old;}ListNode*r=d->next;free(d);return r;}
/* Q84 */
typedef struct CacheNode{int key,val;struct CacheNode*prev,*next;}CacheNode;typedef struct{int cap,size;CacheNode*head,*tail;}LRU;static void unlinkNode(LRU*c,CacheNode*x){x->prev->next=x->next;x->next->prev=x->prev;}static void frontNode(LRU*c,CacheNode*x){x->next=c->head->next;x->prev=c->head;c->head->next->prev=x;c->head->next=x;}/* Hash-map omitted: use linear key scan for dependency-free C. */int q84_get(LRU*c,int key){for(CacheNode*x=c->head->next;x!=c->tail;x=x->next)if(x->key==key){unlinkNode(c,x);frontNode(c,x);return x->val;}return -1;}void q84_put(LRU*c,int key,int val){for(CacheNode*x=c->head->next;x!=c->tail;x=x->next)if(x->key==key){x->val=val;unlinkNode(c,x);frontNode(c,x);return;}CacheNode*x=malloc(sizeof(CacheNode));x->key=key;x->val=val;frontNode(c,x);if(++c->size>c->cap){CacheNode*z=c->tail->prev;unlinkNode(c,z);free(z);c->size--;}}
/* Q85 */
/* Two-heap implementation using sorted dynamic arrays for portability. */
typedef struct{long long*a;int n,cap;}Arr;void q85_add(Arr*h,long long x){if(h->n==h->cap){h->cap=h->cap?2*h->cap:8;h->a=realloc(h->a,h->cap*sizeof(long long));}h->a[h->n++]=x;}double q85_median(Arr*h){for(int i=1;i<h->n;i++){long long x=h->a[i];int j=i-1;while(j>=0&&h->a[j]>x)h->a[j+1]=h->a[j],j--;h->a[j+1]=x;}return h->n%2?h->a[h->n/2]:(h->a[h->n/2-1]+h->a[h->n/2])/2.0;}
/* Q86 */
char*q86_serialize(TreeNode*r){if(!r){char*x=strdup("#");return x;}char*a=q86_serialize(r->left),*b=q86_serialize(r->right);int n=snprintf(NULL,0,"%d,%s,%s",r->val,a,b);char*x=malloc(n+1);sprintf(x,"%d,%s,%s",r->val,a,b);free(a);free(b);return x;}
/* Q87 */
int q87_max_path_sum(TreeNode*r){int ans=INT_MIN;int f(TreeNode*x){if(!x)return 0;int a=f(x->left),b=f(x->right);if(a<0)a=0;if(b<0)b=0;int v=x->val+a+b;if(v>ans)ans=v;return x->val+(a>b?a:b);}f(r);return ans;}
/* Q88 */
void q88_recover_bst(TreeNode*r){TreeNode*st[4096],*first=NULL,*second=NULL,*prev=NULL;int top=0;while(r||top){while(r)st[top++]=r,r=r->left;r=st[--top];if(prev&&prev->val>r->val){if(!first)first=prev;second=r;}prev=r;r=r->right;}if(first){int t=first->val;first->val=second->val;second->val=t;}}
/* Q89 */
typedef struct TrieNode{int end;struct TrieNode*c[26];}TrieNode;TrieNode*q89_new(){return calloc(1,sizeof(TrieNode));}void q89_insert(TrieNode*r,const char*s){for(;*s;s++){int i=*s-'a';if(!r->c[i])r->c[i]=q89_new();r=r->c[i];}r->end=1;}bool q89_search(TrieNode*r,const char*s){for(;*s;s++){r=r->c[*s-'a'];if(!r)return false;}return r->end;}bool q89_starts_with(TrieNode*r,const char*s){for(;*s;s++){r=r->c[*s-'a'];if(!r)return false;}return true;}
/* Q90 */
void q90_word_search_ii_dfs(char**b,int n,int m,int i,int j,TrieNode*p,char*path,int d,char**out,int*outn){char ch=b[i][j];if(ch=='#'||!p->c[ch-'a'])return;p=p->c[ch-'a'];path[d]=ch;path[d+1]=0;if(p->end){out[*outn]=strdup(path);p->end=0;(*outn)++;}b[i][j]='#';int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};for(int k=0;k<4;k++){int x=i+dx[k],y=j+dy[k];if(x>=0&&x<n&&y>=0&&y<m)q90_word_search_ii_dfs(b,n,m,x,y,p,path,d+1,out,outn);}b[i][j]=ch;}
/* Q91 */
long long*q91_dijkstra(int n,int edges[][3],int e,int src){long long*dist=malloc(n*sizeof(long long));char*used=calloc(n,1);for(int i=0;i<n;i++)dist[i]=LLONG_MAX/4;dist[src]=0;for(int it=0;it<n;it++){int u=-1;for(int i=0;i<n;i++)if(!used[i]&&(u<0||dist[i]<dist[u]))u=i;if(u<0||dist[u]>=LLONG_MAX/4)break;used[u]=1;for(int z=0;z<e;z++)if(edges[z][0]==u&&dist[edges[z][1]]>dist[u]+edges[z][2])dist[edges[z][1]]=dist[u]+edges[z][2];}free(used);return dist;}
int q92_network_delay(int n,int e[][3],int m,int src){long long*d=q91_dijkstra(n,e,m,src-1);long long mx=0;for(int i=0;i<n;i++){if(d[i]>=LLONG_MAX/4){free(d);return -1;}if(d[i]>mx)mx=d[i];}free(d);return (int)mx;}
typedef struct{int*p,*r;}DSU;DSU dsu_new(int n){DSU d={malloc(n*sizeof(int)),calloc(n,sizeof(int))};for(int i=0;i<n;i++)d.p[i]=i;return d;}int dsu_f(DSU*d,int x){return d->p[x]==x?x:(d->p[x]=dsu_f(d,d->p[x]));}bool dsu_u(DSU*d,int a,int b){a=dsu_f(d,a);b=dsu_f(d,b);if(a==b)return false;if(d->r[a]<d->r[b]){int t=a;a=b;b=t;}d->p[b]=a;if(d->r[a]==d->r[b])d->r[a]++;return true;}
int q93_mst(int n,int e[][3],int m){for(int i=0;i<m;i++)for(int j=i+1;j<m;j++)if(e[j][2]<e[i][2])for(int k=0;k<3;k++){int t=e[i][k];e[i][k]=e[j][k];e[j][k]=t;}DSU d=dsu_new(n);int ans=0;for(int i=0;i<m;i++)if(dsu_u(&d,e[i][0],e[i][1]))ans+=e[i][2];free(d.p);free(d.r);return ans;}
/* Q94 */
void q94_dfs(int u,int pe,int n,int e[][2],int m,int*tin,int*low,int*timer,int*isBridge){tin[u]=low[u]=(*timer)++;for(int i=0;i<m;i++){int v=-1;if(i==pe)continue;if(e[i][0]==u)v=e[i][1];else if(e[i][1]==u)v=e[i][0];else continue;if(tin[v]>=0){if(tin[v]<low[u])low[u]=tin[v];}else{q94_dfs(v,i,n,e,m,tin,low,timer,isBridge);if(low[v]<low[u])low[u]=low[v];if(low[v]>tin[u])isBridge[i]=1;}}}void q94_critical_connections(int n,int e[][2],int m,int*out){int*tin=malloc(n*sizeof(int)),*low=malloc(n*sizeof(int));for(int i=0;i<n;i++)tin[i]=-1;memset(out,0,m*sizeof(int));int timer=0;for(int i=0;i<n;i++)if(tin[i]<0)q94_dfs(i,-1,n,e,m,tin,low,&timer,out);free(tin);free(low);}
/* Q95 */
void q95_scc(int n,int e[][2],int m,int*comp){/* Kosaraju with O(n^2) adjacency for clarity. */int*vis=calloc(n,1),*ord=malloc(n*sizeof(int)),k=0;void f(int u){vis[u]=1;for(int i=0;i<m;i++)if(e[i][0]==u&&!vis[e[i][1]])f(e[i][1]);ord[k++]=u;}for(int i=0;i<n;i++)if(!vis[i])f(i);for(int i=0;i<n;i++)comp[i]=-1;void r(int u,int c){comp[u]=c;for(int i=0;i<m;i++)if(e[i][1]==u&&comp[e[i][0]]<0)r(e[i][0],c);}int c=0;for(int i=n-1;i>=0;i--)if(comp[ord[i]]<0)r(ord[i],c++);free(vis);free(ord);}
/* Q96 */
char*q96_alien_dictionary(const char**w,int n){int edge[26][26]={0},deg[26]={0},present[26]={0};for(int i=0;i<n;i++)for(int j=0;w[i][j];j++)present[w[i][j]-'a']=1;for(int i=1;i<n;i++){int k=0;while(w[i-1][k]&&w[i][k]&&w[i-1][k]==w[i][k])k++;if(!w[i][k]&&!w[i-1][k])continue;if(!w[i][k]&&w[i-1][k])return strdup("");if(w[i-1][k]&&w[i][k]&&!edge[w[i-1][k]-'a'][w[i][k]-'a'])edge[w[i-1][k]-'a'][w[i][k]-'a']=1,deg[w[i][k]-'a']++;}char*q=malloc(27);int h=0,t=0;char z[26];for(int i=0;i<26;i++)if(present[i]&&!deg[i])z[t++]=i;while(h<t){int u=z[h++];q[h-1]=(char)('a'+u);for(int v=0;v<26;v++)if(edge[u][v]&&!--deg[v])z[t++]=v;}q[t]=0;int cnt=0;for(int i=0;i<26;i++)cnt+=present[i];if(t!=cnt)q[0]=0;return q;}
bool q97_partition_equal(int*a,int n){int sum=0;for(int i=0;i<n;i++)sum+=a[i];if(sum%2)return false;int t=sum/2;char*dp=calloc(t+1,1);dp[0]=1;for(int i=0;i<n;i++)for(int s=t;s>=a[i];s--)dp[s]|=dp[s-a[i]];bool ans=dp[t];free(dp);return ans;}
int q98_min_cut(const char*s){int n=strlen(s);int*cut=malloc(n*sizeof(int));for(int i=0;i<n;i++)cut[i]=i;for(int r=0;r<n;r++){for(int l=r;l>=0&&s[l]==s[r];l--)cut[r]=l? (cut[r]<cut[l-1]+1?cut[r]:cut[l-1]+1):0;for(int l=r-1;l>=0&&s[l]==s[r];l--)cut[r]=l? (cut[r]<cut[l-1]+1?cut[r]:cut[l-1]+1):0;}int ans=n?cut[n-1]:0;free(cut);return ans;}
long long q99_nqueens(int n){long long ans=0;void f(int r,int cols,int d1,int d2){if(r==n){ans++;return;}int avail=((1<<n)-1)&~(cols|d1|d2);while(avail){int b=avail&-avail;avail-=b;f(r+1,cols|b,(d1|b)<<1,(d2|b)>>1);}}f(0,0,0,0);return ans;}
int q100_burst_balloons(int*a,int n){
 int N=n+2; int*b=malloc(N*sizeof(int)); b[0]=b[N-1]=1; for(int i=0;i<n;i++)b[i+1]=a[i];
 int*dp=calloc(N*N,sizeof(int));
 #define DP(i,j) dp[(i)*N+(j)]
 for(int len=2;len<N;len++) for(int l=0;l+len<N;l++){int r=l+len; for(int k=l+1;k<r;k++){int v=DP(l,k)+b[l]*b[k]*b[r]+DP(k,r); if(v>DP(l,r))DP(l,r)=v;}}
 int ans=DP(0,N-1); free(b); free(dp); return ans;
}
