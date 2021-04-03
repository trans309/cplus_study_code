#include "STL.h"
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <ctime>


class player
{
public:

    string name;
    int score;

    player(string i_name)
    {
        this->name=i_name;
        this->score=0;
    }
};

//创建选手
void creat_p(vector<player>& vp)
{

    string nameseed="ABCDE";
    for(int i=0;i<5;i++)
    {
        //初始化选手名字
        string name="选手";
        name+=nameseed[i];

        //创建选手
        player pp(name);

        //存入vector容器
        vp.push_back(pp);
    }
}

//设置分数
void set_s(vector<player>& vp)
{
    //设置随机种子
    srand((unsigned int)time(NULL));

    //设置数据
    for(vector<player>::iterator it=vp.begin();it<vp.end();it++)
    {
        deque<int>score;
        for(int i=0;i<10;i++)
        {
            score.push_back(rand()%41+60);
        }

//        //测试打印(未删未排序)
//        for(unsigned int a=0;a<score.size();a++)
//        {
//            cout<<score[a]<<" ";
//        }
//        cout<<endl;

        sort(score.begin(),score.end());

        score.pop_front();
        score.pop_back();

//        //测试打印（已删已排序）
//        for(unsigned int b=0;b<score.size();b++)
//        {
//            cout<<score[b]<<" ";
//        }
//        cout<<endl;

        int sum=0;
        for(unsigned int c=0;c<score.size();c++)
        {
            sum+=score[c];
        }

        it->score=sum/score.size();
    }


}

//打印
void print_s(vector<player>& vp)
{
    for(vector<player>::iterator s=vp.begin();s<vp.end();s++)
    {
        cout<<"姓名:"<<s->name<<"\t得分:"<<s->score<<endl;
    }
}

void test2()
{
    vector<player>vp;

    creat_p(vp);
    set_s(vp);
    print_s(vp);
}
