#define _CRT_SECURE_NO_WARNINGS     //��scanf��printf������
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

typedef int ElemType;//����int���͵�ElemtType
typedef struct LNode//��������
{
    ElemType data;
    struct LNode* next;
} LNode, * LinkedList;
typedef enum Status//���� ö�����ͣ�ʹstatus���ͷ���ֵΪerroe��succcess�����Ʋ���
{
    error,
    success
} Status;

//����������
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

Status InitList(LinkedList* L)//��������
{   
    int i = 0;
    int n = 1; 
    LinkedList list1,list2; 
    list2=list1 = (LinkedList)malloc(sizeof(LNode));
    printf("***��ֹ�����������ڲ��ǵ�һ���ݴ�����0***\n");

    list1->data = 1;
    while (n!=0)
    {
        i = i + 1;
    if (list1 == NULL&&list2 == NULL)
    {
        printf("�ڴ����ʧ��\n");
        return error;//ʹ��status���ͷ���ֵ
    }
    if (i == 1)
        *L = list1;
    else list2->next = list1;
        list2 = list1;
        printf("��������������:\n");
    list1 = (LinkedList)malloc(sizeof(LNode));
    scanf("%d", &list1->data);
    n = list1->data; 
    }
    list2->next = NULL;


   

    return success;
}

void DestroyList(LinkedList* L) //��������
{
    LinkedList temp;

    while (*L != NULL)
    {
        temp = *L;
        *L = (*L)->next;
        free(temp);
    }
}
Status InsertList(LNode* p, ElemType data)//������
{
    LinkedList current = p;
    LinkedList newNode = (LinkedList)malloc(sizeof(LNode));

    if (newNode == NULL)
    {
        printf("�ڴ����ʧ��\n");
        return error;
    }
    newNode->data = data;
    newNode->next = NULL;
    if (current == NULL)
        current = newNode;
    if (current->next == NULL)//�������ֻ��һ���ڵ㣬��ֱ�ӽ��½ڵ���뵽ͷ�ڵ��
    {
        current->next = newNode;
        return success;
    }
    while (current->next->next != NULL)
    {
        current = current->next;
    }
    newNode->next=current->next; //���½ڵ�ӵ�����ͬʱʹ�½ڵ�ָ�����һ���ڵ�
  current->next = newNode;   
 
        return success;
}

Status DeleteList(LNode* p, ElemType e) //ɾ�����
{
    if (p == NULL)
    {
        printf("������Ϊ�գ��޷�ɾ��\n");
        return error;
    }
    LinkedList posNode = p->next;
    LinkedList posNodeFront = p;
    if (posNode == NULL)
    {
        printf("����Ϊ�գ��޷�ɾ��\n");
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
                printf("û�и�����\n");
                return error;
            }
        }
        posNodeFront->next = posNode->next;
        free(posNode);
        return success;
    }
}

void TraverseList(LinkedList L)//��������
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

Status SearchList(LinkedList L, ElemType e) //.��������
{
    int n = 0;
    while (L != NULL)
    {
        if (L->data == e)
        { 
            printf("���ڴ����ݣ��ڵ�%d���ڵ���",n);
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

Status ReverseList(LinkedList* L) //��ת����
{
    LNode* newHead;  //����ÿ�η�ת��ĵ�һ���ڵ� 
    LNode* p1;   //ÿ�ζ�ָ��ǰһ���ڵ� 
    LNode* p2;   // ����δ��תǰ����һ���ڵ� 
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

Status FindMidNode(LinkedList L) //�����м���
{
    if (L == NULL)
    {
        printf("������Ϊ�գ��޷�ɾ��\n");
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
    printf("�м�ڵ�Ϊ%d,��λ�ڵ�%d�ڵ�", slow->data, n);
    return success;
}

Status IsLoopList(LinkedList L) //�ж������Ƿ�ɻ�
{
    LinkedList fast = L, slow = L;
    while (fast->next != NULL && slow->next != NULL)
    {
        slow = slow->next;
        if ((fast = fast->next->next) == NULL)
        {         printf("�������ɻ�");
            return error;

        }
   
        if (fast == slow)
        {
            printf("������ɻ�");
            return success;
        }

    }
    printf("�������ɻ�");
    return error;
}

void show(void)
{
    printf("\n\n\n\n������ADT\n\n");
    printf("1.����������������\n");
    printf("2.��������\n");
    printf("3.������\n");
    printf("4.ɾ�����\n");
    printf("5.��������\n");
    printf("6.��������\n");
    printf("7.��ת����\n");
    printf("8.�ж������Ƿ�ɻ�\n");
    printf("9.��ת�����е�ż�����/�޴˹���\n");
    printf("10.�����м���\n");
    printf("11.�˳�\n");
    printf("\n�������Ӧ������(1-11)��");
}

int judge_int(void)  //��ֹ�û��������������ַ�
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
            if (word[m] < '0' || word[m]>'9')  //�����Ƿ��������������ַ�
            {
                printf("������������");
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
    for (m = 0; m < len; m++)  // ���ַ�����ת��Ϊ����
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
 printf("���ȴ�������д������");
 continue;
        }
           
        switch (choice)
        {
        case 1://��������
        {
            if (InitList(&head))
            {
                printf("�������ɹ�\n");
            }
            else
            {
                printf("������ʧ��\n");
            }
        }
        break;

        case 2:  DestroyList(&head);             printf("��������ɹ�\n");  break;//printf("2.��������\n");
        case 3: printf("�������½ڵ�����");
            scanf("%d", &data);
            scanf("%*c");
            if (InsertList(p, data))
            {
                printf("����ڵ�ɹ�\n");
            }
            else
            {
                printf("����ڵ�ʧ��\n");
            };
            break;//printf("3.������\n");
        case 4: printf("������ɾ���ڵ�����");  scanf("%d", &e);             if (DeleteList(p, e))
        {
            printf("ɾ���ڵ�ɹ�\n");
        }
              else
        {
            printf("ɾ���ڵ�ʧ��\n");
        }; break;//printf("4.ɾ�����\n");
        case 5: printf(""); TraverseList(head); break;//printf("5.��������\n");
        case 6: printf("��������ҽڵ������"); scanf("%d", &e); SearchList(head, e); break;//printf("6.��������\n");
        case 7:  ReverseList(&head); printf("��ת�������Ϊ");TraverseList(head);  break;//printf("7.��ת����\n");
        case 8:printf(""); IsLoopList(head); break;//printf("8.�ж������Ƿ�ɻ�\n");
        case 9: break;//printf("9.��ת�����е�ż�����/�޴˹���\n");
        case 10: FindMidNode(head);
        break;//printf("10.�����м���\n");
        case 11:break;//printf("11.�˳�\n");
        default:  printf("���ֳ���1~12��Χ"); break;
        }
        if (choice== 11)
            break;
    }
    //����ѭ����ʹ�����ܽ��ж�β���
    return 0;
}  











