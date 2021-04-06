#include <iostream>

using namespace std;

#include "System base.h"
#include "cstdlib"
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <deque>
#include <numeric>
#include <fstream>

#define filename "previous.csv"

void system_base::menu()
{
    cout<<"|----------------------------|"<<endl
        <<"|    欢迎使用演讲比赛系统    |"<<endl
        <<"|----------------------------|"<<endl
        <<"|                            |"<<endl
        <<"|      1、 开始演讲比赛      |"<<endl
        <<"|      2、 查看往届记录      |"<<endl
        <<"|      3、 清空比赛记录      |"<<endl
        <<"|      0、 退出比赛系统      |"<<endl
        <<"|                            |"<<endl
        <<"|----------------------------|"<<endl;
}

void system_base::Exit()
{
    exit(0);
}

void system_base::Start()
{

    //容器
    vector<Player>player;

    //生成选手信息
    this->creat_player(player);
//    //测试打印
//    this->print_player(player);

    //分组信息
    this->divide_player(player);

    //1、打分
    this->first_score(player);

    //2、打分
    this->second_score(player);

    //保存文件
    this->save(player);

    //保存文件后文件一定不为空
    this->empty_file=false;


}


void system_base::View()
{
    if(this->empty_file==true)
    {
        cout<<"无往届比赛记录！！"<<endl;
        return;
    }

    //为不出现运行时出现“无往届记录“，需先读取文件
    this->read();

    //打印往届记录
    for(map<int,vector<string> >::iterator it=this->vectory.begin();it!=this->vectory.end();it++)
    {
        cout<<endl;
        cout<<"第"<<it->first<<"届"<<endl;
        cout<<"\t"<<"冠军:"<<"\t"<<"编号:"<<it->second[0]<<"\t分数:"<<it->second[1]<<endl;
        cout<<"\t"<<"亚军:"<<"\t"<<"编号:"<<it->second[2]<<"\t分数:"<<it->second[3]<<endl;
        cout<<"\t"<<"季军:"<<"\t"<<"编号:"<<it->second[4]<<"\t分数:"<<it->second[5]<<endl;
        cout<<"-----------------------------------------------"<<endl;
    }
}


//清空记录
void system_base::Clear()
{
    char choice;
    cout<<"确定清空往届记录吗？(y/n)"<<endl;
    cin>>choice;
    if(choice=='y')
    {

        //创建新文件（删除旧文件）
        ofstream ofs;
        ofs.open(filename,ios::trunc);

        ofs.close();

        //空标志设为真
        this->empty_file=true;

        //删除缓存区数据
        this->vectory.clear();

        //提示
        cout<<"往届记录已清空！！"<<endl;

    }

    return;

}








//other_base

//初始化(构造)
system_base::system_base()
{
    //读取文件
    this->read();


}

//生成选手信息
void system_base::creat_player(vector<Player>&player)
{
    vector<int>Idnum;
    vector<string>Name;
//    vector<int>Score;

    srand((unsigned int)time(NULL));



    //随机编号
    for(int a=1;a<=12;a++)
    {
        Idnum.push_back(a+10000);
    }

    random_shuffle(Idnum.begin(),Idnum.end());

    //随机姓名
    for(int b=0;b<12;b++)
    {
        string nameseed="ABCDEFGHIJKL";
        string name="选手";

        name+=nameseed[b];
        Name.push_back(name);
    }

    random_shuffle(Name.begin(),Name.end());

    //初始化分数
    double Score=0;



    //初始化player
    for(int d=0;d<12;d++)
    {
        Player p(Idnum[d],Name[d],Score);
        player.push_back(p);
    }
}


//打印函数指针
void print(Player p)
{
    cout<<"编号："<<p.m_Idnum<<"   "<<"姓名："<<p.m_Name<<"   "<<"得分："<<p.m_Score<<endl;
}
//便利打印选手信息
void system_base::print_player(vector<Player>&player)
{
    for_each(player.begin(),player.end(),print);
}


//分组
void system_base::divide_player(vector<Player>&player)
{
    cout<<"第一组为：";
    for(vector<Player>::iterator it1=player.begin();it1!=player.begin()+6;it1++)
    {
        cout<<it1->m_Idnum<<" ";
    }

    cout<<endl<<"第二组为：";
    for(vector<Player>::iterator it2=player.begin()+6;it2!=player.end();it2++)
    {
        cout<<it2->m_Idnum<<" ";
    }
    cout<<endl;
}


//player比较函数（＞）
bool Greater(Player &p1,Player &p2)
{
    return p1.m_Score>p2.m_Score;
}

