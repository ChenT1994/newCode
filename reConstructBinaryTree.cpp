class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        TreeNode *root=NULL;
        if(pre.empty())
           return root;
        root=reConstruct(pre,vin);
        return root;
    }
        
    TreeNode* reConstruct(vector<int> &pre,vector<int> &vin)
    {
        if(pre.empty())
            return NULL ;
        TreeNode *root=new TreeNode(pre[0]);
        if(pre.size()==1) 
            return root;
        int len=vin.size();
        int i;
        for(i=0;i<len;++i)
        {
            if(vin[i]==root->val)
                break;
        }
        vector<int> vinleft(vin.begin(),vin.begin()+i);
        vector<int> vinright(vin.begin()+i+1,vin.end());
        vector<int> preleft(pre.begin()+1,pre.begin()+1+vinleft.size());
        vector<int> preright(pre.end()-vinright.size(),pre.end());
        root->left=reConstruct(preleft,vinleft);
        root->right=reConstruct(preright,vinright);
        return root;

    }

};
