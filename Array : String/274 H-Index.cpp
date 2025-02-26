class Solution {
    public:
        int hIndex(vector<int>& citations) 
        {
            sort(citations.begin(),citations.end(),greater<int>());
            int h=0;
            for(int i=0;i<citations.size();i++){
                if(h<citations.size() && citations[h]>h)    ++h;
            }    
            return h;
        }
    };