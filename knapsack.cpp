#include <bits/stdc++.h>
using namespace std;

class knapsack{
    int m,n;
    vector<float> p;
    vector<float> w;
   public:
   void input(){ //take input
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
            if ((p[j]/w[j])<=(p[j+1]/w[j+1])){ //sort in descending order according to profit/weight ratio
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
   vector<float> frac_knap (){ //main knapsack function
    vector<float> x(n,0);
    int i,u=m;
    for(i=0;i<n;i++){ //loop through all items
        if(w[i]>u) break; //if weight of item is greater than remaining capacity, break
        x[i]=1.0; //else add whole item
        u-=w[i]; //reduce remaining capacity
    }
    if(i<=n){ //if there are still items left
        x[i]=u/w[i]; //add fraction of the next item
    }
    
    return x;//return the vector containing fractions of items added to knapsack
   }
   int calc_profit(vector<float> x){ //calculate profit from the fractions of items added to knapsack
    int profit=0;
    for(int i=0;i<n;i++){
        profit+=x[i]*p[i]; //multiply fraction of item by its profit and add to total profit
    }
    return profit; //return total profit
   }

};

int main(){ //main function
    knapsack k; //create knapsack class object
    //vector<float> p = {700,500,900};
    //vector<float> w = {7,1,3};
    k.input(); //take input
    k.bubbleSort(); //sort items according to profit/weight ratio
   vector<float> x =k.frac_knap(); //call knapsack function to get fractions of items added to knapsack
    cout<<"Knapsack is\n"; 
    for(float a:x){
        cout<<a<<" "; //print fractions of items added to knapsack
    }  
    cout<<endl;
    cout<<"Profit is "<<k.calc_profit(x)<<endl; //calculate and print total profit
    return 0;
}