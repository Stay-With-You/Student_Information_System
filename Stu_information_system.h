/**********************************************************************
 **                                                                    **
 **   广东工业大学 2019-2020 学年大一下学期春季 C++ 期末考核报告              **
 **                                                                    **
 **   撰写人：谭湘霖         学号：3119001607                             **
 **                                                                    **
 **   学院：自动化学院        专业班级：数据科学与大数据技术(2)班              **
 **                                                                    **
 **   完成日期：2020 年 7 月 3 日      编译环境：VS2019                    **
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
	char ID[20];                  // 学号
	char name[20];                // 姓名
	float subject_scores[3];     // 三门学科成绩
	struct student* next;  
}STU;

/**
 *  @name        : void link_print_single(STU* student);
 *  @description : 遍历单个学生节点内容
 *  @param       : 头结点 head
 */
void link_print_single(STU* student);

/**
 *  @name        : void link_print_all(STU* head);
 *  @description : 遍历链表内容
 *  @param       : 头结点 head
 */
void link_print_all(STU* head);

/**
 *  @name        : STU* link_pre_insert(STU* head, STU* newNode);
 *  @description : 往前插入链表
 *  @param       : 头结点 head；新节点 newNode
 */
STU* link_pre_insert(STU* head, STU* newNode);

/**
 *  @name        : STU* link_find_name(STU* head, char* name);
 *  @description : 按姓名查找链表
 *  @param       : 头结点 head；学生姓名 name
 */
STU* link_find_name(STU* head, char* name);

/**
 *  @name        : STU* link_find_name(STU* head, long long id);
 *  @description : 按姓名查找链表
 *  @param       : 头结点 head；学生学号 id
 */
STU* link_find_ID(STU* head, char* id);

/**
 *  @name        : STU* link_free(STU* head);
 *  @description : 销毁链表 (备用)
 *  @param       : 头结点 head
 */
STU* link_free(STU* head) 
{
	STU* temp;
	while (head != NULL) {
		temp = head->next;  // 用一个缓冲先保存起来，防止释放完上一个却找不到下一个节点
		free(head);
		head = temp;
	}
	return head;            // 其实是返回空
}

/**
 *  @name        : STU* link_delete(STU* head, char* name);
 *  @description : 按名字删除节点
 *  @param       : 头结点 head；学生姓名 name
 */
STU* link_delete(STU* head, char* name);

/**
 *  @name        : void swap(STU* student01, STU* student02);
 *  @description : 交换学生的信息内容
 *  @param       : 学生1 student01；学生2 student02；
 */
void swap(STU* student01, STU* student02);

/**
 *  @name        : STU* link_order(STU* head);
 *  @description : 对所有学生按平均分从高到低排序
 *  @param       : 头结点 head
 */
STU* link_order(STU* head);

/**
 *  @name        : int calAvgScores(STU* student);
 *  @description : 计算学生三门科目成绩的平均分
 *  @param       : 学生结点 student
 */
float calAvgScores(STU* student);

/**
 *  @name        : int countNode(STU* head);
 *  @description : 统计节点数
 *  @param       : 头结点 head
 */
int countNode(STU* head);

/**
 *  @name        : void print_help(void);
 *  @description : 打印操作提示列表
 *  @param       : None
 */
void print_help(void);

#endif // STU_INFORMATION_SYSTEM