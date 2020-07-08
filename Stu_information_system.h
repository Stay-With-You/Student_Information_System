/**********************************************************************
 **                                                                    **
 **   �㶫��ҵ��ѧ 2019-2020 ѧ���һ��ѧ�ڴ��� C++ ��ĩ���˱���              **
 **                                                                    **
 **   ׫д�ˣ�̷����         ѧ�ţ�3119001607                             **
 **                                                                    **
 **   ѧԺ���Զ���ѧԺ        רҵ�༶�����ݿ�ѧ������ݼ���(2)��              **
 **                                                                    **
 **   ������ڣ�2020 �� 7 �� 3 ��      ���뻷����VS2019                    **
 **                                                                    **
 **********************************************************************/
/**********************************************************************/
#ifndef STU_INFORMATION_SYSTEM
#define STU_INFORMATION_SYSTEM

/**************************************************************
 *               Student Information System                    *           
 **************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>

#include<string.h>
#include<malloc.h>
#include<iomanip>
#include<iostream>
using namespace std;

typedef struct student {
	char ID[20];                  // ѧ��
	char name[20];                // ����
	float subject_scores[3];     // ����ѧ�Ƴɼ�
	struct student* next;  
}STU;

/**
 *  @name        : void link_print_single(STU* student);
 *  @description : ��������ѧ���ڵ�����
 *  @param       : ͷ��� head
 */
void link_print_single(STU* student);

/**
 *  @name        : void link_print_all(STU* head);
 *  @description : ������������
 *  @param       : ͷ��� head
 */
void link_print_all(STU* head);

/**
 *  @name        : STU* link_pre_insert(STU* head, STU* newNode);
 *  @description : ��ǰ��������
 *  @param       : ͷ��� head���½ڵ� newNode
 */
STU* link_pre_insert(STU* head, STU* newNode);

/**
 *  @name        : STU* link_find_name(STU* head, char* name);
 *  @description : ��������������
 *  @param       : ͷ��� head��ѧ������ name
 */
STU* link_find_name(STU* head, char* name);

/**
 *  @name        : STU* link_find_name(STU* head, long long id);
 *  @description : ��������������
 *  @param       : ͷ��� head��ѧ��ѧ�� id
 */
STU* link_find_ID(STU* head, char* id);

/**
 *  @name        : STU* link_free(STU* head);
 *  @description : �������� (����)
 *  @param       : ͷ��� head
 */
STU* link_free(STU* head) 
{
	STU* temp;
	while (head != NULL) {
		temp = head->next;  // ��һ�������ȱ�����������ֹ�ͷ�����һ��ȴ�Ҳ�����һ���ڵ�
		free(head);
		head = temp;
	}
	return head;            // ��ʵ�Ƿ��ؿ�
}

/**
 *  @name        : STU* link_delete(STU* head, char* name);
 *  @description : ������ɾ���ڵ�
 *  @param       : ͷ��� head��ѧ������ name
 */
STU* link_delete(STU* head, char* name);

/**
 *  @name        : void swap(STU* student01, STU* student02);
 *  @description : ����ѧ������Ϣ����
 *  @param       : ѧ��1 student01��ѧ��2 student02��
 */
void swap(STU* student01, STU* student02);

/**
 *  @name        : STU* link_order(STU* head);
 *  @description : ������ѧ����ƽ���ִӸߵ�������
 *  @param       : ͷ��� head
 */
STU* link_order(STU* head);

/**
 *  @name        : int calAvgScores(STU* student);
 *  @description : ����ѧ�����ſ�Ŀ�ɼ���ƽ����
 *  @param       : ѧ����� student
 */
float calAvgScores(STU* student);

/**
 *  @name        : int countNode(STU* head);
 *  @description : ͳ�ƽڵ���
 *  @param       : ͷ��� head
 */
int countNode(STU* head);

/**
 *  @name        : void print_help(void);
 *  @description : ��ӡ������ʾ�б�
 *  @param       : None
 */
void print_help(void);

#endif // STU_INFORMATION_SYSTEM