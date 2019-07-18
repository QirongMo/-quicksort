#include<iostream>
#include<vector>
using namespace std;

template <typename Comparable>

// ������ֵ�� 
const Comparable& median3(vector<Comparable>& a, int left, int right)
{
	Comparable pivot;
	int mid = (left + right) / 2;
	Comparable l=a[left], m=a[mid], r=a[right];
	if (((m <= l) && (l <= r)) || ((r <=l) && (l <= m)))
		pivot= l;
		
	else if ((m >= l && m <= r) || (m <=l && m >=r)) {
		pivot = m;
		std::swap(a[mid], a[left]);
	}
	
	else if (((m >= r) && (r >= l)) || ((r <= l) && (r >= m))) {
		pivot=r;
		std::swap(a[right], a[left]);
	}
	
	return pivot;
}

template <typename Comparable>
void quicksort(vector<Comparable>& a, int left, int right){
	if ((left + 2) <= right){  //Ԫ�ظ�������3������������ֵ�� 
		const Comparable pivot = median3(a, left, right);
		int i = left + 1, j = right;
		
		for (; ; ){
			while (a[i] < pivot) { i++; }
			while (pivot < a[j]) { j--; }
			if (i < j)
				std::swap(a[i], a[j]);
			else
				break;
		}
		
		std::swap(a[j], a[left]);  // ��׼Ԫ��λ 
		if (left <= (j - 1))
			quicksort(a, left, j - 1);     // �Ի�׼Ԫ��ߵ�Ԫ�ؽ��п������� 
		if ((j + 1) <= right)
			quicksort(a, j + 1, right);    // �Ի�׼Ԫ�ұߵ�Ԫ�ؽ��п������� 
	}

	else if ((right - left) == 1) {  //Ԫ�ظ���ֻ��2����ֱ�ӱȽ� 
		if (a[left] > a[right])
			std::swap(a[left], a[right]);
		else return;
	}
	
	else return;  //Ԫ�ظ���ֻ��һ����ֱ�ӷ��� 

}

template <typename Comparable>
void quicksort(vector<Comparable>& a){
	quicksort(a, 0, a.size() - 1);
}

int main(){

	vector<int>a = {1, 5, 6, 8, 3, 2, 9, 7, 4, 1};
	
    cout<<"δ����ʱ������Ϊ��";
	for (int i = 0; i < (a.size()); i++)
		cout << a[i] << "  ";
	cout << endl;
	
	quicksort(a);
	
	cout<<"����������Ϊ��"; 
	for (int i = 0; i < a.size() ; i++)
		cout << a[i] << "  ";
	cout << endl;
	
	return 0;


}

