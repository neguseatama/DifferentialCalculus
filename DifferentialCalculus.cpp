/*
 Differential calculus in C++
 C++によるn次方程式の微分法
 https://github.com/neguseatama
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
//微分を実行する関数
pair<ll,ll> differentiate(pair<ll,ll> p){
    return {p.first*p.second,p.second-1};
}
int main(void){
    ll m;
    cin>>m;
    //mは項の数
    vector<pair<ll,ll>> term,ans;
    //termに項の係数・指数を入れる
    //ansには微分係数の項の係数・指数を入れる
    for(ll i=0;i<m;i++){
        ll x,d;
        cin>>x>>d;
        //termに入れるために係数x・指数dを入力として受け取る
        term.push_back({x,d});
        pair<ll,ll> p=differentiate(term[i]);
        ans.push_back({p.second,p.first});
        //降べきの順にソートしやすいように、
        //係数と指数を逆にしてansに入れた
    }
    sort(ans.rbegin(),ans.rend());
    //ansをソートする
    for(auto i : ans){
        if(i.second==0){
            break;
        }
        cout<<i.second<<" "<<i.first<<endl; //微分結果を出力
    }
    return 0;
}