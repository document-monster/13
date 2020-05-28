#include<iostream>
#include "linkedList.h"
using namespace std;
typedef struct node
{
    int data;
    node* next;
} LList, * PList;
template <typename T>
class linkedList
{
private:
    int count;    //��ʾ�����е�Ԫ�ص�����
    LList* head;     //ָ������ͷ��ָ��
public:
    linkedList()     //���캯������ͷ�ڵ�
    {
        LList* p = new struct node;
        p->data = NULL;
        p->next = NULL;
        head = p;
        count = 0;
    }
    ~linkedList()    //���������ͷ����нڵ�
    {
        LList* p;
        while (head)
        {
            p = head;
            head = head->next;
            free(p);
        }
    }
    bool initiate()    //�ж������Ƿ񴴽�
    {
        if (head != NULL)
            return true;
        else
            return false;
    }
    void insert(int val);    //�������в���һ������ val
    int Length()     //����������
    {
        return count;
    }
    void print()    //��˳����������е�date
    {
        LList* p = head->next;
        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    bool remove(int n, int& val)    //�Ƴ������еĵ�n��
    {
        if (n > count)
        {
            cout << "pos > len,failed" << endl;
            return false;
        }
        else
            if (n <= 0)
            {
                cout << "pos <= 0, failed" << endl;
                return false;
            }
        int i;
        LList* p = head;
        LList* q = head->next;
        for (i = 0;;i++)
        {
            if (i == n - 1)
            {
                val = q->data;
                count--;
                p->next = q->next;
                free(q);
                break;
            }
            else
            {
                p = p->next;q = q->next;
            }

        }
        return true;
    }
};
template <typename T>
void linkedList<T>::insert(int val)
{
    LList* p = new struct node;
    p->data = val;
    p->next = NULL;
    LList* q = head;
    while (q->next)
    {
        q = q->next;
    }
    q->next = p;
    count++;
}
