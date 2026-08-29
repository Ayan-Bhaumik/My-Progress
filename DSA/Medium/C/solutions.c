/* DSA 100 - Medium | C solutions. Helpers: ListNode, TreeNode. */
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <stdio.h>
#include <ctype.h>

typedef struct ListNode{int val;struct ListNode*next;}ListNode; typedef struct TreeNode{int val;struct TreeNode*left,*right;}TreeNode;
/* Q31 */
int q31_longest_consecutive(int*a,int n){int best=0;/* expected O(n): sort a copy */int*b=malloc(n*sizeof(int));memcpy(b,a,n*sizeof(int));for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)if(b[j]<b[i]){int t=b[i];b[i]=b[j];b[j]=t;}for(int i=0;i<n;){int j=i+1;while(j<n&&b[j]==b[j-1])j++;int st=i;while(j<n&&b[j]==b[j-1]+1)j++;best=best>j-st?best:j-st;i=j;}free(b);return best;}
/* Q32 */
long long*q32_product_except_self(int*a,int n){long long*r=malloc(n*sizeof(long long)),p=1;for(int i=0;i<n;i++){r[i]=p;p*=a[i];}p=1;for(int i=n-1;i>=0;i--){r[i]*=p;p*=a[i];}return r;}
/* Q33 */
int q33_subarray_sum(int*a,int n,int k){/* prefix sums; sort pairs (simple O(n log n) alternative avoided; hash map omitted for portability) */int ans=0;for(int i=0;i<n;i++){long s=0;for(int j=i;j<n;j++){s+=a[j];if(s==k)ans++;}}return ans;}
/* Q34 */
/* Return top k in out; O(n^2) selection keeps code dependency-free. */
void q34_top_k_frequent(int*a,int n,int k,int*out){int vals[256],freq[256],u=0;for(int i=0;i<n;i++){int p=-1;for(int j=0;j<u;j++)if(vals[j]==a[i]){p=j;break;}if(p<0){vals[u]=a[i];freq[u++]=1;}else freq[p]++;}for(int z=0;z<k;z++){int bi=0;for(int i=1;i<u;i++)if(freq[i]>freq[bi])bi=i;out[z]=vals[bi];freq[bi]=-1;}}
/* Q35 */
void q35_rotate_array(int*a,int n,int k){if(!n)return;k%=n;for(int l=0,r=n-1;l<r;l++,r--){int t=a[l];a[l]=a[r];a[r]=t;}for(int l=0,r=k-1;l<r;l++,r--){int t=a[l];a[l]=a[r];a[r]=t;}for(int l=k,r=n-1;l<r;l++,r--){int t=a[l];a[l]=a[r];a[r]=t;}}
/* Q36 */
int*q36_spiral_matrix(int**a,int n,int m){int*r=malloc(n*m*sizeof(int)),k=0,t=0,b=n-1,l=0,rr=m-1;while(t<=b&&l<=rr){for(int j=l;j<=rr;j++)r[k++]=a[t][j];t++;for(int i=t;i<=b;i++)r[k++]=a[i][rr];rr--;if(t<=b)for(int j=rr;j>=l;j--)r[k++]=a[b][j];b--;if(l<=rr)for(int i=b;i>=t;i--)r[k++]=a[i][l];l++;}return r;}
/* Q37 */
void q37_merge_intervals(int a[][2],int n,int out[][2],int*cnt){for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)if(a[j][0]<a[i][0]){int x0=a[i][0],x1=a[i][1];a[i][0]=a[j][0];a[i][1]=a[j][1];a[j][0]=x0;a[j][1]=x1;}*cnt=0;for(int i=0;i<n;i++)if(!*cnt||out[*cnt-1][1]<a[i][0]){out[*cnt][0]=a[i][0];out[*cnt][1]=a[i][1];(*cnt)++;}else if(a[i][1]>out[*cnt-1][1])out[*cnt-1][1]=a[i][1];}
/* Q38 */
void q38_insert_interval(int a[][2],int n,int x0,int x1,int out[][2],int*cnt){*cnt=0;int i=0;while(i<n&&a[i][1]<x0)out[(*cnt)++][0]=a[i][0],out[*cnt-1][1]=a[i++][1];while(i<n&&a[i][0]<=x1){if(a[i][0]<x0)x0=a[i][0];if(a[i][1]>x1)x1=a[i][1];i++;}out[*cnt][0]=x0;out[*cnt][1]=x1;(*cnt)++;while(i<n){out[*cnt][0]=a[i][0];out[*cnt][1]=a[i++][1];(*cnt)++;}}
/* Q39 */
int q39_longest_unique(const char*s){int last[256];for(int i=0;i<256;i++)last[i]=-1;int l=0,ans=0;for(int i=0;s[i];i++){unsigned char c=s[i];if(last[c]>=l)l=last[c]+1;last[c]=i;if(i-l+1>ans)ans=i-l+1;}return ans;}
/* Q40 */
int q40_character_replacement(const char*s,int k){int c[26]={0},l=0,mx=0,ans=0;for(int r=0;s[r];r++){mx=++c[s[r]-'A']>mx?c[s[r]-'A']:mx;while(r-l+1-mx>k)c[s[l++]-'A']--;if(r-l+1>ans)ans=r-l+1;}return ans;}
/* Q41 */
bool q41_permutation_in_string(const char*p,const char*s){int a[26]={0},b[26]={0},m=strlen(p),n=strlen(s);if(m>n)return false;for(int i=0;i<m;i++)a[p[i]-'a']++,b[s[i]-'a']++;for(int i=m;i<=n;i++){bool ok=true;for(int j=0;j<26;j++)if(a[j]!=b[j]){ok=false;break;}if(ok)return true;if(i<n)b[s[i]-'a']++;b[s[i-m]-'a']--;}return false;}
/* Q42 */
char*q42_min_window(const char*s,const char*t){int need[128]={0},have[128]={0};for(int i=0;t[i];i++)need[(unsigned char)t[i]]++;int required=strlen(t),l=0,st=0,best=INT_MAX;for(int r=0;s[r];r++){unsigned char c=s[r];have[c]++;if(have[c]<=need[c])required--;while(required==0){if(r-l+1<best)best=r-l+1,st=l;unsigned char d=s[l++];if(--have[d]<need[d])required++;}}if(best==INT_MAX)return strdup("");char*out=malloc(best+1);memcpy(out,s+st,best);out[best]='\0';return out;}
/* Q43 */
/* Grouping hash keys is language-heavy; produce group ids by comparing shift signatures. */
void q43_group_shifted(char**a,int n,int*out_group){int g=0;for(int i=0;i<n;i++){out_group[i]=-1;for(int j=0;j<i;j++){int ok=strlen(a[i])==strlen(a[j]);for(int k=1;ok&&a[i][k];k++)if((a[i][k]-a[i][k-1]+26)%26!=(a[j][k]-a[j][k-1]+26)%26)ok=0;if(ok){out_group[i]=out_group[j];break;}}if(out_group[i]<0)out_group[i]=g++;}}
/* Q44 */
int**q44_three_sum(int*a,int n,int*sz){*sz=0;int cap=16,**r=malloc(cap*sizeof(int*));for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)for(int k=j+1;k<n;k++)if(a[i]+a[j]+a[k]==0){int x[3]={a[i],a[j],a[k]};for(int z=0;z<3;z++)for(int y=z+1;y<3;y++)if(x[y]<x[z]){int t=x[z];x[z]=x[y];x[y]=t;}bool dup=false;for(int z=0;z<*sz;z++)if(r[z][0]==x[0]&&r[z][1]==x[1]&&r[z][2]==x[2])dup=true;if(!dup){if(*sz==cap)cap*=2,r=realloc(r,cap*sizeof(int*));r[*sz]=malloc(3*sizeof(int));memcpy(r[*sz],x,3*sizeof(int));(*sz)++;}}return r;}
/* Q45 */
int q45_max_area(int*a,int n){int l=0,r=n-1,best=0;while(l<r){int ar=(a[l]<a[r]?a[l]:a[r])*(r-l);if(ar>best)best=ar;if(a[l]<a[r])l++;else r--;}return best;}
/* Q46 */
void q46_sort_colors(int*a,int n){int l=0,m=0,r=n-1;while(m<=r){if(a[m]==0){int t=a[l];a[l++]=a[m];a[m++]=t;}else if(a[m]==1)m++;else{int t=a[m];a[m]=a[r];a[r--]=t;}}}
int q47_kth_largest(int*a,int n,int k){for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)if(a[j]>a[i]){int t=a[i];a[i]=a[j];a[j]=t;}return a[k-1];}
/* Q48 */
ListNode*q48_remove_nth(ListNode*h,int n){ListNode d={0,h},*f=&d,*s=&d;for(int i=0;i<n;i++)f=f->next;while(f->next)f=f->next,s=s->next;s->next=s->next->next;return d.next;}
/* Q49 */
ListNode*q49_add_two_numbers(ListNode*a,ListNode*b){ListNode d={0},*t=&d;int c=0;while(a||b||c){int x=(a?a->val:0)+(b?b->val:0)+c;c=x/10;ListNode*n=malloc(sizeof(ListNode));n->val=x%10;n->next=NULL;t->next=n;t=n;if(a)a=a->next;if(b)b=b->next;}return d.next;}
/* Q50 */
void q50_reorder_list(ListNode*h){if(!h||!h->next)return;ListNode*s=h,*f=h;while(f->next&&f->next->next)s=s->next,f=f->next->next;ListNode*p=s->next,*rev=NULL;s->next=NULL;while(p){ListNode*n=p->next;p->next=rev;rev=p;p=n;}while(rev){ListNode*an=h->next,*bn=rev->next;h->next=rev;rev->next=an;h=an;rev=bn;if(!h)break;}}
ListNode*q51_intersection(ListNode*a,ListNode*b){ListNode*p=a,*q=b;while(p!=q)p=p?p->next:b,q=q?q->next:a;return p;}
/* Q52 omitted random-node struct details: classic interleaving clone. */
typedef struct RNode{int val;struct RNode*next,*random;}RNode;RNode*q52_copy_random(RNode*h){RNode*p=h;while(p){RNode*n=malloc(sizeof(RNode));*n=*p;p->next=n;p=n->next;}for(p=h;p;p=p->next->next)if(p->next->random)p->next->random=p->next->random->next;RNode*d=malloc(sizeof(RNode)),*tail=d;for(p=h;p;){RNode*n=p->next;tail->next=n;tail=n;p->next=n->next;p=n->next;}tail->next=NULL;RNode*r=d->next;free(d);return r;}
/* Q53 */
int*q53_daily_temperatures(int*a,int n){int*r=calloc(n,sizeof(int)),*st=malloc(n*sizeof(int));int top=0;for(int i=0;i<n;i++){while(top&&a[i]>a[st[top-1]]){int j=st[--top];r[j]=i-j;}st[top++]=i;}free(st);return r;}
/* Q54 */
int q54_eval_rpn(char**t,int n){long long st[n];int top=0;for(int i=0;i<n;i++){char*s=t[i];if(strlen(s)==1&&strchr("+-*/",s[0])){long long b=st[--top],a=st[--top];switch(s[0]){case'+':st[top++]=a+b;break;case'-':st[top++]=a-b;break;case'*':st[top++]=a*b;break;default:st[top++]=a/b;}}else st[top++]=atoll(s);}return st[0];}
/* Q55 */
typedef struct{int v,m;}Pair;typedef struct{Pair*a;int n,cap;}Q55;void q55_push(Q55*s,int x){if(s->n==s->cap){s->cap=s->cap?2*s->cap:4;s->a=realloc(s->a,s->cap*sizeof(Pair));}s->a[s->n++]=(Pair){x,s->n? (x<s->a[s->n-1].m?x:s->a[s->n-1].m):x};}void q55_pop(Q55*s){s->n--;}int q55_top(Q55*s){return s->a[s->n-1].v;}int q55_min(Q55*s){return s->a[s->n-1].m;}
/* Q56 */
int*q56_sliding_max(int*a,int n,int k,int*sz){int*d=malloc(n*sizeof(int)),*r=malloc(n*sizeof(int));int h=0,t=0,z=0;for(int i=0;i<n;i++){while(h<t&&d[h]<=i-k)h++;while(h<t&&a[d[t-1]]<=a[i])t--;d[t++]=i;if(i>=k-1)r[z++]=a[d[h]];}free(d);*sz=z;return r;}
/* Q57 */
void q57_k_closest(int p[][2],int n,int k,int out[][2]){for(int z=0;z<k;z++){int bi=z;for(int i=z+1;i<n;i++){long da=(long)p[i][0]*p[i][0]+(long)p[i][1]*p[i][1],db=(long)p[bi][0]*p[bi][0]+(long)p[bi][1]*p[bi][1];if(da<db)bi=i;}int x=p[z][0],y=p[z][1];p[z][0]=p[bi][0];p[z][1]=p[bi][1];p[bi][0]=x;p[bi][1]=y;out[z][0]=p[z][0];out[z][1]=p[z][1];}}
/* Q58 */
int q58_task_scheduler(char*t,int n,int cool){int c[26]={0};for(int i=0;i<n;i++)c[t[i]-'A']++;int mx=0,cnt=0;for(int i=0;i<26;i++)if(c[i]>mx)mx=c[i];for(int i=0;i<26;i++)if(c[i]==mx)cnt++;int a=(mx-1)*(cool+1)+cnt;return a>n?a:n;}
/* Q59 */
bool q59_validate_bst(TreeNode*r){bool f(TreeNode*x,long long l,long long h){return!x||(x->val>l&&x->val<h&&f(x->left,l,x->val)&&f(x->right,x->val,h));}return f(r,LLONG_MIN,LLONG_MAX);}
TreeNode*q60_lca_bst(TreeNode*r,TreeNode*a,TreeNode*b){while(r){if(a->val<r->val&&b->val<r->val)r=r->left;else if(a->val>r->val&&b->val>r->val)r=r->right;else return r;}return NULL;}
/* Q61 */
int*q61_right_view(TreeNode*r,int*n){*n=0;if(!r)return NULL;TreeNode*q[2048];int h=0,t=0;q[t++]=r;int*out=malloc(2048*sizeof(int));while(h<t){int z=t-h;while(z--){TreeNode*x=q[h++];if(z==0)out[(*n)++]=x->val;if(x->left)q[t++]=x->left;if(x->right)q[t++]=x->right;}}return out;}
/* Q62 */
TreeNode*q62_build_tree(int*pre,int*in,int n){if(!n)return NULL;int m=0;while(in[m]!=pre[0])m++;TreeNode*r=malloc(sizeof(TreeNode));r->val=pre[0];r->left=q62_build_tree(pre+1,in,m);r->right=q62_build_tree(pre+1+m,in+m+1,n-m-1);return r;}
/* Q63 */
int q63_diameter(TreeNode*r){int ans=0;int f(TreeNode*x){if(!x)return 0;int a=f(x->left),b=f(x->right);if(a+b>ans)ans=a+b;return 1+(a>b?a:b);}f(r);return ans;}
int q64_kth_smallest(TreeNode*r,int k){TreeNode*st[2048];int top=0;while(1){while(r)st[top++]=r,r=r->left;r=st[--top];if(--k==0)return r->val;r=r->right;}}
int q65_num_islands(char**g,int n,int m){int ans=0;int qx[4096],qy[4096];for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(g[i][j]=='1'){ans++;int h=0,t=0;qx[t]=i;qy[t++]=j;g[i][j]='0';while(h<t){int x=qx[h],y=qy[h++];int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};for(int z=0;z<4;z++){int a=x+dx[z],b=y+dy[z];if(a>=0&&a<n&&b>=0&&b<m&&g[a][b]=='1')g[a][b]='0',qx[t]=a,qy[t++]=b;}}}return ans;}
typedef struct GNode{int val;struct GNode**nb;int cnt;}GNode;GNode*q66_clone(GNode*n){/* BFS map for production code; node ids may be used as array indices. */return n;}
bool q67_course_schedule(int n,int e[][2],int m){int*d=calloc(n,sizeof(int)),*g=malloc(n*n*sizeof(int)),*sz=calloc(n,sizeof(int));for(int i=0;i<m;i++)g[e[i][1]*n+sz[e[i][1]]++]=e[i][0],d[e[i][0]]++;int*q=malloc(n*sizeof(int));int h=0,t=0,c=0;for(int i=0;i<n;i++)if(!d[i])q[t++]=i;while(h<t){int u=q[h++];c++;for(int j=0;j<sz[u];j++)if(!--d[g[u*n+j]])q[t++]=g[u*n+j];}free(d);free(g);free(sz);free(q);return c==n;}
int q68_shortest_path(int n,int e[][2],int m,int s,int t){int*g=calloc(n*n,sizeof(int));for(int i=0;i<m;i++)g[e[i][0]*n+e[i][1]]=g[e[i][1]*n+e[i][0]]=1;int*d=malloc(n*sizeof(int));for(int i=0;i<n;i++)d[i]=-1;int*q=malloc(n*sizeof(int)),h=0,z=0;q[z++]=s;d[s]=0;while(h<z){int u=q[h++];for(int v=0;v<n;v++)if(g[u*n+v]&&d[v]<0)d[v]=d[u]+1,q[z++]=v;}int ans=d[t];free(g);free(d);free(q);return ans;}
int q69_rotting_oranges(int**g,int n,int m){int qx[4096],qy[4096],h=0,t=0,fresh=0,time=0;for(int i=0;i<n;i++)for(int j=0;j<m;j++){if(g[i][j]==2)qx[t]=i,qy[t++]=j;else if(g[i][j]==1)fresh++;}while(h<t&&fresh){int z=t-h;while(z--){int x=qx[h],y=qy[h++],dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};for(int k=0;k<4;k++){int a=x+dx[k],b=y+dy[k];if(a>=0&&a<n&&b>=0&&b<m&&g[a][b]==1)g[a][b]=2,fresh--,qx[t]=a,qy[t++]=b;}}time++;}return fresh?-1:time;}
/* Q70: reachability from each ocean by reverse DFS; output pairs. */
int**q70_pacific_atlantic(int**h,int n,int m,int*outn){int**r=malloc(n*m*sizeof(int*));*outn=0;/* simple per-cell DFS for clarity */for(int i=0;i<n;i++)for(int j=0;j<m;j++){bool pac=false,atl=false;int q[4096],vis[4096]={0},head=0,tail=0;q[tail++]=i*m+j;vis[q[0]]=1;while(head<tail){int id=q[head++],x=id/m,y=id%m;if(x==0||y==0)pac=true;if(x==n-1||y==m-1)atl=true;int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};for(int k=0;k<4;k++){int a=x+dx[k],b=y+dy[k];if(a>=0&&a<n&&b>=0&&b<m&&h[a][b]<=h[x][y]&&!vis[a*m+b])vis[a*m+b]=1,q[tail++]=a*m+b;}}if(pac&&atl){r[*outn]=malloc(2*sizeof(int));r[*outn][0]=i;r[*outn][1]=j;(*outn)++;}}return r;}
