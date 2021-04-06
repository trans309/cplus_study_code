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
        <<"|    ��ӭʹ���ݽ�����ϵͳ    |"<<endl
        <<"|----------------------------|"<<endl
        <<"|                            |"<<endl
        <<"|      1�� ��ʼ�ݽ�����      |"<<endl
        <<"|      2�� �鿴�����¼      |"<<endl
        <<"|      3�� ��ձ�����¼      |"<<endl
        <<"|      0�� �˳�����ϵͳ      |"<<endl
        <<"|                            |"<<endl
        <<"|----------------------------|"<<endl;
}

void system_base::Exit()
{
    exit(0);
}

void system_base::Start()
{

    //����
    vector<Player>player;

    //����ѡ����Ϣ
    this->creat_player(player);
//    //���Դ�ӡ
//    this->print_player(player);

    //������Ϣ
    this->divide_player(player);

    //1�����
    this->first_score(player);

    //2�����
    this->second_score(player);

    //�����ļ�
    this->save(player);

    //�����ļ����ļ�һ����Ϊ��
    this->empty_file=false;


}


void system_base::View()
{
    if(this->empty_file==true)
    {
        cout<<"�����������¼����"<<endl;
        return;
    }

    //Ϊ����������ʱ���֡��������¼�������ȶ�ȡ�ļ�
    this->read();

    //��ӡ�����¼
    for(map<int,vector<string> >::iterator it=this->vectory.begin();it!=this->vectory.end();it++)
    {
        cout<<endl;
        cout<<"��"<<it->first<<"��"<<endl;
        cout<<"\t"<<"�ھ�:"<<"\t"<<"���:"<<it->second[0]<<"\t����:"<<it->second[1]<<endl;
        cout<<"\t"<<"�Ǿ�:"<<"\t"<<"���:"<<it->second[2]<<"\t����:"<<it->second[3]<<endl;
        cout<<"\t"<<"����:"<<"\t"<<"���:"<<it->second[4]<<"\t����:"<<it->second[5]<<endl;
        cout<<"-----------------------------------------------"<<endl;
    }
}


//��ռ�¼
void system_base::Clear()
{
    char choice;
    cout<<"ȷ����������¼��(y/n)"<<endl;
    cin>>choice;
    if(choice=='y')
    {

        //�������ļ���ɾ�����ļ���
        ofstream ofs;
        ofs.open(filename,ios::trunc);

        ofs.close();

        //�ձ�־��Ϊ��
        this->empty_file=true;

        //ɾ������������
        this->vectory.clear();

        //��ʾ
        cout<<"�����¼����գ���"<<endl;

    }

    return;

}








//other_base

//��ʼ��(����)
system_base::system_base()
{
    //��ȡ�ļ�
    this->read();


}

//����ѡ����Ϣ
void system_base::creat_player(vector<Player>&player)
{
    vector<int>Idnum;
    vector<string>Name;
//    vector<int>Score;

    srand((unsigned int)time(NULL));



    //������
    for(int a=1;a<=12;a++)
    {
        Idnum.push_back(a+10000);
    }

    random_shuffle(Idnum.begin(),Idnum.end());

    //�������
    for(int b=0;b<12;b++)
    {
        string nameseed="ABCDEFGHIJKL";
        string name="ѡ��";

        name+=nameseed[b];
        Name.push_back(name);
    }

    random_shuffle(Name.begin(),Name.end());

    //��ʼ������
    double Score=0;



    //��ʼ��player
    for(int d=0;d<12;d++)
    {
        Player p(Idnum[d],Name[d],Score);
        player.push_back(p);
    }
}


//��ӡ����ָ��
void print(Player p)
{
    cout<<"��ţ�"<<p.m_Idnum<<"   "<<"������"<<p.m_Name<<"   "<<"�÷֣�"<<p.m_Score<<endl;
}
//������ӡѡ����Ϣ
void system_base::print_player(vector<Player>&player)
{
    for_each(player.begin(),player.end(),print);
}


//����
void system_base::divide_player(vector<Player>&player)
{
    cout<<"��һ��Ϊ��";
    for(vector<Player>::iterator it1=player.begin();it1!=player.begin()+6;it1++)
    {
        cout<<it1->m_Idnum<<" ";
    }

    cout<<endl<<"�ڶ���Ϊ��";
    for(vector<Player>::iterator it2=player.begin()+6;it2!=player.end();it2++)
    {
        cout<<it2->m_Idnum<<" ";
    }
    cout<<endl;
}


