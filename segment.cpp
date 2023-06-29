pair<int,int> getmima(PII *st,int *arr,int ss,int se,int si,int qs,int qe){
    if(se<qs or ss>qe) return {INT_MAX,INT_MIN};
    if(qs<=ss and qe>=se) return {st[si].first,st[si].second};
    int mid = (se+ss)/2;
    pair<int,int> p1 = getmima(st,arr,ss,mid,2*si+1,qs,qe);
    pair<int,int> p2 = getmima(st,arr,mid+1,se,2*si+2,qs,qe);
    return{min(p1.first,p2.first),max(p1.second,p2.second)};
    
}
//Function to update a value in input array and segment tree.
PII getMinMax(PII *st, int *arr, int n, int qs, int qe)
{
    //add code here 
    return getmima(st,arr,0,n-1,0,qs,qe);
}

//Function to return minimum and maximum of elements in range from index
void updateV(int *arr,PII *st,int ss,int se,int si,int index,int new_val){
    if(index<ss or index>se) return;
    if(ss == se){
        st[si].first = st[si].second = new_val;
        return;
    }
    int mid = (se+ss)/2;
    updateV(arr,st,ss,mid,2*si+1,index,new_val);
    updateV(arr,st,mid+1,se,2*si+2,index,new_val);
    st[si] = {min(st[2*si+1].first,st[2*si+2].first),max(st[2*si+1].second,st[2*si+2].second)};
}
//qs (quey start) to qe (query end).
void updateValue(int *arr, PII *st, int n, int index, int new_val)
{
   // add code here
   updateV(arr,st,0,n-1,0,index,new_val);
   arr[index] = new_val;
}