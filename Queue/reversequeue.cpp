class Solution
{
    void reverse(queue<int>&q)
    {
        if(q.empty())
        {
            return;
        }
        
        int temp = q.front();
        q.pop();
        reverse(q);
        q.push(temp);
    }
    public:
    queue<int> rev(queue<int> q)
    {
        // stack<int> st;
        
        // while(!q.empty())
        // {
        //     st.push(q.front());
        //     q.pop();
        // }
        
        // while(!st.empty())
        // {
        //     q.push(st.top());
        //     st.pop();
        // }
        // return q;
        
        reverse(q);
        return q;
    }
};