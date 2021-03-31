#include "menu_system.h"
#include "worker.h"

//��ӡ�˵�
void menu_system::menu()
{
    cout<<"******************************"<<endl;
    cout<<"*****��ӭʹ��ְ������ϵͳ*****"<<endl;
    cout<<"*****  1�� ����ְ����Ϣ  *****"<<endl;
    cout<<"*****  2�� ��ʾְ����Ϣ  *****"<<endl;
    cout<<"*****  3�� ɾ����ְְ��  *****"<<endl;
    cout<<"*****  4�� �޸�ְ����Ϣ  *****"<<endl;
    cout<<"*****  5�� ����ְ����Ϣ  *****"<<endl;
    cout<<"*****  6�� ����ְ����Ϣ  *****"<<endl;
    cout<<"*****  7�� ���������Ϣ  *****"<<endl;
    cout<<"*****  0�� �˳�����ϵͳ  *****"<<endl;
    cout<<"******************************"<<endl;
}



//����--��ʼ���ļ�����
void menu_system::init_num()
{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int num=0;
    string m_id;
    string m_name;
    int m_p_id;

    //ÿ��ȡһ�У�����num+1
    while(ifs>>m_id&&ifs>>m_name&&ifs>>m_p_id)//ifs>>  ----  ��ģʽ��ȡ��ÿ�������ո񡢻��С��ļ���������ֹͣ��ȡ
    {
        num++;
    }

    //��ʼ������
    this->worker_num=num;

//    //����
//    cout<<"������"<<num<<"��ְ��"<<endl;
    ifs.close();
}

//����--�����ļ����ݣ�ָ��ָ���ļ�����
void menu_system::init_worker()
{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);

    worker** new_worker_arr=new worker*[this->worker_num];

        string m_id;
        string m_name;
        int m_p_id;
        int i=0;

        while(ifs>>m_id&&ifs>>m_name&&ifs>>m_p_id)
        {
            if(m_p_id==1)
            {
                new_worker_arr[i]=new employee(m_id,m_name,m_p_id);
            }
            else if(m_p_id==2)
            {
                new_worker_arr[i]=new manage(m_id,m_name,m_p_id);
            }
            else if(m_p_id==3)
            {
                new_worker_arr[i]=new boss(m_id,m_name,m_p_id);
            }
            i++;
        }

    //�ͷžɿռ�
    delete[] this->worker_arr;
    this->worker_arr=NULL;

    //�����¿ռ�
    this->worker_arr=new_worker_arr;

//    //���ԣ���ӡԱ��
//    this->show_worker();

    this->FileExists=true;

    ifs.close();
}








//�������ܺ���


//���ְ��
void menu_system::add_worker()
{
    int num;
    cout<<"���������ְ������"<<endl;
    cin>>num;

    //�ж���������
    if(num>0)
    {
        //�����¿ռ�
        worker **newspace=new worker*[this->worker_num+num];
        //����Ԫ��,�������ݿ���
        if(this->worker_arr!=NULL)
        {

            int i=0;
            for(;i<this->worker_num;i++)
            {
                newspace[i]=this->worker_arr[i];
            }
        }

        //ѭ�����
        int j=0;
        for(;j<num;j++)
        {
            int post;
            string name,id;

            cout<<"������ְ�����:";
            cin>>id;
            cout<<"������ְ������:";
            cin>>name;
            cout<<"1��Ա��"<<endl;
            cout<<"2������"<<endl;
            cout<<"3���ϰ�"<<endl;
            cout<<"������ְ��ְλ:"<<endl;
            cin>>post;

            //����ְλ�����¿ռ䣨Ԫ�أ�
            switch(post)
            {
            case 1:
                newspace[worker_num+j]=new employee(id,name,post);cout<<"��ӳɹ���"<<endl<<endl;
                break;
            case 2:
                newspace[worker_num+j]=new manage(id,name,post);cout<<"��ӳɹ���"<<endl<<endl;
                break;
            case 3:
                newspace[worker_num+j]=new boss(id,name,post);cout<<"��ӳɹ���"<<endl<<endl;
                break;
            default:
                cout<<"��������������\n"<<endl;
                j--;
                break;
            }
        }

        //�ͷ��Ͽռ䣬�����¿ռ�
        delete[] this->worker_arr;
        this->worker_arr=newspace;

        //����ְ������
        this->worker_num+=num;

        //�����ļ�
        this->save_worker();
        this->FileExists=true;
        cout<<"�ɹ����"<<num<<"��ְ��\n"<<endl;
    }

    //���������������
    else
    {
        cout<<"�������,�˳����\n"<<endl;
    }
}

