#include<iostream>
#include<vector>
using namespace std;

//计数排序  参数（容器  容器中最大的元素  bool判断升序或降序）
void Countsort(vector<int>&v, int max , bool flag)
{
	//创建一个新的容器  容器初始为 MAX+1 个 0
	vector<int>temp(max + 1, 0);
	//遍历原容器  将原容器中的元素作为下标放进新容器中  新容器记录原容器中元素出现的次数
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		temp[*it]++;
	}
	int index = 0;//记录原容器下标
	if (!flag)//升序
	{
		//遍历新容器 
		for (int i = 0; i <= max; i++)
		{
			//将新容器中不为 0 的元素下标作为元素依次放进原容器中 并将新容器中的元素 -1
			while (temp[i] != 0)
			{
				v[index] = i;
				index++;
				temp[i]--;
			}
		}
	}
	else//降序
	{
		for (int i = max; i >=0 ; i--)
		{
			while (temp[i] != 0)
			{
				v[index] = i;
				index++;
				temp[i]--;
			}
		}
	}
}
int main()
{
	bool greater = false;//升序
	bool less = true;//降序
	vector<int>v = { 1,1,3,2,3,5,3 };//容器中的元素必须都是大于等于0的整数
	int MAX = 5;//容器中最大元素
	Countsort(v,MAX,greater);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}