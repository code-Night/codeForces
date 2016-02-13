#include <iostream>
#include <vector>
using namespace std;
struct node{
    int v;
    int type ;
};
node tree [8*(1<<17)];
vector <int> elements ;
int n,m;
void build(int i,int l,int r){
    if(l == r){
        tree[i].v = elements[l];
        tree[i].type = 0;
        return ;
    }
    int mid = (l+r)/2;
    build(2*i+1,l,mid);
    build(2*i+2,mid+1,r);
    if(tree[2*i+1].type == tree[2*i+2].type){
        int currT = (tree[2*i+1].type+1)%2 ;
        if(currT == 1){
            tree[i].v = tree[2*i+1].v | tree[2*i+2].v;
        }else{
            tree[i].v = tree[2*i+1].v ^ tree[2*i+2].v;
        }
        tree[i].type = currT;
    }
}
void update(int i,int l,int r,int ind,int val){
    if(l == r && l == ind){
        tree[i].v = val;
        return ;
    }
    int mid = (l+r)/2 ;
    if(ind <= mid){
        update(2*i+1,l,mid,ind,val);
    }else{
        update(2*i+2,mid+1,r,ind,val);
    }
    if(tree[i].type == 1){
        tree[i].v = tree[2*i+1].v | tree[2*i+2].v;
    }else{
        tree[i].v = tree[2*i+1].v ^ tree[2*i+2].v;
    }
}
int main()
{
    cin >> n>>m;
    elements.resize(1<<n);
    for(int i=0 ; i < 1<<n ; i++){
        cin >> elements[i];
    }
    build(0,0,(1<<n)-1);
//    for(int i=0 ; i<10 ; i++)
//        cout << tree[i].v << endl;
    for(int i=0 ; i<m ; i++){
        int p,b;
        cin >> p >> b ;
        update(0,0,(1<<n)-1,p-1,b);
//        cout << "===============\n";
//        for(int i=0 ; i<10 ; i++)
//            cout << tree[i].v << endl;
//        cout << "===============\n";
        cout << tree[0].v << endl ;
    }
    return 0;
}
