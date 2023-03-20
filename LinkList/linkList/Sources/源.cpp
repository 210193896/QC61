#define _CRT_SECURE_NO_WARNINGS     //令scanf，printf不报错
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

typedef int ElemType;//定义int类型的ElemtType
typedef struct LNode//定义链表
{
    ElemType data;
    struct LNode* next;
} LNode, * LinkedList;
typedef enum Status//定义 枚举类型，使status类型返回值为erroe或succcess，类似布尔
{
    error,
    success
} Status;

//函数的声明
Status InitList(LinkedList* L);
void DestroyList(LinkedList* L); 
Status InsertList(LNode* p, ElemType data);
Status DeleteList(LNode* p, ElemType e);
void TraverseList(LinkedList L);
Status SearchList(LinkedList L, ElemType e);
Status ReverseList(LinkedList* L);
Status IsLoopList(LinkedList L);
Status FindMidNode(LinkedList L);
void show(void);
int judge_int(void);

Status InitList(LinkedList* L)//建立链表
{   
    int i = 0;
    int n = 1; 
    LinkedList list1,list2; 
    list2=list1 = (LinkedList)malloc(sizeof(LNode));
    printf("***终止数据输入请在不是第一数据处输入0***\n");

    list1->data = 1;
    while (n!=0)
    {
        i = i + 1;
    if (list1 == NULL&&list2 == NULL)
    {
        printf("内存分配失败\n");
        return error;//使用status类型返回值
    }
    if (i == 1)
        *L = list1;
    else list2->next = list1;
        list2 = list1;
        printf("请输入链表数据:\n");
    list1 = (LinkedList)malloc(sizeof(LNode));
    scanf("%d", &list1->data);
    n = list1->data; 
    }
    list2->next = NULL;


   

    return success;
}

void DestroyList(LinkedList* L) //销毁链表
{
    LinkedList temp;

    while (*L != NULL)
    {
        temp = *L;
        *L = (*L)->next;
        free(temp);
    }
}
Status InsertList(LNode* p, ElemType data)//插入结点
{
    LinkedList current = p;
    LinkedList newNode = (LinkedList)malloc(sizeof(LNode));

    if (newNode == NULL)
    {
        printf("内存分配失败\n");
        return error;
    }
    newNode->data = data;
    newNode->next = NULL;
    if (current == NULL)
        current = newNode;
    if (current->next == NULL)//如果链表只有一个节点，则直接将新节点加入到头节点后
    {
        current->next = newNode;
        return success;
    }
    while (current->next->next != NULL)
    {
        current = current->next;
    }
    newNode->next=current->next; //将新节点加到链表，同时使新节点指向最后一个节点
  current->next = newNode;   
 
        return success;
}

Status DeleteList(LNode* p, ElemType e) //删除结点
{
    if (p == NULL)
    {
        printf("链表首为空，无法删除\n");
        return error;
    }
    LinkedList posNode = p->next;
    LinkedList posNodeFront = p;
    if (posNode == NULL)
    {
        printf("链表为空，无法删除\n");
        return error;
    }
    else
    {
        while (posNode->data != e)
        {
            posNodeFront = posNode;
            posNode = posNode->next;
            if (posNode == NULL)
            {
                printf("没有该数据\n");
                return error;
            }
        }
        posNodeFront->next = posNode->next;
        free(posNode);
        return success;
    }
}

