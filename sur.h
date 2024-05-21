#ifndef SUR_H
#define SUR_H
#include "hash.h"
#define BACKGROUND  0

const int LEFT = 50;
const int  TOP = 50;

using namespace std;

//坐标结构体
/*struct Position
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
};*/
//判断是否跨弧吃子结构体
struct Node
{
    int i;//行
	int j;//列
	int arc;//逆时钟有无弧
	int color;//颜色
};
class Sur
{
    public:
        Sur();
        void Init();  //初始化
        void Drawboard();//画棋盘
        bool Iswin(int board[6][6],int side);//判断输赢
        int IsGameOver(int position[6][6],int nDepth);//判断输赢，返回int值
        bool isLegal(int position[6][6],Position positionFrom, Position positionTo);//判断是否合法
        void PlayManToMan();
        void PlayComputerToMan();
        void PlayManToComputer();
        void Fupan();//复盘
        void FPDraw();//复盘用的画棋
        void Game();
        bool isInit();
        void More();//后手残局库
        void Fmore();//先手残局库
        int bn();//黑色棋子
    protected:
        int AlphaBeta(int depth,int alpha,int beta,int side);//alphaBeta搜索
        int AlphaBeta_Hash(int depth,int alpha,int beta,int side);//alphaBeta搜索
        int PVS(int depth,int alpha,int beta,int side);//PVS算法
        MovePosition SearchAGoodMove(int board[6][6],int depth,int side);
        vector<MovePosition> GenerateMovePosition(int side);//生产可下位置
        vector<MovePosition> GenerateMovePosition1(int side);//生产可下位置
        void displayCanMove(vector<MovePosition> vec);//显示可下位置，用于判断生产可下位置是否正确
        int FileDialog(char *path);//弹出文件框
        //估值函数
        int Value1(int board[6][6],int side);
        int Value2(int board[6][6],int side);
        int Value3(int board[6][6],int side);
        int Value4(int board[6][6],int side);
        int Value5(int board[6][6],int side);
        int Valuation(int board[6][6],int side);
    public:
        Hash hash;//创建Hash对象
        int m_HistoryTable[36][36];//历史估值
    protected:
        int GetHistoryScore(MovePosition move);//返回历史估值
        void EnterHistoryScore(MovePosition move,int depth);//存储历史估值
    private:
        int board[6][6]; //棋盘
        int side;          // 对手
        int count;  //次数
        int MaxDepth;//最大深度
        int c;
        //int m_nMoveCount;//队列数量
        //MovePosition m_nMoveList[8][100];
        Position positionFrom;//初始位置
        Position positionTo;//末位置
        MovePosition bestPosition;//最优位置

};

#endif // SUR_H
