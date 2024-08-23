// Given an array of integers, sort it in descending order using merge sort algorithm.
#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>&v, vector<int>&v2,vector<int>&arr)
{
    int i=0;
    int j=0;
    int k=0;
    while(i<v.size()&&j<v2.size())
    {
        if(v[i]<v2[j])
        {
            arr[k++]=v[i++];
        }
        else
        {
            arr[k++]=v2[j++];
        }
    }
    if(i==v.size())
    {
        while(j<v2.size())
        {
            arr[k++]=v2[j++];
        }
    }
    else if(j==v2.size())
    {
        while(i<v.size())
        {
            arr[k++]=v[i++];
        }
    }
}
void mergesort(vector<int>&arr)
{
    int n= arr.size();
    if(n==1)return;
    int n1= n/2;
    int n2= n-n/2;
    vector<int>v(n1);
    vector<int >v2(n2);
    for(int i=0;i<n1;i++)
    {
        v[i]=arr[i];
    }
    for(int i=0;i<n2;i++)
    {
        v2[i]=arr[i+n1];
    }
    mergesort(v);
    mergesort(v2);
    merge(v,v2,arr);

}
int main()
{
    vector<int >v ={9,7,5,3,1,0};
    mergesort(v);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }


}