//ɾ����ְְ��
void menu_system::delete_worker()
{
    string input;
    cout<<"����Ҫɾ����ְְ����Ż�������";
    cin>>input;

    int i=this->find_worker(input);

    //δ�鵽ְ��
    if(i==-1)
    {
        cout<<"�޴�����Ϣ�������\n"<<endl;
        return;
    }

    //ȷ����Ϣ
    string ch;
    cout<<"ȷ��ɾ�����ˣ���y/n��"<<endl;
    cin>>ch;

    //ȷ��ɾ��
    if(ch=="y")
    {
        //��ְ����Ϣ��������Ϣ����
        for(;i<this->worker_num-1;i++)
        {
            this->worker_arr[i]=this->worker_arr[i+1];
        }

        //ְ������-1
        this->worker_num--;

        //���ɾ��������Ϊ0����flag����Ϊ��--���ļ�������
        if(this->worker_num==0)
        {
            this->FileExists=false;
        }

        //�����ļ�
        this->save_worker();
        cout<<"ɾ���ɹ�����"<<endl;
        return;
    }

    //ȡ��ɾ��
    cout<<"ȡ��ɾ������\n"<<endl;
}

//��ʾ����ӡ��ϵͳְ��
void menu_system::show_worker()
{
    int i=0;
    if(this->worker_num>0 && this->FileExists==true)//����������˼һ��,��ѡ��һ����
    {
        for(;i<this->worker_num;i++)
        {
            this->worker_arr[i]->showInfo();
        }
    }
    else
    {
        cout<<"\n��ְ����Ϣ��"<<"\n"<<"�������ӣ���\n"<<endl;
    }
}

//����ְ��
void menu_system::search_worker()
{
    string input;
    cout<<"����Ҫ����ְ����Ż�������";
    cin>>input;

    //find_worker���������ҵ��� ���д�ӡ �� �����±�
    //δ�ҵ� ����ӡ �� ����-1
    int i=this->find_worker(input);

    if(i==-1)
    {
        cout<<"�޴�����Ϣ�������\n"<<endl;
        return;
    }
}

//�޸�Ա����Ϣ
void menu_system::modify_worker()
{
    string input;
    cout<<"����Ҫ�޸�ְ����Ż�������";
    cin>>input;

    //find_worker���������ҵ��� ���д�ӡ �� �����±�
    //δ�ҵ� ����ӡ �� ����-1
    int i=this->find_worker(input);

    if(i==-1)
    {
        cout<<"�޴�����Ϣ�������\n"<<endl;
        return;
    }

    //ֻ��ѡ����ȷ�����˳�ѭ��
    while(1)
    {
        string choise;
        cout<<"1��ְ�����\n"<<"2��ְ������\n"<<"3��ְ��ְλ"<<endl;
        cout<<"��ѡ���޸ĵ���Ŀ��";
        cin>>choise;

        if(choise=="1"||choise=="2"||choise=="3")
        {
            //�޸�ְ�����
            if(choise=="1")
            {
                string mod;
                cout<<"������޸�Ϊ��";
                cin>>mod;
                this->worker_arr[i]->id=mod;
                cout<<"�޸ĳɹ���"<<endl;
            }

            //�޸�ְ������
            else if(choise=="2")
            {
                string mod;
                cout<<"�������޸�Ϊ��";
                cin>>mod;
                this->worker_arr[i]->name=mod;
                cout<<"�޸ĳɹ���"<<endl;
            }

            //�޸�ְ��ְλ
            else if(choise=="3")
            {
                //�޸�ְ��ְλ�漰�麯��
                //��Ҫ�����ڶ������ٿռ�
                //���ú���ʵ��
                this->mod_pid(this->worker_arr[i]);
            }

            //ֻ��ѡ����ȷ��1��2��3��
            //�����޸����ݺ�
            //��ѯ���Ƿ�����޸�
            cout<<"�Ƿ�����޸ģ�y/n��"<<endl;
            cin>>choise;

            //��y���������ǡ�y���˳��޸�
            if(choise!="y")
            {
                break;
            }

        }

        //�޸ĵ���Ŀ��Ϊ1��2��3ʱ����ʾ������󣬲��˳�ѭ��
        else
        {
            cout<<"\n���������������\n"<<endl;
        }
    }

    //��ӡ�޸ĺ����Ϣ
    cout<<"��Ϣ���޸�Ϊ��"<<endl;
    this->worker_arr[i]->showInfo();

    //�����ļ�
    this->save_worker();

}

//�����Ϣ
void menu_system::clean_worker()
{
    //ȷ����Ϣ
    string c;
    cout<<"ȷ�����������Ϣ�𣿣�y/n��"<<endl;
    cin>>c;

    //ȷ�����
    if(c=="y")
    {
        //�ͷſռ�
        delete[] this->worker_arr;

        //��ʼ������������
        this->worker_arr=NULL;
        this->worker_num=0;

        //��ʼ��flagΪ��
        this->FileExists=false;

        //�����ļ�
        this->save_worker();
        cout<<"������Ϣ����գ���\n"<<endl;
        return;
    }

    //ȡ�����
    cout<<"ȡ��������ݳɹ�����\n"<<endl;

}

