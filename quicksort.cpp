#include<iostream>
#include<vector>
using namespace std;

template <typename Comparable>

// 三数中值法 
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
	if ((left + 2) <= right){  //元素个数大于3个采用三数中值法 
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
		
		std::swap(a[j], a[left]);  // 基准元归位 
		if (left <= (j - 1))
			quicksort(a, left, j - 1);     // 对基准元左边的元素进行快速排序 
		if ((j + 1) <= right)
			quicksort(a, j + 1, right);    // 对基准元右边的元素进行快速排序 
	}

	else if ((right - left) == 1) {  //元素个数只有2个，直接比较 
		if (a[left] > a[right])
			std::swap(a[left], a[right]);
		else return;
	}
	
	else return;  //元素个数只有一个，直接返回 

}

template <typename Comparable>
void quicksort(vector<Comparable>& a){
	quicksort(a, 0, a.size() - 1);
}

int main(){

	vector<int>a = {1, 5, 6, 8, 3, 2, 9, 7, 4, 1};
	
    cout<<"未排序时的序列为：";
	for (int i = 0; i < (a.size()); i++)
		cout << a[i] << "  ";
	cout << endl;
	
	quicksort(a);
	
	cout<<"排序后的序列为："; 
	for (int i = 0; i < a.size() ; i++)
		cout << a[i] << "  ";
	cout << endl;
	
	return 0;


}

