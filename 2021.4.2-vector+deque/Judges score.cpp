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

//����ѡ��
void creat_p(vector<player>& vp)
{

    string nameseed="ABCDE";
    for(int i=0;i<5;i++)
    {
        //��ʼ��ѡ������
        string name="ѡ��";
        name+=nameseed[i];

        //����ѡ��
        player pp(name);

        //����vector����
        vp.push_back(pp);
    }
}

//���÷���
void set_s(vector<player>& vp)
{
    //�����������
    srand((unsigned int)time(NULL));

    //��������
    for(vector<player>::iterator it=vp.begin();it<vp.end();it++)
    {
        deque<int>score;
        for(int i=0;i<10;i++)
        {
            score.push_back(rand()%41+60);
        }

//        //���Դ�ӡ(δɾδ����)
//        for(unsigned int a=0;a<score.size();a++)
//        {
//            cout<<score[a]<<" ";
//        }
//        cout<<endl;

        sort(score.begin(),score.end());

        score.pop_front();
        score.pop_back();

//        //���Դ�ӡ����ɾ������
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

//��ӡ
void print_s(vector<player>& vp)
{
    for(vector<player>::iterator s=vp.begin();s<vp.end();s++)
    {
        cout<<"����:"<<s->name<<"\t�÷�:"<<s->score<<endl;
    }
}

void test2()
{
    vector<player>vp;

    creat_p(vp);
    set_s(vp);
    print_s(vp);
}
