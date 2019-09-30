#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int binarysearch(int arr[],int left,int right, int num){
	
	while(left<=right)
	{
		int mid=left +(right -left)/2;
		if(arr[mid]<num)
		{
			left=mid+1;
		}
		else if(arr[mid]>num)
		{
			right=mid-1;
		}
		else{
			return mid;
		}
	}
	return -1;
}

int main() {
	int num;
	int myarr[10];
	int *p;
	int size;
	int output;
	cout<<"enter array size"<<endl;
	cin>>size;
	p= new int(size);
	cout<<"Enter numbers "<<endl;
	for(int i=0;i<size;i++)
	{
		cin>>p[i];
	}
	for (int i=0;i<size;i++)
	{
		int temp;
		for(int j=i+1;j<size;j++){
			if (p[j]<p[i]){
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
	cout<<"Enter number to search"<<endl;
	cin>>num;
	output=binarysearch(p,0,size-1,num);
	if(output==-1){
		cout<<"Match not found"<<endl;
	}
	 else{
	 	
	 }cout<<"Match found at index : "<<output<<endl;
	
	
		return 0;
}