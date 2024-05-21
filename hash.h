#ifndef HASH_H
#define HASH_H
#include<iostream>
#include<vector>
#include<fstream>
#include<winbgim.h>
#include<stack>
#include<time.h>
#include <Commdlg.h>
#include<cstdio>
enum ENTRY_TYPE{exact,lower,upper};

struct Position
{
    int x;
    int y;
    int k;//记录是否吃子
};
//起始和末位置坐标结构体
struct MovePosition
{
    Position From;
    Position To;
    int Score;//得分
};
struct HashItem{
    long long checksum;//64位校验码
	ENTRY_TYPE entry_type;	//数据类型
	int depth;	//取得此值时的层次
	int eval;	//节点的值
};
class Hash
{
    public:
	Hash();
	virtual ~Hash();
	void CalculateInitHashKey(int CurPosition[6][6]);//计算给定棋盘的哈希值
    void Hash_MakeMove(MovePosition move,int CurPosition[6][6],int type);//根据走法增量生成新的哈希值
    void Hash_UnMakeMove(MovePosition move,int CurPosition[6][6],int type);	//撤销走法的哈希值
	int LookUpHashTable(int alpha,int beta,int depth,int TableNo);	//查找哈希表当前节点数据
	void EnterHashTable(enum ENTRY_TYPE entry_type,int eval,int depth,int TableNo);	//将当前节点值录入哈希表

	void InitializeHashKey();	//初始化随机数组

	unsigned long long m_nHashKey32[2][6][6]; //32位随机数组，用以生成32位哈希值
	unsigned long long m_ulHashKey64[2][6][6];//64位随机数组，用以生成64位哈希值
	HashItem *m_pTT[2];	//置换表头指针
	unsigned long long m_HashKey32;	//32位哈希值
	unsigned long long m_HashKey64;	//64位哈希值
};

#endif // HASH_H