void TraverseList(LinkedList L)//遍历链表
{
    LinkedList temp;

    temp = L->next;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Status SearchList(LinkedList L, ElemType e) //.查找数据
{
    int n = 0;
    while (L != NULL)
    {
        if (L->data == e)
        { 
            printf("存在此数据，在第%d个节点上",n);
            return success;
           
        }
        L = L->next;
        n = n + 1;
    }
    return error;
}

/*
void ReverseList(LinkedList L) {
    LinkedList current, next, pre;
    current = L->next;
    pre = NULL;
    while(current != NULL)
    {
        next = current->next;
        current->next = pre;
        pre = current;
        current = next;
    }
    L->next = pre;
}
*/

Status ReverseList(LinkedList* L) //反转链表
{
    LNode* newHead;  //储存每次反转后的第一个节点 
    LNode* p1;   //每次都指向前一个节点 
    LNode* p2;   // 储存未反转前的下一个节点 
    p1 = (*L)->next;
    p2 = p1->next;
    p1->next = NULL;
    newHead = p1;
    while (p2 != NULL) {
        p1 = p2;
        p2 = p1->next;
        p1->next = newHead;
        newHead = p1;
    }
    (*L)->next = newHead;
    return success;
}

Status FindMidNode(LinkedList L) //查找中间结点
{
    if (L == NULL)
    {
        printf("链表首为空，无法删除\n");
        return error;
    }
    int n = 0;
    LinkedList slow = L, fast = L;
    while (fast != NULL && slow != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        n = n + 1;
    }
    printf("中间节点为%d,且位于第%d节点", slow->data, n);
    return success;
}

Status IsLoopList(LinkedList L) //判断链表是否成环
{
    LinkedList fast = L, slow = L;
    while (fast->next != NULL && slow->next != NULL)
    {
        slow = slow->next;
        if ((fast = fast->next->next) == NULL)
        {         printf("该链表不成环");
            return error;

        }
   
        if (fast == slow)
        {
            printf("该链表成环");
            return success;
        }

    }
    printf("该链表不成环");
    return error;
}

void show(void)
{
    printf("\n\n\n\n单链表ADT\n\n");
    printf("1.创建链表并输入数据\n");
    printf("2.销毁链表\n");
    printf("3.插入结点\n");
    printf("4.删除结点\n");
    printf("5.遍历链表\n");
    printf("6.查找数据\n");
    printf("7.反转链表\n");
    printf("8.判断链表是否成环\n");
    printf("9.反转链表中的偶数结点/无此功能\n");
    printf("10.查找中间结点\n");
    printf("11.退出\n");
    printf("\n请输入对应的数字(1-11)：");
}

int judge_int(void)  //防止用户乱输入其他的字符
{
    int len, num = 0, arg = 1;
    char word[10];
    int m, j = 1, k;
    while (j)
    {
        scanf("%s", word);
        word[9] = '0';
        len = strlen(word);
        for (m = 0; m < len; m++)
        {
            if (word[m] < '0' || word[m]>'9')  //检验是否有乱输入其他字符
            {
                printf("请输入整数：");
                break;
            }
            else
            {
                if (m == len - 1)
                    j = 0;
            }
        }
    }

    j = len - 1;
    for (m = 0; m < len; m++)  // 将字符重新转换为数字
    {
        for (k = 0; k < j; k++)
            arg *= 10;
        num += (word[m] - '0') * arg;
        arg = 1;
        j--;
    }
    return num;
}

int main(void)
{
    int choice, num = 0;
    LinkedList head=NULL;
    LNode* p=  head;
    ElemType e=0,data=0;

    for (int i=0;;i++)
    {
        p = head;
        show();
        choice = judge_int();
        system("cls");
        if (i == 0 && choice != 1&&choice!=3&&choice!=11)
        {
 printf("请先创建链表并写入数据");
 continue;
        }
           
        switch (choice)
        {
        case 1://创建链表
        {
            if (InitList(&head))
            {
                printf("链表创建成功\n");
            }
            else
            {
                printf("链表创建失败\n");
            }
        }
        break;

        case 2:  DestroyList(&head);             printf("销毁链表成功\n");  break;//printf("2.销毁链表\n");
        case 3: printf("请输入新节点数据");
            scanf("%d", &data);
            scanf("%*c");
            if (InsertList(p, data))
            {
                printf("插入节点成功\n");
            }
            else
            {
                printf("插入节点失败\n");
            };
            break;//printf("3.插入结点\n");
        case 4: printf("请输入删除节点数据");  scanf("%d", &e);             if (DeleteList(p, e))
        {
            printf("删除节点成功\n");
        }
              else
        {
            printf("删除节点失败\n");
        }; break;//printf("4.删除结点\n");
        case 5: printf(""); TraverseList(head); break;//printf("5.遍历链表\n");
        case 6: printf("请输入查找节点的数据"); scanf("%d", &e); SearchList(head, e); break;//printf("6.查找数据\n");
        case 7:  ReverseList(&head); printf("反转后的链表为");TraverseList(head);  break;//printf("7.反转链表\n");
        case 8:printf(""); IsLoopList(head); break;//printf("8.判断链表是否成环\n");
        case 9: break;//printf("9.反转链表中的偶数结点/无此功能\n");
        case 10: FindMidNode(head);
        break;//printf("10.查找中间结点\n");
        case 11:break;//printf("11.退出\n");
        default:  printf("数字超出1~12范围"); break;
        }
        if (choice== 11)
            break;
    }
    //构成循环，使链表能进行多次操作
    return 0;
}  











