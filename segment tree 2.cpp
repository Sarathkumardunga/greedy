
//Segment tree
class Numarray {
    private:
    int n;
    vector<int> seg;
    int build(const vector<int> &nums,int left,int right,int node){
        int mid;
        int leftsum,rightsum;
        if(left==right) return seg[node]=nums[i];
        mid=(left+right)/2;
        leftsum= return build(nums,left,mid,2*node);
        rightsum=return build(nums,mid+1,right,2*node+1);
        return seg[node]=leftsum+rightsum;
    }

    int sumrange_helper(int l,int r,int s,int e,int node){
        int leftsum,rightsum;
        if(l<=s && e<=r) return seg[node];
        if(l>e || r<s) return 0;
        int mid=(s+e)/2;
        leftsum=sumrange_helper(l,r,s,mid,2*n);
        rightsum=sumrange_helper(l,r,mid+1,e,2*n+1);
        return leftsum+rightsum;
    }

    int update(int index;int val,int s,int e,int node){
        int leftsum,rightsum;
        int mid;
        if(index<s || index>e) return seg[node];
        if(s==e){
            return seg[node]=newvalue;
        }
        mid=(s+e)/2;
        leftsum=update(index,val,s,mid,2*n);
        rightsum=update(index,val,mid+1,e,2*n+1);
        return seg[node]=leftsum+rightsum;
    }
    
    public:
    Numarray(vector<int> &nums){
        n=nums.size();
        seg.resize(4*n);
        build(nums,1,n,1);
    }

    void update(int index,int val){
        update(index,val,1,n,1);
    }
    
    int sumrange(int left,int right){
        return sumrange_helper(left,right,1,n,1);
    }
};