struct Node{
  int val,left,right;
};
int a[500010],cnt=0,versions[500010];
Node tree[25*N+15];
int build(int b,int e){
  cnt++;
  int curr=cnt;
  if(b==e){
    tree[curr].val=1e9+7;
    return curr;
  }
  int mid=(b+e)/2;
  tree[curr].left=build(b,mid);
  tree[curr].right=build(mid+1,e);
  tree[curr].val=min(tree[tree[curr].left].val,tree[tree[curr].right].val);
  return curr;
}
int update(int prev,int b,int e,int idx,int x){
  cnt++;
  int curr=cnt;
  if(b==e){
    tree[curr].val=x;
    return curr;
  }
  int mid=(b+e)/2;
  if(idx<=mid){
    tree[curr].left=update(tree[prev].left,b,mid,idx,x);
    tree[curr].right=tree[prev].right;
  }
  else{
    tree[curr].left=tree[prev].left;
    tree[curr].right=update(tree[prev].right,mid+1,e,idx,x);
  }
  tree[curr].val=min(tree[tree[curr].left].val,tree[tree[curr].right].val);
  return curr;
}
int query(int curr,int b,int e,int l,int r){
  if(e<l || b>r) return 1e9+7;
  if(b>=l && e<=r) return tree[curr].val;
  int mid=(b+e)/2;
  int q1=query(tree[curr].left,b,mid,l,r);
  int q2=query(tree[curr].right,mid+1,e,l,r);
  return min(q1,q2);
}