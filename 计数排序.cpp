#include<iostream>
#include<vector>
using namespace std;

//��������  ����������  ����������Ԫ��  bool�ж��������
void Countsort(vector<int>&v, int max , bool flag)
{
	//����һ���µ�����  ������ʼΪ MAX+1 �� 0
	vector<int>temp(max + 1, 0);
	//����ԭ����  ��ԭ�����е�Ԫ����Ϊ�±�Ž���������  ��������¼ԭ������Ԫ�س��ֵĴ���
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		temp[*it]++;
	}
	int index = 0;//��¼ԭ�����±�
	if (!flag)//����
	{
		//���������� 
		for (int i = 0; i <= max; i++)
		{
			//���������в�Ϊ 0 ��Ԫ���±���ΪԪ�����ηŽ�ԭ������ �����������е�Ԫ�� -1
			while (temp[i] != 0)
			{
				v[index] = i;
				index++;
				temp[i]--;
			}
		}
	}
	else//����
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
	bool greater = false;//����
	bool less = true;//����
	vector<int>v = { 1,1,3,2,3,5,3 };//�����е�Ԫ�ر��붼�Ǵ��ڵ���0������
	int MAX = 5;//���������Ԫ��
	Countsort(v,MAX,greater);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}