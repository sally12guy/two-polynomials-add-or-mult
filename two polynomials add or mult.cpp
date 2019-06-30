/*Author¡G§d²»³Ô¡]B053040044¡^
   Date¡G¡] 11. 24, 2017¡^
   Purpose¡Ghw5
*/
#include <iostream>
using namespace std;
//¸`ÂI 
class node{
	public:
		node(){}
		node(int c,int e=0, node* next=0){
			cof=c;
			ex=e;
			this->next=next;
		}
		int cof;//cofficient
		int ex;//exponent
		node *next;//point to next node
};
//poly list
class poly{
	public:
		poly(){	
			first=0;
		}
		//insert
		void insert(int c,int e){
			node *pre=0;//previos
			node *cur=first;//current
			if(first==0)	
				first=new node(c,e);	
			else{
				while(cur){
					if(e==cur->ex){//if exponent is equal to cur then add the cofficient
						cur->cof+=c;
						break;
					}
					else if(e>cur->ex){//if exponent is bigger than cur then create new node and put it infront of cur
						node *newnode=new node(c,e,cur);
						if(pre==0)
							first=newnode;
						else
							pre->next=newnode;
						break;
					}
					else if(cur->next==0){//if exponent is smaller than all cur then create new node and put it behind cur 
						cur->next=new node(c,e);
						break;
					}
					//let pre and cur point to its next
					pre=cur;
					cur=cur->next;
				}
			}
			//clear zero cofficent
			cur=first;
			pre=0;
			while(cur!=0){
				if(cur->cof==0){
					if(cur==first){//if the zero cofficent is in first
						first=cur->next;
						cur=first;
					}
					else{//if the zero cofficent isn't in first
						pre->next=cur->next;
						delete cur;
						cur=pre->next;
					}	
				}
				//let pre and cur point to its next
				else{
					pre=cur;
					cur=cur->next;
				}
			}
		}
		friend poly operator +(poly a,poly b){
			poly newp;
			node* temp;
			temp=a.first;
			//insert poly a's data to newp
			while(temp!=0){
				newp.insert(temp->cof,temp->ex);
				temp=temp->next;
			}
			temp=b.first;
			//insert poly b's data to newp
			while(temp!= 0){
				newp.insert(temp->cof,temp->ex);
				temp=temp->next;
			}
			return newp;
		}
		friend poly operator *(poly a,poly b){
			poly newp;
			node *tempa=a.first;
			while(tempa){
				node *tempb=b.first;
				//insert poly a nad poly b multiply data to newp
				while(tempb){
					newp.insert(tempa->cof*tempb->cof,tempa->ex+tempb->ex);
					tempb=tempb->next;
				}
				tempa=tempa->next;
			}
			return newp;
		}
		//print the list
		void output(){
			if(first==0)
				cout<<"0 0"<<endl;
			else{
				node *t=first;
				while(t!=0){
					cout<<t->cof<<" "<<t->ex<<endl;
					t=t->next;
				}
			}
		}
	private:
		node *first;//first
};
int main() {
	int p,q;//number of data
	int c,e;//cof and exponent
	int r=0;//runtime
	while(1){
		poly a,b,C,d;
		cin>>p;
		//read data
		for(int i=0;i<p;i++){
			cin>>c>>e;
			a.insert(c,e);	
		}
		cin>>q;
		if(p==0&&q==0)
			return 0;
		//read data
		for (int i=0;i<q;i++){
			cin>>c>>e;
			b.insert(c,e);	
		}
		C=a+b;//poly C=a+b
		d=a*b;//poly d=a*b;
		cout<<"Case"<<++r<<":"<<endl;
		cout<<"ADD:"<<endl;
		C.output();
		cout<<"MULTIPLY:"<<endl;
		d.output();
	}
}
