using namespace std;
#include <iostream>
#include <string.h> 
#include <string>
int num[10]={10,10,10,10,10,10,10,10,10,10};
int dis[9]={1,2,3,4,5,6,7,8,9};
struct ticket{
	string name;
	int id;
	char a,b;
	int a1,b1;
	int cost;
	int day,hour,min;
}pa[100];
bool cw(ticket &s){
	if(s.a!='A'||s.b!='A'||s.a1<1||s.a1>=10||s.b1<2||s.b1>10||s.a1==s.b1)return false; 
	return true;                          //判断输入信息 
}
void tickets(ticket &s){
	for(int i=s.a1-1;i<s.b1-1;i++)            //录票 
	num[i]--;
}
int tcost(ticket &s){                    //计算票价 
	int cost=0;
	for(int i=s.a1-1;i<s.b1-1;i++)
	cost+=dis[i];
	return cost;
} 
int main(){
	char po[10];
	for(int i=0;i<10;i++)
		po[i]='A';
	int i=0;
	while(cin>>pa[i].a>>pa[i].a1>>pa[i].b>>pa[i].b1){
		if(!cw(pa[i])){
			cout<<"输入站台信息错误";
			continue; 
		}
		cout<<"当前余票："<<num[pa[i].a1-1]<<"张"<<'\n'<<"票价："<<tcost(pa[i])<<"元"<<endl;
		if(num[pa[i].a1-1]){
			cin>>pa[i].name>>pa[i].id;
			pa[i].cost=tcost(pa[i]);
			tickets(pa[i]);
			i++;
		}
		else {
		     cout<<"请更换站台"; 
		}
		
	}
	return 0; 
	
}
