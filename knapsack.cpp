#include <bits/stdc++.h>
using namespace std;

class knapsack{
    int m,n;
    vector<float> p;
    vector<float> w;
   public:
   void input(){
    cout<<"Enter size of knapsack\n";
    cin>>m;
    cout<<"Enter total number of items\n";
    cin>>n;
    cout<<"Enter profits and weights\n";
    for(int i=0;i<n;i++){
        float a=0,b=0;
        cout<<"Enter weight "<<i+1<<"\n";
        cin>>a;
        w.push_back(a);
        cout<<"\nEnter profit "<<i+1<<"\n";
        cin>>b;
        p.push_back(b);
        cout<<endl;
    }
    cout<<"\nInput complete!\n";
   }
   void bubbleSort(){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if ((p[j]/w[j])<=(p[j+1]/w[j+1])){
               swap(p[j],p[j+1]);
               swap(w[j],w[j+1]);

        }
    }
   }
   /*cout<<"p"<<endl;
   for(float a:p){
    cout<<a<<" ";
   }
   cout<<endl;
   cout<<"w"<<endl;
   for(float a:w){
    cout<<a<<" ";
   }
   cout<<endl;*/
}
   vector<float> frac_knap (){
    vector<float> x(n,0);
    int i,u=m;
    for(i=0;i<n;i++){
        if(w[i]>u) break;
        x[i]=1.0;
        u-=w[i];
    }
    if(i<=n){
        x[i]=u/w[i];
    }
    
    return x;
   }
   int calc_profit(vector<float> x){
    int profit=0;
    for(int i=0;i<n;i++){
        profit+=x[i]*p[i];
    }
    return profit;
   }

};

int main(){
    knapsack k;
    //vector<float> p = {700,500,900};
    //vector<float> w = {7,1,3};
    k.input();
    k.bubbleSort();
   vector<float> x =k.frac_knap();
    cout<<"Result is\n";
    for(float a:x){
        cout<<a<<" ";
    }  
    cout<<endl;
    cout<<"Profit is "<<k.calc_profit(x)<<endl; 
    return 0;
}