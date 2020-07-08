#include"Stu_information_system.h"

void link_print_single(STU* student) 
{
	cout << "该学生信息如下：\n";
	cout << "姓名：" << student->name << endl;
	cout << "学号：" << student->ID << endl;
	cout << "三门学科成绩：";
	for (int i = 0; i < 3; i++)
	{
		cout << student->subject_scores[i] << ' ';
	}cout << endl;
	cout << std::fixed << setprecision(2) << "三门学科平均分：" 
		 << calAvgScores(student) << endl;
}
void link_print_all(STU* head) 
{
	cout << "所有学生信息如下：\n";
	while (head != NULL) {
		link_print_single(head);
		head = head->next;
	}
}
STU* link_pre_insert(STU* head, STU* newNode)
{
	STU* temp = head;

	if (head == NULL) {                // 头节点不存在，那么申请的newNode即为头节点
		head = newNode;
		newNode->next = NULL;
	}                                   // 到这里只能处理一个节点
	else if (newNode != NULL) {
		while (temp->next != NULL)     // 先去遍历一遍找到最后的节点（找到就会退出这个循环）
			temp = temp->next;
		temp->next = newNode;          // 找到，插入新节点
		newNode->next = NULL;          // 对下一个节点进行初始化
	}
	return head;  
}
STU* link_find_name(STU* head, char* name) 
{
	while (head != NULL) {
		if (strcmp(head->name, name) == 0)
			break;
		head = head->next;
	}
	return head;  
}
STU* link_find_ID(STU* head, char* id) 
{
	while (head != NULL) {
		if (strcmp(head->ID, id) == 0)
			break;
		head = head->next;
	}
	return head;  
}
STU* link_delete(STU* head, char* name) 
{                                                 // 删除是依据查找函数来的
	STU* temp01 = head;                           // 先初始化，以防第一次就找到了要删除的东西
	STU* temp02 = head;                           // 因为要返回head，所以要防止head被改动
	while (temp02 != NULL) 
	{
		if (strcmp(temp02->name, name) == 0) 
		{   // 条件满足即相当于找到了要删除的目标
			if (temp02 == head)                   // 判断第一次进来是否就恰好匹配到！
				head = head->next;                // 若是则把头节点后移，因为第一个要被释放！
			// 这个判断假若只有一个节点也满足，因为一开始在主函数的初始化中,
			// 下一个节点是提前赋给 NULL 的,因此最后返回会返回空节点
			else 
				temp01->next = temp02->next;      // 把节点接到要删除的下一个！
			free(temp02);                          // 找到匹配的就释放掉！
			break;
		}
		// 匹配到就释放，匹配不到就执行下面的代码继续找
		temp01 = temp02;                           // head在往后走查找的时候，要先备份
		temp02 = temp02->next;                     // 把链接继续（节点往后）
	}   // 这一套下来是第一次没找到头节点的！
	
	return head;                                   // 找到之后就返回头节点
}
float calAvgScores(STU* student) 
{
	return (student->subject_scores[0] + student->subject_scores[1] + 
			student->subject_scores[2]) / 3;
}
void swap(STU* student01, STU* student02) 
{
	// 交换内容
	STU temp = *student01;
	*student01 = *student02;
	*student02 = temp;
	// 交换所属指针
	temp.next = student01->next;
	student01->next = student02->next;
	student02->next = temp.next;
}
STU* link_order(STU* head) 
{  
	STU* student01, * student02;
	student01 = head;

	while (student01->next != NULL) 
	{                                                                // 无法用for循环，因为我们这里只能操作指针
		student02 = student01->next;
		while (student02 != NULL) 
		{  
			if (calAvgScores(student01) < calAvgScores(student02))  // 按平均分排序
				swap(student01, student02);
			else if (calAvgScores(student01) == calAvgScores(student02)) 
			{                                                         // 比名字首字母排序
				if (*(student01->name) > * (student02->name))        // 比较名字第一个字母的ASSCI码值
					swap(student01, student02);
			}
			student02 = student02->next;  
		}
		student01 = student01->next;
	}
	return head;
}
int countNode(STU* head)
{
	int count = 0;
	if (head == NULL)
		return 0;
	while (head != NULL)
	{
		count++;
		head = head->next;
	}
	return count;
}
void print_help(void)
{
	cout << "************************************************\n";
	cout << "         欢迎来到简易版学生成绩管理系统\n";
	cout << "************************************************\n";
	cout << "            输入 0 插入学生信息\n";
	cout << "            输入 1 遍历学生信息\n";
	cout << "            输入 2 查找学生信息\n";
	cout << "            输入 3 删除学生信息\n";
	cout << "            输入 4 修改学生信息\n";
	cout << "            输入 5 导入学生信息\n";
	cout << "            输入 6 导出全部信息\n";
	cout << "            输入 7 学生综合信息排序\n";
	cout << "            输入 8 查看使用帮助\n";
	cout << "            输入 9 退出管理系统\n";
	cout << "************************************************\n";
}
int main( ) 
{  
	STU* newNode = NULL, * head = NULL;
	newNode = new STU[1]; 
	
	char name[20]; char id[20]; 
	float subject_scores[3];
	char file_name[256];                            // 文件路径
	int flag = 0, file_row = 0;

	print_help( );
	while (1)
	{
		cout << "进入初始操作界面，请输入操作码："; 
		int ops_01; cin >> ops_01;

		int s; char str[20];
		s = cin.rdstate( );
		while (s)               // 判断输入数据是否为 0 - 9
		{
			cin.clear( );
			cin >> str;
			cout << "操作码错误，请重新输入！\n" << endl;
			cout << "进入初始操作界面，请输入操作码：";
			cin >> ops_01;
			s = cin.rdstate( );
		}
		
		switch (ops_01)
		{
		case 0: // insert a student's information
		{
			newNode = (STU*)malloc(sizeof(STU));
			cout << "请输入学生姓名：" << endl;
			cin.ignore( );
			cin.getline(newNode->name, 20);
			cout << "请输入学生学号(勿输入空格)：" << endl;
			cin >> newNode->ID;
			cout << "请输入学生三门成绩：" << endl;
			for (int i = 0; i < 3; i++)
			{
				cout << "第" << i + 1 << "门科目：";
				cin >> newNode->subject_scores[i];
			}	cout << endl;
			head = link_pre_insert(head, newNode);
			break;
		}
		case 1:
		{
			if (head == NULL)
				cout << "无任何学生信息，请手动输入或外部导入\n" << endl;
			else
			{
				link_print_all(head);
				cout << "总共 " << countNode(head) << " 条信息\n" << endl;
			}
			break;
		}
		case 2:
		{
			if (countNode(head) == 0)
				cout << "无任何学生信息！\n" << endl;
			else
			{
				while (1)
				{
					cout << "进入信息查询界面，输入 1 按姓名查询，输入 2 按学号查询，输入其他数字退出本界面\n";
					int ops_02; cin >> ops_02;
					switch (ops_02)
					{
					case 1: {
						cout << "请输入要查找学生的姓名：\n";
						cin.ignore( );
						cin.getline(name, 20);
						STU* p = link_find_name(head, name);
						if (p != NULL)
						{
							link_print_single(head);
							cout << endl;
						}
						else
							cout << "查无此人!\n" << endl;
						break; }
					case 2: {
						cout << "请输入要查找学生的学号(勿输入空格)：\n"; cin >> id;
						STU* q = link_find_ID(head, id);
						if (q != NULL)
						{
							link_print_single(head);
							cout << endl;
						}
						else
							cout << "查无此人!\n" << endl;
						break; }
					}
					if (ops_02 != 1 && ops_02 != 2)
					{
						cout << "已退出查询界面！\n" << endl;
						break;
					}
				}
			}
			break;
		}
		case 3:
		{
			if (countNode(head) == 0)
				cout << "无任何学生信息！\n" << endl;
			else
			{
				cout << "请输入需要被删除对象的姓名：";
				cin.ignore( );
				cin.getline(name, 20);
				STU* p = link_find_name(head, name);
				if (p != NULL)
					link_print_single(head);
				else
					cout << "查无此人!\n" << endl;
				cout << "请确认是否删除该学生信息？输入 1 删除，输入 2 取消删除 (请勿输入其他数字或字母): ";
				int ops_03; cin >> ops_03;
				if (ops_03 == 1)
				{
					head = link_delete(head, name);
					cout << "\n该学生信息删除成功!\n" << endl;
				}
				else if (ops_03 != 1)
					cout << "删除失败!\n" << endl;
				// cout << "余下学生信息如下：\n";
				// link_print_all(head);
			}
			break;
		}
		case 4:
		{
			if (countNode(head) == 0)
				cout << "无任何学生信息！\n" << endl;
			else
			{
				cout << "进入学生信息修改界面，输入 1 以姓名查询方式修改，输入 2 以学号查询方式修改\n";
				int ops_04; cin >> ops_04;
				if (ops_04 == 1)
				{
					cout << "请输入要修改学生信息的姓名：\n";
					cin.ignore( );
					cin.getline(name, 20);
					STU* p = link_find_name(head, name);
					if (p != NULL)
					{
						link_print_single(head);
						cout << "输入 1 修改学号，输入 2 修改姓名，输入 3 修改三门科目成绩\n";
						cin >> ops_04;
						if (ops_04 == 1)
						{
							cout << "请输入修改后学号(勿输入空格)："; cin >> id;
							strcpy(p->ID, id);
							cout << "修改成功！\n" << endl;
							break;
						}
						else if (ops_04 == 2)
						{
							cout << "请输入修改后姓名：";
							cin.ignore( );
							cin.getline(name, 20);
							strcpy(p->name, name);
							cout << "修改成功！\n" << endl;
							break;
						}
						else if (ops_04 == 3)
						{
							cout << "请输入修改后三门科目成绩：\n";
							for (int i = 0; i < 3; i++)
							{
								cout << "第" << i + 1 << "门科目：";
								cin >> subject_scores[i];
							}cout << endl;
							for (int j = 0; j < 3; j++)
								p->subject_scores[j] = subject_scores[j];
							cout << "修改成功！\n" << endl;
							break;
						}
						else
						{
							cout << "未修改任何信息！\n" << endl;
							break;
						}
					}
					else
					{
						cout << "查无此人!\n" << endl;
						break;
					}
				}
				else if (ops_04 == 2)
				{
					cout << "请输入要修改学生信息的学号(勿输入空格)：\n"; cin >> id;
					STU* p = link_find_ID(head, id);
					if (p != NULL)
					{
						link_print_single(head);
						cout << endl;
						cout << "输入 1 修改学号，输入 2 修改姓名，输入 3 修改三门科目成绩\n";
						cin >> ops_04;
						if (ops_04 == 1)
						{
							cout << "请输入修改后学号(勿输入空格)："; cin >> id;
							strcpy(p->ID, id);
							cout << "修改成功！\n" << endl;
							break;
						}
						else if (ops_04 == 2)
						{
							cout << "请输入修改后姓名：";
							cin.ignore( );
							cin.getline(name, 20);
							strcpy(p->name, name);
							cout << "修改成功！\n" << endl;
							break;
						}
						else if (ops_04 == 3)
						{
							cout << "请输入修改后三门科目成绩：\n";
							for (int i = 0; i < 3; i++)
							{
								cout << "第" << i + 1 << "门科目：";
								cin >> subject_scores[i];
							}cout << endl;
							for (int j = 0; j < 3; j++)
								p->subject_scores[j] = subject_scores[j];
							cout << "修改成功！\n" << endl;
							break;
						}
						else
						{
							cout << "未修改任何信息！\n" << endl;
							break;
						}
					}
					else
					{
						cout << "查无此人!\n" << endl;
						break;
					}
				}
			}
			break;
		}
		case 5:
		{
			cout << "WARNING: 外部导入的文件内容格式须严格遵守(每行)：姓名 + 学号 + 三门科目成绩\n";
			cout << "请在下面输入所导入信息文件的绝对路径 (无须加上双引号,并以 / 分割文件夹名称)：\n";
			cin.ignore( );
			cin.getline(file_name, 256);
			FILE* fp1 = fopen(file_name, "r+");
			if (!fp1)
			{
				cout << "读取失败！\n" << endl;
				break;
			}
			else cout << "读取成功！\n" << endl;

			while (!feof(fp1))
			{
				flag = fgetc(fp1);
				if (flag == '\n')
					file_row++;
			}
			fseek(fp1, 0, SEEK_SET);        // 把文件光标退回初始位置

			for (int i = 0; i < file_row; i++)
			{
				newNode = (STU*)malloc(sizeof(STU));
				fscanf(fp1, "%s%s%f%f%f", newNode->name,
						newNode->ID, &newNode->subject_scores[0],
						&newNode->subject_scores[1], &newNode->subject_scores[2]);
				head = link_pre_insert(head, newNode);
			}
			fclose(fp1);

			cout << "数据读取完成,请遍历链表查询全体学生信息！\n" << endl;
			break;
		}
		case 6:
		{
			if (countNode(head) == 0)
				cout << "无任何可导出数据！\n" << endl;
			else
			{
				cout << "请在下面输入导出路径：(无须加上双引号,并以 / 分割文件夹名称)\n";
				cin.ignore( );
				cin.getline(file_name, 256);
				FILE* fp2 = fopen(file_name, "w+");
				if (!fp2)
				{
					cout << "创建文件夹失败！\n";
					break;
				}
				else cout << "创建成功！准备导出数据！\n···\n";

				if (countNode(head) == 0)
					cout << "无任何数据可导出！\n" << endl;
				else
				{
					int i = 0; STU* temp = head;
					fprintf(fp2, "全部学生信息如下：\n");
					while (i < countNode(head))
					{
						fprintf(fp2, "%s %s %.2f %.2f %.2f\n", temp->name,
								temp->ID, &temp->subject_scores[0],
								&temp->subject_scores[1], &temp->subject_scores[2]);
						temp = temp->next;
						i++;
					}
					fprintf(fp2, "共 %d 条信息！\n", i);
					cout << "Tips: 已导出的文件请删去第一行和最后一行后再导入！否则将发生错误读取！\n" << endl;
					cout << "数据导出完成！\n";
				}

				fclose(fp2);
			}
			break;
		}
		case 7:
			if (countNode(head) == 0)
				cout << "无任何学生信息！\n" << endl;
			else
			{
				head = link_order(head);
				cout << "排序成功！请再次遍历查询所有学生信息！\n" << endl;
			}
			break;
		case 8:
			cout << endl;
			print_help( );
			break;
		case 9:
			cout << "已退出学生信息管理系统！";
			return 0;
			break;
		}
	}
}









