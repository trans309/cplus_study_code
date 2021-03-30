#include "menu_system.h"
#include "worker.h"

//打印菜单
void menu_system::menu()
{
    cout<<"******************************"<<endl;
    cout<<"*****欢迎使用职工管理系统*****"<<endl;
    cout<<"*****  1、 增加职工信息  *****"<<endl;
    cout<<"*****  2、 显示职工信息  *****"<<endl;
    cout<<"*****  3、 删除离职职工  *****"<<endl;
    cout<<"*****  4、 修改职工信息  *****"<<endl;
    cout<<"*****  5、 查找职工信息  *****"<<endl;
    cout<<"*****  6、 按早编号排序  *****"<<endl;
    cout<<"*****  7、 清空所有文档  *****"<<endl;
    cout<<"*****  0、 退出管理系统  *****"<<endl;
    cout<<"******************************"<<endl;
}

//构造--初始化文件人数
void menu_system::init_num()
{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int num=0;
    string m_id;
    string m_name;
    int m_p_id;

    //每读取一行，人数num+1
    while(ifs>>m_id&&ifs>>m_name&&ifs>>m_p_id)//ifs>>  ----  流模式读取，每遇到“空格、换行、文件结束”，停止读取
    {
        num++;
    }

    //初始化人数
    this->worker_num=num;

//    //测试
//    cout<<"共导入"<<num<<"名职工"<<endl;
    ifs.close();
}

//构造--导入文件内容，指针指向文件内容
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

    //释放旧空间
    delete[] this->worker_arr;
    this->worker_arr=NULL;

    //链接新空间
    this->worker_arr=new_worker_arr;

//    //测试，打印员工
//    this->show_worker();

    ifs.close();
}

//保存为文件
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

//添加职工
void menu_system::add_worker()
{
    int num;
    cout<<"请输入添加职工数："<<endl;
    cin>>num;

    //判断输入人数
    if(num>0)
    {
        //申请新空间
        worker **newspace=new worker*[this->worker_num+num];
        //若有元素,进行数据拷贝
        if(this->worker_arr!=NULL)
        {

            int i=0;
            for(;i<this->worker_num;i++)
            {
                newspace[i]=this->worker_arr[i];
            }
        }

        //循环添加
        int j=0;
        for(;j<num;j++)
        {
            int post;
            string name,id;

            cout<<"请输入职工编号:";
            cin>>id;
            cout<<"请输入职工姓名:";
            cin>>name;
            cout<<"1、员工"<<endl;
            cout<<"2、经理"<<endl;
            cout<<"3、老板"<<endl;
            cout<<"请输入职工职位:"<<endl;
            cin>>post;

            //根据职位申请新空间（元素）
            switch(post)
            {
            case 1:
                newspace[worker_num+j]=new employee(id,name,post);cout<<"添加成功！"<<endl<<endl;
                break;
            case 2:
                newspace[worker_num+j]=new manage(id,name,post);cout<<"添加成功！"<<endl<<endl;
                break;
            case 3:
                newspace[worker_num+j]=new boss(id,name,post);cout<<"添加成功！"<<endl<<endl;
                break;
            default:
                cout<<"输入错误，重新添加\n"<<endl;
                j--;
                break;
            }
        }

        //释放老空间，链接新空间
        delete[] this->worker_arr;
        this->worker_arr=newspace;

        //更新职工人数
        this->worker_num+=num;

        //保存文件
        this->save_worker();
        cout<<"成功添加"<<num<<"名职工\n"<<endl;
    }

    //错误输入添加人数
    else
    {
        cout<<"输入错误,退出添加\n"<<endl;
    }
}

//显示（打印）系统职工
void menu_system::show_worker()
{
    int i=0;
    if(this->worker_num>0)
    {
        for(;i<this->worker_num;i++)
        {
            this->worker_arr[i]->showInfo();
        }
    }
    else
    {
        cout<<"无职工信息！"<<"\n"<<"请进行添加！！\n"<<endl;
    }
}
