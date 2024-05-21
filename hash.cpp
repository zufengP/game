#include "hash.h"

long long rand64()//可生成64位随机数的函数？
{
     return rand()^((long long)rand()<<15)^((long long)rand()<<30)^((long long)rand()<<45)^((long long)rand()<<60);
}

long long rand32()//可生成32位随机数的函数？
{
    long long a=rand()^((long long)rand()<<15)^((long long)rand()<<30);
    if(a<0)
    {
        a=-a;
    }
    return a;
}
Hash::Hash()
{
    InitializeHashKey();
}

Hash::~Hash()
{
    delete m_pTT[0];
    delete m_pTT[1];
}
void Hash::InitializeHashKey()
{
    int i,j,k;
	srand((unsigned)time(NULL));
	for(k=0;k<2;k++)
    {
        for(i=0;i<6;i++)
        {
            for(j=0;j<6;j++)
            {
                m_nHashKey32[k][i][j] = rand32();
                m_ulHashKey64[k][i][j] = rand64();
            }
        }
    }
    m_pTT[0]=new HashItem[1024*10240];
    m_pTT[1]=new HashItem[1024*10240];
}
//将所有棋子对应的随机哈希数加总
void Hash::CalculateInitHashKey(int CurPosition[6][6])
{
    int i,j,nChessType;
    m_HashKey32=0;
    m_HashKey64=0;
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            nChessType=CurPosition[i][j];
            if(nChessType!=0)//考察位置不是空
            {
                //黑方为0
                if(nChessType==1)
                {
                    nChessType=0;
                }
                else
                {
                    nChessType=1;
                }
                m_HashKey32=m_HashKey32^m_nHashKey32[nChessType][i][j];//将随机数与0做异或运算//0 <-> 1互相变化//加总
                m_HashKey64=m_HashKey64^m_ulHashKey64[nChessType][i][j];
            }
        }
    }
}
//哈希表中落子
void Hash::Hash_MakeMove(MovePosition move,int CurPosition[6][6],int type)
{
    if(type == 1)
    {
        type = 0;
    }
    else
    {
        type = 1;
    }
    //将要移动的棋子从中去除
    m_HashKey32 = m_HashKey32^m_nHashKey32[type][move.From.x][move.From.y];
    m_HashKey64 = m_HashKey64^m_ulHashKey64[type][move.From.x][move.From.y];

    int Totype;
    Totype=CurPosition[move.To.x][move.To.y];
    //目标位置有棋子也要去除
    if(Totype !=0)
    {
        if(Totype == 1)
        {
            Totype=0;
        }
        else
        {
            Totype=1;
        }
        m_HashKey32 = m_HashKey32^m_nHashKey32[Totype][move.To.x][move.To.y];
        m_HashKey64 = m_HashKey64^m_ulHashKey64[Totype][move.To.x][move.To.y];
    }
    //将移动的棋子在目标位置的随机数添入
    m_HashKey32 = m_HashKey32^m_nHashKey32[type][move.To.x][move.To.y];
    m_HashKey64 = m_HashKey64^m_ulHashKey64[type][move.To.x][move.To.y];
}
void Hash::Hash_UnMakeMove(MovePosition move,int CurPosition[6][6],int type)
{
    int ntype;
    ntype=CurPosition[move.To.x][move.To.y];
    if(ntype==1)
    {
        ntype=0;
    }
    else
    {
        ntype=1;
    }
    m_HashKey32=m_HashKey32^m_nHashKey32[ntype][move.From.x][move.From.y];
    m_HashKey64=m_HashKey64^m_ulHashKey64[ntype][move.From.x][move.From.y];
    m_HashKey32=m_HashKey32^m_nHashKey32[ntype][move.To.x][move.To.y];
    m_HashKey64=m_HashKey64^m_ulHashKey64[ntype][move.To.x][move.To.y];
    if(type!=0)
    {
        if(type==1)
        {
           type=0;
        }
        else
        {
            type=1;
        }
        m_HashKey32=m_HashKey32^m_nHashKey32[type][move.To.x][move.To.y];
        m_HashKey64=m_HashKey64^m_ulHashKey64[type][move.To.x][move.To.y];
    }
}
void Hash::EnterHashTable(enum ENTRY_TYPE entry_type,int eval,int depth,int TableNo)
{
    int x;
    HashItem pht;
    x=m_HashKey32 & 0xFFFFF;
    pht=m_pTT[TableNo][x];
    //将数据写入哈希表
    pht.checksum=m_HashKey64;
    pht.entry_type=entry_type;
    pht.eval=eval;
    pht.depth=depth;
}
int Hash::LookUpHashTable(int alpha,int beta,int depth,int TableNo)
{
    int x;
    HashItem pht;
    x=m_HashKey32 & 0xFFFFF;
    if(x <0)
    {
        x=-x;
    }
    pht=m_pTT[TableNo][x];
    if ((pht.depth>=depth) && (pht.checksum==m_HashKey64))
    {
        switch(pht.entry_type)
        {
            case 0:
                return pht.eval;
            case 1:
                if(pht.eval>=beta)
                {
                    return (pht.eval);
                }
                else
                {
                    break;
                }
			case 2:
                if(pht.eval<=alpha)
                {
                    return (pht.eval);
                }
                else
                {
                    break;
                }
        }
    }
    return 66666;//没有命中返回无效标志
}