//第一次得分（淘汰赛）
void system_base::first_score(vector<Player>&player)
{
    system("pause");
    system("cls");
    this->menu();

    //打分
    for(vector<Player>::iterator it=player.begin();it!=player.end();it++)
    {
        deque<double>s;
        for(int a=0;a<10;a++)
        {
            s.push_back((rand()%201+800)/10.f);//随机打分
        }

        sort(s.begin(),s.end());//升序排序
        s.pop_back();//去除最高
        s.pop_front();//去除最低

        double score=accumulate(s.begin(),s.end(),0)/s.size();//求平均

        it->m_Score=score;
    }

    //可以在创建时设置容器size，或者之后resize
    //否则程序会崩溃（硬塞无法插入，需先开辟空间）
    vector<Player>p1;
    vector<Player>p2;

    //自定义参数resize时需要一个 该类 的空构造函数
    p1.resize(6);//player.size()/2
    p2.resize(6);

    //拷贝两个新容器，存放分组后的数据
    p1.end()=copy(player.begin(),player.begin()+6,p1.begin());
    p2.end()=copy(player.begin()+6,player.end(),p2.begin());

    //降序排序
    sort(p1.begin(),p1.end(),Greater);
    sort(p2.begin(),p2.end(),Greater);



    //打印分组后的得分信息
    cout<<"淘汰赛两组得分为："<<endl
        <<"第一组排名："<<endl;
    for_each(p1.begin(),p1.end(),print);
    cout<<endl<<"第二组排名："<<endl;
    for_each(p2.begin(),p2.end(),print);




    //更改player容器为只存在晋级者

    //去除两组后三名
    for(int b=0;b<3;++b)
    {
        p1.pop_back();
        p2.pop_back();
    }

    //p1,p2合并并降序排序
    vector<Player>newp(6);
    newp.end()=merge(p1.begin(),p1.end(),p2.begin(),p2.end(),newp.begin(),Greater);

    //交换数据
    swap(player,newp);
}

//第二次打分（决赛）
void system_base::second_score(vector<Player>&player)
{
    system("pause");
    system("cls");
    this->menu();

    //打分
    for(vector<Player>::iterator it=player.begin();it!=player.end();it++)
    {
        deque<double>s;
        for(int a=0;a<10;a++)
        {
            s.push_back((rand()%210+800)/10.3f);//随机打分
        }

        sort(s.begin(),s.end());//升序排序
        s.pop_back();//去除最高
        s.pop_front();//去除最低

        double score=accumulate(s.begin(),s.end(),0)/s.size();//求平均

        it->m_Score=score;
    }

    sort(player.begin(),player.end(),Greater);

    cout<<"决赛得分为："<<endl;
    for_each(player.begin(),player.end(),print);


    cout<<endl<<"最终排名为："<<endl;
    cout<<"冠军：\t";
        print(player[0]);
    cout<<"亚军：\t";
        print(player[1]);
    cout<<"季军：\t";
        print(player[2]);
    cout<<endl;
}


//保存记录
void system_base::save(vector<Player>&player)
{
    ofstream ofs;
    ofs.open(filename,ios::out|ios::app);
    for(vector<Player>::iterator it=player.begin();it!=player.begin()+3;it++)
    {
        ofs<<it->m_Idnum<<","<<it->m_Score<<",";
    }
    ofs<<endl;

    this->empty_file=false;

    ofs.close();
}


//读取文件
void system_base::read()
{
    ifstream ifs;

    string temp;
    int index=1;

    ifs.open(filename,ios::in);

    //1、文件不存在
    if(!ifs.is_open())
    {
//        cout<<"文件不存在"<<endl;
        this->empty_file=true;
        ifs.close();
        return;
    }

    //2、文件为空
    char ch;
    ch=ifs.get();
    if(ifs.eof())
    {
//        cout<<"文件为空"<<endl;
        this->empty_file=true;
        ifs.close();
        return;
    }

    //3、文件不为空
    ifs.putback(ch);
    vector<string>s;

    while(getline(ifs,temp))
    {
//        cout<<temp<<endl;
        int pos=-1;
        int start=0;

        while(1)
        {
            pos=temp.find(",",start);
            if(pos == -1)
            {
                break;
            }

            string a=temp.substr(start,pos-start);
            start=pos+1;

//            cout<<a<<endl;
            s.push_back(a);

        }
        //测试
//        for_each(s.begin(),s.end(),printstring());

        this->vectory.insert(pair<int,vector<string> >(index,s));

        //清空s（否则会有上次的遗留元素），方便下次插入map
        s.clear();

        index++;
    }

    this->empty_file=false;
    ifs.close();
}


