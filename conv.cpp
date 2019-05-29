#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
此题目是参加网易面试的时候他们算法部门出的，写出卷积的实现。当时紧张，卷积的定义都忘了，没写出来，回家后
一个人就写出来了，哎，不多说了，上一下我的C++代码，这里主要注意越界问题。同时这是很普通的实现，有一种简单的方法，
时域的卷积，频域的乘积。不过c++写fft太麻烦，我这里给个matlab的例子：

close all; clc; clear all;

a=[2,4];
b=[1,8,3,7];

a=[a.';zeros(3,1)];
b=[b.';zeros(1,1)];

fa=fft(a);
fb=fft(b);

fc=fa.*fb;
c=ifft(fc);

*/
vector<int> conv(vector<int> &w,vector<int> &x){
	int T=x.size();
	int N=w.size();
	vector<int> result;
	x.resize(N+T-1);
	for(int i=0;i<T+N-1;i++){
		int tmp=0;
		for(int j=0;j<N;j++){
			tmp+=((i-j)>=0?x[i-j]:0)*w[j];
		}
		result.push_back(tmp);	
	}
	return result;
}

int main(){
	vector<int> s={2,4};
	vector<int> d={1,8,3,7};
	vector<int> result=conv(s,d);
	for(auto i:result){
		cout<<i<<endl;
	}
}


