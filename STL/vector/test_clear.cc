#include <iostream>
#include <vector>

using namespace std;
int main() {
    vector<int> a;
    cout << a.size() << " " << a.capacity() << endl;
    cout << a.empty() << endl;  //输出   1  代表该vector此时是空
    a.push_back(1);
    a.push_back(2);
    cout << a[0] << " " << a[1] << endl;  //输出1 2
    cout << a.empty() << endl;            //输出 0 代表该vector此时非空
    cout << a.size() << endl;             //输出2
    cout << a.capacity() << endl;         //输出2
    cout << "***************" << endl;

    // a[0]=NULL;a[1]=NULL; 这是赋值为0，并不清空数据，也不释放内存。
    a.clear();
    cout << a.size() << " " << a.capacity() << endl;
    // 仍然输出1 2，因为没有释放内存，所以输出该地址的内容仍然与之前一样
    cout << a[0] << " " << a[1] << endl;
    cout << a.empty() << endl;  //输出1  代表该vector此时已经为空
    //输出0，代表当前容器内存储元素个数是0，与.empty()类似，都告诉我们当前容器是空的意思
    cout << a.size() << endl;
    //输出2，代表当前该vector在重新分配存储空间前所能容纳的元素数量并没有改变
    cout << a.capacity() << endl;
    cout << "*************************" << endl;

    /*
    下面这五行说明，.pop_back()与.clear()起到了相同的作用，都是清空数据，但是没有释放内存
    while(!a.empty()){
        a.pop_back();
    }
    cout<<a.empty()<<endl;//输出 1 代表该vector此时已经为空
    cout<<a[0]<<" "<<a[1]<<endl;//仍然输出为 1 2
    因为没有释放内存，所以输出该地址的内容仍然与之前一样
    */
    a.push_back(4);
    a.push_back(4);
    cout << a.size() << " " << a.capacity() << endl;
    cout << a[0] << " " << a[1] << " " << a[2] << endl;

    vector<int>().swap(a);
    cout << a.size() << " " << a.capacity() << endl;
}