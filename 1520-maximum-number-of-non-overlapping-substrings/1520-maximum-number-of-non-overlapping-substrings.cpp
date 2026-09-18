class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
         vector<int> l(26, -1), r(26, -1);

        for(int i=0;i<s.size();i++){
            int x=s[i]-'a';
            if(l[x]==-1) l[x]=i;
            r[x]=i;
        }

        vector<pair<int,int>> a;

        for(int c=0;c<26;c++){
            if(l[c]==-1) continue;

            int L=l[c], R=r[c];
            bool ok=true;

            for(int i=L;i<=R;i++){
                int x=s[i]-'a';
                if(l[x]<L) ok=false;
                R=max(R,r[x]);
            }

            if(ok) a.push_back({L,R});
        }

        sort(a.begin(),a.end(),[](auto x,auto y){
            return x.second<y.second;
        });

        vector<string> ans;
        int end=-1;

        for(auto p:a)
            if(p.first>end){
                ans.push_back(s.substr(p.first,p.second-p.first+1));
                end=p.second;
            }

        return ans;
    }
};