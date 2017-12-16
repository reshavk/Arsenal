//Segment Tree for range maximum query
void build(int node, int s, int e) {
    if(s == e) {
        tree[node] = a[s];
    }
    int mid = (s + e)/2;
    build(node*2, s, mid);
    build(node*2+1, mid+1, e);
    tree[node] = max(tree[node*2], tree[node*2+1]);
}

void update(int node, int s, int e, int idx, int val) {
    if(s == e) {
        a[idx] += val;
        tree[node] = a[s];
    }
    else{
        int mid = (s+e)/2;
        if(s <= idx && idx <= mid)
            update(node*2, s, mid, idx, val);
        else
            update(node*2+1, mid+1, e, idx, val);
        tree[node] = max(tree[node*2], tree[node*2+1]);
    }
}

int query(int node, int s, int e, int l, int r) {
    if(s > e || s > r || e < l)
        return 0;
    if(l <= start && e <= r)
        return tree[node];
    int mid = (s+e)/2;
    int p1 = query(node*2, s, mid, l, r);
    int p2 = query(node*2+1, mid+1, e, l, r);
    return max(p1, p2);
}
