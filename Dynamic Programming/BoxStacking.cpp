//Problem : To find the maximum height of stack that can be formed by placing one box on top of other,
//			where l and b of the upper box should be strictly less than the lower box.

struct box {
	int l, b, h;
};

bool cmp(pair<int, box> a, pair<int, box> b) {
    if(a.first > b.first)
        return true;
    else if(a.first < b.first)
        return false;
    else {
        if(a.second.l > b.second.l)
            return true;
        else
            return false;
    }
}

int maxheight(int l[], int b[], int h[], int n) {
	vector< pair<int, box> > v;

	for(int i=0; i<n; i++) {
		box b1, b2, b3;
		b1.l = max(l[i], b[i]);		b1.b = min(l[i], b[i]);		b1.h = h[i];
		b2.l = max(b[i], h[i]);		b2.b = min(b[i], h[i]);		b2.h = l[i];
		b3.l = max(l[i], h[i]); 	b3.b = min(l[i], h[i]);		b3.h = b[i];
		v.push_back(make_pair(l[i]*b[i], b1));
		v.push_back(make_pair(b[i]*h[i], b2));
		v.push_back(make_pair(l[i]*h[i], b3));
	}

	sort(v.begin(), v.end(), cmp);

	int dp[v.size()] = {};
	for(int i=0; i<v.size(); i++) {
        dp[i] = v[i].second.h;
	}

	int i = 1, j = 0;
	while(i < v.size()) {
        while(j < i) {
            if(v[i].second.l < v[j].second.l && v[i].second.b < v[j].second.b) {
                dp[i] = max(dp[i], dp[j] + v[i].second.h);
            }
            j++;
        }
        j = 0;
        i++;
	}

	int ans = dp[0];
	for(int i=1; i<v.size(); i++) {
        ans = max(ans, dp[i]);
	}
	return ans;
}