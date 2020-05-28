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
    int count;    //表示链表中的元素的数量
    LList* head;     //指向链表头的指针
public:
    linkedList()     //构造函数构造头节点
    {
        LList* p = new struct node;
        p->data = NULL;
        p->next = NULL;
        head = p;
        count = 0;
    }
    ~linkedList()    //析构函数释放所有节点
    {
        LList* p;
        while (head)
        {
            p = head;
            head = head->next;
            free(p);
        }
    }
    bool initiate()    //判断链表是否创建
    {
        if (head != NULL)
            return true;
        else
            return false;
    }
    void insert(int val);    //向链表中插入一个整数 val
    int Length()     //返回链表长度
    {
        return count;
    }
    void print()    //按顺序输出链表中的date
    {
        LList* p = head->next;
        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    bool remove(int n, int& val)    //移除链表中的第n节
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
