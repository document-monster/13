#include <iostream>
#include <iomanip>
#include"linkedList.cpp"
using namespace std;

int main(int argc, char* argv[])
{
    linkedList<int> L1;
    int n;
    int val;
    //��ʼ������
    if (!L1.initiate())
        return 0;

    cin >> n;//�������������ݸ���
    for (int i = 0; i < n; i++) //����n����������������
    {
        cin >> val; 
        L1.insert(val);
    }
    cout << "Origin Length��" << L1.Length() << endl;//���������
    cout << "data��";
    L1.print();//��ӡ����

    cin >> n;//������Ҫɾ�������ݵ�λ��
    if (L1.remove(n, val))
    {
        //ɾ��λ��n�����ݣ�����ɾ��������ֵ����val��
        cout << "Delete the data at position(" << n << "):" << val << endl;
        cout << "New Length��" << L1.Length() << endl;//���������
        cout << "data��";
        L1.print();//��ӡ����
    }

    return 0;
}