//������Ϣ
//�����֣��������
//����������
void menu_system::sort_worker()
{
    int choice1;
    cout<<"1��ְԱ���\n"<<"2��ְԱ����"<<endl;
    cout<<"��ѡ��������Ŀ��";
    cin>>choice1;
    if(choice1==1)
    {
        int choice2;
        cout<<"1����������\n"<<"2����������"<<endl;
        cout<<"��ѡ������ʽ��";
        cin>>choice2;
        if(choice2==1)
        {
            //�������
            this->choose_sort(this->worker_arr,1,1);
        }
        else
        {
            //��Ž���
            this->choose_sort(this->worker_arr,1,2);
        }
    }
    else if(choice1==2)
    {
        int choice2;
        cout<<"1����������\n"<<"2����������"<<endl;
        cout<<"��ѡ������ʽ��";
        cin>>choice2;
        if(choice2==1)
        {
            //��������
            this->choose_sort(this->worker_arr,2,1);
        }
        else
        {
            //��������
            this->choose_sort(this->worker_arr,2,2);
        }
    }

        string c;
        cout<<"�Ƿ񱣴浽�ļ��У���y/n��"<<endl;
        cin>>c;

        if(c=="y")
        {
            this->save_worker();
            cout<<"���浽�ļ��ɹ�"<<endl;
            return;
        }

        cout<<"������δ���浽�ļ���"<<endl;
}





//���ӹ���ʵ��


//����Ϊ�ļ�
void menu_system::save_worker()
{
    ofstream ofs;
    ofs.open(FILENAME,ios::out);
    int i=0;
    for(;i<this->worker_num;i++)
    {
        ofs<<this->worker_arr[i]->id<<"\t"
            <<this->worker_arr[i]->name<<"\t"
            <<this->worker_arr[i]->p_id<<endl;
    }
    ofs.close();
}

//����Ż�������������Ϣ
int menu_system::find_worker(string input)
{
    for(int i=0;i<this->worker_num;i++)
    {
        if(input==this->worker_arr[i]->name || input==this->worker_arr[i]->id)
        {
            cout<<endl;
            this->worker_arr[i]->showInfo();//��ӡְ����Ϣ
            cout<<endl;
            return i;//���ҵ�ְ���򷵻��±�
        }
    }
    return -1;//�鲻���򷵻�-1
}

//�޸�ְλ
void menu_system::mod_pid(worker* &sor)//&--�޸�����������
{
    int post;
    cout<<"\n1��Ա��"<<endl;
    cout<<"2������"<<endl;
    cout<<"3���ϰ�"<<endl;
    cout<<"��ְ��ְλ�޸�Ϊ:";
    cin>>post;

    //����ְλ�����¿ռ䣨Ԫ�أ�
    switch(post)
    {
    case 1:
        sor=new employee(sor->id,sor->name,post);cout<<"�޸ĳɹ���"<<endl<<endl;
        break;
    case 2:
        sor=new manage(sor->id,sor->name,post);cout<<"�޸ĳɹ���"<<endl<<endl;
        break;
    case 3:
        sor=new boss(sor->id,sor->name,post);cout<<"�޸ĳɹ���"<<endl<<endl;
        break;
    default:
        break;
    }
}

//��������
void Swap(worker* &a,worker* &b)
{
    worker* temp=a;
    a=b;
    b=temp;
}

//ѡ������
//way1 --- ��Ŀ
//way2 --- ����
void menu_system::choose_sort(worker** &sor,int way1,int way2)
{
    //�������
    if(way1==1&&way2==1)
    {
        int i=0;
        for(;i<this->worker_num;i++)
        {
            int j=i;
            int MIN=i;

            for(;j<this->worker_num;j++)
            {
                if(this->worker_arr[j]->id<this->worker_arr[MIN]->id)//ȷ����Сֵ�±�
                {
                    MIN=j;
                }
            }
            Swap(this->worker_arr[MIN],this->worker_arr[i]);
        }
    }

    //��Ž���
    else if(way1==1&&way2==2)
    {
        int i=0;
        for(;i<this->worker_num;i++)
        {
            int j=i;
            int MAX=i;

            for(;j<this->worker_num;j++)
            {
                if(this->worker_arr[j]->id>this->worker_arr[MAX]->id)//ȷ�����ֵ�±�
                {
                    MAX=j;
                }
            }
            Swap(this->worker_arr[MAX],this->worker_arr[i]);
        }
    }

    //��������
    else if(way1==2&&way2==1)
    {
        int i=0;
        for(;i<this->worker_num;i++)
        {
            int j=i;
            int MIN=i;

            for(;j<this->worker_num;j++)
            {
                if(this->worker_arr[j]->name<this->worker_arr[MIN]->name)//ȷ����Сֵ�±�
                {
                    MIN=j;
                }
            }
            Swap(this->worker_arr[MIN],this->worker_arr[i]);
        }
    }

    //��������
    else if(way1==2&&way2==2)
    {
        int i=0;
        for(;i<this->worker_num;i++)
        {
            int j=i;
            int MAX=i;

            for(;j<this->worker_num;j++)
            {
                if(this->worker_arr[j]->name>this->worker_arr[MAX]->name)//ȷ�����ֵ�±�
                {
                    MAX=j;
                }
            }
            Swap(this->worker_arr[MAX],this->worker_arr[i]);
        }
    }

}