//player�ȽϺ���������
bool Greater(Player &p1,Player &p2)
{
    return p1.m_Score>p2.m_Score;
}

//��һ�ε÷֣���̭����
void system_base::first_score(vector<Player>&player)
{
    system("pause");
    system("cls");
    this->menu();

    //���
    for(vector<Player>::iterator it=player.begin();it!=player.end();it++)
    {
        deque<double>s;
        for(int a=0;a<10;a++)
        {
            s.push_back((rand()%201+800)/10.f);//������
        }

        sort(s.begin(),s.end());//��������
        s.pop_back();//ȥ�����
        s.pop_front();//ȥ�����

        double score=accumulate(s.begin(),s.end(),0)/s.size();//��ƽ��

        it->m_Score=score;
    }

    //�����ڴ���ʱ��������size������֮��resize
    //�������������Ӳ���޷����룬���ȿ��ٿռ䣩
    vector<Player>p1;
    vector<Player>p2;

    //�Զ������resizeʱ��Ҫһ�� ���� �Ŀչ��캯��
    p1.resize(6);//player.size()/2
    p2.resize(6);

    //������������������ŷ���������
    p1.end()=copy(player.begin(),player.begin()+6,p1.begin());
    p2.end()=copy(player.begin()+6,player.end(),p2.begin());

    //��������
    sort(p1.begin(),p1.end(),Greater);
    sort(p2.begin(),p2.end(),Greater);



    //��ӡ�����ĵ÷���Ϣ
    cout<<"��̭������÷�Ϊ��"<<endl
        <<"��һ��������"<<endl;
    for_each(p1.begin(),p1.end(),print);
    cout<<endl<<"�ڶ���������"<<endl;
    for_each(p2.begin(),p2.end(),print);




    //����player����Ϊֻ���ڽ�����

    //ȥ�����������
    for(int b=0;b<3;++b)
    {
        p1.pop_back();
        p2.pop_back();
    }

    //p1,p2�ϲ�����������
    vector<Player>newp(6);
    newp.end()=merge(p1.begin(),p1.end(),p2.begin(),p2.end(),newp.begin(),Greater);

    //��������
    swap(player,newp);
}

//�ڶ��δ�֣�������
void system_base::second_score(vector<Player>&player)
{
    system("pause");
    system("cls");
    this->menu();

    //���
    for(vector<Player>::iterator it=player.begin();it!=player.end();it++)
    {
        deque<double>s;
        for(int a=0;a<10;a++)
        {
            s.push_back((rand()%210+800)/10.3f);//������
        }

        sort(s.begin(),s.end());//��������
        s.pop_back();//ȥ�����
        s.pop_front();//ȥ�����

        double score=accumulate(s.begin(),s.end(),0)/s.size();//��ƽ��

        it->m_Score=score;
    }

    sort(player.begin(),player.end(),Greater);

    cout<<"�����÷�Ϊ��"<<endl;
    for_each(player.begin(),player.end(),print);


    cout<<endl<<"��������Ϊ��"<<endl;
    cout<<"�ھ���\t";
        print(player[0]);
    cout<<"�Ǿ���\t";
        print(player[1]);
    cout<<"������\t";
        print(player[2]);
    cout<<endl;
}


//�����¼
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


//��ȡ�ļ�
void system_base::read()
{
    ifstream ifs;

    string temp;
    int index=1;

    ifs.open(filename,ios::in);

    //1���ļ�������
    if(!ifs.is_open())
    {
//        cout<<"�ļ�������"<<endl;
        this->empty_file=true;
        ifs.close();
        return;
    }

    //2���ļ�Ϊ��
    char ch;
    ch=ifs.get();
    if(ifs.eof())
    {
//        cout<<"�ļ�Ϊ��"<<endl;
        this->empty_file=true;
        ifs.close();
        return;
    }

    //3���ļ���Ϊ��
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
        //����
//        for_each(s.begin(),s.end(),printstring());

        this->vectory.insert(pair<int,vector<string> >(index,s));

        //���s����������ϴε�����Ԫ�أ��������´β���map
        s.clear();

        index++;
    }

    this->empty_file=false;
    ifs.close();
}


